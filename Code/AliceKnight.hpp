#ifndef __ALICE__KNIGHT__HPP__
#define __ALICE__KNIGHT__HPP__

#include "AlicePiece.hpp"
#include "Knight.hpp"
#include "AlicePawn.hpp"

class AliceKnight: public Knight, public AlicePiece{
	protected:
	Piece* _doMove(Coordinate, Board*,Game&) override;
	void _reverseMove(Coordinate, Board*, Game&, Piece*) override;
	bool _isPlaceFree(Coordinate ,Board*) override;
	
	public:
	AliceKnight(const char color, const char column , const char row) : Knight(color,column,row), AlicePiece(false){}
	AliceKnight(const AliceKnight& original) : Knight(original), AlicePiece(original){}
	explicit AliceKnight(const AlicePawn& original) : Knight(original), AlicePiece(original){}
	virtual ~AliceKnight() = default;
	
	AliceKnight& operator= (const AliceKnight& original){
		this->Knight::operator= (original);
		this->AlicePiece::operator= (original);
		return *this;
	}
	
	bool _checkMove(Coordinate, Board*, Game&) override;
	bool _isMovePossible(int column, int row, Board* board, Game& game) override {return Piece::_isMovePossible(column, row, board, game);}
	bool _isMovePossible(Coordinate, Board*, Game&) override;
};

#endif

