#ifndef __PAWN__HPP__ 
#define __PAWN__HPP__

#include "Piece.hpp"

class Pawn : public Piece {

	protected :
		bool _moved;

	public :

		Pawn(const char& color, char& x, unsigned& y) noexcept : Piece(color, x, y) {}
		virtual ~Pawn() noexcept = default;
		bool hasMoved() const {return _moved;}
		virtual bool checkMove() const = 0; 	//A voir comment on implémente
};

#endif
