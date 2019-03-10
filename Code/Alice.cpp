#ifndef _ALICE_CPP_
#define _ALICE_CPP_

#include <cmath>
#include "Alice.hpp"
#include "../Communication/Data.hpp"
extern Data data;

#define KING_INDEX 4

void Alice::_Pieces() {
	_pieces = new Piece*[_piecesAmount];
	_pieces[0] = new AliceRook('w', 'A', '1');		//0 -> 7 : pièces fortes blanches
	_pieces[1] = new AliceKnight('w', 'B', '1');
	_pieces[2] = new AliceBishop('w', 'C', '1');
	_pieces[3] = new AliceQueen('w', 'D', '1');
	_pieces[4] = new AliceKing('w', 'E', '1');
	_pieces[5] = new AliceBishop('w', 'F', '1');
	_pieces[6] = new AliceKnight('w', 'G', '1');
	_pieces[7] = new AliceRook('w', 'H', '1');
	_pieces[8] = new AlicePawn('w', 'A', '2');		//8 -> 15 : pions blancs
	_pieces[9] = new AlicePawn('w', 'B', '2');
	_pieces[10] = new AlicePawn('w', 'C', '2');
	_pieces[11] = new AlicePawn('w', 'D', '2');
	_pieces[12] = new AlicePawn('w', 'E', '2');
	_pieces[13] = new AlicePawn('w', 'F', '2');
	_pieces[14] = new AlicePawn('w', 'G', '2');
	_pieces[15] = new AlicePawn('w', 'H', '2');

	_pieces[16] = new AliceRook('b', 'A', '8');		//16 -> 23 : pièces fortes noires
	_pieces[17] = new AliceKnight('b', 'B', '8');
	_pieces[18] = new AliceBishop('b', 'C', '8');
	_pieces[19] = new AliceQueen('b', 'D', '8');
	_pieces[20] = new AliceKing('b', 'E', '8');
	_pieces[21] = new AliceBishop('b', 'F', '8');
	_pieces[22] = new AliceKnight('b', 'G', '8');
	_pieces[23] = new AliceRook('b', 'H', '8');
	_pieces[24] = new AlicePawn('b', 'A', '7');		//24 -> 31 : pions noirs
	_pieces[25] = new AlicePawn('b', 'B', '7');
	_pieces[26] = new AlicePawn('b', 'C', '7');
	_pieces[27] = new AlicePawn('b', 'D', '7');
	_pieces[28] = new AlicePawn('b', 'E', '7');
	_pieces[29] = new AlicePawn('b', 'F', '7');
	_pieces[30] = new AlicePawn('b', 'G', '7');
	_pieces[31] = new AlicePawn('b', 'H', '7');
}

Alice::~Alice(){
	for(int i = int(_piecesAmount) - 1; i>=0; i--)
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

void Alice::_sendGameMode() {
	std::string game = "Alice";
	_player1->transferGameMode(game);
	_player2->transferGameMode(game);
}

void Alice::_sendStart() {
	std::string update = "start";
	_player1->transferUpdate(update);
	_player2->transferUpdate(update);
	update = "alice";
	_player1->transferUpdate(update);
	_player2->transferUpdate(update);
}

void Alice::_changePawn(Piece* pawn, Piece* promotedPawn, Board* board){
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

bool Alice::_executeMove(Coordinate start, Coordinate end, char playerColor){
	Piece *movingPiece;
	movingPiece = _board->getCase(start);
	if (!movingPiece || movingPiece->getColor() != playerColor) return false;
	return movingPiece->move(end, _board, *this);
}

void Alice::_nextTurn() {
	Player *currentPlayer = _getCurrentPlayer();
	char playerColor = currentPlayer == _player1 ? 'w':'b';
	Coordinate start,end;

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
			start = Coordinate(playerMove[0], playerMove[1]);
			end = Coordinate(playerMove[2], playerMove[3]);
			isMoveValid = this->_executeMove(start, end, playerColor);
		}
	}
}

