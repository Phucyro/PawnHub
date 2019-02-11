#ifndef __GHOSTPAWN__CPP__
#define __GHOSTPAWN__CPP__

#include <cmath>
#include "GhostPawn.hpp"

GhostPawn& GhostPawn::operator= (const GhostPawn& original){
  this->Piece::operator= (original);
  _creationTurn = original._creationTurn;
  _target = original._target;
}

void GhostPawn::changeIsTaken(unsigned turn,Piece taker){
  if (_isActive(turn) && dynamic_cast<Pawn*>(taker)){
    if(!_isTaken){

    }
    else{

    }
  }

}

bool GhostPawn::_isActive(unsigned turn){
  return turn == _creationTurn + 1;
}

#endif
