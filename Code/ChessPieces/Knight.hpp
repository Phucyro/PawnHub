#ifndef __KNIGHT__HPP__
#define __KNIGHT__HPP__
#endif

#include "ChessPiece.hpp"

class Knight : public ChessPiece {

	protected :
		bool _moved;

	public :

		Knight(const char& color, char& x, unsigned& y) noexcept : ChessPiece(color, x, y) {}
		virtual ~Knight() noexcept = default;
		bool hasMoved() const {return _moved;}
		virtual bool checkMove() const = 0; 	//A voir comment on implémente
};
