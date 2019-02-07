#ifndef ROOK_HPP
#define ROOK_HPP

class Rook : public ChessPiece {

	protected :

		bool _moved;

	public :

		constexpr Rook(const char& color, char& x, unsigned& y) noexcept : ChessPiece(color, x, y) {}
		virtual ~Rook() noexcept = default;
		bool hasMoved() const {return _moved;}
		virtual bool checkMove() const = 0; 	//A voir comment on implémente
}