bool Alice::_isCheckmate(char playerColor){
	Piece *dangerousPiece = nullptr, *inTest;
	int offset = _calculOffset(playerColor);
	Piece *king = _pieces[offset+KING_INDEX];
	bool dimension = dynamic_cast<AlicePiece*>(king)->getDimension();
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
	std::cout<<"dangerous piece exist"<<std::endl;
	if (king->canMove(_board, *this)) return false;
	std::cout<<"king can't move"<<std::endl;
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
					if ((!_pieces[i]->isTaken()) && _pieces[i]->_isMovePossible(Coordinate(column, row), _board, *this) && dynamic_cast<AlicePiece*>(_pieces[i])->getDimension() != dimension) return false;
				}
				row += rowDirection;
				column += columnDirection;
			}
		}
		//rook or queen case(row)
		else if (rowMove){
			for (int j = int(king->getRow())+rowDirection; j != int(dangerousPiece->getRow()); j += rowDirection){
				for(int i = offset; i < 16 + offset; i++){
					if ((!_pieces[i]->isTaken()) && _pieces[i]->_isMovePossible(Coordinate(int(king->getColumn()), j), _board, *this) && dynamic_cast<AlicePiece*>(_pieces[i])->getDimension() != dimension) return false;
				}
			}
		}
		//rook or queen case(column)
		else if (columnMove){
			for (int j = int(king->getColumn())+columnDirection; j != int(king->getColumn()); j += columnDirection){
				for(int i = offset; i < 16 + offset; i++){
					if ((!_pieces[i]->isTaken()) && _pieces[i]->_isMovePossible(Coordinate(j, int(king->getRow())), _board, *this) && dynamic_cast<AlicePiece*>(_pieces[i])->getDimension() != dimension) return false;
				}
			}
		}
		//can the dangerousPiece be taken?
		for (int i = offset; i < 16 + offset; i++){
			if ((!_pieces[i]->isTaken()) && _pieces[i]->_isMovePossible(dangerousPiece->getCoord(), _board, *this)) return false;
		}
	}
	return true;
}

bool Alice::_isStalemate(char playerColor){
	if (this->testCheck(playerColor)) return false;
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
	if (_winner){
		_sendCheckmate();
		return true;
	}
	Player *currentPlayer = _getCurrentPlayer();
	char opponentColor = currentPlayer == _player2 ? 'w':'b';
	if (this->_isCheckmate(opponentColor)){
		if (opponentColor == 'w'){
			std::cout << "Black Player win !" << std::endl;
			data.addUserAliceWin(_player2->getName());
			data.addUserAliceLose(_player1->getName());
		}
		else {
			std::cout << "White Player win !" << std::endl;
			data.addUserAliceLose(_player2->getName());
			data.addUserAliceWin(_player1->getName());
		}
		_winner = currentPlayer;
		_sendCheckmate();
		return true;
	}
	if (this->_isStalemate(opponentColor)) {
		data.addUserAliceDraw(_player2->getName());
		data.addUserAliceDraw(_player1->getName());
		_sendStalemate();
		return true;
	}
	if (this->_notEnoughtPieces()){
		data.addUserAliceDraw(_player2->getName());
		data.addUserAliceDraw(_player1->getName());
		_sendStalemate();
		return true;
	}
	return false;
}

void Alice::_sendBoard(){
	std::string state;
	state += '1';
	this->_boardState(state);
	_player1->showBoard(state);
	_player2->showBoard(state);
	state.clear();
	state += '2';
	this->_boardState(state);
	_player1->showBoard(state);
	_player2->showBoard(state);
}

void Alice::_boardState(std::string& state){
	bool rightDimension = state[0] == '2';
	int i = 0;
	for (; i < 16; i++){
		if (!_pieces[i]->isTaken() && dynamic_cast<AlicePiece*>(_pieces[i])->getDimension() == rightDimension) state += _pieces[i]->toString();
	}
	state += "!";
	for (; i < 32; i++){
		if (!_pieces[i]->isTaken() && dynamic_cast<AlicePiece*>(_pieces[i])->getDimension() == rightDimension) state += _pieces[i]->toString();
	}
	state += "#";
}

void Alice::promote(Piece* piece)
{	
	this->_sendBoard();
	char type = this->_getCurrentPlayer()->askPromotion();
	if (type == 's'){
		if (_getCurrentPlayer() == _player1) _winner = _player2;
		else _winner = _player1;
	}
	AlicePawn *pawn = dynamic_cast<AlicePawn*>(piece);
	if (!pawn) throw std::string("the piece to promote is not a pawn");
	Piece* promotedPawn;
	switch (type) {
		case 'q':
			promotedPawn = new AliceQueen(*pawn);
			break;


		case 'b':
			promotedPawn = new AliceBishop(*pawn);
			break;


		case 'h':
			promotedPawn = new AliceKnight(*pawn);
			break;


		case 'r':
			promotedPawn = new AliceRook(*pawn);
			break;


	}
	this->_changePawn(pawn, promotedPawn, _board);
}

#endif
