#ifdef PAWN_HPP
#define PAWN_HPP


#include "Pawn.hpp"

class GhostPawn : public Pawn{

    protected : 
        unsigned creationTurn;
        Pawn * target ;
    public :
        bool isActive();

};

#endif
