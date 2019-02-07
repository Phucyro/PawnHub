#ifndef CHESSPIECE_HPP
#define CHESSPIECE_HPP
#endif

#include "ChessPiece.hpp"

class Pawn : public ChessPiece {

	protected :
		bool _moved;

	public :

		Pawn(const char& color, char& x, unsigned& y) noexcept : ChessPiece(color, x, y) {}
		virtual ~Pawn() noexcept = default;
		bool hasMoved() const {return _moved;}
		virtual bool checkMove() const = 0; 	//A voir comment on implémente
};
