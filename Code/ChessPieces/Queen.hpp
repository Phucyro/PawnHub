#ifndef __QUEEN__HPP__ 
#define __QUEEN__HPP__

#include "Piece.hpp"

class Queen : public Piece {

	protected :
		bool _moved;

	public :

		Queen(const char& color, char& x, unsigned& y) noexcept : Piece(color, x, y) {}
		virtual ~Queen() noexcept = default;
		bool hasMoved() const {return _moved;}
		virtual bool checkMove() const = 0; 	//A voir comment on implémente
};

#endif
