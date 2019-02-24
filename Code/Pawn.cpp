#ifndef __PAWN__CPP__
#define __PAWN__CPP__

#include <cmath>
#include "Pawn.hpp"

Pawn::~Pawn() noexcept {
	delete _ghost;
}

Pawn::Pawn(const Pawn& original) noexcept : Piece(original), _moved(original.hasMoved()), _ghost(nullptr) {
	_ghost = new GhostPawn(*(original._ghost));
}

Pawn& Pawn::operator= (const Pawn& original){
	this->Piece::operator= (original);
	_moved = original._moved;
	_ghost = new GhostPawn(original._ghost);
	return *this;
}

Pawn& Pawn::operator= (Pawn&& original){
	this->Piece::operator= (original);
	_moved = original._moved;
	_ghost = original._ghost;
	original._ghost = nullptr;
	return *this;
}

bool Pawn::_checkMove(Coordinate end, Board* board, Game& game){
	int rowMove = int(end.getRealRow()) - int(_coords.getRealRow());
	int columnMove = int(end.getRealColumn()) - int(_coords.getRealColumn());

	//TODO add possibility to jump even if a gostpawn is on the way
	if (std::abs(columnMove) > 1) return false;
	if (this->getColor() == 'w'){
		if (std::abs(columnMove) == 1){
			if (rowMove != 1) return false;
			if ((!_isPlaceFree(end, board)) && board->getCase(end)->getColor() == 'w') return false;
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
			if ((!_isPlaceFree(end, board)) && board->getCase(end)->getColor() == 'b') return false;
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

bool Pawn::move(Coordinate end, Board* board, Game& game){
	if (this->Piece::move(end, board, game)){
		int rowMove = int(end.getRealRow()) - int(_coords.getRealRow());
		if (rowMove == 2) _ghost = new GhostPawn(getColor(), Coordinate(_coords.getRealColumn(), _coords.getRealRow() - 1), game.getTurn(), this);
		if (_coords.getRealRow() == 0 || _coords.getRealRow() == board->getRow() - 1) _promote(game);
		_moved = true;
		return true;
	}
	else return false;
}

bool Pawn::canMove(Board* board, Game& game){
	if (this->_isMovePossible(1, 1, board, game)) return false;
	if (this->_isMovePossible(0, 1, board, game)) return false;
	if (this->_isMovePossible(-1, 1, board, game)) return false;
	return true;
}

void Pawn::_promote(Game& game){
	game.promote(this);
}

#endif
