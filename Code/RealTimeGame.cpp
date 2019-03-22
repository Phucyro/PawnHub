#ifndef __REAL__TIME__GAME__CPP__
#define __REAL__TIME__GAME__CPP__

#include <iostream>
#include <string>
#include <queue>
#include <sys/select.h>
#include <chrono>
#include <thread>
#include <cmath>
#include "RealTimeGame.hpp"
#include "Queen.hpp"


RealTimeGame::RealTimeGame(Piece** pieces, unsigned piecesAmount, Player* player1, Player* player2, unsigned lastStrongPiecesWhite, unsigned lastStrongPieceBlack):
	Game(pieces,piecesAmount, player1, player2, lastStrongPiecesWhite, lastStrongPieceBlack, nullptr),
	_currentPlayer(nullptr),
	_lastUpdate(0u)
{
	_board = new RealTimeBoard();
}



RealTimeGame& RealTimeGame::operator= (const RealTimeGame& original){
	this->Game::operator= (original);
	_currentPlayer = original._currentPlayer;
	_lastUpdate = original._lastUpdate;
	return *this;
}


RealTimeGame& RealTimeGame::operator= (RealTimeGame&& original){
	this->Game::operator= (original);
	_currentPlayer = original._currentPlayer;
	original._currentPlayer = nullptr;
	_lastUpdate = original._lastUpdate;
	return *this;
}



void RealTimeGame::_sendBoard(){
	this->Game::_sendBoard();
	_lastUpdate = _turn;
}

void RealTimeGame::_sendStart() {
	std::string update = "start";
	_player1->transferUpdate(update);
	_player2->transferUpdate(update);
	update = "realtime";
	_player1->transferUpdate(update);
	_player2->transferUpdate(update);
}


void RealTimeGame::start()
{
	_player1->setColor('w');
	_player2->setColor('b');
	std::cout << "Starting Game" << std::endl;
	this->_initBoard();
	this->_sendGameMode();
	this->_sendPlayerColour();
	this->_sendStart();
	this->_sendBoard();
	this->_mainLoop();
	std::cout << "Game finished" << std::endl;
}

void RealTimeGame::_addToQueue(Coordinate moveStart, Coordinate moveEnd, std::queue<ChainedMove*>& movesQueue){
	Piece* movingPiece = _board->getCase(moveStart);
	ChainedMove* currentMove = new ChainedMove(movingPiece, moveEnd);
	currentMove->setMoment(_turn + MOVE_TIME/2);
	movesQueue.push(currentMove);
	this->_getBoard()->lock(moveEnd);
	movingPiece->startMovingTo(*this, moveEnd);
}

void RealTimeGame::_handleSpecialMove(Coordinate moveStart, Coordinate moveEnd, std::queue<ChainedMove*>& movesQueue){
	Piece* movingPiece = _board->getCase(moveStart);
	if (movingPiece->getType() == 'k'){
		if (moveStart == Coordinate('E','1')){
			if (moveEnd == Coordinate('G','1')) _addToQueue(Coordinate('H','1'), Coordinate('F','1'), movesQueue);
			else if (moveEnd == Coordinate('C','1')) _addToQueue(Coordinate('A','1'), Coordinate('D','1'), movesQueue);
		}
		else if (moveStart == Coordinate('E','8')){
			if (moveEnd == Coordinate('G','8')) _addToQueue(Coordinate('H','8'), Coordinate('F','8'), movesQueue);
			else if (moveEnd == Coordinate('C','8')) _addToQueue(Coordinate('A','8'), Coordinate('D','8'), movesQueue);
		}
	}
}

