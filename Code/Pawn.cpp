#ifndef __PAWN__CPP__
#define __PAWN__CPP__

#include <cmath>
#include "Pawn.hpp"

Pawn::~Pawn() noexcept {
	delete _ghost;
}

Pawn::Pawn(const Pawn& original) noexcept : BasicPawn(original), _ghost(nullptr), _ghostPlacement(original._ghostPlacement) {
	_ghost = new GhostPawn(*(original._ghost));
}

Pawn& Pawn::operator= (const Pawn& original){
	this->BasicPawn::operator= (original);
	_ghost = new GhostPawn(original._ghost);
	_ghostPlacement = original._ghostPlacement;
	return *this;
}

Pawn& Pawn::operator= (Pawn&& original){
	this->BasicPawn::operator= (original);
	_ghost = original._ghost;
	original._ghost = nullptr;
	_ghostPlacement = original._ghostPlacement;
	return *this;
}

bool Pawn::_checkMove(Coordinate end, Board* board, Game& game){
	int rowMove = int(end.getRealRow()) - int(_coords.getRealRow());
	int columnMove = int(end.getRealColumn()) - int(_coords.getRealColumn());
	int colorDirection = _color == 'w' ? 1 : -1;
	int rowDirection = rowMove ? rowMove/std::abs(rowMove) : 0;
	GhostPawn* ghost =  dynamic_cast<GhostPawn*>(board->getCase(end));
	return (ghost && ghost->getColor() != this->getColor() && ghost->isActive(game.getTurn()) && std::abs(rowMove) == 1 && rowDirection == colorDirection && std::abs(columnMove) == 1) || this->BasicPawn::_checkMove(end, board, game);
}

bool Pawn::move(Coordinate end, Board* board, Game& game){
	int rowMove = int(end.getRealRow()) - int(_coords.getRealRow());
	int rowDirection = rowMove ? rowMove/std::abs(rowMove) : 0;
	if (this->BasicPawn::move(end, board, game)){
		if (std::abs(rowMove) == 2) {
			_ghost = new GhostPawn(getColor(), Coordinate(_coords.getRealColumn(), _coords.getRealRow() - 1*rowDirection), game.getTurn(), this);
			board->setCase(Coordinate(_coords.getRealColumn(), _coords.getRealRow() - 1*rowDirection), _ghost);
		}
		return true;
	}
	return false;
}

void Pawn::startMovingTo(Game& game, Coordinate end){
	this->BasicPawn::startMovingTo(game, end);
	int rowMove = int(end.getRealRow()) - int(_coords.getRealRow());
	int rowDirection = rowMove ? rowMove/std::abs(rowMove) : 0;
	if (std::abs(rowMove) == 2) _ghostPlacement = rowDirection;
}

void Pawn::stopMoving(Game& game, Board* board){
	this->BasicPawn::stopMoving(game, board);
	if(_ghostPlacement){
		_ghost = new GhostPawn(getColor(), Coordinate(_coords.getRealColumn(), _coords.getRealRow() - 1*_ghostPlacement), game.getTurn(), this, 10000);
		board->setCase(Coordinate(_coords.getRealColumn(), _coords.getRealRow() - 1*_ghostPlacement), _ghost);
		_ghostPlacement = 0;
	}
}

#endif
