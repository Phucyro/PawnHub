#ifndef __ALICE__PAWN__CPP__
#define __ALICE__PAWN__CPP__

#include "AlicePawn.hpp"

Piece* AlicePawn::_doMove(Coordinate end, Board* board, Game& game){
	Piece* takenPiece = this->BasicPawn::_doMove(end, board, game);
	_swapDimension();
	return takenPiece;
}

void AlicePawn::_reverseMove(Coordinate end, Board* board, Game& game, Piece* takenPiece){
	this->BasicPawn::_reverseMove(end, board, game, takenPiece);
	_swapDimension();
}

bool AlicePawn::_isPlaceFree(Coordinate place ,Board* board, bool careOfMoving){
	return this->BasicPawn::_isPlaceFree(place, board, careOfMoving) || this->AlicePiece::_isPlaceFree(place, board);
}

bool AlicePawn::_checkMove(Coordinate end, Board* board, Game& game, bool careOfMoving){
	return this->AlicePiece::_checkMove(end, board, game) && this->BasicPawn::_checkMove(end, board, game, careOfMoving);
}

bool AlicePawn::_isMovePossible(Coordinate end, Board* board, Game& game){
	if (this->BasicPawn::_isMovePossible(end, board, game)){
		_swapDimension();
		return true;
	}
	return false;
}

bool AlicePawn::canMove(Board* board, Game& game){
	int direction = this->getColor() == 'w' ? 1:-1;
	return this->BasicPawn::canMove(board, game) || this->_isMovePossible(0, 2*direction, board, game);
}

void AlicePawn::stopMoving(Game& game, Board* board){
	this->Piece::stopMoving(game, board);
	this->AlicePiece::stopMoving(game);
}

#endif
