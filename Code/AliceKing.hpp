#ifndef __ALICE__KING__HPP__
#define __ALICE__KING__HPP__

#include "AlicePiece.hpp"
#include "King.hpp"

class AliceKing: public King, public AlicePiece{
	protected:
	bool _reverseEnable;
	
	Piece* _doMove(Coordinate, Board*,Game&) override;
	void _reverseMove(Coordinate, Board*, Game&, Piece*) override;
	bool _isPlaceFree(Coordinate ,Board*, bool = true) override;
	
	public:
	AliceKing(const char color, const char column , const char row) : King(color,column,row), AlicePiece(false), _reverseEnable(true){}
	AliceKing(const AliceKing& original) : King(original), AlicePiece(original){}
	virtual ~AliceKing() = default;
	
	AliceKing& operator= (const AliceKing& original){
		this->King::operator= (original);
		this->AlicePiece::operator= (original);
		return *this;
	}
	
	bool _checkMove(Coordinate, Board*, Game&, bool = true) override;
	bool _isMovePossible(int column, int row, Board* board, Game& game) override {return Piece::_isMovePossible(column, row, board, game);}
	bool _isMovePossible(Coordinate, Board*, Game&) override;
	bool move(Coordinate, Board*, Game&) override;
	void stopMoving(Game& game, Board*) override;
};

#endif

