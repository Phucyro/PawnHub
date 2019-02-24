#ifndef __TEST__ROOK__CPP__
#define __TEST__ROOK__CPP__

#include <exception>
#include <iostream>
#include "testRook.hpp"
#include "../Coordinate.hpp"
#include "../Board.hpp"
#include "../Game.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION (TestRook);

void TestRook :: setUp()
{
  game = new SimpleGame();
  board = new Board();

  //black eats white
	rookA = new Rook('b',Coordinate('A','1'));//->A8
  board->setCase(Coordinate('A','1'), rookA);
  rookG = new Rook('w',Coordinate('A','8'));
  board->setCase(Coordinate('A','8'),rookG);

  //black tries to eat black
  rookB = new Rook('b',Coordinate('B','1'));//-> B3
  board->setCase(Coordinate('B','1'), rookB);
  rookC = new Rook('b',Coordinate('B','3'));
  board->setCase(Coordinate('B','3'),rookC);

  //piece in the way
  rookD = new Rook('b',Coordinate('C','3'));
  board->setCase(Coordinate('C','3'), rookD);//-> A3 and B3 on tha way

  //wrong move
  rookE = new Rook('b',Coordinate('D','4'));//->C5 ->diag movement
  board->setCase(Coordinate('D','4'),rookE);


  //wrong move due to check
  rookF = new Rook('w',Coordinate('E','1'));
  board->setCase(Coordinate('E','1'), rookF);
  rookM = new Rook('b',Coordinate('E','5'));
  board->setCase(Coordinate('E','5'),rookM);


  //good move
  rookH = new Rook('w',Coordinate('F','7'));//-->F6 down
  board->setCase(Coordinate('F','7'), rookH);
  rookI = new Rook('w',Coordinate('G','2')); //->G3 up
  board->setCase(Coordinate('G','2'),rookI);

  rookJ = new Rook('w',Coordinate('F','4')); //->G4 right
  board->setCase(Coordinate('F','4'), rookJ);
  rookL = new Rook('w',Coordinate('G','5'));
  board->setCase(Coordinate('G','5'),rookL); //->F5 left


  //out of bounds move
  rookK = new Rook('w',Coordinate('H','1'));//-> H9
  board->setCase(Coordinate('H','1'),rookK);
}


void TestRook :: tearDown()
{
	delete rookA;
  delete rookB;
  delete rookC;
  delete rookD;
  delete rookE;
  delete rookF;
  delete rookG;
  delete rookH;
  delete rookI;
  delete rookJ;
  delete rookK;
  delete rookL;
  delete rookM;
  delete game;
  delete board;
}


