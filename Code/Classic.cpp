#ifndef _CLASSIC_CPP_
#define _CLASSIC_CPP_

#include "Classic.hpp"

Classic::~Classic(){
	for(int i = _piecesAmount - 1; i>=0; i--)
	{
		delete _pieces[i];
	}
	delete[] _pieces;
}

void Classic::_initBoard() {

	//White part

	Game::_board.setCase(Coordinate('A', '1'), Game::_pieces[0]);
	Game::_board.setCase(Coordinate('B', '1'), Game::_pieces[1]);
	Game::_board.setCase(Coordinate('C', '1'), Game::_pieces[2]);
	Game::_board.setCase(Coordinate('D', '1'), Game::_pieces[3]);
	Game::_board.setCase(Coordinate('E', '1'), Game::_pieces[4]);
	Game::_board.setCase(Coordinate('F', '1'), Game::_pieces[5]);
	Game::_board.setCase(Coordinate('G', '1'), Game::_pieces[6]);
	Game::_board.setCase(Coordinate('H', '1'), Game::_pieces[7]);
	Game::_board.setCase(Coordinate('A', '2'), Game::_pieces[8]);
	Game::_board.setCase(Coordinate('B', '2'), Game::_pieces[9]);
	Game::_board.setCase(Coordinate('C', '2'), Game::_pieces[10]);
	Game::_board.setCase(Coordinate('D', '2'), Game::_pieces[11]);
	Game::_board.setCase(Coordinate('E', '2'), Game::_pieces[12]);
	Game::_board.setCase(Coordinate('F', '2'), Game::_pieces[13]);
	Game::_board.setCase(Coordinate('G', '2'), Game::_pieces[14]);
	Game::_board.setCase(Coordinate('H', '2'), Game::_pieces[15]);

	//Black part

	Game::_board.setCase(Coordinate('A', '8'), Game::_pieces[16]);
	Game::_board.setCase(Coordinate('B', '8'), Game::_pieces[17]);
	Game::_board.setCase(Coordinate('C', '8'), Game::_pieces[18]);
	Game::_board.setCase(Coordinate('D', '8'), Game::_pieces[19]);
	Game::_board.setCase(Coordinate('E', '8'), Game::_pieces[20]);
	Game::_board.setCase(Coordinate('F', '8'), Game::_pieces[21]);
	Game::_board.setCase(Coordinate('G', '8'), Game::_pieces[22]);
	Game::_board.setCase(Coordinate('H', '8'), Game::_pieces[23]);
	Game::_board.setCase(Coordinate('A', '7'), Game::_pieces[24]);
	Game::_board.setCase(Coordinate('B', '7'), Game::_pieces[25]);
	Game::_board.setCase(Coordinate('C', '7'), Game::_pieces[26]);
	Game::_board.setCase(Coordinate('D', '7'), Game::_pieces[27]);
	Game::_board.setCase(Coordinate('E', '7'), Game::_pieces[28]);
	Game::_board.setCase(Coordinate('F', '7'), Game::_pieces[29]);
	Game::_board.setCase(Coordinate('G', '7'), Game::_pieces[30]);
	Game::_board.setCase(Coordinate('H', '7'), Game::_pieces[31]);
}

void Classic::_nextTurn() {

	++Game::_turn;

	//Déroulement d'un tour à mettre
}

bool Classic::_isFinish() const {

	if (Game::_winner != nullptr) return true;
	else return false;
}

bool Classic::testCheck(const char& color) const {
	if (color == 'w' || color == 'a'){	//White part (a = all)
		for (unsigned i = 1; _pieces[4]->getCoord()->getRealRow()+i <= 7; ++i){	//Right
			Piece* tmpPiece = board->getCase(Coordinate(_pieces[4]->getCoord()->getRealColumn(), _pieces[4]->getCoord()->getRealRow()+i))
			if (tmpPiece){
				if (tmpPiece->getColor() == 'w') break;
				if (tmpPiece->getType() == 'p' || tmpPiece->getType() == 'k' || tmpPiece->getType() == 'b') break;
				if (i != 1 && tmpPiece->getType() == 'K') break;
				return true;
			}
		}
		for (unsigned i = 1; _pieces[4]->getCoord()->getRealColumn()+i <= 7; ++i){	//Top
			Piece* tmpPiece = board->getCase(Coordinate(_pieces[4]->getCoord()->getRealColumn()+i, _pieces[4]->getCoord()->getRealRow()))
			if (tmpPiece){
				if (tmpPiece->getColor() == 'w') break;
				if (tmpPiece->getType() == 'p' || tmpPiece->getType() == 'k' || tmpPiece->getType() == 'b') break;
				if (i != 1 && tmpPiece->getType() == 'K') break;
				return true;
			}
		}
		for (unsigned i = 1; _pieces[4]->getCoord()->getRealRow()-i >= 0; ++i){	//Left
			Piece* tmpPiece = board->getCase(Coordinate(_pieces[4]->getCoord()->getRealColumn(), _pieces[4]->getCoord()->getRealRow()-i))
			if (tmpPiece){
				if (tmpPiece->getColor() == 'w') break;
				if (tmpPiece->getType() == 'p' || tmpPiece->getType() == 'k' || tmpPiece->getType() == 'b') break;
				if (i != 1 && tmpPiece->getType() == 'K') break;
				return true;
			}
		}
		for (unsigned i = 1; _pieces[4]->getCoord()->getRealColumn()+i <= 7; ++i){	//Bottom
			Piece* tmpPiece = board->getCase(Coordinate(_pieces[4]->getCoord()->getRealColumn(), _pieces[4]->getCoord()->getRealRow()+i))
			if (tmpPiece){
				if (tmpPiece->getColor() == 'w') break;
				if (tmpPiece->getType() == 'p' || tmpPiece->getType() == 'k' || tmpPiece->getType() == 'b') break;
				if (i != 1 && tmpPiece->getType() == 'K') break;
				return true;
			}
		}
	}
}

#endif
