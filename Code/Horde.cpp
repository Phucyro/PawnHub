#ifndef _HORDE_CPP_
#define _HORDE_CPP_

#include "Horde.hpp"
#include "../Communication/Data.hpp"
extern Data data;

void Horde::_Pieces(){
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


	_pieces[16] = new Pawn('b','A','8',true);
	_pieces[17] = new Pawn('b','A','7');
	_pieces[18] = new Pawn('b','A','6',true);
	_pieces[19] = new Pawn('b','A','5',true);
	_pieces[20] = new Pawn('b','B','8',true);
	_pieces[21] = new Pawn('b','B','7');
	_pieces[22] = new Pawn('b','B','6',true);
	_pieces[23] = new Pawn('b','B','5',true);
	_pieces[24] = new Pawn('b','C','8',true);
	_pieces[25] = new Pawn('b','C','7');
	_pieces[26] = new Pawn('b','C','6',true);
	_pieces[27] = new Pawn('b','C','5',true);
	_pieces[28] = new Pawn('b','D','7');
	_pieces[29] = new Pawn('b','D','6',true);
	_pieces[30] = new Pawn('b','D','5',true);
	_pieces[31] = new Pawn('b','D','4',true);
	_pieces[32] = new Pawn('b','E','7');
	_pieces[33] = new Pawn('b','E','6',true);
	_pieces[34] = new Pawn('b','E','5',true);
	_pieces[35] = new Pawn('b','E','4',true);
	_pieces[36] = new Pawn('b','F','8',true);
	_pieces[37] = new Pawn('b','F','7');
	_pieces[38] = new Pawn('b','F','6',true);
	_pieces[39] = new Pawn('b','F','5',true);
	_pieces[40] = new Pawn('b','G','8',true);
	_pieces[41] = new Pawn('b','G','7');
	_pieces[42] = new Pawn('b','G','6',true);
	_pieces[43] = new Pawn('b','G','5',true);
	_pieces[44] = new Pawn('b','H','8',true);
	_pieces[45] = new Pawn('b','H','7');
	_pieces[46] = new Pawn('b','H','6',true);
	_pieces[47] = new Pawn('b','H','5',true);
}