void TestRook :: testMove()
{
  //black eats white
  CPPUNIT_ASSERT_EQUAL(rookA->move(Coordinate('A','8'), board, *game), true); // make rookA move to A8
  CPPUNIT_ASSERT(board->getCase(Coordinate('A','8')) == rookA); //checks if rookA is in A2
  CPPUNIT_ASSERT(rookG->isTaken()); //checks if rookG was taken correctly
  CPPUNIT_ASSERT(rookA->_coords == Coordinate('A','8')); //checks coords of RookA

  //black tries to eat black
  CPPUNIT_ASSERT_EQUAL(rookB->move(Coordinate('B','3'), board, *game), false); //checks if RookB can take the place of RookC
  CPPUNIT_ASSERT(board->getCase(Coordinate('B','1')) == rookB); //checks if rookB is in B1
  CPPUNIT_ASSERT(board->getCase(Coordinate('B','3')) == rookC); //checks if rookC is in B3
  CPPUNIT_ASSERT(rookB->_coords == Coordinate('B','1'));//checks coords of RookB
  CPPUNIT_ASSERT(rookC->_coords == Coordinate('B','3'));//checks coords of RookC

  //piece in the way
  CPPUNIT_ASSERT_EQUAL(rookD->move(Coordinate('A','3'), board, *game), false);//checks if RookD cant pass over the place of RookE
  CPPUNIT_ASSERT(rookD->_coords == Coordinate('C','3'));//checks coords of RookD
  CPPUNIT_ASSERT(board->getCase(Coordinate('A','3')) == nullptr); //checks if rookD is not in F3
  CPPUNIT_ASSERT(board->getCase(Coordinate('C','3')) == rookD); //checks if rookD is in C3

  //wrong move
  CPPUNIT_ASSERT_EQUAL(rookE->move(Coordinate('C','5'), board, *game), false);
  CPPUNIT_ASSERT(rookE->_coords == Coordinate('D','4'));//checks coords of RookE
  CPPUNIT_ASSERT(board->getCase(Coordinate('C','5')) == nullptr); //checks if rookE is not in C5
  CPPUNIT_ASSERT(board->getCase(Coordinate('D','4')) == rookE); //checks if rookE is in D4

  //good move
  CPPUNIT_ASSERT_EQUAL(rookH->move(Coordinate('F','6'), board, *game), true); // make rookA move to F7
  CPPUNIT_ASSERT(board->getCase(Coordinate('F','6')) == rookH); //checks if rookH is in F7
  CPPUNIT_ASSERT(board->getCase(Coordinate('F','7')) == nullptr); //checks if rookH is not in F6
  CPPUNIT_ASSERT(rookH->_coords == Coordinate('F','6')); //checks coords of RookH

  CPPUNIT_ASSERT_EQUAL(rookI->move(Coordinate('G','3'), board, *game), true); // make rookH move to G3
  CPPUNIT_ASSERT(board->getCase(Coordinate('G','3')) == rookI); //checks if rookH is in G2
  CPPUNIT_ASSERT(board->getCase(Coordinate('G','2')) == nullptr); //checks if rookH is not in G3
  CPPUNIT_ASSERT(rookI->_coords == Coordinate('G','3')); //checks coords of RookH

  CPPUNIT_ASSERT_EQUAL(rookJ->move(Coordinate('G','4'), board, *game), true); // make rookJ move to G4
  CPPUNIT_ASSERT(board->getCase(Coordinate('G','4')) == rookJ); //checks if rookJ is in F4
  CPPUNIT_ASSERT(board->getCase(Coordinate('F','4')) == nullptr); //checks if rookJ is not in G4
  CPPUNIT_ASSERT(rookJ->_coords == Coordinate('G','4')); //checks coords of RookJ

  CPPUNIT_ASSERT_EQUAL(rookL->move(Coordinate('F','5'), board, *game), true); // make rookL move to F5
  CPPUNIT_ASSERT(board->getCase(Coordinate('F','5')) == rookL); //checks if rookL is in G5
  CPPUNIT_ASSERT(board->getCase(Coordinate('G','5')) == nullptr); //checks if rookL is not in F5
  CPPUNIT_ASSERT(rookL->_coords == Coordinate('F','5')); //checks coords of RookL

  //wrong move due to check
  game->changeTestCheck();

  CPPUNIT_ASSERT_EQUAL(rookF->move(Coordinate('E','5'), board, *game), false); // make rookF move to E5
  CPPUNIT_ASSERT(board->getCase(Coordinate('E','1')) == rookF); //checks if rookF is in E1
  CPPUNIT_ASSERT(board->getCase(Coordinate('E','5')) == rookM); //checks if rookC is in E5
  CPPUNIT_ASSERT(rookF->_coords == Coordinate('E','1'));//checks coords of RookF
  CPPUNIT_ASSERT(rookM->_coords == Coordinate('E','5'));//checks coords of RookM

  game->changeTestCheck();
  //out of bounds
  //CPPUNIT_ASSERT_THROW(rookK->move(Coordinate('H','9'), board, *game), std::out_of_range); // make rookK move to I5

}

void TestRook:: testCheckMove()
{
  //black eats white
  CPPUNIT_ASSERT_EQUAL(rookA->_checkMove(Coordinate('A','8'), board, *game), true);

  //black tries to eat black
  CPPUNIT_ASSERT_EQUAL(rookB->_checkMove(Coordinate('B','3'), board, *game), false);

  //piece in the way
  CPPUNIT_ASSERT_EQUAL(rookD->_checkMove(Coordinate('A','3'), board, *game), false);

  //wrong move
  CPPUNIT_ASSERT_EQUAL(rookE->_checkMove(Coordinate('C','5'), board, *game), false);

  //good move
  CPPUNIT_ASSERT_EQUAL(rookH->_checkMove(Coordinate('F','6'), board, *game), true);
  CPPUNIT_ASSERT_EQUAL(rookI->_checkMove(Coordinate('G','3'), board, *game), true);
  CPPUNIT_ASSERT_EQUAL(rookJ->_checkMove(Coordinate('G','4'), board, *game), true);
  CPPUNIT_ASSERT_EQUAL(rookL->_checkMove(Coordinate('F','5'), board, *game), true);
}

#endif
