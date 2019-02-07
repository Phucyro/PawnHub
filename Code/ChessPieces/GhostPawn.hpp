#ifndef __GHOSTPAWN__HPP__
#define __GHOSTPAWN__HPP__

#include "Pawn.hpp"

class GhostPawn : public Pawn{

    protected : 
        unsigned creationTurn;
        Pawn * target ;
    public :
        bool isActive();

};

#endif
