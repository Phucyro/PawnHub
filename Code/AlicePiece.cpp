#ifndef __ALICE__PIECE__CPP__
#define __ALICE__PIECE__CPP__

#include "AlicePiece.hpp"

bool AlicePiece::_isPlaceFree(Coordinate place ,Board* board){
	AlicePiece* pieceToTake = _convertPiece(board->getCase(place));
	return (!pieceToTake) || pieceToTake->getDimension() != getDimension();
}
AlicePiece::~AlicePiece(){}

#endif
