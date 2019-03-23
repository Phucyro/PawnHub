#ifndef __TURN__BASED__GAME__CPP__
#define __TURN__BASED__GAME__CPP__

#include "TurnBasedGame.hpp"

TurnBasedGame::TurnBasedGame(Piece** pieces, unsigned piecesAmount, Player* player1, Player* player2, unsigned lastStrongPiecesWhite, unsigned lastStrongPieceBlack):
	Game(pieces,piecesAmount, player1, player2, lastStrongPiecesWhite, lastStrongPieceBlack, nullptr)
{
	_board = new Board();
}



TurnBasedGame& TurnBasedGame::operator= (const TurnBasedGame& original){
	this->Game::operator= (original);
	return *this;
}


TurnBasedGame& TurnBasedGame::operator= (TurnBasedGame&& original){
	this->Game::operator= (original);
	return *this;
}



void TurnBasedGame::_sendTime(){
	_player1->transferTime(600);
	_player2->transferTime(600);
}


void TurnBasedGame::start()
{
	this->Game::start();
	do
	{
		++_turn;
		this->_sendTurn();
		this->_nextTurn();
		this->_sendBoard();
	}
	while(! this->_isFinish());
	std::cout << "Game finished" << std::endl;
}

void TurnBasedGame::_nextTurn(){
	Player *currentPlayer = _getCurrentPlayer();
	char playerColor = currentPlayer == _player1 ? 'w':'b';
	Coordinate start,end;

	bool isMoveValid = false;
	std::string playerMove;
	while(!isMoveValid){
		playerMove = currentPlayer->askMove();
		std::cout<<"game received: "<<playerMove<<std::endl;
		if (playerMove[0] == '/' && playerMove[1] == 'e' && playerMove[2] == 'n' && playerMove[3] == 'd'){
			if(currentPlayer == _player1) _winner = _player2;
			else _winner = _player1;
			_sendSurrend();
			isMoveValid = true;
		}
		else if (playerMove[0] == '/' && playerMove[1] == 't' && playerMove[2] == 'i' && playerMove[3] == 'm'){
			if(currentPlayer == _player1) _winner = _player2;
			else _winner = _player1;
			_sendTimeout();
			isMoveValid = true;
		}
		else if (this->_fitInBoard(playerMove)){
			start = Coordinate(playerMove[0], playerMove[1]);
			end = Coordinate(playerMove[2], playerMove[3]);
			isMoveValid = this->_executeMove(start, end, playerColor);
		}
	}
	currentPlayer->transferGoodMove();
}

#endif
