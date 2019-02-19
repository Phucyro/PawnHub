#ifndef __PAWN__HPP__
#define __PAWN__HPP__

#include "Piece.hpp"
#include "GhostPawn.hpp"

class Pawn : public Piece {

	protected :
		bool _moved;
		GhostPawn *_ghost;

		void _promote(Game&);

	public :

		Pawn(const char color, Coordinate coords) noexcept : Piece(color, coords), _moved(false), _ghost(nullptr) {
			_str[TYP] = 'p';
		}
		Pawn(const char color, const char column , const char row) : Piece(color,column,row), _moved(false), _ghost(nullptr) {
			_str[TYP] = 'p';
		}

		Pawn(const Pawn& original) noexcept : Piece(original), _moved(original.hasMoved()), _ghost(nullptr) {
			_ghost = new GhostPawn(*(original._ghost));
		}

		Pawn(Pawn&& original) noexcept : Piece(original), _moved(original.hasMoved()), _ghost(original._ghost) {
			original._ghost = nullptr;
		}

		virtual ~Pawn() noexcept {delete _ghost;}
		Pawn& operator= (const Pawn&);
		Pawn& operator= (Pawn&&);
		explicit operator Queen(const Pawn&)

		bool hasMoved() const override {return _moved;}
		bool move(Coordinate, Board*, Game&) override;
		bool canMove(Board*, Game&) override;
		bool _checkMove(Coordinate, Board*, Game&) override;
};

#endif
