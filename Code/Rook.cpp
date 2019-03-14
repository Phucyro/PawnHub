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
		for (int i = int(_coords.getRealRow()) + rowDirection; i != int(end.getRealRow()); i += rowDirection){
			if (!_isPlaceFree(Coordinate(end.getRealColumn(), unsigned(i)), board)) return false;
		}
	}
	else if(columnMove){
		// check if there is no piece in the way
		for (int i = int(_coords.getRealColumn()) + columnDirection; i != int(end.getRealColumn()); i += columnDirection){
			if (!_isPlaceFree(Coordinate(unsigned(i), end.getRealRow()), board)) return false;
		}
	}
	else return false;
	if ((!_isPlaceFree(end, board)) && board->getCase(end)->getColor() == this->getColor()) return false;
	return true;
}

bool Rook::move(Coordinate end, Board* board, Game& game, const bool& ForPossibleMoves){
	if(this->Piece::move(end, board, game, ForPossibleMoves)){
		_moved = true;
		return true;
	}
	else return false;
}

bool Rook::canMove(Board* board, Game& game){
	if (this->_isMovePossible(0, 1, board, game)) return true;
	if (this->_isMovePossible(1, 0, board, game)) return true;
	if (this->_isMovePossible(-1, 0, board, game)) return true;
	if (this->_isMovePossible(0, -1, board, game)) return true;
	return false;
}

bool Rook::_isMovePossible(Coordinate dest, Board* board, Game& game){
	bool moved = _moved;
	bool res = this->Piece::_isMovePossible(dest, board, game);
	_moved = moved;
	return res;
}

Coordinate* Rook::PossibleMoves(Board* board, Game& game){
	Coordinate res[14];
	int index = 0;
	int i = 1;
	while (this->_isMovePossible(0, i, board, game)){
		res[index] = Coordinate(_coords.getRealColumn(), _coords.getRealRow()+i);
		++index;
		if (board->getCase(Coordinate(_coords.getRealColumn(), _coords.getRealRow()+i)) && 
		board->getCase(Coordinate(_coords.getRealColumn(), _coords.getRealRow()+i))->getColor() != this->getColor()) 
			break;
		++i;
	}
	i = 1;
	while (this->_isMovePossible(i, 0, board, game)){
		res[index] = Coordinate(_coords.getRealColumn()+i, _coords.getRealRow());
		++index;
		if (board->getCase(Coordinate(_coords.getRealColumn()+i, _coords.getRealRow())) && 
		board->getCase(Coordinate(_coords.getRealColumn()+i, _coords.getRealRow()))->getColor() != this->getColor()) 
			break;
		++i;
	}
	i = -1;
	while (this->_isMovePossible(0, i, board, game)){
		res[index] = Coordinate(_coords.getRealColumn(), _coords.getRealRow()+i);
		++index;
		if (board->getCase(Coordinate(_coords.getRealColumn(), _coords.getRealRow()+i)) && 
		board->getCase(Coordinate(_coords.getRealColumn(), _coords.getRealRow()+i))->getColor() != this->getColor()) 
			break;
		--i;
	}
	i = -1;
	while (this->_isMovePossible(i, 0, board, game)){
		res[index] = Coordinate(_coords.getRealColumn()+i, _coords.getRealRow());
		if (board->getCase(Coordinate(_coords.getRealColumn()+i, _coords.getRealRow())) && 
		board->getCase(Coordinate(_coords.getRealColumn()+i, _coords.getRealRow()))->getColor() != this->getColor()) 
			break;
		++index;
		--i;
	}
	return res;
}

#endif
