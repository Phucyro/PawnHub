#ifndef __ALICE__PIECE__CPP__
#define __ALICE__PIECE__CPP__

#include "AlicePiece.hpp"

bool AlicePiece::_isPlaceFree(Coordinate place ,Board* board){
	AlicePiece* pieceToTake = _convertPiece(board->getCase(place));
	return (!pieceToTake) || pieceToTake->getDimension() != getDimension();
}
AlicePiece::~AlicePiece(){}

bool AlicePiece::_canMoveInLine(int columnDirection, int rowDirection, Board* board, Game& game){
	int column = columnDirection, row = rowDirection;
	while (board->isInBoard(Coordinate(column, row))){
		if (this->_isMovePossible(column, row, board, game)) return true;
		column += columnDirection;
		row += rowDirection;
	}
	return false;
}

void AlicePiece::stopMoving(Game& game){
	_swapDimension();
}

#endif
