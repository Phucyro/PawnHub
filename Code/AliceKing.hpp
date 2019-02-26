#ifndef __ALICE__KING__HPP__
#define __ALICE__KING__HPP__

#include "AlicePiece.hpp"
#include "King.hpp"

class AliceKing: public King, public AlicePiece{
	protected:
	Piece* _doMove(Coordinate, Board*,Game&) override;
	void _reverseMove(Coordinate, Board*, Game&, Piece*) override;
	bool _isPlaceFree(Coordinate ,Board*) override;
	
	public:
	AliceKing(const char color, const char column , const char row) : King(color,column,row), AlicePiece(false){}
	AliceKing(const AliceKing& original) : King(original), AlicePiece(original){}
	virtual ~AliceKing() = default;
	
	AliceKing& operator= (const AliceKing& original){
		this->King::operator= (original);
		this->AlicePiece::operator= (original);
		return *this;
	}
	
	bool _checkMove(Coordinate, Board*, Game&) override;
	bool _isMovePossible(Coordinate, Board*, Game&) override;
};

#endif

