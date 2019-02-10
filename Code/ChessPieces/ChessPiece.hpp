#ifdef  __CHESSPIECE__HPP__
#define __CHESSPIECE__HPP__

#include "Coordinate.hpp"
#include "Board.hpp"
#include "Game.hpp"

#define ROW 0 // row
#define COL 1 // column
#define PAI 2 // color
#define TYP 3 // type

class ChessPiece {

	protected :

		char 				_color  ;		// 'w' ou 'b'
	  Coordinate 	_coords ; 	// coords of Piece
    bool 				_isTaken; 	// tells if piece has been taken
		char 				_str[4]	; 	// string containing info about piece

		constexpr ChessPiece(const char color,Coordinate coords) : _color(color),_coords(coords),_isTaken(false),_str(char[4]) {
			_str[ROW] = coords.getAbstractRow();
			_str[COL] = coords.getAbstractColumn();
			_str[PAI] = color;
		}
		
		ChessPiece(const ChessPiece& original) : _color(original._color), _coords(original._coords), _isTaken(original._isTaken), _str(char[4]) {
			for (int i = 0; i < 4; i++){
				_str[i] = original._str[i];
			}
		}
		
		ChessPiece(ChessPiece&& original) : _color(original._color), _coords(original._coords), _isTaken(original._isTaken), _str(original._str) {
			original._str = nullptr;
		}
		
		
		
		virtual bool _checkMove() = 0;

	public :
		
		ChessPiece& operator= (const ChessPiece&);
		ChessPiece& operator= (ChessPiece&&);
    bool move(Coordinate, Board*, Game);
		virtual ~ChessPiece() = default;
		char getColor() const {return _color;}
    virtual char[]  toString {return _str}
		virtual void changeIsTaken(){_isTaken = !_isTaken;}
		bool isTaken() const {return _isTaken;}

};

#endif
