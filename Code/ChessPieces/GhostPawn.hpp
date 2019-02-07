#ifdef  __GHOSTPAWN__HPP__
#define __GHOSTPAWN__HPP__
#endif

#include "Pawn.hpp"

class GhostPawn : public Pawn{

    protected : 
        unsigned creationTurn;
        Pawn * target ;
    public :
        bool isActive();

};
