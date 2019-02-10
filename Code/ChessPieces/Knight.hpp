#ifndef __KNIGHT__HPP__
#define __KNIGHT__HPP__

#include "Piece.hpp"

class Knight : public Piece {

	protected :
		bool _checkMove(Coordinate, Board*, Game&) override;

	public :

		Knight(const char& color, Coordinate coords) noexcept : Piece(color, coords){
			_str[TYP] = 'h';
		}
		Knight(const Knight& original) : Piece(original){}
		virtual ~Knight() noexcept = default;
		
		Knight& operator= (const Knight&);
};

#endif
