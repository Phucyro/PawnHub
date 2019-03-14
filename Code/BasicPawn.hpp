#ifndef __BASIC__PAWN__HPP__
#define __BASIC__PAWN__HPP__

#include "Piece.hpp"

class GhostBasicPawn;


class BasicPawn : public Piece {

	protected :
		bool _moved;

		void _promote(Game&);

	public :

		BasicPawn(const char color, Coordinate coords, bool moved = false) noexcept : Piece(color, coords), _moved(moved){
			_str[TYP] = 'p';
		}
		BasicPawn(const char color, const char column , const char row, bool moved = false) : Piece(color,column,row), _moved(moved) {
			_str[TYP] = 'p';
		}

		BasicPawn(const BasicPawn& original) noexcept;

		BasicPawn(BasicPawn&& original) noexcept : Piece(original), _moved(original.hasMoved()) {}

		virtual ~BasicPawn() noexcept = default;
		BasicPawn& operator= (const BasicPawn&);
		BasicPawn& operator= (BasicPawn&&);

		Coordinate* PossibleMoves(Board*, Game&) override;
		bool hasMoved() const override {return _moved;}
		bool move(Coordinate, Board*, Game&, const bool&) override;
		bool canMove(Board*, Game&) override;
		bool _checkMove(Coordinate, Board*, Game&) override;
		using Piece::_isMovePossible;
		bool _isMovePossible(Coordinate, Board*, Game&) override;
};

#endif
