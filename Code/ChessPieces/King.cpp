#ifndef _KING_CPP_
#define _KING_CPP_

#include <cmath>
#include "King.hpp"

Piece* _doMove(Coordinate end, Board* board){
	int columnMove = int(end.getRealColumn()) - int(_coords.getRealColumn());
	
	if (columnMove == 2){
		Coordinate startRook = Coordinate(end.getRealColumn()+1u, end.getRealRow());
		Coordinate endRook = Coordinate(end.getRealColumn()-1, int(end.getRealRow()));
		board->movePiece(startRook, endRook);
	}
	else if (columnMove == -2) {
		Coordinate startRook = Coordinate(end.getRealColumn()-2, int(end.getRealRow()));
		Coordinate endRook = Coordinate(end.getRealColumn()+1u, end.getRealRow());
		board->movePiece(startRook, endRook);
	}
	return this->Piece::_doMove(end, board);
}

Piece* _reverseMove(Coordinate end, Board* board, Piece* takenPiece){
	int columnMove = int(end.getRealColumn()) - int(_coords.getRealColumn());
	
	if (columnMove == 2){
		Coordinate endRook = Coordinate(end.getRealColumn()+1u, end.getRealRow());
		Coordinate startRook = Coordinate(end.getRealColumn()-1, int(end.getRealRow()));
		board->movePiece(startRook, endRook);
	}
	else if (columnMove == -2) {
		Coordinate endRook = Coordinate(end.getRealColumn()-2, int(end.getRealRow()));
		Coordinate statRook = Coordinate(end.getRealColumn()+1u, end.getRealRow());
		board->movePiece(startRook, endRook);
	}
	this->Piece::_reverseMove(end, board, takenPiece);
}

bool move(Coordinate end, Board* board, Game& game) {
  if (this->Piece::move(end, board, game)){
		_moved = true;
		return true;
	}
	else return false;
}

bool _checkmove(Coordinate end, Board* board, Game& game){
  int rowMove = int(end.getRealRow()) - int(_coords.getRealRow());
  int columnMove = int(end.getRealColumn()) - int(_coords.getRealColumn());
  int absColumnMove = std::abs(columnMove);
  int columnDirection = columnMove/absColumnMove;

  if (end == _coords) return false; //test if the move normal for a King
  if (std::abs(rowMove) > 1 || absColumnMove > 2) return false;
  if (std::abs(rowMove) + absColumnMove >= 3) return false;

  if (absColumnMove == 2) {  //Let's roque baby
    if (this->hasMoved() || game.testCheck())return false;   //King moved or is checked ?
    Coordinate tmpcoord; //coords of he rook
    if (columnMove == 2) tmpcoord = Coordinate(end.getRealColumn()+1, end.getRealRow()); //Petit Roque
    else tmpcoord = Coordinate(end.getRealColumn()-2, end.getRealRow()); //Grand roque
    Piece* rook = dynamic_cast<*Rook>(board->getCase(tmpcoord));
    if (rook->hasMoved() || !rook) return false; //Is the Rook validate ?
		
		//check if there is no piece in the way + if the king will not be checked in the way
		bool res = true;
    Coordinate middleCoord = Coordinate(_coords.getRealColumn() + unsigned(1*columnDirection), _coords.getRealRow());
    if (board->getCase(middleCoord)) return false;
    board->movePiece(_coords, middleCoord);  //Ca me parait lourd comme démarche, a voir une fois testcheck ready
    if (game->testCheck()) res = false;
    
    if (board->getCase(end)) return false;
    board->movePiece(middleCoord, end);
    if (game->testCheck())res = false;
    
    board->movePiece(end, _coords);
    if (board->getCase(Coordinate(tmpcoords.getRealColumn() - 1*columnDirection, int(tmpcoords.getRealRow())))) return false; //test if the case next to the rook is empty
   	return res;
  }

  //test if there is a Piece of the same color to the destination
  if (board->getCase(end) && board->getCase(end)->getColor() == this->getColor()) return false;
  return true;
}

#endif
