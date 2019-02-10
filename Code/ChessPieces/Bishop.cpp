#ifndef __BISHOP__CPP__
#define __BISHOP__CPP__

#include <cmath>
#include "Bishop.hpp"

Bishop& Bishop::operator= (const Bishop& original){
	this->Piece::operator= (original);
	return *this;
}


bool Bishop::_checkMove(Coordinate end, Board* board, Game& game){
	int rowMove = int(end.getRealRow()) - int(_coords.getRealRow());
	int rowDirection = rowMove/std::abs(rowMove);
	int columnMove = int(end.getRealColumn()) - int(_coords.getRealColumn());
	int columnDirection = columnMove/std::abs(columnMove); 
	
	if (end == _coords) return false;
	if (std::abs(rowMove) != std::abs(columnMove)) return false; //test if the move normal for a bishop
	
	//test if there is no piece in the way
	int row = _coords.getRealRow(), column = _coords.getRealColumn();
	while(row != end.getRealRow()){
		if (board->getCase(Coordinate(column, row))) return false;
		row += rowDirection;
		column += columnDirection;
	}
	
	if (board->getCase(end) && board->getCase(end)->getColor() == _color) return false;
	return true;
}
#endif
