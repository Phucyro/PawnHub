#ifndef __GHOSTPAWN__HPP__
#define __GHOSTPAWN__HPP__

#include "Piece.hpp"
class Pawn;

class GhostPawn : public Piece{

  private :
      bool _isActive(unsigned);

  protected :
      unsigned _creationTurn;
      Pawn *_target ;

      bool _checkMove(Coordinate, Board*, Game&) override {return false;}

  public :
      GhostPawn(const char color, Coordinate coords, unsigned turn, Pawn* target) : Piece(color, coords), _creationTurn(turn), _target(target) {
        _str[TYP] = 'g';
      }
      GhostPawn(const GhostPawn& original) : Piece(original), _creationTurn(original._creationTurn), _target(original._target) {}
      virtual ~GhostPawn();

      GhostPawn& operator= (const GhostPawn&);

      void changeIsTaken(unsigned, Piece*, Board*) override;
};

#include "Pawn.hpp"

#endif
