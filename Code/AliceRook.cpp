#ifndef __ALICE__ROOK__CPP__
#define __ALICE__ROOK__CPP__

#include "AliceRook.hpp"

Piece* AliceRook::_doMove(Coordinate end, Board* board, Game& game){
	Piece* takenPiece = this->Rook::_doMove(end, board, game);
	_swapDimension();
	return takenPiece;
}

void AliceRook::_reverseMove(Coordinate end, Board* board, Game& game, Piece* takenPiece){
	this->Rook::_reverseMove(end, board, game, takenPiece);
	_swapDimension();
}

bool AliceRook::_isPlaceFree(Coordinate place ,Board* board){
	return this->Rook::_isPlaceFree(place, board) || this->AlicePiece::_isPlaceFree(place, board);
}

bool AliceRook::_checkMove(Coordinate end, Board* board, Game& game){
	return this->AlicePiece::_checkMove(end, board, game) && this->Rook::_checkMove(end, board, game);
}

bool AliceRook::_isMovePossible(Coordinate end, Board* board, Game& game){
	if (this->Rook::_isMovePossible(end, board, game)){
		_swapDimension();
		return true;
	}
	return false;
}

bool AliceRook::canMove(Board* board, Game& game){
	if (this->_canMoveInLine(0, 1, board, game)) return true;
	if (this->_canMoveInLine(1, 0, board, game)) return true;
	if (this->_canMoveInLine(-1, 0, board, game)) return true;
	if (this->_canMoveInLine(0, -1, board, game)) return true;
	return false;
}

#endif
