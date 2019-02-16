#ifndef __BISHOP__HPP__
#define __BISHOP__HPP__

#include "Piece.hpp"
#include "Pawn.hpp"

class TestBishop;

class Bishop : public Piece {

	protected :
		bool _checkMove(Coordinate, Board*, Game&) override;

	public :
		Bishop(const char color, Coordinate coords) noexcept : Piece(color, coords){
			_str[TYP] = 'b';
		}
		constexpr Bishop(const char color, const char column , const char row) : Piece(color,column,row){
			_str[TYP] = 'b';
		}
		Bishop(const Bishop& original) noexcept : Piece(original){}
		explicit Bishop(const Pawn& original) noexcept : Piece(original){
			_str[TYP] = 'b';
		}
		virtual ~Bishop() noexcept = default;

		Bishop& operator= (const Bishop&);

		friend TestBishop;
};


#endif