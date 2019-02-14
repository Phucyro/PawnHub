#ifndef _CLASSIC_CPP_
#define _CLASSIC_CPP_

#include <cmath>
#include "Classic.hpp"

#define KING_INDEX 4

Classic::~Classic(){
	for(int i = _piecesAmount - 1; i>=0; i--)
	{
		delete _pieces[i];
	}
	delete[] _pieces;
}

void Classic::_initBoard() {

	//White part

	Game::_board->setCase(Coordinate('A', '1'), Game::_pieces[0]);
	Game::_board->setCase(Coordinate('B', '1'), Game::_pieces[1]);
	Game::_board->setCase(Coordinate('C', '1'), Game::_pieces[2]);
	Game::_board->setCase(Coordinate('D', '1'), Game::_pieces[3]);
	Game::_board->setCase(Coordinate('E', '1'), Game::_pieces[4]);
	Game::_board->setCase(Coordinate('F', '1'), Game::_pieces[5]);
	Game::_board->setCase(Coordinate('G', '1'), Game::_pieces[6]);
	Game::_board->setCase(Coordinate('H', '1'), Game::_pieces[7]);
	Game::_board->setCase(Coordinate('A', '2'), Game::_pieces[8]);
	Game::_board->setCase(Coordinate('B', '2'), Game::_pieces[9]);
	Game::_board->setCase(Coordinate('C', '2'), Game::_pieces[10]);
	Game::_board->setCase(Coordinate('D', '2'), Game::_pieces[11]);
	Game::_board->setCase(Coordinate('E', '2'), Game::_pieces[12]);
	Game::_board->setCase(Coordinate('F', '2'), Game::_pieces[13]);
	Game::_board->setCase(Coordinate('G', '2'), Game::_pieces[14]);
	Game::_board->setCase(Coordinate('H', '2'), Game::_pieces[15]);

	//Black part

	Game::_board->setCase(Coordinate('A', '8'), Game::_pieces[16]);
	Game::_board->setCase(Coordinate('B', '8'), Game::_pieces[17]);
	Game::_board->setCase(Coordinate('C', '8'), Game::_pieces[18]);
	Game::_board->setCase(Coordinate('D', '8'), Game::_pieces[19]);
	Game::_board->setCase(Coordinate('E', '8'), Game::_pieces[20]);
	Game::_board->setCase(Coordinate('F', '8'), Game::_pieces[21]);
	Game::_board->setCase(Coordinate('G', '8'), Game::_pieces[22]);
	Game::_board->setCase(Coordinate('H', '8'), Game::_pieces[23]);
	Game::_board->setCase(Coordinate('A', '7'), Game::_pieces[24]);
	Game::_board->setCase(Coordinate('B', '7'), Game::_pieces[25]);
	Game::_board->setCase(Coordinate('C', '7'), Game::_pieces[26]);
	Game::_board->setCase(Coordinate('D', '7'), Game::_pieces[27]);
	Game::_board->setCase(Coordinate('E', '7'), Game::_pieces[28]);
	Game::_board->setCase(Coordinate('F', '7'), Game::_pieces[29]);
	Game::_board->setCase(Coordinate('G', '7'), Game::_pieces[30]);
	Game::_board->setCase(Coordinate('H', '7'), Game::_pieces[31]);
}

bool Classic::_executeMove(Coordinate start, Coordinate end, char playerColor){
	Piece *movingPiece;
	movingPiece = _board->getCase(start);
	if (!movingPiece || movingPiece->getColor() != playerColor) return false;
	return movingPiece->move(end, _board, *this);
}

void Classic::_nextTurn() {

	++_turn;
	Player *currentPlayer = _getCurrentPlayer();
	char playerColor = currentPlayer == _player1 ? 'w':'b';
	
	bool isMoveValid = false;
	char* playerMove;
	while(!isMoveValid){
		playerMove = currentPlayer->askMove();
		if (_fitInBoard(playerMove)){
			Coordinate start = Coordinate(playerMove[0], playerMove[1]), end = Coordinate(playerMove[2], playerMove[3]);
			isMoveValid = this->_executeMove(start, end, playerColor);
		}
	}
	_player1->showBoard(_board);
	_player2->showBoard(_board);
}

