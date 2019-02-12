#ifnedf _KING_CPP_
#define _KING_CPP_

#include <cmath>
#include "King.hpp"

bool move(Coordinate end, Board* board, Game& game) {
  if(this->Piece::move(end, board, game)){
		_moved = true;
		return true;
	}
	else return false;
}

bool _checkmove(Coordinate end, Board* board, Game& game){
  int rowMove = int(end.getRealRow()) - int(_coords.getRealRow());
  int columnMove = int(end.getRealColumn()) - int(_coords.getRealColumn());

  if (end == _coords) return false; //test if the move normal for a King
  if (columnMove < -1 || columnMove > 1 || rowMove > 2 || rowMove < -2) return false;
  if ((std::abs(rowMove) + std::abs(columnMove)) >= 3) return false;

  if (rowMove == 2 || rowMove == -2) {  //Let's roque baby
    if (!(this->hasMoved())){   //King moved ?
      if (rowMove == 2) {Coordinate tmpcoord = Coordinate(end.getRealColumn(), end.getRealRow()+1);} //Roque
      else {Coordinate tmpcoord = Coordinate(end.getRealColumn(), end.getRealRow()-2);} //Grand roque
      if (board->getCaseType(tmpcoord) == 'r' && !(board->getCaseMove()) && board->getCaseColor(tmpcoord) == this->getColor()){ //Is the Rook validate ?
        if (rowMove == 2){  //check if there is no piece in the way
          if (board->getCase(Coordinate(_coords.getRealColumn(), _coords.getRealRow()+1))) return false;
          if (board->getCase(Coordinate(_coords.getRealColumn(), _coords.getRealRow()+2))) return false;
          Coordinate coordRook = Coordinate(tmpcoord.getRealColumn(), tmpcoord.getRealRow()-2); //coord for Rook move
        }
        else {
          if (board->getCase(Coordinate(_coords.getRealColumn(), _coords.getRealRow()-1))) return false;
          if (board->getCase(Coordinate(_coords.getRealColumn(), _coords.getRealRow()-2))) return false;
          Coordinate coordRook = Coordinate(tmpcoord.getRealColumn(), tmpcoord.getRealRow()+3); //coord for Rook move
        }
        if (board->getCase(tmpcoord)->move(coordRook, board, game)) return true;  //move Rook then return true  //A changer pour loi démeter
        else std::cerr << "[Error] move Rook to roque" << std::cout;
      }
      else return false
    }
    else return false
  }

  //test if there is a Piece of the same color to the destination
  if (board->getCase(end) && board->getCase(end)->getColor() == this->getColor()) return false;

  //test if the king will not be mat


}

#endif
