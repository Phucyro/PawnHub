#ifndef  __PIECE__CPP__
#define __PIECE__CPP__

#include "Piece.hpp"

Piece& Piece::operator= (const Piece& original){
	_color = original._color;
	_coords = original._coords;
	_isTaken = original._isTaken;
	for (int i = 0; i < 4; i++){
				_str[i] = original._str[i];
			}
			return *this;
}

Piece* Piece::_doMove(Coordinate end, Board* board, Game& game){
	Piece *takenPiece;
	takenPiece = board->movePiece(_coords, end);
	if (takenPiece) takenPiece->changeIsTaken(game.getTurn(),takenPiece,board);
	return takenPiece;
}

void Piece::_reverseMove(Coordinate end, Board* board, Game& game, Piece* takenPiece){
	board->movePiece(end, _coords);
	board->setCase(end, takenPiece);
	if (takenPiece) takenPiece->changeIsTaken(game.getTurn(), this, board);
}

bool Piece::move(Coordinate end, Board* board, Game& game){
/*Move this piece to the correct location on the board and return true if the move is possible. Else return false and leave the board unchanged*/
	if(!(this->_checkMove(end, board, game))) return false;
	Piece* takenPiece = this->_doMove(end, board, game);
	
	if(game.testCheck(this->getOpenentColor())){		//0 a changer
		this->_reverseMove(end, board, game, takenPiece);
		return false;
	}
	_setCoordinate(end);
	return true;
}

bool Piece::_isMovePossible(Coordinate dest, Board* board, Game& game){
	Coordinate start = this->getCoord();
	if (!board->isInBoard(dest))return false;
	Piece* takenPiece = board->getCase(dest);
	if (!this->move(dest, board, game))return false;
	board->movePiece(dest, start);
	board->setCase(dest, takenPiece);
	return true;
}

#endif