bool Classic::_isCheckmate(char playerColor){
	Piece *dangerousPiece, *inTest;
	int offset = playerColor == 'w' ? 0 : 16;
	Piece *king = _pieces[KING_INDEX];
	Coordinate kingPlace = king->getPlace(), dPiecePlace = dangerousPiece->getPlace();
	int i = offset;
	bool moreThan2;
	while(i < 16+offset && !moreThan2){
		inTest = _pieces[i];
		if (!inTest->isTaken()){
			if (inTest->move(kingPlace, _board, *this)){
				if (!dangerousPiece) dangerousPiece = inTest;
				else moreThan2 = true;
				_board->movePiece(kingPlace, dPiecePlace);
				_board->setCase(kingPlace, king);
				king->changeIsTaken(this->getTurn(), nullptr, _board);
			}
		}
		i++;
	}
	if (!dangerousPiece) return false;
	if (_checkPieceMove(1, 1, king)) return false;
	if (_checkPieceMove(0, 1, king)) return false;
	if (_checkPieceMove(-1, 1, king)) return false;
	if (_checkPieceMove(1, 0, king)) return false;
	if (_checkPieceMove(-1, 0, king)) return false;
	if (_checkPieceMove(1, -1, king)) return false;
	if (_checkPieceMove(0, -1, king)) return false;
	if (_checkPieceMove(-1, -1, king)) return false;
	
	if (!moreThan2){
		int rowMove = int(dangerousPiece->getRow()) - int(king->getRow());
		int rowDirection = rowMove/std::abs(rowMove);
		int columnMove = int(dangerousPiece->getColumn()) - int(king->getColumn());
		int columnDirection = columnMove/std::abs(columnMove);
		
		if (std::abs(rowMove) == std::abs(columnMove)){
			int row = 0, column = 0;
			while(std::abs(row) < std::abs(rowMove)){
				for(int i = 16-offset; i < 32 - offset; i++){
					if ((!_pieces[i]->isTaken()) && _checkPieceMove(column, row, _pieces[i])) return false;
					row += rowDirection;
					column += columnDirection;
				}
			}
		}
		else if (rowMove){
			for (int j = 0; std::abs(j) < std::abs(rowMove); j += rowDirection){
				for(int i = 16-offset; i < 32 - offset; i++){
					if ((!_pieces[i]->isTaken()) && _checkPieceMove(0, j, _pieces[i])) return false;
				}
			}
		}
		else if (columnMove){
			for (int j = 0; std::abs(j) < std::abs(columnMove); j += columnDirection){
				for(int i = 16-offset; i < 32 - offset; i++){
					if ((!_pieces[i]->isTaken()) && _checkPieceMove(j, 0, _pieces[i])) return false;
				}
			}
		}
		else{
			for(int i = 16-offset; i < 32 - offset; i++){
				if (_checkPieceMove(dangerousPiece->getPlace(), _pieces[i])) return false;
			}
		}
	}
	return true;
}

bool Classic::_isFinish() {
	Player *currentPlayer = _getCurrentPlayer();
	char opponentColor = currentPlayer == _player2 ? 'w':'b';
	if(this->_isCheckmate(opponentColor))
	{
		_winner = currentPlayer;
		return true;
	}
	//TODO other end case
}

bool Classic::testCheck(const char color) const {
	if (color == 'w' || color == 'a'){	//White		//a = all

		//strong pieces
		if (_pieces[16]->_checkMove(_pieces[4]->getCoord(), Game::_board, *this)) return true;
		if (_pieces[17]->_checkMove(_pieces[4]->getCoord(), Game::_board, *this)) return true;
		if (_pieces[18]->_checkMove(_pieces[4]->getCoord(), Game::_board, *this)) return true;
		if (_pieces[19]->_checkMove(_pieces[4]->getCoord(), Game::_board, *this)) return true;
		if (_pieces[20]->_checkMove(_pieces[4]->getCoord(), Game::_board, *this)) return true;
		if (_pieces[21]->_checkMove(_pieces[4]->getCoord(), Game::_board, *this)) return true;
		if (_pieces[22]->_checkMove(_pieces[4]->getCoord(), Game::_board, *this)) return true;
		if (_pieces[23]->_checkMove(_pieces[4]->getCoord(), Game::_board, *this)) return true;

		//Pawn
		Piece* MaybePawn = Game::_board->getCase(_pieces[4]->getCoord()->getRealColumn()+1, _pieces[4]->getCoord()->getRealRow()+1);
		if (MaybePawn && MaybePawn->getColor() == 'b' && MaybePawn->getType() == 'p') return true;
		Piece* MaybePawn = Game::_board->getCase(_pieces[4]->getCoord()->getRealColumn()+1, _pieces[4]->getCoord()->getRealRow()-1);
		if (MaybePawn && MaybePawn->getColor() == 'b' && MaybePawn->getType() == 'p') return true;

	if (color == 'b' || color == 'a'){	//Black		//a = all

		//strong pieces
		if (_pieces[0]->_checkMove(_pieces[20]->getCoord(), Game::_board, *this)) return true;
		if (_pieces[1]->_checkMove(_pieces[20]->getCoord(), Game::_board, *this)) return true;
		if (_pieces[2]->_checkMove(_pieces[20]->getCoord(), Game::_board, *this)) return true;
		if (_pieces[3]->_checkMove(_pieces[20]->getCoord(), Game::_board, *this)) return true;
		if (_pieces[4]->_checkMove(_pieces[20]->getCoord(), Game::_board, *this)) return true;
		if (_pieces[5]->_checkMove(_pieces[20]->getCoord(), Game::_board, *this)) return true;
		if (_pieces[6]->_checkMove(_pieces[20]->getCoord(), Game::_board, *this)) return true;
		if (_pieces[7]->_checkMove(_pieces[20]->getCoord(), Game::_board, *this)) return true;

		//Pawn
		Piece* MaybePawn = Game::_board->getCase(_pieces[20]->getCoord()->getRealColumn()-1, _pieces[20]->getCoord()->getRealRow()+1);
		if (MaybePawn && MaybePawn->getColor() == 'w' && MaybePawn->getType() == 'p') return true;
		Piece* MaybePawn = Game::_board->getCase(_pieces[4]->getCoord()->getRealColumn()-1, _pieces[20]->getCoord()->getRealRow()-1);
		if (MaybePawn && MaybePawn->getColor() == 'w' && MaybePawn->getType() == 'p') return true;

	return false;

#endif
