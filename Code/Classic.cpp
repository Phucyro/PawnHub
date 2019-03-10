#ifndef _CLASSIC_CPP_
#define _CLASSIC_CPP_

#include <cmath>
#include "Classic.hpp"
#include "../Communication/Data.hpp"
extern Data data;

#define KING_INDEX 4

void Classic::_Pieces() {
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

Classic::~Classic(){
	for(int i = int(_piecesAmount) - 1; i>=0; i--)
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

	// _sendBoard();
}

void Classic::_sendGameMode() {
	std::string game = "Classic";
	_player1->transferGameMode(game);
	_player2->transferGameMode(game);
}

void Classic::_changePawn(Piece *pawn, Piece* promotedPawn, Board* board){
	int start, i, end;
	if (pawn->getColor() == 'w'){
		_lastStrongPiecesWhite ++;
		int start = int(_lastStrongPiecesWhite);
		int i = int(_lastStrongPiecesWhite);
		end = 16;
		for (; i < end; i++) {
			if (_pieces[i] == pawn){
				board->setCase(_pieces[i]->getCoord(), promotedPawn);
				delete pawn;
				_pieces[i] = _pieces[start];
				_pieces[start] = promotedPawn;
				break; // <3 <3 <3
			}
		}
	}else{
		_lastStrongPieceBlack ++;
		start = int(_lastStrongPieceBlack);
		i = int(_lastStrongPieceBlack);
		end = 32;
		for (; i < end; i++) {
			if (_pieces[i] == pawn){
				board->setCase(_pieces[i]->getCoord(), promotedPawn);
				delete pawn;
				_pieces[i] = _pieces[start];
				_pieces[start] = promotedPawn;
				break; // <3 <3 <3
			}
		}
	}
}

bool Classic::_executeMove(Coordinate start, Coordinate end, char playerColor){
	Piece *movingPiece;
	movingPiece = _board->getCase(start);
	if (!movingPiece || movingPiece->getColor() != playerColor) return false;
	return movingPiece->move(end, _board, *this);
}

void Classic::_nextTurn() {
	Player *currentPlayer = _getCurrentPlayer();
	char playerColor = currentPlayer == _player1 ? 'w':'b';

	bool isMoveValid = false;
	std::string playerMove;
	while(!isMoveValid){
		playerMove = currentPlayer->askMove();
		std::cout<<"game received: "<<playerMove<<std::endl;
		if (playerMove[0] == 's' && playerMove[1] == 's'){
			if(currentPlayer == _player1) _winner = _player2;
			else _winner = _player1;
			isMoveValid = true;
		}
		else if (this->_fitInBoard(playerMove)){
			Coordinate start = Coordinate(playerMove[0], playerMove[1]), end = Coordinate(playerMove[2], playerMove[3]);
			isMoveValid = this->_executeMove(start, end, playerColor);
		}
	}

}

// yall have some unsigned/signed int to deal with in here, it's stupid and a mess
bool Classic::_isCheckmate(char playerColor){
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
		int rowDirection = rowMove ? rowMove/std::abs(rowMove) : 0;
		int columnMove = int(dangerousPiece->getColumn()) - int(king->getColumn());
		int columnDirection = columnMove ? columnMove/std::abs(columnMove) : 0;

		//bishop or pawn or queen case
		if (std::abs(rowMove) == std::abs(columnMove)){
			int row = int(king->getRow())+rowDirection, column = int(king->getColumn())+columnDirection;
			while(row != int(dangerousPiece->getRow())){
				for (int i = offset; i < 16 + offset; i++){
					if ((!_pieces[i]->isTaken()) && _pieces[i]->_isMovePossible(Coordinate(column, row), _board, *this)) return false;
				}
				row += rowDirection;
				column += columnDirection;
			}
		}
		//rook or queen case(row)
		else if (rowMove){
			for (int j = int(king->getRow())+rowDirection; j != int(dangerousPiece->getRow()); j += rowDirection){
				for(int i = offset; i < 16 + offset; i++){
					if ((!_pieces[i]->isTaken()) && _pieces[i]->_isMovePossible(Coordinate(int(king->getColumn()), j), _board, *this)) return false;
				}
			}
		}
		//rook or queen case(column)
		else if (columnMove){
			for (int j = int(king->getColumn())+columnDirection; j != int(dangerousPiece->getColumn()); j += columnDirection){
				for(int i = offset; i < 16 + offset; i++){
					if ((!_pieces[i]->isTaken()) && _pieces[i]->_isMovePossible(Coordinate(j, int(king->getRow())), _board, *this)) return false;
				}
			}
		}
		//test if the dangerousPiece can be taken
		for (int i = offset; i < 16 + offset; i++){
			if ((!_pieces[i]->isTaken()) && _pieces[i]->_isMovePossible(dangerousPiece->getCoord(), _board, *this)) return false;
		}
	}
	return true;
}

bool Classic::_isStalemate(char playerColor){
	if (this->testCheck(playerColor)) return false;
	int offset = _calculOffset(playerColor);
	for (int i = offset; i < 16+offset; i++){
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
	if (_winner){
		_sendCheckmate();
		return true;
	}
	Player *currentPlayer = _getCurrentPlayer();
	char opponentColor = currentPlayer == _player2 ? 'w':'b';
	if (this->_isCheckmate(opponentColor)){
		if (opponentColor == 'w'){
			std::cout << "Black Player win !" << std::endl;
			data.addUserClassicWin(_player2->getName());
			data.addUserClassicLose(_player1->getName());
		}
		else {
			std::cout << "White Player win !" << std::endl;
			data.addUserClassicLose(_player2->getName());
			data.addUserClassicWin(_player1->getName());
		}
		_winner = currentPlayer;
		_sendCheckmate();
		return true;
	}
	if (this->_isStalemate(opponentColor)) {
		data.addUserClassicDraw(_player2->getName());
		data.addUserClassicDraw(_player1->getName());
		_sendStalemate();
		return true;
	}
	if (this->_notEnoughtPieces()){
		data.addUserClassicDraw(_player2->getName());
		data.addUserClassicDraw(_player1->getName());
		_sendStalemate();
		return true;
	}
	return false;
}

void Classic::_boardState(std::string& state){
	int i = 0;
	for (; i < 16; i++){
		if (!_pieces[i]->isTaken()) state += _pieces[i]->toString();
	}
	state += "!";
	for (; i < 32; i++){
		if (!_pieces[i]->isTaken()) state += _pieces[i]->toString();
	}
	state += "#";
}
#endif
