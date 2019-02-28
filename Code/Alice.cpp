#ifndef _ALICE_CPP_
#define _ALICE_CPP_

#include <cmath>
#include "Alice.hpp"

#define KING_INDEX 4

void Alice::_Pieces() {
	_pieces = new Piece*[_piecesAmount];
	_pieces[0] = new Rook('w', 'A', '1');		//0 -> 7 : pièces fortes blanches
	_pieces[1] = new Knight('w', 'B', '1');
	_pieces[2] = new Bishop('w', 'C', '1');
	_pieces[3] = new Queen('w', 'D', '1');
	_pieces[4] = new King('w', 'E', '1');
	_pieces[5] = new Bishop('w', 'F', '1');
	_pieces[6] = new Knight('w', 'G', '1');
	_pieces[7] = new Rook('w', 'H', '1');
	_pieces[8] = new Pawn('w', 'A', '2');		//8 -> 15 : pions blancs
	_pieces[9] = new Pawn('w', 'B', '2');
	_pieces[10] = new Pawn('w', 'C', '2');
	_pieces[11] = new Pawn('w', 'D', '2');
	_pieces[12] = new Pawn('w', 'E', '2');
	_pieces[13] = new Pawn('w', 'F', '2');
	_pieces[14] = new Pawn('w', 'G', '2');
	_pieces[15] = new Pawn('w', 'H', '2');

	_pieces[16] = new Rook('b', 'A', '8');		//16 -> 23 : pièces fortes noires
	_pieces[17] = new Knight('b', 'B', '8');
	_pieces[18] = new Bishop('b', 'C', '8');
	_pieces[19] = new Queen('b', 'D', '8');
	_pieces[20] = new King('b', 'E', '8');
	_pieces[21] = new Bishop('b', 'F', '8');
	_pieces[22] = new Knight('b', 'G', '8');
	_pieces[23] = new Rook('b', 'H', '8');
	_pieces[24] = new Pawn('b', 'A', '7');		//24 -> 31 : pions noirs
	_pieces[25] = new Pawn('b', 'B', '7');
	_pieces[26] = new Pawn('b', 'C', '7');
	_pieces[27] = new Pawn('b', 'D', '7');
	_pieces[28] = new Pawn('b', 'E', '7');
	_pieces[29] = new Pawn('b', 'F', '7');
	_pieces[30] = new Pawn('b', 'G', '7');
	_pieces[31] = new Pawn('b', 'H', '7');
}

Alice::~Alice(){
	for(int i = _piecesAmount - 1; i>=0; i--)
	{
		delete _pieces[i];
	}
	delete[] _pieces;
}

void Alice::_initBoard() {

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

void Alice::_changePawn(Piece *pawn, Piece* promotedPawn){
	int start, i, end;
	if (pawn->getColor() == 'w'){
		int start = _lastStrongPiecesWhite;
		int i = _lastStrongPiecesWhite;
		_lastStrongPiecesWhite ++;
		end = 16;
	}else{
		start = _lastStrongPieceBlack;
		i = _lastStrongPieceBlack;
		_lastStrongPieceBlack ++;
		end = 32;
	}

	for (; i < end; i++) {
		if (_pieces[i] == pawn){
			delete pawn;
			_pieces[i] = _pieces[start];
			_pieces[start] = promotedPawn;
			break; // <3
		}
	}
}

bool Alice::_executeMove(Coordinate start, Coordinate end, char playerColor){
	Piece *movingPiece;
	movingPiece = _board->getCase(start);
	if (!movingPiece || movingPiece->getColor() != playerColor) return false;
	return movingPiece->move(end, _board, *this);
}

void Alice::_nextTurn() {
	Player *currentPlayer = _getCurrentPlayer();
	char playerColor = currentPlayer == _player1 ? 'w':'b';

	bool isMoveValid = false;
	std::string playerMove;
	while(!isMoveValid){
		playerMove = currentPlayer->askMove();
		if (this->_fitInBoard(playerMove)){
			Coordinate start = Coordinate(playerMove[0], playerMove[1]), end = Coordinate(playerMove[2], playerMove[3]);
			isMoveValid = this->_executeMove(start, end, playerColor);
		}
	}
}

bool Alice::_isCheckmate(char playerColor){
	Piece *dangerousPiece = nullptr, *inTest;
	int offset = _calculOffset(playerColor);
	Piece *king = _pieces[offset+KING_INDEX];
	Coordinate kingPlace = king->getCoord(), dPiecePlace;
	int i = 16-offset;
	bool moreThan2 = false;
	while(i < 32-offset && !moreThan2){
		inTest = _pieces[i];
		if (!inTest->isTaken()){
			dPiecePlace = inTest->getCoord();
			if (inTest->_checkMove(kingPlace, _board, *this)){
				if (!dangerousPiece) dangerousPiece = inTest;
				else moreThan2 = true;
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

bool Alice::_isStalemate(char playerColor){
	int offset = _calculOffset(playerColor);
	for (int i = offset; i < offset+16; i++){
		if ((!_pieces[i]->isTaken()) && _pieces[i]->canMove(_board, *this)) return false;
	}
	return true;
}

bool Alice::_notEnoughtPieces(){
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

bool Alice::_isFinish() {
	Player *currentPlayer = _getCurrentPlayer();
	char opponentColor = currentPlayer == _player2 ? 'w':'b';
	if (this->_isCheckmate(opponentColor)){
		_winner = currentPlayer;
		return true;
	}
	if (this->_isStalemate(opponentColor)) return true;
	return this->_notEnoughtPieces();
}

void Alice::_boardState(std::string& state){
	int i = 0;
	for (; i < 16; i++){
		if (!_pieces[i]->isTaken()) state += _pieces[i]->toString();
	}
	state += "!";
	for (; i < 32; i++){
		if (!_pieces[i]->isTaken()) state += _pieces[i]->toString();
	}
}
#endif