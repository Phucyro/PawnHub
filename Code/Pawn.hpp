#ifndef __PAWN__HPP__
#define __PAWN__HPP__

#include "GhostPawn.hpp"
#include "Piece.hpp"

class GhostPawn;


class Pawn : public Piece {

	protected :
		bool _moved;
		GhostPawn *_ghost;

		void _promote(Game&);

	public :

		Pawn(const char color, Coordinate coords, bool moved = false) noexcept : Piece(color, coords), _moved(moved), _ghost(nullptr) {
			_str[TYP] = 'p';
		}
		Pawn(const char color, const char column , const char row, bool moved = false) : Piece(color,column,row), _moved(moved), _ghost(nullptr) {
			_str[TYP] = 'p';
		}

		Pawn(const Pawn& original) noexcept;

		Pawn(Pawn&& original) noexcept : Piece(original), _moved(original.hasMoved()), _ghost(original._ghost) {
			original._ghost = nullptr;
		}

		virtual ~Pawn() noexcept;
		Pawn& operator= (const Pawn&);
		Pawn& operator= (Pawn&&);

		bool hasMoved() const override {return _moved;}
		bool move(Coordinate, Board*, Game&) override;
		bool canMove(Board*, Game&) override;
		bool _checkMove(Coordinate, Board*, Game&) override;
		using Piece::_isMovePossible;
		bool _isMovePossible(Coordinate, Board*, Game&) override;
};

#endif
