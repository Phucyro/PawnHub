#ifndef __GHOSTPAWN__HPP__
#define __GHOSTPAWN__HPP__

#include "Piece.hpp"

class GhostPawn : public Piece{

    protected : 
        unsigned creationTurn;
        Pawn * target ;
    public :
        bool isActive();

};

#endif
