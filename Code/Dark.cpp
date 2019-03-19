#ifndef _DARK_CPP_
#define _DARK_CPP_

#include "Dark.hpp"
#include "../Communication/Data.hpp"
extern Data data;

void Dark::_Pieces() {
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

Dark::~Dark(){
	for(int i = int(_piecesAmount) - 1; i>=0; i--)
	{
		delete _pieces[i];
	}
	delete[] _pieces;
}

void Dark::_initBoard() {

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

void Dark::_sendGameMode() {
	std::string game = "Dark";
	_player1->transferGameMode(game);
	_player2->transferGameMode(game);
}

void Dark::_changePawn(Piece *pawn, Piece* promotedPawn, Board* board){
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

bool Dark::_executeMove(Coordinate start, Coordinate end, char playerColor){
	Piece *movingPiece;
	movingPiece = _board->getCase(start);
	if (!movingPiece || movingPiece->getColor() != playerColor) return false;
	return movingPiece->move(end, _board, *this);
}

void Dark::_nextTurn() {
	Player *currentPlayer = _getCurrentPlayer();
	char playerColor = currentPlayer == _player1 ? 'w':'b';

	bool isMoveValid = false;
	std::string playerMove;
	while(!isMoveValid){
		playerMove = currentPlayer->askMove();
		if (playerMove[0] == '/' && playerMove[1] == 'e' && playerMove[2] == 'n' && playerMove[3] == 'd'){
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

bool Dark::_isFinish() {
	if (_winner){
		_sendSurrend();
		return true;
	}
	Player *currentPlayer = _getCurrentPlayer();
	char opponentColor = currentPlayer == _player2 ? 'w':'b';
	if (this->_isCheckmate(opponentColor)){
		if (opponentColor == 'w'){
			std::cout << "Black Player win !" << std::endl;
			data.addUserDarkWin(_player2->getName());
			data.addUserDarkLose(_player1->getName());
			data.updateRating(_player2->getName(),data.expectedWin(data.getEloRating(_player2->getName()),data.getEloRating(_player1->getName())),WIN);
			data.updateRating(_player1->getName(),data.expectedWin(data.getEloRating(_player1->getName()),data.getEloRating(_player2->getName())),LOSE);
		}
		else {
			std::cout << "White Player win !" << std::endl;
			data.addUserDarkLose(_player2->getName());
			data.addUserDarkWin(_player1->getName());
			data.updateRating(_player2->getName(),data.expectedWin(data.getEloRating(_player2->getName()),data.getEloRating(_player1->getName())),LOSE);
			data.updateRating(_player1->getName(),data.expectedWin(data.getEloRating(_player1->getName()),data.getEloRating(_player2->getName())),WIN);
		}
		_winner = currentPlayer;
		_sendCheckmate();
		return true;
	}
	return false;
}

bool Dark::_isCheckmate(char playerColor){
	int offset = _calculOffset(playerColor);
	return _pieces[KING_INDEX+offset]->isTaken();
}

bool Dark::_isStalemate(char playerColor){
	int offset = _calculOffset(playerColor);
	for (int i = offset; i < offset+16; i++){
		if ((!_pieces[i]->isTaken()) && _pieces[i]->canMove(_board, *this)) return false;
	}
	return true;
}

void Dark::_sendBoard(){
	std::string state;
	state += 'w';
	this->_boardState(state);
	_player1->showBoard(state);
	state[0] = 'b';
	this->_boardState(state);
	_player2->showBoard(state);
}

void Dark::_boardState(std::string& state){
	char color = state[0];
	state.clear();
	for (int i = 0; i < 16; i++) if ((!_pieces[i]->isTaken()) && _isVisible(_pieces[i], color)) state += _pieces[i]->toString();
	state += "!";
	for (int i = 16; i < 32; i++) if ((!_pieces[i]->isTaken()) && _isVisible(_pieces[i], color)) state += _pieces[i]->toString();
	state += "#";
}

bool Dark::_isVisible(Piece* piece, char color){
	if (piece->getColor() == color) return true;
	Coordinate leftMaybePawn, rightMaybePawn, frontMaybePawn, frontMaybePawn2;
	if (piece->getColor() == 'w'){	//White

		//Pawn
		frontMaybePawn = Coordinate(piece->getCoord().getRealColumn(), piece->getCoord().getRealRow()+1);
		Piece* MaybePawn = nullptr;
		if (_board->isInBoard(frontMaybePawn)) MaybePawn = TurnBasedGame::_board->getCase(frontMaybePawn);
		if (MaybePawn && MaybePawn->getColor() == 'b' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'r' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k')) return true;

		frontMaybePawn2 = Coordinate(piece->getCoord().getRealColumn(), piece->getCoord().getRealRow()+2);
		MaybePawn = nullptr;
		if (_board->isInBoard(frontMaybePawn2)) MaybePawn = TurnBasedGame::_board->getCase(frontMaybePawn2);
		if (MaybePawn && MaybePawn->getColor() == 'b' && ((MaybePawn->getType() == 'p' && (!MaybePawn->hasMoved()) && ((!_board->getCase(frontMaybePawn)) || _board->getCase(frontMaybePawn)->getType() != 'g')) || MaybePawn->getType() == 'r' || MaybePawn->getType() == 'q')) return true;

		leftMaybePawn = Coordinate(piece->getCoord().getRealColumn()+1, piece->getCoord().getRealRow()+1);
		MaybePawn = nullptr;
		if (_board->isInBoard(leftMaybePawn)) MaybePawn = TurnBasedGame::_board->getCase(leftMaybePawn);
		if (MaybePawn && MaybePawn->getColor() == 'b' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'b' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k')) return true;

		rightMaybePawn = Coordinate(piece->getCoord().getRealColumn()-1, piece->getCoord().getRealRow()+1);
		MaybePawn = nullptr;
		if (_board->isInBoard(rightMaybePawn)) MaybePawn = TurnBasedGame::_board->getCase(rightMaybePawn);
		if (MaybePawn && MaybePawn->getColor() == 'b' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'b' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k')) return true;

		//strong pieces
		for (unsigned i = 16; i <= _lastStrongPieceBlack; ++i){
			if (!_pieces[i]->isTaken())
				if (_pieces[i]->_checkMove(piece->getCoord(), TurnBasedGame::_board, *this)) return true;
		}
	}

	else{	//Black

		//Pawn
		frontMaybePawn = Coordinate(piece->getCoord().getRealColumn(), piece->getCoord().getRealRow()-1);
		Piece* MaybePawn = nullptr;
		if (_board->isInBoard(frontMaybePawn)) MaybePawn = TurnBasedGame::_board->getCase(frontMaybePawn);
		if (MaybePawn && MaybePawn->getColor() == 'w' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'r' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k')) return true;

		frontMaybePawn2 = Coordinate(piece->getCoord().getRealColumn(), piece->getCoord().getRealRow()-2);
		MaybePawn = nullptr;
		if (_board->isInBoard(frontMaybePawn2)) MaybePawn = TurnBasedGame::_board->getCase(frontMaybePawn2);
		if (MaybePawn && MaybePawn->getColor() == 'w' && ((MaybePawn->getType() == 'p' && (!MaybePawn->hasMoved()) && ((!_board->getCase(frontMaybePawn)) || _board->getCase(frontMaybePawn)->getType() != 'g')) || MaybePawn->getType() == 'r' || MaybePawn->getType() == 'q')) return true;

		leftMaybePawn = Coordinate(piece->getCoord().getRealColumn()-1, piece->getCoord().getRealRow()-1);
		MaybePawn = nullptr;
		if (_board->isInBoard(leftMaybePawn)) MaybePawn = TurnBasedGame::_board->getCase(leftMaybePawn);
		if (MaybePawn && MaybePawn->getColor() == 'w' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'b' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k')) return true;

		rightMaybePawn = Coordinate(piece->getCoord().getRealColumn()+1, piece->getCoord().getRealRow()-1);
		MaybePawn = nullptr;
		if (_board->isInBoard(rightMaybePawn)) MaybePawn = TurnBasedGame::_board->getCase(rightMaybePawn);
		if (MaybePawn && MaybePawn->getColor() == 'w' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'b' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k')) return true;

		//strong pieces
		for (unsigned i = 0; i <= _lastStrongPiecesWhite; ++i){
			if (!_pieces[i]->isTaken())
				if (_pieces[i]->_checkMove(piece->getCoord(), TurnBasedGame::_board, *this)) return true;
		}
	}
	return false;
}

#endif
