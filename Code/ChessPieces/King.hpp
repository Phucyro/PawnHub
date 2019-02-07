#ifndef CHESSPIECE_HPP
#define CHESSPIECE_HPP
#endif

#include "ChessPiece.hpp"

class King : public ChessPiece {

	protected :
		bool _moved;

	public :

	    King(const char& color, char& x, unsigned& y) noexcept : ChessPiece(color, x, y) {}
		virtual ~King() noexcept = default;
		bool hasMoved() const {return _moved;}
		virtual bool checkMove() const = 0; 	//A voir comment on implémente
};