void Horde::_initBoard(){
	_board->setCase(Coordinate('A', '1'), _pieces[0]);		//0 -> 7 : pièces fortes blanches
	_board->setCase(Coordinate('B', '1'), _pieces[1]);
	_board->setCase(Coordinate('C', '1'), _pieces[2]);
	_board->setCase(Coordinate('D', '1'), _pieces[3]);
	_board->setCase(Coordinate('E', '1'), _pieces[4]);
	_board->setCase(Coordinate('F', '1'), _pieces[5]);
	_board->setCase(Coordinate('G', '1'), _pieces[6]);
	_board->setCase(Coordinate('H', '1'), _pieces[7]);
	_board->setCase(Coordinate('A', '2'), _pieces[8]);		//8 -> 15 : pions blancs
	_board->setCase(Coordinate('B', '2'), _pieces[9]);
	_board->setCase(Coordinate('C', '2'), _pieces[10]);
	_board->setCase(Coordinate('D', '2'), _pieces[11]);
	_board->setCase(Coordinate('E', '2'), _pieces[12]);
	_board->setCase(Coordinate('F', '2'), _pieces[13]);
	_board->setCase(Coordinate('G', '2'), _pieces[14]);
	_board->setCase(Coordinate('H', '2'), _pieces[15]);


	_board->setCase(Coordinate('A','8'), _pieces[16]);
	_board->setCase(Coordinate('A','7'), _pieces[17]);
	_board->setCase(Coordinate('A','6'), _pieces[18]);
	_board->setCase(Coordinate('A','5'), _pieces[19]);
	_board->setCase(Coordinate('B','8'), _pieces[20]);
	_board->setCase(Coordinate('B','7'), _pieces[21]);
	_board->setCase(Coordinate('B','6'), _pieces[22]);
	_board->setCase(Coordinate('B','5'), _pieces[23]);
	_board->setCase(Coordinate('C','8'), _pieces[24]);
	_board->setCase(Coordinate('C','7'), _pieces[25]);
	_board->setCase(Coordinate('C','6'), _pieces[26]);
	_board->setCase(Coordinate('C','5'), _pieces[27]);
	_board->setCase(Coordinate('D','7'), _pieces[28]);
	_board->setCase(Coordinate('D','6'), _pieces[29]);
	_board->setCase(Coordinate('D','5'), _pieces[30]);
	_board->setCase(Coordinate('D','4'), _pieces[31]);
	_board->setCase(Coordinate('E','7'), _pieces[32]);
	_board->setCase(Coordinate('E','6'), _pieces[33]);
	_board->setCase(Coordinate('E','5'), _pieces[34]);
	_board->setCase(Coordinate('E','4'), _pieces[35]);
	_board->setCase(Coordinate('F','8'), _pieces[36]);
	_board->setCase(Coordinate('F','7'), _pieces[37]);
	_board->setCase(Coordinate('F','6'), _pieces[38]);
	_board->setCase(Coordinate('F','5'), _pieces[39]);
	_board->setCase(Coordinate('G','8'), _pieces[40]);
	_board->setCase(Coordinate('G','7'), _pieces[41]);
	_board->setCase(Coordinate('G','6'), _pieces[42]);
	_board->setCase(Coordinate('G','5'), _pieces[43]);
	_board->setCase(Coordinate('H','8'), _pieces[44]);
	_board->setCase(Coordinate('H','7'), _pieces[45]);
	_board->setCase(Coordinate('H','6'), _pieces[46]);
	_board->setCase(Coordinate('H','5'), _pieces[47]);
}

Horde::~Horde(){
	for(int i = int(_piecesAmount) - 1; i>=0; i--)
	{
		delete _pieces[i];
	}
	delete[] _pieces;
}

void Horde::_sendGameMode() {
	std::string game = "Horde";
	_player1->transferGameMode(game);
	_player2->transferGameMode(game);
}

