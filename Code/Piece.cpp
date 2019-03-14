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
	if (takenPiece && (takenPiece->getType() == 'p' || takenPiece->getType() == 'r' || takenPiece->getType() == 'b' ||
takenPiece->getType() == 'h' || takenPiece->getType() == 'q' || takenPiece->getType() == 'k' || takenPiece->getType() == 'g')) {
		takenPiece->changeIsTaken(game.getTurn(),this,board);
		return takenPiece;
	}
	return nullptr;
}

void Piece::_reverseMove(Coordinate end, Board* board, Game& game, Piece* takenPiece){
	board->movePiece(end, _coords);
	board->setCase(end, takenPiece);
	if (takenPiece && (takenPiece->getType() == 'p' || takenPiece->getType() == 'r' || takenPiece->getType() == 'b' ||
takenPiece->getType() == 'h' || takenPiece->getType() == 'q' || takenPiece->getType() == 'k' || takenPiece->getType() == 'g')) {
		takenPiece->changeIsTaken(game.getTurn(),this,board);
	}
}

bool Piece::move(Coordinate end, Board* board, Game& game, const bool& ForPossibleMoves){
/*Move this piece to the correct location on the board and return true if the move is possible. Else return false and leave the board unchanged*/
	Coordinate start = _coords;
	if (ForPossibleMoves) {if(!(this->_checkMove(end, board, game))) return false;}
	Piece* takenPiece = this->_doMove(end, board, game);
	_setCoordinate(end);

	if(game.testCheck(this->getColor())){		
		_setCoordinate(start);
		this->_reverseMove(end, board, game, takenPiece);
		return false;
	}

	if (ForPossibleMoves) {_setCoordinate(start); this->_reverseMove(end, board, game, takenPiece);}
	return true;
}

bool Piece::_isMovePossible(Coordinate dest, Board* board, Game& game){
	if (!board->isInBoard(dest)) return false;
	if (board->getCase(dest) && board->getCase(dest)->getColor() == this->getColor()) return false;
	if (!this->Piece::move(dest, board, game, true)) return false;

	return true;
}

#endif
