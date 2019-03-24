#ifndef __BOARD__HPP__
#define __BOARD__HPP__

#include <stdexcept>
#include "Coordinate.hpp"

class Piece;
class TestBoard;

class Board
{
	protected:
	unsigned _column;
	unsigned _row;
	Piece*** _state;
	virtual void _copyState(const Board&);
	virtual void _delState();

	public:
	Board(unsigned = 8, unsigned = 8);
	Board(const Board&);
	Board(Board&&);
	virtual ~Board();

	Board& operator= (const Board&);
	Board& operator= (Board&&);

	unsigned getColumn() const {return _column;}
	unsigned getRow() const {return _row;}
	Piece* getCase(Coordinate) const;
	char getCaseColor(Coordinate place) const{
		if (!isInBoard(place)) throw std::out_of_range("the board is to small");
		return place.getRealRow() + place.getRealColumn() % 2 ? 'w':'b';
	}
	Piece* movePiece(Coordinate, Coordinate);
	void setCase(Coordinate, Piece*);
	bool isInBoard(Coordinate place) const {return place.getRealRow() < _row && place.getRealColumn() < _column;}
	virtual bool isCaseEmpty(Coordinate place) const {return !_state[place.getRealColumn()][place.getRealRow()];}

	friend TestBoard;
};

#include"Piece.hpp"

#endif
