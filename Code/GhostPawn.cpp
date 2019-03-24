#ifndef __GHOSTPAWN__CPP__
#define __GHOSTPAWN__CPP__

#include <cmath>
#include <iostream>
#include "GhostPawn.hpp"



GhostPawn& GhostPawn::operator= (const GhostPawn& original){
  this->Piece::operator= (original);
  _creationTurn = original._creationTurn;
  _target = original._target;
  _activationTime = original._activationTime;
  return *this;
}

void GhostPawn::changeIsTaken(unsigned turn, Piece* taker, Board* board){
  if (isActive(turn) && dynamic_cast<Pawn*>(taker)){
    if(_isTaken) board->setCase(_target->getCoord(), _target);
    else board->setCase(_target->getCoord(), nullptr);

    _target->changeIsTaken();
  }
  this->Piece::changeIsTaken();
}

bool GhostPawn::isActive(unsigned turn){
  return turn <= _creationTurn + _activationTime;
}

#endif
