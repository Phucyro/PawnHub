#ifndef __QUEEN__HPP__
#define __QUEEN__HPP__

#include "Piece.hpp"

class Queen : public Piece {

	protected :
		bool _checkMoveRook(Coordinate, Board*, Game&) override;
		bool _checkMoveBishop(Coordinate, Board*, Game&) override;
		bool _checkMove(Coordinate, Board*, Game&) override;


	public :

		Queen(const char& color, Coordinate& coords) noexcept : Piece(color, coords){
			_str[TYP] = 'q';
		}

		constexpr Queen(const char color, const char column , const char row) : Piece(color,column,row){
			_str[TYP] = 'q';
		}

		Queen(const Queen& original) noexcept : Piece(original){}
		virtual ~Queen() noexcept = default;

		Queen& operator= (const Queen&);
};

#endif
