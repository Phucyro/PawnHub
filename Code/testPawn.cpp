#ifndef __TEST__PAWN__CPP__
#define __TEST__PAWN__CPP__

#include <exception>
#include <iostream>
#include "testPawn.hpp"
#include "Coordinate.hpp"
#include "Board.hpp"
#include "Game.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION (TestPawn);

void TestPawn :: setUp()
{
  game = new SimpleGame();
  board = new Board();


  //white eats black
	pawnA = new Pawn('w',Coordinate('A','1'));
  board->setCase(Coordinate('A','1'), pawnA);
  pawnG = new Pawn('b',Coordinate('B','2'));
  board->setCase(Coordinate('B','2'),pawnG);

  //white tries to eat white
  pawnB = new Pawn('w',Coordinate('B','1'));
  board->setCase(Coordinate('B','1'), pawnB);
  pawnC = new Pawn('w',Coordinate('C','2'));
  board->setCase(Coordinate('C','2'),pawnC);


  //piece in the way
  pawnD = new Pawn('w',Coordinate('D','1'));
  board->setCase(Coordinate('D','1'), pawnD);

  //wrong move
  pawnE = new Pawn('b',Coordinate('D','2'));
  board->setCase(Coordinate('D','2'),pawnE);


  //wrong move due to check
  pawnF = new Pawn('w',Coordinate('E','4'));
  board->setCase(Coordinate('E','4'), pawnF);
  pawnM = new Pawn('b',Coordinate('F','5'));
  board->setCase(Coordinate('F','5'),pawnM);


  //good move
  pawnH = new Pawn('b',Coordinate('C','7'));
  board->setCase(Coordinate('C','7'), pawnH);
  pawnI = new Pawn('b',Coordinate('H','2'));
  board->setCase(Coordinate('H','2'),pawnI);

  pawnJ = new Pawn('w',Coordinate('E','7'));
  board->setCase(Coordinate('E','7'), pawnJ);
  pawnL = new Pawn('w',Coordinate('B','4'));
  board->setCase(Coordinate('B','4'),pawnL);


  //out of bounds move
  pawnK = new Pawn('w',Coordinate('E','1'));
  board->setCase(Coordinate('E','1'),pawnK);



}


void TestPawn :: tearDown()
{
	delete pawnA;
  delete pawnB;
  delete pawnC;
  delete pawnD;
  delete pawnE;
  delete pawnF;
  delete pawnG;
  delete pawnH;
  delete pawnI;
  delete pawnJ;
  delete pawnK;
  delete pawnL;
  delete pawnM;
  delete game;
  delete board;
}


