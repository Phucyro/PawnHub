#ifndef __BASIC__PAWN__CPP__
#define __BASIC__PAWN__CPP__

#include <cmath>
#include "BasicPawn.hpp"

BasicPawn::BasicPawn(const BasicPawn& original) noexcept : Piece(original), _moved(original.hasMoved()){}

BasicPawn& BasicPawn::operator= (const BasicPawn& original){
	this->Piece::operator= (original);
	_moved = original._moved;
	return *this;
}

BasicPawn& BasicPawn::operator= (BasicPawn&& original){
	this->Piece::operator= (original);
	_moved = original._moved;
	return *this;
}

bool BasicPawn::_checkMove(Coordinate end, Board* board, Game& game){
	int rowMove = int(end.getRealRow()) - int(_coords.getRealRow());
	int columnMove = int(end.getRealColumn()) - int(_coords.getRealColumn());

	if (std::abs(columnMove) > 1) return false;
	if (this->getColor() == 'w'){
		if (std::abs(columnMove) == 1){
			if (rowMove != 1) return false;
			if (_isPlaceFree(end, board)) return false;
			if (board->getCase(end)->getColor() == 'w') return false;
		}
		else{
			if (rowMove > 2 || rowMove < 1) return false;
			if (rowMove == 2){
				if (this->hasMoved()) return false;
				if (board->getCase(end)) return false;
			}
			if (!_isPlaceFree(Coordinate(_coords.getRealColumn(), _coords.getRealRow() + 1), board)) return false;
		}
	}
	else {
		if (std::abs(columnMove) == 1){
			if (rowMove != -1) return false;
			if (_isPlaceFree(end, board)) return false;
			if (board->getCase(end)->getColor() == 'b') return false;
		}
		else{
			if (rowMove < -2 || rowMove > -1) return false;
			if (rowMove == -2){
				if (this->hasMoved()) return false;
				if (board->getCase(end)) return false;
			}
			if (!_isPlaceFree(Coordinate(_coords.getRealColumn(), _coords.getRealRow() - 1), board)) return false;
		}
	}
	return true;
}

bool BasicPawn::move(Coordinate end, Board* board, Game& game){
	int rowMove = int(end.getRealRow()) - int(_coords.getRealRow());
	int rowDirection = rowMove ? rowMove/std::abs(rowMove) : 0;
	if (this->Piece::move(end, board, game)){
		if (_coords.getRealRow() == 0 || _coords.getRealRow() == board->getRow() - 1) _promote(game);
		_moved = true;
		return true;
	}
	return false;
}

bool BasicPawn::canMove(Board* board, Game& game){
	int direction = this->getColor() == 'w' ? 1:-1;
	if (this->_isMovePossible(1, 1*direction, board, game)) return true;
	if (this->_isMovePossible(0, 1*direction, board, game)) return true;
	if (this->_isMovePossible(-1, 1*direction, board, game)) return true;
	return false;
}

bool BasicPawn::_isMovePossible(Coordinate dest, Board* board, Game& game){
	bool moved = _moved;
	bool res = this->Piece::_isMovePossible(dest, board, game);
	_moved = moved;
	return res;
}

void BasicPawn::_promote(Game& game){
	game.promote(this);
}

void BasicPawn::startMovingTo(Game& game, Coordinate end){
	this->Piece::startMovingTo(game, end);
	_moved = true;
}

#endif
