#ifndef __TEST__QUEEN__CPP__
#define __TEST__QUEEN__CPP__

#include <exception>
#include <iostream>
#include "testQueen.hpp"
#include "Coordinate.hpp"
#include "Board.hpp"
#include "Game.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION (TestQueen);

void TestQueen :: setUp()
{
  game = new SimpleGame();
  board = new Board();

  //Bishop part

  //black eats white
	queenA = new Queen('b',Coordinate('A','1'));
  board->setCase(Coordinate('A','1'), queenA);
  queenG = new Queen('w',Coordinate('B','2'));
  board->setCase(Coordinate('B','2'),queenG);

  //black tries to eat black
  queenB = new Queen('b',Coordinate('B','1'));
  board->setCase(Coordinate('B','1'), queenB);
  queenC = new Queen('b',Coordinate('C','2'));
  board->setCase(Coordinate('C','2'),queenC);


  //piece in the way
  queenD = new Queen('b',Coordinate('D','1'));
  board->setCase(Coordinate('D','1'), queenD);

  //wrong move
  queenE = new Queen('b',Coordinate('E','2'));
  board->setCase(Coordinate('E','2'),queenE);


  //wrong move due to check
  queenF = new Queen('w',Coordinate('E','4'));
  board->setCase(Coordinate('E','4'), queenF);
  queenM = new Queen('b',Coordinate('F','5'));
  board->setCase(Coordinate('F','5'),queenM);


  //good move
  queenH = new Queen('w',Coordinate('C','7'));
  board->setCase(Coordinate('C','7'), queenH);
  queenI = new Queen('w',Coordinate('H','2'));
  board->setCase(Coordinate('H','2'),queenI);

  queenJ = new Queen('w',Coordinate('E','7'));
  board->setCase(Coordinate('E','7'), queenJ);
  queenL = new Queen('w',Coordinate('B','4'));
  board->setCase(Coordinate('B','4'),queenL);


  //out of bounds move
  queenK = new Queen('w',Coordinate('E','1'));
  board->setCase(Coordinate('E','1'),queenK);



}


void TestQueen :: tearDown()
{
	delete queenA;
  delete queenB;
  delete queenC;
  delete queenD;
  delete queenE;
  delete queenF;
  delete queenG;
  delete queenH;
  delete queenI;
  delete queenJ;
  delete queenK;
  delete queenL;
  delete queenM;
  delete game;
  delete board;
}


