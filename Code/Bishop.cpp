#ifndef __BISHOP__CPP__
#define __BISHOP__CPP__

#include <cmath>
#include "Bishop.hpp"

Bishop& Bishop::operator= (const Bishop& original){
	this->Piece::operator= (original);
	return *this;
}

bool Bishop::_checkMove(Coordinate end, Board* board, Game& game, bool careOfMoving){
	int rowMove = int(end.getRealRow()) - int(_coords.getRealRow());
	int rowDirection = rowMove == 0 ? 0 : rowMove/std::abs(rowMove);
	int columnMove = int(end.getRealColumn()) - int(_coords.getRealColumn());
	int columnDirection = columnMove == 0 ? 0 : columnMove/std::abs(columnMove);

	if (end == _coords) return false;

	if (std::abs(rowMove) != std::abs(columnMove)) return false; //test if the move normal for a bishop

	//test if there is no piece in the way
	unsigned row = _coords.getRealRow()+unsigned(rowDirection), column = _coords.getRealColumn()+unsigned(columnDirection);
	while(row != end.getRealRow()){
		if (!_isPlaceFree(Coordinate(column, row), board, careOfMoving)) return false;
		row += unsigned(rowDirection);
		column += unsigned(columnDirection);
	}

	if ((!_isPlaceFree(end, board, careOfMoving)) && board->getCase(end)->getColor() == this->getColor()) return false;
	return true;
}

bool Bishop::canMove(Board* board, Game& game){
	if (this->_isMovePossible(1, 1, board, game)) return true;
	if (this->_isMovePossible(-1, 1, board, game)) return true;
	if (this->_isMovePossible(1, -1, board, game)) return true;
	if (this->_isMovePossible(-1, -1, board, game)) return true;
	return false;
}
#endif
