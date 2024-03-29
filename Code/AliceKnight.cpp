#ifndef __ALICE__KNIGHT__CPP__
#define __ALICE__KNIGHT__CPP__

#include "AliceKnight.hpp"

Piece* AliceKnight::_doMove(Coordinate end, Board* board, Game& game){
	Piece* takenPiece = this->Knight::_doMove(end, board, game);
	_swapDimension();
	return takenPiece;
}

void AliceKnight::_reverseMove(Coordinate end, Board* board, Game& game, Piece* takenPiece){
	this->Knight::_reverseMove(end, board, game, takenPiece);
	_swapDimension();
}

bool AliceKnight::_isPlaceFree(Coordinate place ,Board* board, bool careOfMoving){
	return this->Knight::_isPlaceFree(place, board, careOfMoving) || this->AlicePiece::_isPlaceFree(place, board);
}

bool AliceKnight::_checkMove(Coordinate end, Board* board, Game& game, bool careOfMoving){
	return this->AlicePiece::_checkMove(end, board, game) && this->Knight::_checkMove(end, board, game, careOfMoving);
}

bool AliceKnight::_isMovePossible(Coordinate end, Board* board, Game& game){
	if (this->Knight::_isMovePossible(end, board, game)){
		_swapDimension();
		return true;
	}
	return false;
}

void AliceKnight::stopMoving(Game& game, Board* board){
	this->Piece::stopMoving(game, board);
	this->AlicePiece::stopMoving(game);
}

#endif
