#ifndef __KNIGHT__HPP__
#define __KNIGHT__HPP__

#include "Piece.hpp"

class Knight : public Piece {

	protected :
		bool _moved;

	public :

		Knight(const char& color, char& x, unsigned& y) noexcept : Piece(color, x, y) {}
		virtual ~Knight() noexcept = default;
		bool hasMoved() const {return _moved;}
		virtual bool checkMove() const = 0; 	//A voir comment on implémente
};

#endif
