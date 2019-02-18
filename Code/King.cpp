#ifndef _KING_CPP_
#define _KING_CPP_

#include <cmath>
#include "King.hpp"

Piece* King::_doMove(Coordinate end, Board* board, Game& game){
	int columnMove = int(end.getRealColumn()) - int(_coords.getRealColumn());

	if (columnMove == 2){
		Coordinate startRook = Coordinate(end.getRealColumn()+1u, end.getRealRow());
		Coordinate endRook = Coordinate(end.getRealColumn()-1, end.getRealRow());
		board->movePiece(startRook, endRook);
	}
	else if (columnMove == -2) {
		Coordinate startRook = Coordinate(end.getRealColumn()-2, end.getRealRow());
		Coordinate endRook = Coordinate(end.getRealColumn()+1u, end.getRealRow());
		board->movePiece(startRook, endRook);
	}
	return this->Piece::_doMove(end, board, game);
}

void King::_reverseMove(Coordinate end, Board* board, Game& game, Piece* takenPiece){
	int columnMove = int(end.getRealColumn()) - int(_coords.getRealColumn());

	if (columnMove == 2){
		Coordinate endRook = Coordinate(end.getRealColumn()+1u, end.getRealRow());
		Coordinate startRook = Coordinate(end.getRealColumn()-1, end.getRealRow());
		board->movePiece(startRook, endRook);
	}
	else if (columnMove == -2) {
		Coordinate endRook = Coordinate(end.getRealColumn()-2, end.getRealRow());
		Coordinate startRook = Coordinate(end.getRealColumn()+1u, end.getRealRow());
		board->movePiece(startRook, endRook);
	}
	this->Piece::_reverseMove(end, board, game, takenPiece);
}

bool King::move(Coordinate end, Board* board, Game& game) {
  if (this->Piece::move(end, board, game)){
		_moved = true;
		return true;
	}
	else return false;
}

bool King::_checkMove(Coordinate end, Board* board, Game& game){
  int rowMove = int(end.getRealRow()) - int(_coords.getRealRow());
  int columnMove = int(end.getRealColumn()) - int(_coords.getRealColumn());
  int absColumnMove = std::abs(columnMove);
  int columnDirection = absColumnMove == 0 ? 0 : columnMove/absColumnMove;

  if (end == _coords) return false; //test if the move normal for a King
  if (std::abs(rowMove) > 1 || absColumnMove > 2) return false;
  if (std::abs(rowMove) + absColumnMove >= 3) return false;

  if (absColumnMove == 2) {  //Let's roque baby						//0 a changer
    if (this->hasMoved() || game.testCheck(this->getColor(), 0))return false;   //King moved or is checked ?
		Coordinate tmpcoord =  columnMove == 2 ? Coordinate(end.getRealColumn()+1, end.getRealRow()) : Coordinate(end.getRealColumn()-2, end.getRealRow());//coords of he rook
    //if (columnMove == 2) tmpcoord = Coordinate(end.getRealColumn()+1, end.getRealRow()); //Petit Roque
    //else tmpcoord = Coordinate(end.getRealColumn()-2, end.getRealRow()); //Grand roque
    Piece* rook = dynamic_cast<Rook*>(board->getCase(tmpcoord));
    if (!rook || rook->hasMoved()) return false; //Is the Rook validate ?

		//check if there is no piece in the way + if the king will not be checked in the way
		bool res = true;
    Coordinate middleCoord = Coordinate(_coords.getRealColumn() + unsigned(1*columnDirection), _coords.getRealRow());
    if (board->getCase(middleCoord)) return false;
    board->movePiece(_coords, middleCoord);  //Ca me parait lourd comme démarche, a voir une fois testcheck ready
    if (game.testCheck(this->getColor(), 0)) res = false;	//0 a changer

    if (board->getCase(end)) return false;
    board->movePiece(middleCoord, end);
    if (game.testCheck(this->getColor(), 0))res = false;	//0 a changer

    board->movePiece(end, _coords);
    if (board->getCase(Coordinate(tmpcoord.getRealColumn() - 1*columnDirection, tmpcoord.getRealRow()))) return false; //test if the case next to the rook is empty
    return res;
  }


  //test if there is a Piece of the same color to the destination
  if (board->getCase(end) && board->getCase(end)->getColor() == this->getColor()) return false;
  return true;
}

bool King::canMove(Board* board, Game& game){
	if (this->_isMovePossible(1, 1, board, game)) return false;
	if (this->_isMovePossible(0, 1, board, game)) return false;
	if (this->_isMovePossible(-1, 1, board, game)) return false;
	if (this->_isMovePossible(1, 0, board, game)) return false;
	if (this->_isMovePossible(-1, 0, board, game)) return false;
	if (this->_isMovePossible(1, -1, board, game)) return false;
	if (this->_isMovePossible(0, -1, board, game)) return false;
	if (this->_isMovePossible(-1, -1, board, game)) return false;
	return true;
}

#endif
