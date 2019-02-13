#ifndef  __PIECE__HPP__
#define __PIECE__HPP__

#include "Coordinate.hpp"
#include "Board.hpp"
#include "Game.hpp"

#define TYP 0 // type
#define ROW 1 // row
#define COL 2 // column


class Piece {

	protected :

		char 				_color  ;		// 'w' ou 'b'
	  Coordinate 	_coords ; 	// coords of Piece
    bool 				_isTaken; 	// tells if piece has been taken
		char 				_str[3]	; 	// string containing info about piece

		constexpr Piece(const char color, const char column, const char row) : _color(color), _coords(column, row),_isTaken(false),_str(){
			_str[ROW] = _coords.getAbstractRow();
			_str[COL] = _coords.getAbstractColumn();
		}

		Piece(const char color,Coordinate coords) : _color(color),_coords(coords),_isTaken(false),_str() {
			_str[ROW] = coords.getAbstractRow();
			_str[COL] = coords.getAbstractColumn();
		}

		Piece(const Piece& original) : _color(original._color), _coords(original._coords), _isTaken(original._isTaken), _str() {
			for (int i = 0; i < 4; i++){
				_str[i] = original._str[i];
			}
		}

		virtual bool _checkMove(Coordinate, Board*, Game&) = 0;
		virtual Piece* _doMove(Coordinate, Board*,Game&);
		virtual void _reverseMove(Coordinate, Board*, Game&, Piece*);
		inline bool _isPlaceFree(Coordinate place ,Board* board){Piece* piece = board->getCase(place); return (!piece) || piece->_str[TYP] == 'g';}

	public :
		Piece& operator= (const Piece&);
    virtual bool move(Coordinate, Board*, Game&);
		virtual ~Piece() = default;
		char getColor() const {return _color;}
    virtual char* toString() {return _str;}
		virtual void changeIsTaken(unsigned turn, Piece*, Board*){_isTaken = !_isTaken;}
		bool isTaken() const {return _isTaken;}

};

#endif
