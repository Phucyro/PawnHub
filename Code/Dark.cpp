#ifndef _DARK_CPP_
#define _DARK_CPP_

#include "Dark.hpp"

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
	for(int i = _piecesAmount - 1; i>=0; i--)
	{
		delete _pieces[i];
	}
	delete[] _pieces;
}

void Dark::_initBoard() {

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

void Dark::_changePawn(Piece *pawn, Piece* promotedPawn, Board* board){
	int start, i, end;
	if (pawn->getColor() == 'w'){
		int start = _lastStrongPiecesWhite;
		int i = _lastStrongPiecesWhite;
		_lastStrongPiecesWhite ++;
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
		start = _lastStrongPieceBlack;
		i = _lastStrongPieceBlack;
		_lastStrongPieceBlack ++;
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
		if (this->_fitInBoard(playerMove)){
			Coordinate start = Coordinate(playerMove[0], playerMove[1]), end = Coordinate(playerMove[2], playerMove[3]);
			isMoveValid = this->_executeMove(start, end, playerColor);
		}
	}
}

bool Dark::_isFinish() {
	Player *currentPlayer = _getCurrentPlayer();
	char opponentColor = currentPlayer == _player2 ? 'w':'b';
	if (this->_isCheckmate(opponentColor)){
		_winner = currentPlayer;
		return true;
	}
	return this->_isStalemate(opponentColor);
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
	int offset = _calculOffset(state[0]);
	state.clear();
	for (int i = offset; i < 16+offset; i++) if (!_pieces[i]->isTaken()) state += _pieces[i]->toString();
	state += "!";
	for (int i = 16-offset; i < 32-offset; i++) if ((!_pieces[i]->isTaken()) && _isVisible(_pieces[i])) state += _pieces[i]->toString();
	state += "#";
}

bool Dark::_isVisible(Piece* piece){
	Coordinate leftMaybePawn, rightMaybePawn, frontMaybePawn;
	if (piece->getColor() == 'w'){	//White

		//Pawn
		frontMaybePawn = Coordinate(piece->getCoord().getRealColumn(), piece->getCoord().getRealRow()+1);
		Piece* MaybePawn = nullptr;
		if (_board->isInBoard(frontMaybePawn)) MaybePawn = Game::_board->getCase(frontMaybePawn);
		if (MaybePawn && MaybePawn->getColor() == 'b' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'b' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k')) return true;

		leftMaybePawn = Coordinate(piece->getCoord().getRealColumn()+1, piece->getCoord().getRealRow()+1);
		MaybePawn = nullptr;
		if (_board->isInBoard(leftMaybePawn)) MaybePawn = Game::_board->getCase(leftMaybePawn);
		if (MaybePawn && MaybePawn->getColor() == 'b' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'b' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k')) return true;

		rightMaybePawn = Coordinate(piece->getCoord().getRealColumn()-1, piece->getCoord().getRealRow()+1);
		MaybePawn = nullptr;
		if (_board->isInBoard(rightMaybePawn)) MaybePawn = Game::_board->getCase(rightMaybePawn);
		if (MaybePawn && MaybePawn->getColor() == 'b' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'b' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k')) return true;

		//strong pieces
		for (unsigned i = 16; i <= _lastStrongPieceBlack; ++i){
			if (!_pieces[i]->isTaken())
				if (_pieces[i]->_checkMove(piece->getCoord(), Game::_board, *this)) return true;
		}
	}

	else{	//Black

		//Pawn
		frontMaybePawn = Coordinate(piece->getCoord().getRealColumn(), piece->getCoord().getRealRow()-1);
		Piece* MaybePawn = nullptr;
		if (_board->isInBoard(frontMaybePawn)) MaybePawn = Game::_board->getCase(frontMaybePawn);
		if (MaybePawn && MaybePawn->getColor() == 'w' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'b' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k')) return true;

		leftMaybePawn = Coordinate(piece->getCoord().getRealColumn()-1, piece->getCoord().getRealRow()-1);
		MaybePawn = nullptr;
		if (_board->isInBoard(leftMaybePawn)) MaybePawn = Game::_board->getCase(leftMaybePawn);
		if (MaybePawn && MaybePawn->getColor() == 'w' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'b' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k')) return true;

		rightMaybePawn = Coordinate(piece->getCoord().getRealColumn()+1, piece->getCoord().getRealRow()-1);
		MaybePawn = nullptr;
		if (_board->isInBoard(rightMaybePawn)) MaybePawn = Game::_board->getCase(rightMaybePawn);
		if (MaybePawn && MaybePawn->getColor() == 'w' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'b' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k')) return true;

		//strong pieces
		for (unsigned i = 0; i <= _lastStrongPiecesWhite; ++i){
			if (!_pieces[i]->isTaken())
				if (_pieces[i]->_checkMove(piece->getCoord(), Game::_board, *this)) return true;
		}
	}
	return false;
}

#endif
