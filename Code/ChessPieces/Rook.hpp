#ifndef __ROOK__HPP__
#define __ROOK__HPP__ 
#endif

#include "ChessPiece.hpp"

class Rook : public ChessPiece {

	protected :
		bool _moved;

	public :

		Rook(const char& color, char& x, unsigned& y) noexcept : ChessPiece(color, x, y) {}
		virtual ~Rook() noexcept = default;
		bool hasMoved() const {return _moved;}
		virtual bool checkMove() const = 0; 	//A voir comment on implémente
};
