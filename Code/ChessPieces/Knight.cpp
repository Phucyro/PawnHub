#ifndef __KNIGHT__CPP__
#define __KNIGHT__CPP__

#include <cmath>
#include "Knight.hpp"

Knight& Knight::operator= (const Knight& original){
	this->Piece::operator= (original);
	return *this;
}

bool Knight::_checkMove(Coordinate end, Board* board, Game& game){
	int rowMove = int(end.getRealRow()) - int(_coords.getRealRow());
	int columnMove = int(end.getRealColumn()) - int(_coords.getRealColumn());
	
	return ((std::abs(columnMove == 2) && std::abs(rowMove == 1))  ||  (std::abs(columnMove == 1) && std::abs(rowMove == 2))) // true if the move is normal for the knight
	&& board->getCase(end)->getColor() != this->getColor(); //true if the color of the piece taken is not the same
}

#endif
