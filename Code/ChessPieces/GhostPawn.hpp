#ifndef __GHOSTPAWN__HPP__
#define __GHOSTPAWN__HPP__

#include "ChessPiece.hpp"

class GhostPawn : public ChessPiece{

    protected : 
        unsigned creationTurn;
        Pawn * target ;
    public :
        bool isActive();

};

#endif