void RealTimeGame::_mainLoop(){
	int p1fd = _player1->getReadPipe();
	int p2fd = _player2->getReadPipe();
	int currentPfd; // current player pipe
	int nfds = p1fd < p2fd ? p2fd+1 : p1fd+1;// first parameter of select
	int nfdSet;// select return value (number of move recieved)
	fd_set pipes;
	
	Piece* movingPiece;
	char move[5];// move recieved by pipe
	Coordinate moveStart, moveEnd;
	ChainedMove* currentMove = nullptr;
	std::queue<ChainedMove*> movesQueue;
	
	std::chrono::time_point<std::chrono::system_clock> timerStart, timerStop;
	int timeBeforeNextMove;
	struct timeval timeLeft;
	
	while(!this->_isFinish()){
		timeLeft.tv_sec = 0;
		if (movesQueue.empty()){
			timeLeft.tv_usec = _timeBeforeUpdate()*1000;
		}
		else{
			timeBeforeNextMove = movesQueue.front()->getMoment() - _turn;
			timeLeft.tv_usec = _timeBeforeUpdate() < timeBeforeNextMove ? _timeBeforeUpdate()*1000 : timeBeforeNextMove*1000;
		}
		
		FD_ZERO(&pipes);
		FD_SET(p1fd, &pipes);
		FD_SET(p2fd, &pipes);
		
		timerStart = std::chrono::system_clock::now();
		nfdSet = select(nfds, &pipes, nullptr, nullptr, &timeLeft);
		if (nfdSet == -1) throw std::runtime_error("Select failed");
		timerStop = std::chrono::system_clock::now();
		_turn += std::chrono::duration_cast<std::chrono::milliseconds>(timerStop - timerStart).count();
				
		//move recieved
		if (nfdSet){
			if (FD_ISSET(p1fd, &pipes)){
				_currentPlayer = _player1;
				currentPfd = p1fd;	
			}
			else if (FD_ISSET(p2fd, &pipes)){
				_currentPlayer = _player2;
				currentPfd = p2fd;	
			}
			read(currentPfd, &move, 4*sizeof(char));
			move[4] = '\0';
			if (move[0] == '/' && move[1] == 'e' && move[2] == 'n' && move[3] == 'd'){
				if(_currentPlayer == _player1) _winner = _player2;
				else _winner = _player1;
			}
			std::cout<<"mainLoop: Recieved move "<<move<<" from "<<_currentPlayer->getName()<<std::endl;
			moveStart = Coordinate(move[0], move[1]);
			moveEnd = Coordinate(move[2], move[3]);
			
			if (_isMovePossible(moveStart, moveEnd)){
				_addToQueue(moveStart, moveEnd, movesQueue);
				_handleSpecialMove(moveStart, moveEnd, movesQueue);
			}
		}
		//no move recived before end of timer
		else{
			//move to do
			while (!movesQueue.empty() && movesQueue.front()->getMoment() <= _turn && !this->_isFinish()){
				currentMove = movesQueue.front();
				movesQueue.pop();
				movingPiece = currentMove->getPiece();
				moveEnd = currentMove->nextMove();
				if (movingPiece->isTaken()){
					delete currentMove;
				}
				else if(moveEnd == Coordinate('T','9')){
					this->_getBoard()->unlock(movingPiece->getCoord());
					movingPiece->stopMoving(*this, _board);
					delete currentMove;
				}
				else{
					_executeMove(movingPiece, moveEnd);
					
					if (!currentMove->isEmpty()) currentMove->setMoment(_turn + MOVE_TIME);
					else{
						currentMove->setMoment(_turn + MOVE_TIME/2);
						currentMove->stopPieceMovingNext();
					}
					movesQueue.push(currentMove);
				}
			}
			//send update
			if (_timeBeforeUpdate() <= 0) this->_sendBoard();
		}
	}
}

bool RealTimeGame::_isMovePossible(Coordinate start, Coordinate end){
	if (! (_board->isInBoard(start) && _board->isInBoard(end)) ) return false;
	RealTimeBoard* board = this->_getBoard();
	Piece* movingPiece = board->getCase(start);
	return movingPiece && _currentPlayer->getColor() == movingPiece->getColor() && (!movingPiece->isCoolingDown(*this)) && (!board->isLock(end)) && movingPiece->_checkMove(end, board, *this);
}

void RealTimeGame::_executeMove(Piece* movingPiece, Coordinate end){
	RealTimeBoard* board = this->_getBoard();
	Piece* taken;
	Coordinate start = movingPiece->getCoord();
	if (board->getCase(start) == movingPiece){
		taken = board->movePiece(start, end);
		board->setCase(start, movingPiece->getNext());
		movingPiece->clearNext();
		
		if (movingPiece->getType() == 'h'){
			board->setCase(end, taken);
			movingPiece->_setCoordinate(end);
		return;
		}
	}
	else{
		taken = board->getCase(end);
		board->setCase(end, movingPiece);
	}
	if (taken){//collision
		if (movingPiece->getType() != 'p' && taken->getType() == 'g') movingPiece->setNext(taken);
		else if(taken->getColor() != movingPiece->getColor()){
			unsigned takenStart = taken->getMovementStart(), movingPieceStart = movingPiece->getMovementStart();
			if (!taken->isMoving()) taken->changeIsTaken(_turn, movingPiece, board);
			else if(takenStart > movingPieceStart){// taken started moving before movingPiece
				taken->changeIsTaken(_turn, movingPiece, board);
				this->_getBoard()->unlock(taken->getDest());
			}
			else if(takenStart < movingPieceStart){// taken started moving after movingPiece
				movingPiece->changeIsTaken(_turn, taken, board);
				this->_getBoard()->unlock(movingPiece->getDest());
				board->setCase(end, taken);
			}
		}
	}
	movingPiece->_setCoordinate(end);
	if ((end.getAbstractRow() == '8' || end.getAbstractRow() == '1') && movingPiece->getType() == 'p') promote(movingPiece);
}

void RealTimeGame::promote(Piece* piece){
	this->_changePawn(piece, new Queen(*piece), _board);
}

#endif
















































