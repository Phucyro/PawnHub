#ifndef __ALICE__QUEEN__HPP__
#define __ALICE__QUEEN__HPP__

#include "AlicePiece.hpp"
#include "Queen.hpp"

class AliceQueen: public Queen, public AlicePiece{
	protected:
	Piece* _doMove(Coordinate, Board*,Game&) override;
	void _reverseMove(Coordinate, Board*, Game&, Piece*) override;
	bool _isPlaceFree(Coordinate ,Board*) override;
	
	public:
	AliceQueen(const char color, const char column , const char row) : Queen(color,column,row), AlicePiece(false){}
	AliceQueen(const AliceQueen& original) : Queen(original), AlicePiece(original){}
	virtual ~AliceQueen() = default;
	
	AliceQueen& operator= (const AliceQueen& original){
		this->Queen::operator= (original);
		this->AlicePiece::operator= (original);
		return *this;
	}
	
	bool _checkMove(Coordinate, Board*, Game&) override;
	bool _isMovePossible(Coordinate, Board*, Game&) override;
};

#endif
