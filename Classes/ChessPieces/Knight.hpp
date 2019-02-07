#ifndef KNIGHT_HPP
#define KNIGHT_HPP

class Knight : public ChessPiece {

	public :
	
		constexpr Knight(const char& color, char& x, unsigned& y) noexcept : ChessPiece(color, x, y) {}
		virtual ~Knight() noexcept = default;
		virtual bool checkMove() const = 0; 	//A voir comment on implémente
}

#endif