#ifndef __ALICE__QUEEN__CPP__
#define __ALICE__QUEEN__CPP__

#include "AliceQueen.hpp"

Piece* AliceQueen::_doMove(Coordinate end, Board* board, Game& game){
	this->Queen::_doMove(end, board, game);
	_swapDimension();
}

Piece* AliceQueen::_reverseMove(Coordinate end, Board* board, Game& game){
	this->Queen::_reverseMove(end, board, game);
	_swapDimension();
}

bool AliceQueen::_isPlaceFree(Coordinate place ,Board* board){
	return this->Queen::_isPlaceFree(place, board) || this->AlicePiece::_isPlaceFree(place, board);
}

bool AliceQueen::_checkMove(Coordinate end, Board* board, Game& game){
	return this->AlicePiece::_checkMove(end, board, game) && this->Queen::_checkMove(end, board, game);
}

bool AliceQueen::_isMovePossible(Coordinate end, Board* board, Game& game){
	if (this->Queen::_isMovePossible(end, board, game)){
		_swapDimension();
		return true;
	}
	return false;
}

#endif
