#ifndef __ROOK__HPP__
#define __ROOK__HPP__ 

#include "Piece.hpp"

class Rook : public Piece {

	protected :
		bool _moved;

	public :

		Rook(const char& color, char& x, unsigned& y) noexcept : Piece(color, x, y) {}
		virtual ~Rook() noexcept = default;
		bool hasMoved() const {return _moved;}
		virtual bool checkMove() const = 0; 	//A voir comment on implémente
};

#endif
