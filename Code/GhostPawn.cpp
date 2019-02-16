#ifndef __GHOSTPAWN__CPP__
#define __GHOSTPAWN__CPP__

#include <cmath>
#include "GhostPawn.hpp"

GhostPawn& GhostPawn::operator= (const GhostPawn& original){
  this->Piece::operator= (original);
  _creationTurn = original._creationTurn;
  _target = original._target;
}

void GhostPawn::changeIsTaken(unsigned turn, Piece* taker, Board* board){
  if (_isActive(turn) && dynamic_cast<Pawn*>(taker)){
    if(_isTaken) board->setCase(Coordinate(_coords.getRealColumn(), _coords.getRealRow() + 1u), _target);
    else board->setCase(Coordinate(_coords.getRealColumn(), _coords.getRealRow() + 1u), nullptr);

    _target->changeIsTaken();
    this->Piece::changeIsTaken();
  }
}

bool GhostPawn::_isActive(unsigned turn){
  return turn == _creationTurn + 1;
}

#endif
