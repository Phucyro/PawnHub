#ifndef __REAL__TIME__CLASSIC__CPP__
#define __REAL__TIME__CLASSIC__CPP__

#include "RealTimeClassic.hpp"

extern Data data;

void RealTimeClassic::_Pieces() {
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


RealTimeClassic::~RealTimeClassic(){
	for(int i = int(_piecesAmount) - 1; i>=0; i--)
	{
		delete _pieces[i];
	}
	delete[] _pieces;
}


void RealTimeClassic::_initBoard() {

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

void RealTimeClassic::_sendGameMode() {
	std::string game = "RealTimeClassic";
	_player1->transferGameMode(game);
	_player2->transferGameMode(game);
}


bool RealTimeClassic::_isFinish() {
	if (_winner){
		_sendSurrend();
		return true;
	}
	char opponentColor = _currentPlayer == _player2 ? 'w':'b';
	if (this->_isCheckmate(opponentColor)){
		if (opponentColor == 'w'){
			std::cout << "Black Player win !" << std::endl;
			data.addUserRealTimeClassicWin(_player2->getName());
			data.addUserRealTimeClassicLose(_player1->getName());
			data.updateRating(_player2->getName(),data.expectedWin(data.getEloRating(_player2->getName()),data.getEloRating(_player1->getName())),WIN);
			data.updateRating(_player1->getName(),data.expectedWin(data.getEloRating(_player1->getName()),data.getEloRating(_player2->getName())),LOSE);
		}
		else {
			std::cout << "White Player win !" << std::endl;
			data.addUserRealTimeClassicLose(_player2->getName());
			data.addUserRealTimeClassicWin(_player1->getName());
			data.updateRating(_player2->getName(),data.expectedWin(data.getEloRating(_player2->getName()),data.getEloRating(_player1->getName())),LOSE);
			data.updateRating(_player1->getName(),data.expectedWin(data.getEloRating(_player1->getName()),data.getEloRating(_player2->getName())),WIN);
		}
		_winner = _currentPlayer;
		_sendBoard(); //why Romain? 
		_sendCheckmate();
		return true;
	}
	return false;
}

bool RealTimeClassic::_isCheckmate(char playerColor){
	int offset = _calculOffset(playerColor);
	return _pieces[KING_INDEX+offset]->isTaken();
}

void RealTimeClassic::_boardState(std::string& state){
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

void RealTimeClassic::_changePawn(Piece *pawn, Piece* promotedPawn, Board* board){
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

#endif
