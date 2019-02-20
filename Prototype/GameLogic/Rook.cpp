#ifndef __ROOK__CPP__
#define __ROOK__CPP__

#include <cmath>
#include "Rook.hpp"

Rook& Rook::operator= (const Rook& original){
	this->Piece::operator= (original);
	_moved = original._moved;
	return *this;
}

bool Rook::_checkMove(Coordinate end, Board* board, Game& game){
	int rowMove = int(end.getRealRow()) - int(_coords.getRealRow());
	int rowDirection = rowMove == 0 ? 0 : rowMove/std::abs(rowMove);
	int columnMove = int(end.getRealColumn()) - int(_coords.getRealColumn());
	int columnDirection = columnMove == 0 ? 0 : columnMove/std::abs(columnMove);

	if (rowMove){
		if (columnMove) return false;

		// check if there is no piece in the way
		for (int i = int(_coords.getRealRow()) + rowDirection; i != end.getRealRow(); i += rowDirection){
			if (board->getCase(Coordinate(end.getRealColumn(), unsigned(i)))) return false;
		}
	}
	else if(columnMove){
		// check if there is no piece in the way
		for (int i = int(_coords.getRealColumn()) + columnDirection; i != end.getRealColumn(); i += columnDirection){
			if (board->getCase(Coordinate(unsigned(i), end.getRealColumn()))) return false;
		}
	}
	else return false;
	if (board->getCase(end) && board->getCase(end)->getColor() == this->getColor()) return false;
	return true;
}

bool Rook::move(Coordinate end, Board* board, Game& game){
	if(this->Piece::move(end, board, game)){
		_moved = true;
		return true;
	}
	else return false;
}

bool Rook::canMove(Board* board, Game& game){
	if (this->_isMovePossible(0, 1, board, game)) return false;
	if (this->_isMovePossible(1, 0, board, game)) return false;
	if (this->_isMovePossible(-1, 0, board, game)) return false;
	if (this->_isMovePossible(0, -1, board, game)) return false;
	return true;
}

#endif
