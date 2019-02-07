#ifndef CHESSPIECE_HPP
#define CHESSPIECE_HPP
#endif

class ChessPiece {

	protected :

		char _color;	//'w' ou 'b'
		char _x;		//a -> h
		unsigned _y;	//1 -> 8

		constexpr ChessPiece(const char color,char  x,unsigned y) noexcept : _color(color), _x(x), _y(y) {}

	public :

		virtual bool checkMove() = 0;
		virtual ~ChessPiece() noexcept {}
		char getColor() const {return _color;}
};
