#ifndef __BISHOP__HPP__
#define __BISHOP__HPP__

#include "ChessPiece.hpp"


class Bishop : public ChessPiece {

	protected :
		virtual bool checkMove(){

		}
	public :
		Bishop(const char& color, Coordinate coords) noexcept : ChessPiece(color, coords), _moved(false){_str[TYP] = 'b'}
		virtual ~Bishop() noexcept = default;
			//A voir comment on implémente
};


#endif
