#ifndef __KING__HPP__
#define __KING__HPP__

#include "Piece.hpp"

class King : public Piece {

	protected :
		bool _moved;

	public :

	    King(const char& color, char& x, unsigned& y) noexcept : Piece(color, x, y) {}
		virtual ~King() noexcept = default;
		bool hasMoved() const {return _moved;}
		virtual bool checkMove() const = 0; 	//A voir comment on implémente
};

#endif
