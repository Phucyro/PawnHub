#ifndef __REAL__TIME__ALICE__CPP__
#define __REAL__TIME__ALICE__CPP__

#include "RealTimeAlice.hpp"

extern Data data;

void RealTimeAlice::_Pieces() {
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


RealTimeAlice::~RealTimeAlice(){
	for(int i = int(_piecesAmount) - 1; i>=0; i--)
	{
		delete _pieces[i];
	}
	delete[] _pieces;
}


void RealTimeAlice::_initBoard() {

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

void RealTimeAlice::_sendGameMode() {
	std::string game = "RealTimeAlice";
	_player1->transferGameMode(game);
	_player2->transferGameMode(game);
}

void RealTimeAlice::_sendBoard(){
	if(!_winner){
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
		_lastUpdate = _turn;
	}
}

void RealTimeAlice::_sendStart() {
	this->RealTimeGame::_sendStart();
	std::string update = "alice";
	_player1->transferUpdate(update);
	_player2->transferUpdate(update);
}


void RealTimeAlice::_updateStat(){
	if (_winner == _player1){
		std::cout << "White Player win !" << std::endl;
		data.addUserRealTimeAliceLose(_player2->getName());
		data.addUserRealTimeAliceWin(_player1->getName());
		data.updateRating(_player2->getName(),data.expectedWin(data.getEloRating(_player2->getName()),data.getEloRating(_player1->getName())),LOSE);
		data.updateRating(_player1->getName(),data.expectedWin(data.getEloRating(_player1->getName()),data.getEloRating(_player2->getName())),WIN);
	}
	else if (_winner == _player2) {
		std::cout << "Black Player win !" << std::endl;
		data.addUserRealTimeAliceWin(_player2->getName());
		data.addUserRealTimeAliceLose(_player1->getName());
		data.updateRating(_player2->getName(),data.expectedWin(data.getEloRating(_player2->getName()),data.getEloRating(_player1->getName())),WIN);
		data.updateRating(_player1->getName(),data.expectedWin(data.getEloRating(_player1->getName()),data.getEloRating(_player2->getName())),LOSE);
	}
}

bool RealTimeAlice::_isFinish() {
	if (_winner){
		_sendSurrend();
		_updateStat();
		return true;
	}
	char opponentColor = _currentPlayer == _player2 ? 'w':'b';
	if (this->_isCheckmate(opponentColor)){
		this->_sendBoard();
		_winner = _currentPlayer;
		_sendCheckmate();
		_updateStat();
		return true;
	}
	return false;
}

bool RealTimeAlice::_isCheckmate(char playerColor){
	int offset = _calculOffset(playerColor);
	return _pieces[KING_INDEX+offset]->isTaken();
}

void RealTimeAlice::_boardState(std::string& state){
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


void RealTimeAlice::_changePawn(Piece *pawn, Piece* promotedPawn, Board* board){
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

void RealTimeAlice::promote(Piece* piece){
	this->_changePawn(piece, new AliceQueen(*(dynamic_cast<AlicePawn*>(piece))), _board);
}

#endif
