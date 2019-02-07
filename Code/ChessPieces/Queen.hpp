#ifndef __QUEEN__HPP__ 
#define __QUEEN__HPP__

#include "ChessPiece.hpp"

class Queen : public ChessPiece {

	protected :
		bool _moved;

	public :

		Queen(const char& color, char& x, unsigned& y) noexcept : ChessPiece(color, x, y) {}
		virtual ~Queen() noexcept = default;
		bool hasMoved() const {return _moved;}
		virtual bool checkMove() const = 0; 	//A voir comment on implémente
};

#endif
