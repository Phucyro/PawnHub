#ifndef __PAWN__CPP__
#define __PAWN__CPP__

#include <cmath>
#include "Pawn.hpp"

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
	if (std::abs(columnMove) == 1){
		if (rowMove != 1) return false;
		if ( board->getCase(end)->getColor() == this->getColor()) return false;
	}
	else{
		if (rowMove > 2 || rowMove < 1) return false;
		if (rowMove == 2){
			if (this->hasMoved()) return false;
			if (board->getCase(end)) return false;
		}
		if (board->getCase(Coordinate(_coords.getRealColumn(), _coords.getRealRow() + 1))) return false;
	}
	return true;
}

bool Pawn::move(Coordinate end, Board* board, Game& game){
	if (this->Piece::move(end, board, game)){
		int rowMove = int(end.getRealRow()) - int(_coords.getRealRow());
		if (rowMove == 2) _ghost = new GhostPawn(getColor(), Coordinate(_coords.getRealColumn(), _coords.getRealRow() - 1), game.getTurn(), this);
		if (_coords.getRealRow() == 0 || _coords.getRealRow() == board->getRow() - 1) _promote();
		_moved = true;
		return true;
	}
	else return false;
}

void Pawn::_promote(){
	//TODO

}

#endif