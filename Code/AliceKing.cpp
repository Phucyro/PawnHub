#ifndef __ALICE__KING__CPP__
#define __ALICE__KING__CPP__

#include "AliceKing.hpp"

Piece* AliceKing::_doMove(Coordinate end, Board* board, Game& game){
	Piece* takenPiece = this->King::_doMove(end, board, game);
	_swapDimension();
	return takenPiece;
}

void AliceKing::_reverseMove(Coordinate end, Board* board, Game& game, Piece* takenPiece){
	this->King::_reverseMove(end, board, game, takenPiece);
	_swapDimension();
}

bool AliceKing::_isPlaceFree(Coordinate place ,Board* board){
	return this->King::_isPlaceFree(place, board) || this->AlicePiece::_isPlaceFree(place, board);
}

bool AliceKing::_checkMove(Coordinate end, Board* board, Game& game){
	return this->AlicePiece::_checkMove(end, board, game) && this->King::_checkMove(end, board, game);
}

bool AliceKing::_isMovePossible(Coordinate end, Board* board, Game& game){
	if (this->King::_isMovePossible(end, board, game)){
		_swapDimension();
		return true;
	}
	return false;
}

#endif
