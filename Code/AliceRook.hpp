#ifndef __ALICE__ROOK__HPP__
#define __ALICE__ROOK__HPP__

#include "AlicePiece.hpp"
#include "Rook.hpp"
#include "AlicePawn.hpp"

class AliceRook: public Rook, public AlicePiece{
	protected:
	Piece* _doMove(Coordinate, Board*,Game&) override;
	void _reverseMove(Coordinate, Board*, Game&, Piece*) override;
	bool _isPlaceFree(Coordinate ,Board*, bool = true) override;
	
	public:
	AliceRook(const char color, const char column , const char row) : Rook(color,column,row), AlicePiece(false){}
	AliceRook(const AliceRook& original) : Rook(original), AlicePiece(original){}
	explicit AliceRook(const AlicePawn& original) : Rook(original), AlicePiece(original){}
	virtual ~AliceRook() = default;
	
	AliceRook& operator= (const AliceRook& original){
		this->Rook::operator= (original);
		this->AlicePiece::operator= (original);
		return *this;
	}
	
	bool _checkMove(Coordinate, Board*, Game&, bool = true) override;
	bool _isMovePossible(int column, int row, Board* board, Game& game) override {return Piece::_isMovePossible(column, row, board, game);}
	bool _isMovePossible(Coordinate, Board*, Game&) override;
	bool canMove(Board*, Game&) override;
	void stopMoving(Game& game, Board*) override;
};

#endif
