#ifndef __ROOK__HPP__
#define __ROOK__HPP__

#include "Piece.hpp"

class TestRook;

class Rook : public Piece {

	protected :
		bool _moved;
		bool _checkMove(Coordinate, Board*, Game&) override;

	public :
		Rook(const char color, Coordinate coords) noexcept : Piece(color, coords), _moved(false) {
			_str[TYP] = 'r';
		}

		Rook(const char color, const char column , const char row) : Piece(color,column,row), _moved(false){
			_str[TYP] = 'r';
		}

		Rook(const Rook& original) noexcept : Piece(original), _moved(original.hasMoved()) {}
		explicit Rook(const Piece& original) noexcept : Piece(original), _moved(original.hasMoved()){
			_str[TYP] = 'r';
		}
		virtual ~Rook() noexcept = default;

		Rook& operator= (const Rook&);

		bool hasMoved() const override {return _moved;}
		bool move(Coordinate, Board*, Game&) override;
		bool canMove(Board*, Game&) override;

		friend TestRook;

};

#endif
