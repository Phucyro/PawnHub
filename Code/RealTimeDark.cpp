#ifndef __REAL__TIME__DARK__CPP__
#define __REAL__TIME__DARK__CPP__

#include "RealTimeDark.hpp"

extern Data data;

void RealTimeDark::_Pieces() {
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


RealTimeDark::~RealTimeDark(){
	for(int i = int(_piecesAmount) - 1; i>=0; i--)
	{
		delete _pieces[i];
	}
	delete[] _pieces;
}


void RealTimeDark::_initBoard() {

	//White part

	RealTimeGame::_board->setCase(Coordinate('A', '1'), RealTimeGame::_pieces[0]);
	RealTimeGame::_board->setCase(Coordinate('B', '1'), RealTimeGame::_pieces[1]);
	RealTimeGame::_board->setCase(Coordinate('C', '1'), RealTimeGame::_pieces[2]);
	RealTimeGame::_board->setCase(Coordinate('D', '1'), RealTimeGame::_pieces[3]);
	RealTimeGame::_board->setCase(Coordinate('E', '1'), RealTimeGame::_pieces[4]);
	RealTimeGame::_board->setCase(Coordinate('F', '1'), RealTimeGame::_pieces[5]);
	RealTimeGame::_board->setCase(Coordinate('G', '1'), RealTimeGame::_pieces[6]);
	RealTimeGame::_board->setCase(Coordinate('H', '1'), RealTimeGame::_pieces[7]);
	RealTimeGame::_board->setCase(Coordinate('A', '2'), RealTimeGame::_pieces[8]);
	RealTimeGame::_board->setCase(Coordinate('B', '2'), RealTimeGame::_pieces[9]);
	RealTimeGame::_board->setCase(Coordinate('C', '2'), RealTimeGame::_pieces[10]);
	RealTimeGame::_board->setCase(Coordinate('D', '2'), RealTimeGame::_pieces[11]);
	RealTimeGame::_board->setCase(Coordinate('E', '2'), RealTimeGame::_pieces[12]);
	RealTimeGame::_board->setCase(Coordinate('F', '2'), RealTimeGame::_pieces[13]);
	RealTimeGame::_board->setCase(Coordinate('G', '2'), RealTimeGame::_pieces[14]);
	RealTimeGame::_board->setCase(Coordinate('H', '2'), RealTimeGame::_pieces[15]);

	//Black part

	RealTimeGame::_board->setCase(Coordinate('A', '8'), RealTimeGame::_pieces[16]);
	RealTimeGame::_board->setCase(Coordinate('B', '8'), RealTimeGame::_pieces[17]);
	RealTimeGame::_board->setCase(Coordinate('C', '8'), RealTimeGame::_pieces[18]);
	RealTimeGame::_board->setCase(Coordinate('D', '8'), RealTimeGame::_pieces[19]);
	RealTimeGame::_board->setCase(Coordinate('E', '8'), RealTimeGame::_pieces[20]);
	RealTimeGame::_board->setCase(Coordinate('F', '8'), RealTimeGame::_pieces[21]);
	RealTimeGame::_board->setCase(Coordinate('G', '8'), RealTimeGame::_pieces[22]);
	RealTimeGame::_board->setCase(Coordinate('H', '8'), RealTimeGame::_pieces[23]);
	RealTimeGame::_board->setCase(Coordinate('A', '7'), RealTimeGame::_pieces[24]);
	RealTimeGame::_board->setCase(Coordinate('B', '7'), RealTimeGame::_pieces[25]);
	RealTimeGame::_board->setCase(Coordinate('C', '7'), RealTimeGame::_pieces[26]);
	RealTimeGame::_board->setCase(Coordinate('D', '7'), RealTimeGame::_pieces[27]);
	RealTimeGame::_board->setCase(Coordinate('E', '7'), RealTimeGame::_pieces[28]);
	RealTimeGame::_board->setCase(Coordinate('F', '7'), RealTimeGame::_pieces[29]);
	RealTimeGame::_board->setCase(Coordinate('G', '7'), RealTimeGame::_pieces[30]);
	RealTimeGame::_board->setCase(Coordinate('H', '7'), RealTimeGame::_pieces[31]);

	// _sendBoard();
}

void RealTimeDark::_sendGameMode() {
	std::string game = "RealTimeDark";
	_player1->transferGameMode(game);
	_player2->transferGameMode(game);
}


bool RealTimeDark::_isFinish() {
	if (_winner){
		_sendSurrend();
		return true;
	}
	char opponentColor = _currentPlayer == _player2 ? 'w':'b';
	if (this->_isCheckmate(opponentColor)){
		if (opponentColor == 'w'){
			std::cout << "Black Player win !" << std::endl;
			data.addUserDarkWin(_player2->getName());
			data.addUserDarkLose(_player1->getName());
		}
		else {
			std::cout << "White Player win !" << std::endl;
			data.addUserDarkLose(_player2->getName());
			data.addUserDarkWin(_player1->getName());
		}
		_winner = _currentPlayer;
		_sendCheckmate();
		return true;
	}
	return false;
}

bool RealTimeDark::_isCheckmate(char playerColor){
	int offset = _calculOffset(playerColor);
	return _pieces[KING_INDEX+offset]->isTaken();
}

void RealTimeDark::_sendBoard(){
	std::string state;
	state += 'w';
	this->_boardState(state);
	_player1->showBoard(state);
	state[0] = 'b';
	this->_boardState(state);
	_player2->showBoard(state);
	_lastUpdate = _turn;
}

void RealTimeDark::_boardState(std::string& state){
	char color = state[0];
	state.clear();
	for (int i = 0; i < 16; i++) if ((!_pieces[i]->isTaken()) && _isVisible(_pieces[i], color)) state += _pieces[i]->toString();
	state += "!";
	for (int i = 16; i < 32; i++) if ((!_pieces[i]->isTaken()) && _isVisible(_pieces[i], color)) state += _pieces[i]->toString();
	state += "#";
}

void RealTimeDark::_changePawn(Piece *pawn, Piece* promotedPawn, Board* board){
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

bool RealTimeDark::_isVisible(Piece* piece, char color){
	if (piece->getColor() == color) return true;
	Coordinate leftMaybePawn, rightMaybePawn, frontMaybePawn, frontMaybePawn2;
	if (piece->getColor() == 'w'){	//White

		//Pawn
		frontMaybePawn = Coordinate(piece->getCoord().getRealColumn(), piece->getCoord().getRealRow()+1);
		Piece* MaybePawn = nullptr;
		if (_board->isInBoard(frontMaybePawn)) MaybePawn = RealTimeGame::_board->getCase(frontMaybePawn);
		if (MaybePawn && MaybePawn->getColor() == 'b' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'r' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k')) return true;
		
		frontMaybePawn2 = Coordinate(piece->getCoord().getRealColumn(), piece->getCoord().getRealRow()+2);
		MaybePawn = nullptr;
		if (_board->isInBoard(frontMaybePawn2)) MaybePawn = RealTimeGame::_board->getCase(frontMaybePawn2);
		if (MaybePawn && MaybePawn->getColor() == 'b' && ((MaybePawn->getType() == 'p' && (!MaybePawn->hasMoved()) && ((!_board->getCase(frontMaybePawn)) || _board->getCase(frontMaybePawn)->getType() != 'g')) || MaybePawn->getType() == 'r' || MaybePawn->getType() == 'q')) return true;

		leftMaybePawn = Coordinate(piece->getCoord().getRealColumn()+1, piece->getCoord().getRealRow()+1);
		MaybePawn = nullptr;
		if (_board->isInBoard(leftMaybePawn)) MaybePawn = RealTimeGame::_board->getCase(leftMaybePawn);
		if (MaybePawn && MaybePawn->getColor() == 'b' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'b' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k')) return true;

		rightMaybePawn = Coordinate(piece->getCoord().getRealColumn()-1, piece->getCoord().getRealRow()+1);
		MaybePawn = nullptr;
		if (_board->isInBoard(rightMaybePawn)) MaybePawn = RealTimeGame::_board->getCase(rightMaybePawn);
		if (MaybePawn && MaybePawn->getColor() == 'b' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'b' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k')) return true;

		//strong pieces
		for (unsigned i = 16; i <= _lastStrongPieceBlack; ++i){
			if (!_pieces[i]->isTaken())
				if (_pieces[i]->_checkMove(piece->getCoord(), RealTimeGame::_board, *this)) return true;
		}
	}

	else{	//Black

		//Pawn
		frontMaybePawn = Coordinate(piece->getCoord().getRealColumn(), piece->getCoord().getRealRow()-1);
		Piece* MaybePawn = nullptr;
		if (_board->isInBoard(frontMaybePawn)) MaybePawn = RealTimeGame::_board->getCase(frontMaybePawn);
		if (MaybePawn && MaybePawn->getColor() == 'w' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'r' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k')) return true;
		
		frontMaybePawn2 = Coordinate(piece->getCoord().getRealColumn(), piece->getCoord().getRealRow()-2);
		MaybePawn = nullptr;
		if (_board->isInBoard(frontMaybePawn2)) MaybePawn = RealTimeGame::_board->getCase(frontMaybePawn2);
		if (MaybePawn && MaybePawn->getColor() == 'w' && ((MaybePawn->getType() == 'p' && (!MaybePawn->hasMoved()) && ((!_board->getCase(frontMaybePawn)) || _board->getCase(frontMaybePawn)->getType() != 'g')) || MaybePawn->getType() == 'r' || MaybePawn->getType() == 'q')) return true;

		leftMaybePawn = Coordinate(piece->getCoord().getRealColumn()-1, piece->getCoord().getRealRow()-1);
		MaybePawn = nullptr;
		if (_board->isInBoard(leftMaybePawn)) MaybePawn = RealTimeGame::_board->getCase(leftMaybePawn);
		if (MaybePawn && MaybePawn->getColor() == 'w' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'b' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k')) return true;

		rightMaybePawn = Coordinate(piece->getCoord().getRealColumn()+1, piece->getCoord().getRealRow()-1);
		MaybePawn = nullptr;
		if (_board->isInBoard(rightMaybePawn)) MaybePawn = RealTimeGame::_board->getCase(rightMaybePawn);
		if (MaybePawn && MaybePawn->getColor() == 'w' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'b' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k')) return true;

		//strong pieces
		for (unsigned i = 0; i <= _lastStrongPiecesWhite; ++i){
			if (!_pieces[i]->isTaken())
				if (_pieces[i]->_checkMove(piece->getCoord(), RealTimeGame::_board, *this)) return true;
		}
	}
	return false;
}

#endif
