#ifdef PAWN_HPP
#define PAWN_HPP
#endif

#include "Pawn.hpp"

class GhostPawn : public Pawn{

    protected : 
        unsigned creationTurn;
        Pawn * target ;
    public :
        bool isActive();

};
