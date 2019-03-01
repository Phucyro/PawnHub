#ifndef __ALICE__PIECE__HPP__
#define __ALICE__PIECE__HPP__

#include "Coordinate.hpp"
#include "Board.hpp"

class Game;

class AlicePiece{
	private:
	AlicePiece* _convertPiece(Piece* piece){return dynamic_cast<AlicePiece*>(piece);}

	protected :
	bool _2Dimension;

	void _swapDimension(){_2Dimension = !_2Dimension;}
	virtual bool _isPlaceFree(Coordinate place ,Board* board);
	AlicePiece(bool dimension): _2Dimension(dimension){}
	AlicePiece(const AlicePiece& original): _2Dimension(original._2Dimension){}

	public :
	virtual ~AlicePiece() = 0;

	AlicePiece& operator= (const AlicePiece& original){
		_2Dimension = original._2Dimension;
		return *this;
	}

	virtual bool _checkMove(Coordinate end, Board* board, Game& game){
		AlicePiece* pieceToTake = _convertPiece(board->getCase(end));
		// des parentheses? la ligne d'en-dessous est chaud a lire
		return (!pieceToTake) != pieceToTake->getDimension() == getDimension();
	}
	bool getDimension(){return _2Dimension;}
};

#include "Game.hpp"
#endif
