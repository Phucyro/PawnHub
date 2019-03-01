#ifndef __ALICE__BISHOP__HPP__
#define __ALICE__BISHOP__HPP__

#include "AlicePiece.hpp"
#include "Bishop.hpp"

class AliceBishop: public Bishop, public AlicePiece{
	protected:
	Piece* _doMove(Coordinate, Board*,Game&) override;
	void _reverseMove(Coordinate, Board*, Game&, Piece*) override;
	bool _isPlaceFree(Coordinate ,Board*) override;
	
	public:
	AliceBishop(const char color, const char column , const char row) : Bishop(color,column,row), AlicePiece(false){}
	AliceBishop(const AliceBishop& original) : Bishop(original), AlicePiece(original){}
	virtual ~AliceBishop() = default;
	
	AliceBishop& operator= (const AliceBishop& original){
		this->Bishop::operator= (original);
		this->AlicePiece::operator= (original);
		return *this;
	}
	
	bool _checkMove(Coordinate, Board*, Game&) override;
	bool _isMovePossible(Coordinate, Board*, Game&) override;
};

#endif
