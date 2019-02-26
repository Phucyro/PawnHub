#ifndef __ALICE__KNIGHT__CPP__
#define __ALICE__KNIGHT__CPP__

#include "AliceKnight.hpp"

Piece* AliceKnight::_doMove(Coordinate end, Board* board, Game& game){
	this->Knight::_doMove(end, board, game);
	_swapDimension();
}

Piece* AliceKnight::_reverseMove(Coordinate end, Board* board, Game& game){
	this->Knight::_reverseMove(end, board, game);
	_swapDimension();
}

bool AliceKnight::_isPlaceFree(Coordinate place ,Board* board){
	return this->Knight::_isPlaceFree(place, board) || this->AlicePiece::_isPlaceFree(place, board);
}

bool AliceKnight::_checkMove(Coordinate end, Board* board, Game& game){
	return this->AlicePiece::_checkMove(end, board, game) && this->Knight::_checkMove(end, board, game);
}

bool AliceKnight::_isMovePossible(Coordinate end, Board* board, Game& game){
	if (this->Knight::_isMovePossible(end, board, game)){
		_swapDimension();
		return true;
	}
	return false;
}

#endif
