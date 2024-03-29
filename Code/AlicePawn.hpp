#ifndef __ALICE__PAWN__HPP__
#define __ALICE__PAWN__HPP__

#include "AlicePiece.hpp"
#include "BasicPawn.hpp"

class AlicePawn: public BasicPawn, public AlicePiece{
	protected:
	Piece* _doMove(Coordinate, Board*,Game&) override;
	void _reverseMove(Coordinate, Board*, Game&, Piece*) override;
	bool _isPlaceFree(Coordinate ,Board*, bool = true) override;
	
	public:
	AlicePawn(const char color, const char column , const char row) : BasicPawn(color,column,row), AlicePiece(false){}
	AlicePawn(const AlicePawn& original) : BasicPawn(original), AlicePiece(original){}
	virtual ~AlicePawn() = default;
	
	AlicePawn& operator= (const AlicePawn& original){
		this->BasicPawn::operator= (original);
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
