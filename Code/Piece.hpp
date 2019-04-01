#ifndef  __PIECE__HPP__
#define __PIECE__HPP__

#include "Coordinate.hpp"
#include "RealTimeBoard.hpp"
#include "Game.hpp"

#define TYP 0 // type
#define ROW 2 // row
#define COL 1 // column
#define COOLDOWN_TIME 10000 //milisecond


class Piece {

	protected :

		char 				_color  			;		// 'w' ou 'b'
	  Coordinate 	_coords 			; 	// coords of Piece
	  Coordinate	_dest					;
	  Coordinate	_start				;
    bool 				_isTaken			; 	// tells if piece has been taken
		char 				_str[4]				; 	// string containing info about piece
		unsigned 		_movementStart;
		unsigned	 	_lastMoveEnd	;
		bool 				_isMoving			;

		Piece(const char color, const char column, const char row) : _color(color), _coords(column, row), _dest(), _isTaken(false),_str(),_movementStart(0),_lastMoveEnd(0),_isMoving(false){
			_str[ROW] = _coords.getAbstractRow();
			_str[COL] = _coords.getAbstractColumn();
			_str[3] = '\0';
		}

		Piece(const char color,Coordinate coords) : _color(color),_coords(coords), _dest(), _isTaken(false),_str(),_movementStart(0),_lastMoveEnd(0),_isMoving(false) {
			_str[ROW] = coords.getAbstractRow();
			_str[COL] = coords.getAbstractColumn();
		}

		Piece(const Piece& original) : _color(original._color), _coords(original._coords), _dest(original._dest), _isTaken(original._isTaken), _str(), _movementStart(original._movementStart), _lastMoveEnd(original._lastMoveEnd), _isMoving(original._isMoving){
			for (int i = 0; i < 4; i++){
				_str[i] = original._str[i];
			}
		}

		Piece(const Piece* original) : _color(original->_color), _coords(original->_coords), _isTaken(original->_isTaken), _dest(original->_dest), _str(), _movementStart(original->_movementStart), _lastMoveEnd(original->_lastMoveEnd), _isMoving(original->_isMoving) {
			for (int i = 0; i < 4; i++){
				_str[i] = original->_str[i];
			}
		}

		virtual Piece* _doMove(Coordinate, Board*,Game&);
		virtual void _reverseMove(Coordinate, Board*, Game&, Piece*);
		virtual bool _isPlaceFree(Coordinate place ,Board* board, bool careOfMoving = true)
		{
			if (board->isCaseEmpty(place)) return true;
			Piece* piece = board->getCase(place);
			return piece && (piece->_str[TYP] == 'g' || (piece->_isMoving && careOfMoving));
		}

	public :
		Piece& operator= (const Piece&);
		virtual bool hasMoved() const = 0;
    virtual bool move(Coordinate, Board*, Game&);
    virtual bool _checkMove(Coordinate, Board*, Game&, bool careOfMoving = true) = 0;
    virtual bool canMove(Board*, Game&) = 0;
		virtual ~Piece() noexcept = default;
		char getType() const {return _str[TYP];}
		Coordinate getCoord() const {return _coords;}
		Coordinate getStartCoord() const {return _start;}
		char getColor() const {return _color;}
		char getOpenentColor() const {return _color == 'w' ? 'b':'w';}
		unsigned getRow() {return _coords.getRealRow();}
		unsigned getColumn() {return _coords.getRealColumn();}
    virtual char* toString() {return _str;}
		virtual void changeIsTaken(unsigned turn, Piece*, Board*){_isTaken = !_isTaken;}
		bool isTaken() const {return _isTaken;}
		virtual bool _isMovePossible(Coordinate, Board*, Game&);
		bool _isMovePossible(int column, int row, Board* board, Game& game){return this->_isMovePossible(Coordinate(int (this->getColumn()) + column, int(this->getRow()) + row), board, game);}
		bool isMoving() const {return _isMoving;}
		virtual void startMovingTo (Game&, Coordinate);
		virtual void stopMoving(Game& game, Board*);
		unsigned getMovementStart() const {return _movementStart;}
		bool isCoolingDown(Game& game) const {return _lastMoveEnd && COOLDOWN_TIME + _lastMoveEnd >= game.getTurn();}
		Coordinate getDest() const {return _dest;}
		void _setCoordinate(Coordinate newCoords){
			_coords = newCoords;
			_str[COL] = _coords.getAbstractColumn();
			_str[ROW] = _coords.getAbstractRow();
		}
};

#endif