void TestPawn :: testMove()
{


  //white eats black
  CPPUNIT_ASSERT_EQUAL(pawnA->move(Coordinate('B','2'), board, *game), true); // make pawnA move to B2
  CPPUNIT_ASSERT(board->getCase(Coordinate('B','2')) == pawnA); //checks if pawnA is in B2
  CPPUNIT_ASSERT(pawnG->isTaken()); //checks if pawnG was taken correctly
  CPPUNIT_ASSERT(pawnA->getCoord() == Coordinate('B','2')); //checks coords of PawnA

  //white tries to eat white
  CPPUNIT_ASSERT_EQUAL(pawnB->move(Coordinate('C','2'), board, *game), false); //checks if PawnB can take the place of PawnC
  CPPUNIT_ASSERT(board->getCase(Coordinate('B','1')) == pawnB); //checks if pawnB is in B1
  CPPUNIT_ASSERT(board->getCase(Coordinate('C','2')) == pawnC); //checks if pawnC is in C2
  CPPUNIT_ASSERT(pawnB->getCoord() == Coordinate('B','1'));//checks coords of PawnB
  CPPUNIT_ASSERT(pawnC->getCoord() == Coordinate('C','2'));//checks coords of PawnC
  CPPUNIT_ASSERT(!(pawnC->isTaken()));

  //piece in the way
  CPPUNIT_ASSERT_EQUAL(pawnD->move(Coordinate('D','2'), board, *game), false);//checks if PawnD cant pass over the place of PawnE
  CPPUNIT_ASSERT(pawnD->getCoord() == Coordinate('D','1'));//checks coords of PawnD
  CPPUNIT_ASSERT(board->getCase(Coordinate('D','2')) == pawnE); //checks if pawnD is not in F3
  CPPUNIT_ASSERT(board->getCase(Coordinate('D','1')) == pawnD); //checks if pawnD is in D1

  //wrong move
  CPPUNIT_ASSERT_EQUAL(pawnE->move(Coordinate('G','7'), board, *game), false);
  CPPUNIT_ASSERT(pawnE->getCoord() == Coordinate('D','2'));//checks coords of PawnE
  CPPUNIT_ASSERT(board->getCase(Coordinate('G','7')) == nullptr); //checks if pawnE is not in G7
  CPPUNIT_ASSERT(board->getCase(Coordinate('D','2')) == pawnE); //checks if pawnE is in E2

  //big move (2 cases)
  CPPUNIT_ASSERT_EQUAL(pawnH->move(Coordinate('C','5'), board, *game), true); //first time = true
  CPPUNIT_ASSERT(board->getCase(Coordinate('C','5')) == pawnH);
  CPPUNIT_ASSERT(board->getCase(Coordinate('C','7')) == nullptr);
  CPPUNIT_ASSERT(pawnH->getCoord() == Coordinate('C','5'));
  CPPUNIT_ASSERT_EQUAL(pawnH->move(Coordinate('C', '3'), board, *game), false); //second time = false
  CPPUNIT_ASSERT(board->getCase(Coordinate('C', '5')) == pawnH);
  CPPUNIT_ASSERT(board->getCase(Coordinate('C', '3')) == nullptr);
  CPPUNIT_ASSERT(pawnH->getCoord() == Coordinate('C','5'));
  CPPUNIT_ASSERT_EQUAL(pawnH->move(Coordinate('C', '4'), board, *game), true); // simple move
  CPPUNIT_ASSERT(board->getCase(Coordinate('C', '4')) == pawnH);
  CPPUNIT_ASSERT(board->getCase(Coordinate('C', '5')) == nullptr);
  CPPUNIT_ASSERT(pawnH->getCoord() == Coordinate('C','4'));

  //Wrong direction
  CPPUNIT_ASSERT_EQUAL(pawnI->move(Coordinate('H','3'), board, *game), false);
  CPPUNIT_ASSERT(board->getCase(Coordinate('H','2')) == pawnI);
  CPPUNIT_ASSERT(board->getCase(Coordinate('H','3')) == nullptr);
  CPPUNIT_ASSERT(pawnI->getCoord() == Coordinate('H','2'));
/*
  CPPUNIT_ASSERT_EQUAL(pawnJ->move(Coordinate('G','5'), board, *game), true); // make pawnJ move to G5
  CPPUNIT_ASSERT(board->getCase(Coordinate('G','5')) == pawnJ); //checks if pawnJ is in G5
  CPPUNIT_ASSERT(board->getCase(Coordinate('E','7')) == nullptr); //checks if pawnJ is not in E7
  CPPUNIT_ASSERT(pawnJ->getCoord() == Coordinate('G','5')); //checks coords of PawnJ

  CPPUNIT_ASSERT_EQUAL(pawnL->move(Coordinate('D','6'), board, *game), true); // make pawnL move to D6
  CPPUNIT_ASSERT(board->getCase(Coordinate('D','6')) == pawnL); //checks if pawnL is in D6
  CPPUNIT_ASSERT(board->getCase(Coordinate('B','4')) == nullptr); //checks if pawnL is not in B4
  CPPUNIT_ASSERT(pawnL->getCoord() == Coordinate('D','6')); //checks coords of PawnL
*/
  //wrong move due to check
  game->changeTestCheck();

  CPPUNIT_ASSERT_EQUAL(pawnF->move(Coordinate('F','5'), board, *game), false); // make pawnF move to F5
  CPPUNIT_ASSERT(board->getCase(Coordinate('E','4')) == pawnF); //checks if pawnF is in E4
  CPPUNIT_ASSERT(board->getCase(Coordinate('F','5')) == pawnM); //checks if pawnC is in F5
  CPPUNIT_ASSERT(pawnF->getCoord() == Coordinate('E','4'));//checks coords of PawnF
  CPPUNIT_ASSERT(pawnM->getCoord() == Coordinate('F','5'));//checks coords of PawnM
  CPPUNIT_ASSERT(!(pawnM->isTaken()));

  game->changeTestCheck();

  //out of bounds
  //CPPUNIT_ASSERT_THROW(pawnK->move(Coordinate('I','5'), board, *game), std::out_of_range); // make pawnK move to I5



}

void TestPawn:: testCheckMove()
{

  //black eats white
  CPPUNIT_ASSERT_EQUAL(pawnA->_checkMove(Coordinate('B','2'), board, *game), true);

  //black tries to eat black
  CPPUNIT_ASSERT_EQUAL(pawnB->_checkMove(Coordinate('C','2'), board, *game), false);

  //piece in the way
  CPPUNIT_ASSERT_EQUAL(pawnD->_checkMove(Coordinate('D','2'), board, *game), false);

  //wrong move
  CPPUNIT_ASSERT_EQUAL(pawnE->_checkMove(Coordinate('G','7'), board, *game), false);

  //good move
  CPPUNIT_ASSERT_EQUAL(pawnH->_checkMove(Coordinate('C','5'), board, *game), true);
  CPPUNIT_ASSERT_EQUAL(pawnI->_checkMove(Coordinate('H','3'), board, *game), false);
  //CPPUNIT_ASSERT_EQUAL(pawnJ->_checkMove(Coordinate('G','5'), board, *game), true);
  //CPPUNIT_ASSERT_EQUAL(pawnL->_checkMove(Coordinate('D','6'), board, *game), true);
}

#endif
