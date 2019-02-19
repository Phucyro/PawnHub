#ifndef __QUEEN__HPP__
#define __QUEEN__HPP__

#include "Piece.hpp"
#include "Pawn.hpp"

class Queen : public Piece {

	protected :
		bool _checkMoveRook(Coordinate, Board*, Game&);
		bool _checkMoveBishop(Coordinate, Board*, Game&);
		bool _checkMove(Coordinate, Board*, Game&) override;
		bool hasMoved() const override {return true;}


	public :

		Queen(const char& color, Coordinate& coords) noexcept : Piece(color, coords){
			_str[TYP] = 'q';
		}

		Queen(const char color, const char column , const char row) : Piece(color,column,row){
			_str[TYP] = 'q';
		}

		Queen(const Queen& original) noexcept : Piece(original){}
		explicit Queen(const Pawn& original) noexcept : Piece(original){
			_str[TYP] = 'q';
		}
		virtual ~Queen() noexcept = default;

		Queen& operator= (const Queen&);

		bool canMove(Board*, Game&) override;
};

#endif
