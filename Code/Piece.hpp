#ifndef  __PIECE__HPP__
#define __PIECE__HPP__

#include "Coordinate.hpp"
#include "Board.hpp"

class Game;
#define TYP 0 // type
#define ROW 2 // row
#define COL 1 // column


class Piece {

	protected :

		char 				_color  ;		// 'w' ou 'b'
	  Coordinate 	_coords ; 	// coords of Piece
    bool 				_isTaken; 	// tells if piece has been taken
		char 				_str[4]	; 	// string containing info about piece

		Piece(const char color, const char column, const char row) : _color(color), _coords(column, row),_isTaken(false),_str(){
			_str[ROW] = _coords.getAbstractRow();
			_str[COL] = _coords.getAbstractColumn();
			_str[3] = '\0';
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

		Piece(const Piece* original) : _color(original->_color), _coords(original->_coords), _isTaken(original->_isTaken), _str() {
			for (int i = 0; i < 4; i++){
				_str[i] = original->_str[i];
			}
		}

		virtual Piece* _doMove(Coordinate, Board*,Game&);
		virtual void _reverseMove(Coordinate, Board*, Game&, Piece*);
		virtual bool _isPlaceFree(Coordinate place ,Board* board)
		{
			Piece* piece = board->getCase(place);
			return (!piece) || piece->_str[TYP] == 'g';
		}
		void _setCoordinate(Coordinate newCoords){
			_coords = newCoords;
			_str[COL] = _coords.getAbstractColumn();
			_str[ROW] = _coords.getAbstractRow();
		}

	public :
		Piece& operator= (const Piece&);
		virtual bool hasMoved() const = 0;
    virtual bool move(Coordinate, Board*, Game&);
    virtual bool _checkMove(Coordinate, Board*, Game&) = 0;
    virtual bool canMove(Board*, Game&) = 0;
		virtual ~Piece() noexcept {}
		char getType() const {return _str[TYP];}
		Coordinate getCoord() const {return _coords;}
		char getColor() const {return _color;}
		char getOpenentColor() const {return _color == 'w' ? 'b':'w';}
		unsigned getRow() {return _coords.getRealRow();}
		unsigned getColumn() {return _coords.getRealColumn();}
    virtual char* toString() {return _str;}
		void changeIsTaken(){_isTaken = !_isTaken;}
		virtual void changeIsTaken(unsigned turn, Piece*, Board*){_isTaken = !_isTaken;}
		bool isTaken() const {return _isTaken;}
		virtual bool _isMovePossible(Coordinate, Board*, Game&);
		bool _isMovePossible(int column, int row, Board* board, Game& game){return this->_isMovePossible(Coordinate(int (this->getColumn()) + column, int(this->getRow()) + row), board, game);}
};
#include "Game.hpp"
#endif
