#ifndef __GHOSTPAWN__HPP__
#define __GHOSTPAWN__HPP__

#include "Piece.hpp"
#include "RealTimeBoard.hpp"
class Pawn;

class GhostPawn : public Piece{

  protected :
      unsigned _creationTurn;
      unsigned _activationTime;
      Pawn *_target ;

      bool _checkMove(Coordinate, Board*, Game&, bool = true) override {return false;}

  public :
      GhostPawn(const char color, Coordinate coords, unsigned turn, Pawn* target, unsigned activationTime = 1) : Piece(color, coords), _creationTurn(turn), _target(target), _activationTime(activationTime) {
        _str[TYP] = 'g';
      }
      GhostPawn(const GhostPawn& original) : Piece(original), _creationTurn(original._creationTurn), _target(original._target), _activationTime(original._activationTime) {}
      virtual ~GhostPawn() noexcept = default;

      GhostPawn& operator= (const GhostPawn&);
      GhostPawn(const GhostPawn* ghost) : Piece(static_cast<const Piece*>(ghost)), _creationTurn(ghost->_creationTurn), _target(ghost->_target) {}

      void changeIsTaken(unsigned, Piece*, Board*) override;
      bool canMove(Board*, Game&) override{return false;}
      bool hasMoved() const override {return false;}
      virtual bool isActive(unsigned);
};

#include "Pawn.hpp"

#endif
