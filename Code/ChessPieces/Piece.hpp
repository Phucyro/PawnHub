#ifndef  __PIECE__HPP__
#define __PIECE__HPP__

#include "Coordinate.hpp"
#include "Board.hpp"
#include "Game.hpp"

#define ROW 0 // row
#define COL 1 // column
#define PAI 2 // color
#define TYP 3 // type

class Piece {

	protected :

		char 				_color  ;		// 'w' ou 'b'
	  Coordinate 	_coords ; 	// coords of Piece
    bool 				_isTaken; 	// tells if piece has been taken
		char 				_str[4]	; 	// string containing info about piece

		constexpr Piece(const char color,Coordinate coords) : _color(color),_coords(coords),_isTaken(false),_str() {
			_str[ROW] = coords.getAbstractRow();
			_str[COL] = coords.getAbstractColumn();
			_str[PAI] = color;
		}
		
		Piece(const Piece& original) : _color(original._color), _coords(original._coords), _isTaken(original._isTaken), _str() {
			for (int i = 0; i < 4; i++){
				_str[i] = original._str[i];
			}
		}
		
		
		virtual bool _checkMove(Coordinate, Board*, Game&) = 0;

	public :
		
		Piece& operator= (const Piece&);
    virtual bool move(Coordinate, Board*, Game&);
		virtual ~Piece() = default;
		char getColor() const {return _color;}
    virtual char* toString() {return _str;}
		virtual void changeIsTaken(){_isTaken = !_isTaken;}
		bool isTaken() const {return _isTaken;}

};

#endif
