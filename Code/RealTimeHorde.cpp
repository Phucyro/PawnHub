#ifndef __REAL__TIME__HORDE__CPP__
#define __REAL__TIME__HORDE__CPP__

#include "RealTimeHorde.hpp"

extern Data data;

void RealTimeHorde::_Pieces() {
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


RealTimeHorde::~RealTimeHorde(){
	for(int i = int(_piecesAmount) - 1; i>=0; i--)
	{
		delete _pieces[i];
	}
	delete[] _pieces;
}


void RealTimeHorde::_initBoard() {

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

	// _sendBoard();
}

void RealTimeHorde::_sendGameMode() {
	std::string game = "RealTimeHorde";
	_player1->transferGameMode(game);
	_player2->transferGameMode(game);
}


void RealTimeHorde::_updateStat(){
	double playerElo1 = data.getEloRating(_player1->getName(), RTHORDE);
	double playerElo2 = data.getEloRating(_player2->getName(), RTHORDE);
	double playerExptWin1 = data.getExpectedWin(playerElo1, playerElo2);
	double playerExptWin2 = data.getExpectedWin(playerElo2, playerElo1);

	if (_winner == _player1){
		std::cout << "White Player win !" << std::endl;
		data.updateRTHordeStat(_player2->getName(), 1);
		data.updateRTHordeStat(_player1->getName(), 0);
		data.updateRating(_player2->getName(), playerExptWin2, LOSE, RTHORDE);
		data.updateRating(_player1->getName(), playerExptWin1, WIN,  RTHORDE);
	}
	else if (_winner == _player2) {
		std::cout << "Black Player win !" << std::endl;
		data.updateRTHordeStat(_player2->getName(), 0);
		data.updateRTHordeStat(_player1->getName(), 1);
		data.updateRating(_player2->getName(), playerExptWin2, WIN,  RTHORDE);
		data.updateRating(_player1->getName(), playerExptWin1, LOSE, RTHORDE);
	}
}

bool RealTimeHorde::_isFinish() {
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

bool RealTimeHorde::_isCheckmate(char playerColor){
	int offset = _calculOffset(playerColor);
	if (playerColor == 'w') return _pieces[KING_INDEX]->isTaken();
	else for (int i = 16; i < 48; i++) if (!_pieces[i]->isTaken()) return false;
	return true;
}

void RealTimeHorde::_boardState(std::string& state){
	int i = 0;
	for (; i < 16; i++){
		if (!_pieces[i]->isTaken()) state += _pieces[i]->toString();
	}
	state += "!";
	for (; i < 48; i++){
		if (!_pieces[i]->isTaken()) state += _pieces[i]->toString();
	}
	state += "#";
}

void RealTimeHorde::_changePawn(Piece *pawn, Piece* promotedPawn, Board* board){
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
	}
	else{
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
#endif
