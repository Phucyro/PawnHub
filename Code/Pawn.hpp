#ifndef __PAWN__HPP__
#define __PAWN__HPP__

#include "GhostPawn.hpp"
#include "BasicPawn.hpp"

class GhostPawn;


class Pawn : public BasicPawn {

	protected :
		GhostPawn *_ghost;

	public :

		Pawn(const char color, Coordinate coords, bool moved = false) noexcept : BasicPawn(color, coords, moved), _ghost(nullptr) {}
		Pawn(const char color, const char column , const char row, bool moved = false) : BasicPawn(color, column, row, moved), _ghost(nullptr) {}

		Pawn(const Pawn& original) noexcept;

		Pawn(Pawn&& original) noexcept : BasicPawn(original), _ghost(original._ghost) {
			original._ghost = nullptr;
		}

		virtual ~Pawn() noexcept;
		Pawn& operator= (const Pawn&);
		Pawn& operator= (Pawn&&);

		bool move(Coordinate, Board*, Game&) override;
		bool _checkMove(Coordinate, Board*, Game&) override;
};

#endif
