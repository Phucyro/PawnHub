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

	TurnBasedGame::_board->setCase(Coordinate('A', '1'), TurnBasedGame::_pieces[0]);
	TurnBasedGame::_board->setCase(Coordinate('B', '1'), TurnBasedGame::_pieces[1]);
	TurnBasedGame::_board->setCase(Coordinate('C', '1'), TurnBasedGame::_pieces[2]);
	TurnBasedGame::_board->setCase(Coordinate('D', '1'), TurnBasedGame::_pieces[3]);
	TurnBasedGame::_board->setCase(Coordinate('E', '1'), TurnBasedGame::_pieces[4]);
	TurnBasedGame::_board->setCase(Coordinate('F', '1'), TurnBasedGame::_pieces[5]);
	TurnBasedGame::_board->setCase(Coordinate('G', '1'), TurnBasedGame::_pieces[6]);
	TurnBasedGame::_board->setCase(Coordinate('H', '1'), TurnBasedGame::_pieces[7]);
	TurnBasedGame::_board->setCase(Coordinate('A', '2'), TurnBasedGame::_pieces[8]);
	TurnBasedGame::_board->setCase(Coordinate('B', '2'), TurnBasedGame::_pieces[9]);
	TurnBasedGame::_board->setCase(Coordinate('C', '2'), TurnBasedGame::_pieces[10]);
	TurnBasedGame::_board->setCase(Coordinate('D', '2'), TurnBasedGame::_pieces[11]);
	TurnBasedGame::_board->setCase(Coordinate('E', '2'), TurnBasedGame::_pieces[12]);
	TurnBasedGame::_board->setCase(Coordinate('F', '2'), TurnBasedGame::_pieces[13]);
	TurnBasedGame::_board->setCase(Coordinate('G', '2'), TurnBasedGame::_pieces[14]);
	TurnBasedGame::_board->setCase(Coordinate('H', '2'), TurnBasedGame::_pieces[15]);

	//Black part

	TurnBasedGame::_board->setCase(Coordinate('A', '8'), TurnBasedGame::_pieces[16]);
	TurnBasedGame::_board->setCase(Coordinate('B', '8'), TurnBasedGame::_pieces[17]);
	TurnBasedGame::_board->setCase(Coordinate('C', '8'), TurnBasedGame::_pieces[18]);
	TurnBasedGame::_board->setCase(Coordinate('D', '8'), TurnBasedGame::_pieces[19]);
	TurnBasedGame::_board->setCase(Coordinate('E', '8'), TurnBasedGame::_pieces[20]);
	TurnBasedGame::_board->setCase(Coordinate('F', '8'), TurnBasedGame::_pieces[21]);
	TurnBasedGame::_board->setCase(Coordinate('G', '8'), TurnBasedGame::_pieces[22]);
	TurnBasedGame::_board->setCase(Coordinate('H', '8'), TurnBasedGame::_pieces[23]);
	TurnBasedGame::_board->setCase(Coordinate('A', '7'), TurnBasedGame::_pieces[24]);
	TurnBasedGame::_board->setCase(Coordinate('B', '7'), TurnBasedGame::_pieces[25]);
	TurnBasedGame::_board->setCase(Coordinate('C', '7'), TurnBasedGame::_pieces[26]);
	TurnBasedGame::_board->setCase(Coordinate('D', '7'), TurnBasedGame::_pieces[27]);
	TurnBasedGame::_board->setCase(Coordinate('E', '7'), TurnBasedGame::_pieces[28]);
	TurnBasedGame::_board->setCase(Coordinate('F', '7'), TurnBasedGame::_pieces[29]);
	TurnBasedGame::_board->setCase(Coordinate('G', '7'), TurnBasedGame::_pieces[30]);
	TurnBasedGame::_board->setCase(Coordinate('H', '7'), TurnBasedGame::_pieces[31]);
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

void Alice::_updateStat(){
	if (_winner == _player1){
		std::cout << "White Player win !" << std::endl;
		data.addUserAliceLose(_player2->getName());
		data.addUserAliceWin(_player1->getName());
		data.updateRating(_player2->getName(),data.expectedWin(data.getEloRating(_player2->getName()),data.getEloRating(_player1->getName())),LOSE);
		data.updateRating(_player1->getName(),data.expectedWin(data.getEloRating(_player1->getName()),data.getEloRating(_player2->getName())),WIN);
	}
	else if (_winner == _player2) {
		std::cout << "Black Player win !" << std::endl;
		data.addUserAliceWin(_player2->getName());
		data.addUserAliceLose(_player1->getName());
		data.updateRating(_player2->getName(),data.expectedWin(data.getEloRating(_player2->getName()),data.getEloRating(_player1->getName())),WIN);
		data.updateRating(_player1->getName(),data.expectedWin(data.getEloRating(_player1->getName()),data.getEloRating(_player2->getName())),LOSE);
	}
	else{
		data.addUserAliceDraw(_player2->getName());
		data.addUserAliceDraw(_player1->getName());
		data.updateRating(_player2->getName(),data.expectedWin(data.getEloRating(_player2->getName()),data.getEloRating(_player1->getName())),TIE);
		data.updateRating(_player1->getName(),data.expectedWin(data.getEloRating(_player1->getName()),data.getEloRating(_player2->getName())),TIE);
	}
}

bool Alice::_isFinish() {
	if (_winner){
		_updateStat();
		return true;
	}
	Player *currentPlayer = _getCurrentPlayer();
	char opponentColor = currentPlayer == _player2 ? 'w':'b';
	if (this->_isCheckmate(opponentColor)){
		_winner = currentPlayer;
		_sendCheckmate();
		_updateStat();
		return true;
	}
	if (this->_isStalemate(opponentColor) || this->_notEnoughtPieces()){
		_sendStalemate();
		_updateStat();
		return true;
	}
	return false;
}

void Alice::_sendBoard(){
	if (!_winner){
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
