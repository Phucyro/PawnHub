#ifndef __PAWN__HPP__ 
#define __PAWN__HPP__

#include "Piece.hpp"

class Pawn : public Piece {

	protected :
		bool _moved;
		bool _checkMove(Coordinate, Board*, Game&) override;

	public :

		Pawn(const char& color, Coordinate coords) noexcept : Piece(color, coords), _moved(false) {
			_str[TYP] = 'p';
		}
		Pawn(const Pawn& original) noexcept : Piece(original), _moved(original.hasMoved()) {}
		
		Pawn& operator= (const Pawn&);
		
		virtual ~Pawn() noexcept = default;
		bool hasMoved() const {return _moved;}
		bool move(Coordinate, Board*, Game&) override;
};

#endif
