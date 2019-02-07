#ifndef __BOARD__HPP__
#define __BOARD__HPP__

#include"Coordinate.hpp"
#include"Piece.hpp" 

class Board
{
	private:
	unsigned _column;
	unsigned _row;
	Piece*** _state;
	void _copyState(const Board&);
	void _delState();
	
	public:
	Board(unsigned = 8, unsigned = 8);
	Board(const Board&);
	Board(Board&&);
	~Board();
	
	Board& operator= (const Board&);
	Board& operator= (Board&&);
	
	unsigned getColumn() const {return _column;}
	unsigned getRow() const {return _row;}
	Piece* getCase(Coordinate&);
	Piece* movePiece(Coordinate&, Coordinate&);
	void setCase(Coordinate&, Piece*);
};

#endif
