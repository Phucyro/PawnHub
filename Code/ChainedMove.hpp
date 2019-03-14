#ifndef __CHAINED__MOVE__HPP__
#define __CHAINED__MOVE__HPP__

#include <queue>
#include <iterator>
#include <string>
#include <cmath>
#include "Piece.hpp"
#include "Coordinate.hpp"
#include "Board.hpp"

class ChainedMove{
	private:
	Piece* _movingPiece;
	std::queue<Coordinate> _moves;
	Coordinate _currentMove;
	unsigned _moment;
	
	public:
	ChainedMove(Piece*, Coordinate);
	ChainedMove(const ChainedMove&) = default;
	~ChainedMove(){_movingPiece = nullptr;}
	
	ChainedMove& operator= (const ChainedMove&) = default;
	
	void setMoment(unsigned moment){_moment = moment;}
	unsigned getMoment() const {return _moment;}
	Piece* getPiece() const {return _movingPiece;}
	bool isEmpty() const {return _moves.empty();}
	Coordinate nextMove();
};

#endif