void TestQueen :: testMove()
{
  //Bishop part

  //black eats white
  CPPUNIT_ASSERT_EQUAL(queenA->move(Coordinate('B','2'), board, *game), true); // make queenA move to B2
  CPPUNIT_ASSERT(board->getCase(Coordinate('B','2')) == queenA); //checks if queenA is in B2
  CPPUNIT_ASSERT(queenG->isTaken()); //checks if queenG was taken correctly
  CPPUNIT_ASSERT(queenA->_coords == Coordinate('B','2')); //checks coords of QueenA

  //black tries to eat black
  CPPUNIT_ASSERT_EQUAL(queenB->move(Coordinate('C','2'), board, *game), false); //checks if QueenB can take the place of QueenC
  CPPUNIT_ASSERT(board->getCase(Coordinate('B','1')) == queenB); //checks if queenB is in B1
  CPPUNIT_ASSERT(board->getCase(Coordinate('C','2')) == queenC); //checks if queenC is in C2
  CPPUNIT_ASSERT(queenB->_coords == Coordinate('B','1'));//checks coords of QueenB
  CPPUNIT_ASSERT(queenC->_coords == Coordinate('C','2'));//checks coords of QueenC

  //piece in the way
  CPPUNIT_ASSERT_EQUAL(queenD->move(Coordinate('F','3'), board, *game), false);//checks if QueenD cant pass over the place of QueenE
  CPPUNIT_ASSERT(queenD->_coords == Coordinate('D','1'));//checks coords of QueenD
  CPPUNIT_ASSERT(board->getCase(Coordinate('F','3')) == nullptr); //checks if queenD is not in F3
  CPPUNIT_ASSERT(board->getCase(Coordinate('D','1')) == queenD); //checks if queenD is in D1

  //wrong move
  CPPUNIT_ASSERT_EQUAL(queenE->move(Coordinate('G','7'), board, *game), false);
  CPPUNIT_ASSERT(queenE->_coords == Coordinate('E','2'));//checks coords of QueenE
  CPPUNIT_ASSERT(board->getCase(Coordinate('G','7')) == nullptr); //checks if queenE is not in G7
  CPPUNIT_ASSERT(board->getCase(Coordinate('E','2')) == queenE); //checks if queenE is in E2

  //good move
  CPPUNIT_ASSERT_EQUAL(queenH->move(Coordinate('A','5'), board, *game), true); // make queenA move to A5
  CPPUNIT_ASSERT(board->getCase(Coordinate('A','5')) == queenH); //checks if queenH is in A5
  CPPUNIT_ASSERT(board->getCase(Coordinate('C','7')) == nullptr); //checks if queenH is not in C7
  CPPUNIT_ASSERT(queenH->_coords == Coordinate('A','5')); //checks coords of QueenH

  CPPUNIT_ASSERT_EQUAL(queenI->move(Coordinate('G','3'), board, *game), true); // make queenH move to G3
  CPPUNIT_ASSERT(board->getCase(Coordinate('G','3')) == queenI); //checks if queenH is in G3
  CPPUNIT_ASSERT(board->getCase(Coordinate('H','2')) == nullptr); //checks if queenH is not in H2
  CPPUNIT_ASSERT(queenI->_coords == Coordinate('G','3')); //checks coords of QueenH

  CPPUNIT_ASSERT_EQUAL(queenJ->move(Coordinate('G','5'), board, *game), true); // make queenJ move to G5
  CPPUNIT_ASSERT(board->getCase(Coordinate('G','5')) == queenJ); //checks if queenJ is in G5
  CPPUNIT_ASSERT(board->getCase(Coordinate('E','7')) == nullptr); //checks if queenJ is not in E7
  CPPUNIT_ASSERT(queenJ->_coords == Coordinate('G','5')); //checks coords of QueenJ

  CPPUNIT_ASSERT_EQUAL(queenL->move(Coordinate('D','6'), board, *game), true); // make queenL move to D6
  CPPUNIT_ASSERT(board->getCase(Coordinate('D','6')) == queenL); //checks if queenL is in D6
  CPPUNIT_ASSERT(board->getCase(Coordinate('B','4')) == nullptr); //checks if queenL is not in B4
  CPPUNIT_ASSERT(queenL->_coords == Coordinate('D','6')); //checks coords of QueenL

  //wrong move due to check
  game->changeTestCheck();

  CPPUNIT_ASSERT_EQUAL(queenF->move(Coordinate('F','5'), board, *game), false); // make queenF move to F5
  CPPUNIT_ASSERT(board->getCase(Coordinate('E','4')) == queenF); //checks if queenF is in E4
  CPPUNIT_ASSERT(board->getCase(Coordinate('F','5')) == queenM); //checks if queenC is in F5
  CPPUNIT_ASSERT(queenF->_coords == Coordinate('E','4'));//checks coords of QueenF
  CPPUNIT_ASSERT(queenM->_coords == Coordinate('F','5'));//checks coords of QueenM

  game->changeTestCheck();

  //out of bounds
  CPPUNIT_ASSERT_THROW(queenK->move(Coordinate('I','5'), board, *game), std::out_of_range); // make queenK move to I5



}

void TestQueen:: testCheckMove()
{
  //Bishop part

  //black eats white
  CPPUNIT_ASSERT_EQUAL(queenA->_checkMove(Coordinate('B','2'), board, *game), true);

  //black tries to eat black
  CPPUNIT_ASSERT_EQUAL(queenB->_checkMove(Coordinate('C','2'), board, *game), false);

  //piece in the way
  CPPUNIT_ASSERT_EQUAL(queenD->_checkMove(Coordinate('F','3'), board, *game), false);

  //wrong move
  CPPUNIT_ASSERT_EQUAL(queenE->_checkMove(Coordinate('G','7'), board, *game), false);

  //good move
  CPPUNIT_ASSERT_EQUAL(queenH->_checkMove(Coordinate('A','5'), board, *game), true);
  CPPUNIT_ASSERT_EQUAL(queenI->_checkMove(Coordinate('G','3'), board, *game), true);
  CPPUNIT_ASSERT_EQUAL(queenJ->_checkMove(Coordinate('G','5'), board, *game), true);
  CPPUNIT_ASSERT_EQUAL(queenL->_checkMove(Coordinate('D','6'), board, *game), true);
}

#endif
