#ifndef __ALICE__PAWN__HPP__
#define __ALICE__PAWN__HPP__

#include "AlicePiece.hpp"
#include "BasicPawn.hpp"

class AlicePawn: public BasicPawn, public AlicePiece{
	protected:
	Piece* _doMove(Coordinate, Board*,Game&) override;
	void _reverseMove(Coordinate, Board*, Game&, Piece*) override;
	bool _isPlaceFree(Coordinate ,Board*) override;
	
	public:
	AlicePawn(const char color, const char column , const char row) : BasicPawn(color,column,row), AlicePiece(false){}
	AlicePawn(const AlicePawn& original) : BasicPawn(original), AlicePiece(original){}
	virtual ~AlicePawn() = default;
	
	AlicePawn& operator= (const AlicePawn& original){
		this->BasicPawn::operator= (original);
		this->AlicePiece::operator= (original);
		return *this;
	}
	
	bool _checkMove(Coordinate, Board*, Game&) override;
	bool _isMovePossible(Coordinate, Board*, Game&) override;
};

#endif
