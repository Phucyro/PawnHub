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

	if ( end.getRealRow() > 7 || end.getRealColumn() > 7) return false;

	return ((std::abs(columnMove) == 2 && std::abs(rowMove) == 1)  ||  (std::abs(columnMove) == 1 && std::abs(rowMove) == 2)) // true if the move is normal for the knight
	&& ((!_isPlaceFree(end, board)) ? board->getCase(end)->getColor() != this->getColor() : true); //true if the color of the piece taken is not the same
}

bool Knight::canMove(Board* board, Game& game){
	if (this->_isMovePossible(1, 2, board, game)) return true;
	if (this->_isMovePossible(1, -2, board, game)) return true;
	if (this->_isMovePossible(-1, 2, board, game)) return true;
	if (this->_isMovePossible(-1, -2, board, game)) return true;
	if (this->_isMovePossible(2, 1, board, game)) return true;
	if (this->_isMovePossible(2, -1, board, game)) return true;
	if (this->_isMovePossible(-2, 1, board, game)) return true;
	if (this->_isMovePossible(-2, -1, board, game)) return true;
	return false;
}

Coordinate* Knight::PossibleMoves(Board* board, Game& game){
	Coordinate res[8];
	int index = 0;
	if (this->_isMovePossible(1, 2, board, game)){
		res[index] = Coordinate(_coords.getRealColumn()+1, _coords.getRealRow()+2);
		++index;
	}
	if (this->_isMovePossible(1, -2, board, game)){
		res[index] = Coordinate(_coords.getRealColumn()+1, _coords.getRealRow()-2);
		++index;
	} 
	if (this->_isMovePossible(-1, 2, board, game)){
		res[index] = Coordinate(_coords.getRealColumn()-1, _coords.getRealRow()+2);
		++index;
	}
	if (this->_isMovePossible(-1, -2, board, game)){
		res[index] = Coordinate(_coords.getRealColumn()-1, _coords.getRealRow()-2);
		++index;
	} 
	if (this->_isMovePossible(2, 1, board, game)){
		res[index] = Coordinate(_coords.getRealColumn()+2, _coords.getRealRow()+1);
		++index;
	} 
	if (this->_isMovePossible(2, -1, board, game)){
		res[index] = Coordinate(_coords.getRealColumn()+2, _coords.getRealRow()-1);
		++index;
	} 
	if (this->_isMovePossible(-2, 1, board, game)){
		res[index] = Coordinate(_coords.getRealColumn()-2, _coords.getRealRow()+1);
		++index;
	} 
	if (this->_isMovePossible(-2, -1, board, game)){
		res[index] = Coordinate(_coords.getRealColumn()-2, _coords.getRealRow()-1);
	}
	return res; 
}

#endif
