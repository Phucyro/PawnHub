#ifndef __KNIGHT__HPP__
#define __KNIGHT__HPP__

#include "Piece.hpp"
class TestKnight;

class Knight : public Piece {

	protected :
		bool _checkMove(Coordinate, Board*, Game&) override;
		bool hasMoved() const override {return true;}

	public :

		Knight(const char color, Coordinate coords) noexcept : Piece(color, coords){
			_str[TYP] = 'h';
		}
		Knight(const char color, const char column , const char row) : Piece(color,column,row){
			_str[TYP] = 'h';
		}


		Knight(const Knight& original) : Piece(original){}
		explicit Knight(const Piece& original) noexcept : Piece(original){
			_str[TYP] = 'h';
		}
		virtual ~Knight() noexcept = default;

		bool canMove(Board*, Game&) override;

		Knight& operator= (const Knight&);

		Coordinate* PossibleMoves(Board*, Game&) override;

		friend TestKnight;
};

#endif
