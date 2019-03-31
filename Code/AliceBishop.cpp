#ifndef __ALICE__BISHOP__CPP__
#define __ALICE__BISHOP__CPP__

#include "AliceBishop.hpp"

Piece* AliceBishop::_doMove(Coordinate end, Board* board, Game& game){
	Piece* takenPiece = this->Bishop::_doMove(end, board, game);
	_swapDimension();
	return takenPiece;
}

void AliceBishop::_reverseMove(Coordinate end, Board* board, Game& game, Piece* takenPiece){
	this->Bishop::_reverseMove(end, board, game, takenPiece);
	_swapDimension();
}

bool AliceBishop::_isPlaceFree(Coordinate place ,Board* board, bool careOfMoving){
	return this->Bishop::_isPlaceFree(place, board, careOfMoving) || this->AlicePiece::_isPlaceFree(place, board);
}

bool AliceBishop::_checkMove(Coordinate end, Board* board, Game& game, bool careOfMoving){
	return this->AlicePiece::_checkMove(end, board, game) && this->Bishop::_checkMove(end, board, game, careOfMoving);
}

bool AliceBishop::_isMovePossible(Coordinate end, Board* board, Game& game){
	if (this->Bishop::_isMovePossible(end, board, game)){
		_swapDimension();
		return true;
	}
	return false;
}

bool AliceBishop::canMove(Board* board, Game& game){
	if (this->_canMoveInLine(1, 1, board, game)) return true;
	if (this->_canMoveInLine(-1, 1, board, game)) return true;
	if (this->_canMoveInLine(1, -1, board, game)) return true;
	if (this->_canMoveInLine(-1, -1, board, game)) return true;
	return false;
}

void AliceBishop::stopMoving(Game& game, Board* board){
	this->Piece::stopMoving(game, board);
	this->AlicePiece::stopMoving(game);
}

#endif
