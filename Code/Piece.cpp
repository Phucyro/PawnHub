#ifndef  __PIECE__CPP__
#define __PIECE__CPP__

#include "Piece.hpp"

Piece& Piece::operator= (const Piece& original){
	_color = original._color;
	_coords = original._coords;
	_dest = original._dest;
	_isTaken = original._isTaken;
	_movementStart = original._movementStart;
	_lastMoveEnd = original._lastMoveEnd;
	_isMoving = original._isMoving;
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

bool Piece::move(Coordinate end, Board* board, Game& game){
/*Move this piece to the correct location on the board and return true if the move is possible. Else return false and leave the board unchanged*/
	Coordinate start = _coords;
	if(!(this->_checkMove(end, board, game))) return false;
	Piece* takenPiece = this->_doMove(end, board, game);
	_setCoordinate(end);

	if(game.testCheck(this->getColor())){		//0 a changer
		_setCoordinate(start);
		this->_reverseMove(end, board, game, takenPiece);
		return false;
	}
	return true;
}

bool Piece::_isMovePossible(Coordinate dest, Board* board, Game& game){
	if (!board->isInBoard(dest))return false;
	Coordinate start = this->getCoord();
	Piece* takenPiece = board->getCase(dest);
	if (!this->move(dest, board, game))return false;
	board->movePiece(dest, start);
	board->setCase(dest, takenPiece);
	if (takenPiece) takenPiece->changeIsTaken(game.getTurn(), this, board);
	_setCoordinate(start);

	return true;
}

void Piece::startMovingTo(Game& game, Coordinate dest){
	_isMoving = true;
	_dest = dest;
	_movementStart = game.getTurn();
}

void Piece::stopMoving(Game& game){
	_isMoving = false;
	_lastMoveEnd = game.getTurn();
}

#endif
