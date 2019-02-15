#ifndef __KING__HPP__
#define __KING__HPP__

#include "Piece.hpp"
#include "Pawn.hpp"

class King : public Piece {

	protected :
		bool _moved;
		
		Piece* _doMove(Coordinate, Board*, Game&) override;
		void _reverseMove(Coordinate, Board*, Game&, Piece*)override;

	public :
		King(const char& color, Coordinate& coords) noexcept : Piece(color, coords), _moved(false) {
			_str[TYP] = 'k';
		}
		King(const char color, const char column , const char row) : Piece(color,column,row), _moved(false){
			_str[TYP] = 'k';
		}

		King(const King& original) noexcept : Piece(original), _moved(original.hasMoved()) {}
		explicit King(const Pawn& original) noexcept : Piece(original), _moved(original.hasMoved()){
			_str[TYP] = 'k';
		}
		virtual ~King() noexcept = default;

		King& operator= (const King&);

		bool hasMoved() const {return _moved;}
		bool move(Coordinate, Board*, Game&) override;
		bool canMove(Board*, Game&) override;
		bool _checkMove(Coordinate, Board*, Game&) override;
};

#endif
