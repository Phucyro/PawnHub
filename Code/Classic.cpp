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
	int offset = _calculOffset(playerColor);
	Piece *king = _pieces[KING_INDEX];
	Coordinate kingPlace = king->getCoord(), dPiecePlace = dangerousPiece->getCoord();
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
	if (king->canMove(_board, *this)) return false;

	if (!moreThan2){
		int rowMove = int(dangerousPiece->getRow()) - int(king->getRow());
		int rowDirection = rowMove/std::abs(rowMove);
		int columnMove = int(dangerousPiece->getColumn()) - int(king->getColumn());
		int columnDirection = columnMove/std::abs(columnMove);

		//bishop or pawn or queen case
		if (std::abs(rowMove) == std::abs(columnMove)){
			int row = 0, column = 0;
			while(std::abs(row) < std::abs(rowMove)){
				for (int i = 16-offset; i < 32 - offset; i++){
					if ((!_pieces[i]->isTaken()) && _pieces[i]->_isMovePossible(column, row, _board, *this)) return false;
					row += rowDirection;
					column += columnDirection;
				}
			}
		}
		//rook or queen case(row)
		else if (rowMove){
			for (int j = 0; std::abs(j) < std::abs(rowMove); j += rowDirection){
				for(int i = 16-offset; i < 32 - offset; i++){
					if ((!_pieces[i]->isTaken()) && _pieces[i]->_isMovePossible(0, j, _board, *this)) return false;
				}
			}
		}
		//rook or queen case(column)
		else if (columnMove){
			for (int j = 0; std::abs(j) < std::abs(columnMove); j += columnDirection){
				for(int i = 16-offset; i < 32 - offset; i++){
					if ((!_pieces[i]->isTaken()) && _pieces[i]->_isMovePossible(0, j, _board, *this)) return false;
				}
			}
		}
		//knight case
		else{
			for (int i = 16-offset; i < 32 - offset; i++){
				if ((!_pieces[i]->isTaken()) && _pieces[i]->_isMovePossible(0, 0, _board, *this)) return false;
			}
		}
	}
	return true;
}

bool Classic::_isStalemate(char playerColor){
	int offset = _calculOffset(playerColor);
	for (int i = offset; i < offset+16; i++){
		if ((!_pieces[i]->isTaken()) && _pieces[i]->canMove(_board, *this)) return false;
	}
	return true;
}

bool Classic::_notEnoughtPieces(){
	char type;
	Piece* lastPieceButKing = nullptr;
	bool doubleBishop = false;
	for (int i = 0; i < 32; i++){
		type = _pieces[i]->isTaken() ? '!' : _pieces[i]->getType();
		switch(type){
			case '!': break;
			case 'k': break;
			case 'p': return false;
			case 'q': return false;
			case 'r': return false;
			case 'h':{if (lastPieceButKing) return false;
				  lastPieceButKing = _pieces[i];
				  break;
				 }
			case 'b':{if (doubleBishop) return false;
				  if (lastPieceButKing && _board->getCaseColor(_pieces[i]->getCoord()) == _board->getCaseColor(lastPieceButKing->getCoord())){
				  	doubleBishop = true;
				  	break;
				  }
				  if (!lastPieceButKing){
				  	lastPieceButKing = _pieces[i];
				  	break;
				  }
				  return false;
				 }
			default: break;
		}
	}
	return true;
}

bool Classic::_isFinish() {
	Player *currentPlayer = _getCurrentPlayer();
	char opponentColor = currentPlayer == _player2 ? 'w':'b';
	if (this->_isCheckmate(opponentColor)){
		_winner = currentPlayer;
		return true;
	}
	if (this->_isStalemate(opponentColor)) return true;
	return this->_notEnoughtPieces();
}

bool Classic::testCheck(const char color) {
	if (color == 'w' || color == 'a'){	//White		//a = all

		//strong pieces
		for (unsigned i = 16; i <= 23; ++i){
			if (!_pieces[i]->isTaken())
				if (_pieces[i]->_checkMove(_pieces[KING_INDEX]->getCoord(), Game::_board, *this)) return true;
		}

		//Pawn
		Piece* MaybePawn = Game::_board->getCase(Coordinate(_pieces[KING_INDEX]->getCoord().getRealColumn()+1, _pieces[KING_INDEX]->getCoord().getRealRow()+1));
		if (MaybePawn && MaybePawn->getColor() == 'b' && MaybePawn->getType() == 'p') return true;
		MaybePawn = Game::_board->getCase(Coordinate(_pieces[KING_INDEX]->getCoord().getRealColumn()+1, _pieces[KING_INDEX]->getCoord().getRealRow()-1));
		if (MaybePawn && MaybePawn->getColor() == 'b' && MaybePawn->getType() == 'p') return true;
	}

	if (color == 'b' || color == 'a'){	//Black		//a = all

		//strong pieces
		for (unsigned i = 0; i <= 7; ++i){
			if (!_pieces[i]->isTaken())
				if (_pieces[i]->_checkMove(_pieces[KING_INDEX]->getCoord(), Game::_board, *this)) return true;
		}

		//Pawn
		Piece* MaybePawn = Game::_board->getCase(Coordinate(_pieces[16+KING_INDEX]->getCoord().getRealColumn()-1, _pieces[16+KING_INDEX]->getCoord().getRealRow()+1));
		if (MaybePawn && MaybePawn->getColor() == 'w' && MaybePawn->getType() == 'p') return true;
		MaybePawn = Game::_board->getCase(Coordinate(_pieces[16+KING_INDEX]->getCoord().getRealColumn()-1, _pieces[16+KING_INDEX]->getCoord().getRealRow()-1));
		if (MaybePawn && MaybePawn->getColor() == 'w' && MaybePawn->getType() == 'p') return true;
	}

	return false;
}
#endif
