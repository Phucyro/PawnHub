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
      virtual ~GhostPawn() noexcept = default;

      GhostPawn& operator= (const GhostPawn&);
      GhostPawn(const GhostPawn* ghost) : Piece(static_cast<const Piece*>(ghost)), _creationTurn(ghost->_creationTurn), _target(ghost->_target) {}

      void changeIsTaken(unsigned, Piece*, Board*) override;
      bool canMove(Board*, Game&) override{return false;}
      bool hasMoved() const override {return false;}
};

#include "Pawn.hpp"

#endif
