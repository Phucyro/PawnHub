#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "Knight.hpp"

class Bishop : public ChessPiece {

	public :
	
		constexpr Bishop(const char& color, char& x, unsigned& y) noexcept : ChessPiece(color, x, y) {}
		virtual ~Bishop() noexcept = default;
		virtual bool checkMove() const = 0; 	//A voir comment on implémente
}

#endif