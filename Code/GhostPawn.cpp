#ifndef __GHOSTPAWN__CPP__
#define __GHOSTPAWN__CPP__

#include <cmath>
#include "GhostPawn.hpp"



GhostPawn& GhostPawn::operator= (const GhostPawn& original){
  this->Piece::operator= (original);
  _creationTurn = original._creationTurn;
  _target = original._target;
  return *this;
}

void GhostPawn::changeIsTaken(unsigned turn, Piece* taker, Board* board){
  if (_isActive(turn) && dynamic_cast<Pawn*>(taker)){
    int rowDirection = _color == 'w' ? 1 : -1;
    if(_isTaken) board->setCase(Coordinate(int(_coords.getRealColumn()), int(_coords.getRealRow()) + 1*rowDirection), _target);
    else board->setCase(Coordinate(int(_coords.getRealColumn()), int(_coords.getRealRow()) + 1*rowDirection), nullptr);

    _target->changeIsTaken();
  }
  this->Piece::changeIsTaken();
}

bool GhostPawn::_isActive(unsigned turn){
  return turn == _creationTurn + 1;
}

#endif