void Horde::_changePawn(Piece *pawn, Piece* promotedPawn, Board* board){
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
		end = 48;
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

bool Horde::_executeMove(Coordinate start, Coordinate end, char playerColor){
	Piece *movingPiece;
	movingPiece = _board->getCase(start);
	if (!movingPiece || movingPiece->getColor() != playerColor) return false;
	return movingPiece->move(end, _board, *this);
}

void Horde::_nextTurn() {
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


bool Horde::_isFinish() {
	if (_winner){
		_sendCheckmate();
		return true;
	}
	Player *currentPlayer = _getCurrentPlayer();
	char opponentColor = currentPlayer == _player2 ? 'w':'b';
	if (this->_isCheckmate(opponentColor)){
		if (opponentColor == 'w'){
			std::cout << "Black Player win !" << std::endl;
			data.addUserHordeWin(_player2->getName());
			data.addUserHordeLose(_player1->getName());
		}
		else {
			std::cout << "White Player win !" << std::endl;
			data.addUserHordeLose(_player2->getName());
			data.addUserHordeWin(_player1->getName());
		}
		_winner = currentPlayer;
		_sendCheckmate();
		return true;
	}
	if (this->_isStalemate(opponentColor)) {
		data.addUserHordeDraw(_player2->getName());
		data.addUserHordeDraw(_player1->getName());
		_sendStalemate();
		return true;
	}
	return false;

}

bool Horde::_isCheckmate(char playerColor){
	if (playerColor == 'w'){
		Piece *dangerousPiece = nullptr, *inTest;
		Piece *king = _pieces[KING_INDEX];
		Coordinate kingPlace = king->getCoord(), dPiecePlace;
		int i = 16;
		bool moreThan2 = false;
		while(i < 48 && !moreThan2){
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
				int row = int(king->getRow())+rowDirection, column = int(king->getColumn())+columnDirection;
				while(row != int(dangerousPiece->getRow())){
					for (int i = 0; i < 16; i++){
						if ((!_pieces[i]->isTaken()) && _pieces[i]->_isMovePossible(Coordinate(column, row), _board, *this)) return false;
					}
					row += rowDirection;
					column += columnDirection;
				}
			}
			//rook or queen case(row)
			else if (rowMove){
			for (int j = int(king->getRow())+rowDirection; j != int(dangerousPiece->getRow()); j += rowDirection){
					for(int i = 0; i < 16; i++){
						if ((!_pieces[i]->isTaken()) && _pieces[i]->_isMovePossible(Coordinate(int(king->getColumn()), j), _board, *this)) return false;
					}
				}
			}
			//rook or queen case(column)
			else if (columnMove){
				for (int j = int(king->getColumn())+columnDirection; j != int(dangerousPiece->getColumn()); j += columnDirection){
					for(int i = 0; i < 16; i++){
						if ((!_pieces[i]->isTaken()) && _pieces[i]->_isMovePossible(Coordinate(j, int(king->getRow())), _board, *this)) return false;
					}
				}
			}
			//test if the dangerousPiece can be taken
			for (int i = 0; i < 16; i++){
				if ((!_pieces[i]->isTaken()) && _pieces[i]->_isMovePossible(dangerousPiece->getCoord(), _board, *this)) return false;
			}
		}
	}
	else for (int i = 16; i < 48; i++) if (!_pieces[i]->isTaken()) return false;
	return true;
}

bool Horde::_isStalemate(char playerColor){
	if (this->testCheck(playerColor)) return false;
	if(playerColor == 'w'){
		for (int i = 0; i < 16; i++){
			if ((!_pieces[i]->isTaken()) && _pieces[i]->canMove(_board, *this)) return false;
		}
	}
	else{
		for (int i = 16; i < 48; i++){
			if ((!_pieces[i]->isTaken()) && _pieces[i]->canMove(_board, *this)) return false;
		}
	}
	return true;
}

bool Horde::testCheck(const char color){
	Coordinate leftMaybePawn, rightMaybePawn;
	if (color == 'w' || color == 'a'){	//White		//a = all

		//Pawn
		leftMaybePawn = Coordinate(_pieces[KING_INDEX]->getCoord().getRealColumn()+1, _pieces[KING_INDEX]->getCoord().getRealRow()+1);
		Piece* MaybePawn = nullptr;
		if (_board->isInBoard(leftMaybePawn)) MaybePawn = Game::_board->getCase(leftMaybePawn);
		if (MaybePawn && MaybePawn->getColor() == 'b' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'b' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k')) return true;

		rightMaybePawn = Coordinate(_pieces[KING_INDEX]->getCoord().getRealColumn()-1, _pieces[KING_INDEX]->getCoord().getRealRow()+1);
		MaybePawn = nullptr;
		if (_board->isInBoard(rightMaybePawn)) MaybePawn = Game::_board->getCase(rightMaybePawn);
		if (MaybePawn && MaybePawn->getColor() == 'b' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'b' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k')) return true;

		//strong pieces
		for (unsigned i = 16; i <= _lastStrongPieceBlack; ++i){
			if (!_pieces[i]->isTaken())
				if (_pieces[i]->_checkMove(_pieces[KING_INDEX]->getCoord(), Game::_board, *this)) return true;
		}
	}
	return false;
}

void Horde::_boardState(std::string& state){
	int i = 0;
	for (; i < 16; i++){
		if (!_pieces[i]->isTaken()) state += _pieces[i]->toString();
	}
	state += "!";
	for (; i < 48; i++){
		if (!_pieces[i]->isTaken()) state += _pieces[i]->toString();
	}
	state += "#";
	std::cout<<"Board state: "<<state<<std::endl;
}

#endif
