#ifndef _KING_CPP_
#define _KING_CPP_

#include <cmath>
#include "King.hpp"
#include <iostream>
#include "Rook.hpp"

Piece* King::_doMove(Coordinate end, Board* board, Game& game){
	int columnMove = int(end.getRealColumn()) - int(_coords.getRealColumn());

	if (columnMove == 2){
		Coordinate startRook = Coordinate(end.getRealColumn()+1u, end.getRealRow());
		Coordinate endRook = Coordinate(end.getRealColumn()-1, end.getRealRow());
		board->getCase(startRook)->move(endRook, board, game);
	}
	else if (columnMove == -2) {
		Coordinate startRook = Coordinate(end.getRealColumn()-2, end.getRealRow());
		Coordinate endRook = Coordinate(end.getRealColumn()+1u, end.getRealRow());
		board->getCase(startRook)->move(endRook, board, game);
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

bool King::_checkMove(Coordinate end, Board* board, Game& game, bool careOfMoving){
  int rowMove = int(end.getRealRow()) - int(_coords.getRealRow());
  int columnMove = int(end.getRealColumn()) - int(_coords.getRealColumn());
  int absColumnMove = std::abs(columnMove);
  int columnDirection = absColumnMove == 0 ? 0 : columnMove/absColumnMove;

  if (end == _coords) return false; //test if the move normal for a King
  if (std::abs(rowMove) > 1 || absColumnMove > 2) return false;
  if (std::abs(rowMove) + absColumnMove >= 3) return false;

  if (absColumnMove == 2) {  //Let's roque baby						//0 a changer
    Coordinate coords = _coords;
    if (this->hasMoved() || game.testCheck(this->getColor()))return false;   //King moved or is checked ?
		Coordinate tmpcoord =  columnMove == 2 ? Coordinate(end.getRealColumn()+1, end.getRealRow()) : Coordinate(end.getRealColumn()-2, end.getRealRow());//coords of he rook
    Piece* rook = dynamic_cast<Rook*>(board->getCase(tmpcoord));//might segfault because of g++ ?
    if (!rook || rook->hasMoved()) return false;
		//check if there is no piece in the way + if the king will not be checked in the way
		bool res = true;
    Coordinate middleCoord = Coordinate(_coords.getRealColumn() + unsigned(1*columnDirection), _coords.getRealRow());
    if (!_isPlaceFree(middleCoord, board, careOfMoving)) return false;
    board->movePiece(_coords, middleCoord);  //Ca me parait lourd comme démarche, a voir une fois testcheck ready
    this->_setCoordinate(middleCoord);
    if (game.testCheck(this->getColor())) res = false;	//0 a changer
    if (!_isPlaceFree(end, board, careOfMoving)) return false;
    board->movePiece(middleCoord, end);
    this->_setCoordinate(end);
    if (game.testCheck(this->getColor()))res = false;	//0 a changer
    board->movePiece(end, coords);
    this->_setCoordinate(coords);
    if (!_isPlaceFree(Coordinate(tmpcoord.getRealColumn() - 1*columnDirection, tmpcoord.getRealRow()), board, careOfMoving)) return false; //test if the case next to the rook is empty
    return res;
  }


  //test if there is a Piece of the same color to the destination
  if ((!_isPlaceFree(end, board, careOfMoving)) && board->getCase(end)->getColor() == this->getColor()) return false;
  return true;
}

bool King::canMove(Board* board, Game& game){
	if (this->_isMovePossible(1, 1, board, game)) return true;
	if (this->_isMovePossible(0, 1, board, game)) return true;
	if (this->_isMovePossible(-1, 1, board, game)) return true;
	if (this->_isMovePossible(1, 0, board, game)) return true;
	if (this->_isMovePossible(-1, 0, board, game)) return true;
	if (this->_isMovePossible(1, -1, board, game)) return true;
	if (this->_isMovePossible(0, -1, board, game)) return true;
	if (this->_isMovePossible(-1, -1, board, game)) return true;
	return false;
}

bool King::_isMovePossible(Coordinate dest, Board* board, Game& game){
	bool moved = _moved;
	bool res = this->Piece::_isMovePossible(dest, board, game);
	_moved = moved;
	return res;
}

void King::startMovingTo(Game& game, Coordinate end){
	this->Piece::startMovingTo(game, end);
	_moved = true;
}

#endif
