#ifndef __ALICE__ROOK__HPP__
#define __ALICE__ROOK__HPP__

#include "AlicePiece.hpp"
#include "Rook.hpp"

class AliceRook: public Rook, public AlicePiece{
	protected:
	Piece* _doMove(Coordinate, Board*,Game&) override;
	void _reverseMove(Coordinate, Board*, Game&, Piece*) override;
	bool _isPlaceFree(Coordinate ,Board*) override;
	
	public:
	AliceRook(const char color, const char column , const char row) : Rook(color,column,row), AlicePiece(false){}
	AliceRook(const AliceRook& original) : Rook(original), AlicePiece(original){}
	virtual ~AliceRook() = default;
	
	AliceRook& operator= (const AliceRook& original){
		this->Rook::operator= (original);
		this->AlicePiece::operator= (original);
		return *this;
	}
	
	bool _checkMove(Coordinate, Board*, Game&) override;
	bool _isMovePossible(Coordinate, Board*, Game&) override;
};

#endif
