#ifndef __ALICE__QUEEN__HPP__
#define __ALICE__QUEEN__HPP__

#include "AlicePiece.hpp"
#include "Queen.hpp"
#include "AlicePawn.hpp"

class AliceQueen: public Queen, public AlicePiece{
	protected:
	Piece* _doMove(Coordinate, Board*,Game&) override;
	void _reverseMove(Coordinate, Board*, Game&, Piece*) override;
	bool _isPlaceFree(Coordinate ,Board*, bool = true) override;
	
	public:
	AliceQueen(const char color, const char column , const char row) : Queen(color,column,row), AlicePiece(false){}
	AliceQueen(const AliceQueen& original) : Queen(original), AlicePiece(original){}
	explicit AliceQueen(const AlicePawn& original) : Queen(original), AlicePiece(original){}
	virtual ~AliceQueen() = default;
	
	AliceQueen& operator= (const AliceQueen& original){
		this->Queen::operator= (original);
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
