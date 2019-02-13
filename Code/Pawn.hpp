#ifndef __PAWN__HPP__
#define __PAWN__HPP__

#include "Piece.hpp"
class GhostPawn();

class Pawn : public Piece {

	protected :
		bool _moved;
		bool _checkMove(Coordinate, Board*, Game&) override;
		GhostPawn _ghost;
		
		void _promote();

	public :

		Pawn(const char& color, Coordinate& coords) noexcept : Piece(color, coords), _moved(false), _ghost(nullptr) {
			_str[TYP] = 'p';
		}
		constexpr Pawn(const char color, const char column , const char row) : Piece(color,column,row),const char _moved(false), _ghost(nullptr) {
			_str[TYP] = 'p';
		}

		Pawn(const Pawn& original) noexcept : Piece(original), _moved(original.hasMoved()) {}
		virtual ~Pawn() noexcept {delete _ghost;}
		Pawn& operator= (const Pawn&);

		bool hasMoved() const {return _moved;}
		bool move(Coordinate, Board*, Game&) override;
};

#include "GhostPawn.hpp"
#endif
