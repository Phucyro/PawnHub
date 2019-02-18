#ifndef __TEST__KING__CPP__
#define __TEST__KING__CPP__

#include <exception>
#include <iostream>
#include "testKing.hpp"
#include "Coordinate.hpp"
#include "Board.hpp"
#include "Game.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION (TestKing);

void TestKing :: setUp()
{
  game = new SimpleGame();
  board = new Board();
  //black eats white
	knightA = new King('b',Coordinate('A','1'));
  board->setCase(Coordinate('A','1'), knightA);
  knightG = new King('w',Coordinate('B','3'));
  board->setCase(Coordinate('B','3'),knightG);

  //black tries to eat black
  knightB = new King('b',Coordinate('B','1'));
  board->setCase(Coordinate('B','1'), knightB);
  knightC = new King('b',Coordinate('C','3'));
  board->setCase(Coordinate('C','3'),knightC);

  //wrong move
  knightE = new King('b',Coordinate('E','2'));
  board->setCase(Coordinate('E','2'),knightE);


  //wrong move due to check
  knightF = new King('w',Coordinate('E','4'));
  board->setCase(Coordinate('E','4'), knightF);
  knightM = new King('b',Coordinate('F','6'));
  board->setCase(Coordinate('F','6'),knightM);


  //good move
  knightH = new King('w',Coordinate('C','6'));
  board->setCase(Coordinate('C','6'), knightH);
  knightI = new King('w',Coordinate('H','2'));
  board->setCase(Coordinate('H','2'),knightI);
  knightJ = new King('w',Coordinate('E','7'));
  board->setCase(Coordinate('E','7'), knightJ);
  knightL = new King('w',Coordinate('B','4'));
  board->setCase(Coordinate('B','4'),knightL);
  knightD = new King('w',Coordinate('A','4'));
  board->setCase(Coordinate('A','4'), knightD);
  knightN = new King('w',Coordinate('D','6'));
  board->setCase(Coordinate('D','6'), knightN);
  knightO = new King('w',Coordinate('G','6'));
  board->setCase(Coordinate('G','6'), knightO);
  knightP = new King('w',Coordinate('F','2'));
  board->setCase(Coordinate('F','2'), knightP);


  //out of bounds move
  knightK = new King('w',Coordinate('H','8'));
  board->setCase(Coordinate('H','8'),knightK);
}


void TestKing :: tearDown()
{
	delete knightA;
  delete knightB;
  delete knightC;
  delete knightD;
  delete knightE;
  delete knightF;
  delete knightG;
  delete knightH;
  delete knightI;
  delete knightJ;
  delete knightK;
  delete knightL;
  delete knightM;
  delete knightN;
  delete knightO;
  delete knightP;
  delete game;
  delete board;
}


void TestKing :: testMove()
{
  //black eats white
  CPPUNIT_ASSERT_EQUAL(knightA->move(Coordinate('B','3'), board, *game), true); // make knightA move to B2
  CPPUNIT_ASSERT(board->getCase(Coordinate('B','3')) == knightA); //checks if knightA is in B3
  CPPUNIT_ASSERT(knightG->isTaken()); //checks if knightG was taken correctly
  CPPUNIT_ASSERT(knightA->_coords == Coordinate('B','3')); //checks coords of KingA

  //black tries to eat black
  CPPUNIT_ASSERT_EQUAL(knightB->move(Coordinate('C','3'), board, *game), false); //checks if KingB can take the place of KingC
  CPPUNIT_ASSERT(board->getCase(Coordinate('B','1')) == knightB); //checks if knightB is in B1
  CPPUNIT_ASSERT(board->getCase(Coordinate('C','3')) == knightC); //checks if knightC is in C3
  CPPUNIT_ASSERT(knightB->_coords == Coordinate('B','1'));//checks coords of KingB
  CPPUNIT_ASSERT(knightC->_coords == Coordinate('C','3'));//checks coords of KingC

  //wrong move
  CPPUNIT_ASSERT_EQUAL(knightE->move(Coordinate('G','7'), board, *game), false);
  CPPUNIT_ASSERT(knightE->_coords == Coordinate('E','2'));//checks coords of KingE
  CPPUNIT_ASSERT(board->getCase(Coordinate('G','7')) == nullptr); //checks if knightE is not in G7
  CPPUNIT_ASSERT(board->getCase(Coordinate('E','2')) == knightE); //checks if knightE is in E2

  //good move

  CPPUNIT_ASSERT_EQUAL(knightH->move(Coordinate('A','5'), board, *game), true); // make knightA move to A5 -2 -1
  CPPUNIT_ASSERT(board->getCase(Coordinate('A','5')) == knightH); //checks if knightH is in A5
  CPPUNIT_ASSERT(board->getCase(Coordinate('C','6')) == nullptr); //checks if knightH is not in C6
  CPPUNIT_ASSERT(knightH->_coords == Coordinate('A','5')); //checks coords of KingH

  CPPUNIT_ASSERT_EQUAL(knightI->move(Coordinate('G','4'), board, *game), true); // make knightH move to G4 -1  2
  CPPUNIT_ASSERT(board->getCase(Coordinate('G','4')) == knightI); //checks if knightH is in G
  CPPUNIT_ASSERT(board->getCase(Coordinate('H','2')) == nullptr); //checks if knightH is not in H2
  CPPUNIT_ASSERT(knightI->_coords == Coordinate('G','4')); //checks coords of KingH

  CPPUNIT_ASSERT_EQUAL(knightJ->move(Coordinate('F','5'), board, *game), true); // make knightJ move to F5  1 -2
  CPPUNIT_ASSERT(board->getCase(Coordinate('F','5')) == knightJ); //checks if knightJ is in f5
  CPPUNIT_ASSERT(board->getCase(Coordinate('E','7')) == nullptr); //checks if knightJ is not in E7
  CPPUNIT_ASSERT(knightJ->_coords == Coordinate('F','5')); //checks coords of KingJ

  CPPUNIT_ASSERT_EQUAL(knightL->move(Coordinate('D','5'), board, *game), true); // make knightL move to D5  2  1
  CPPUNIT_ASSERT(board->getCase(Coordinate('D','5')) == knightL); //checks if knightL is in D5
  CPPUNIT_ASSERT(board->getCase(Coordinate('B','4')) == nullptr); //checks if knightL is not in B4
  CPPUNIT_ASSERT(knightL->_coords == Coordinate('D','5')); //checks coords of KingL

  CPPUNIT_ASSERT_EQUAL(knightD->move(Coordinate('B','6'), board, *game), true); // make knightD move to B6  1  2
  CPPUNIT_ASSERT(board->getCase(Coordinate('B','6')) == knightD); //checks if knightD is in B6
  CPPUNIT_ASSERT(board->getCase(Coordinate('A','4')) == nullptr); //checks if knightD is not in A4
  CPPUNIT_ASSERT(knightD->_coords == Coordinate('B','6')); //checks coords of KingD

  CPPUNIT_ASSERT_EQUAL(knightN->move(Coordinate('B','7'), board, *game), true); // make knightN move to B7 -2  1
  CPPUNIT_ASSERT(board->getCase(Coordinate('B','7')) == knightN); //checks if knightN is in B7
  CPPUNIT_ASSERT(board->getCase(Coordinate('D','6')) == nullptr); //checks if knightN is not in D6
  CPPUNIT_ASSERT(knightN->_coords == Coordinate('B','7')); //checks coords of KingN

  CPPUNIT_ASSERT_EQUAL(knightO->move(Coordinate('F','4'), board, *game), true); // make knightO move to F4 -1 -2
  CPPUNIT_ASSERT(board->getCase(Coordinate('F','4')) == knightO); //checks if knightO is in F4
  CPPUNIT_ASSERT(board->getCase(Coordinate('G','6')) == nullptr); //checks if knightO is not in G6
  CPPUNIT_ASSERT(knightO->_coords == Coordinate('F','4')); //checks coords of knightO

  CPPUNIT_ASSERT_EQUAL(knightP->move(Coordinate('H','1'), board, *game), true); // make knightP move to H1 2 -1
  CPPUNIT_ASSERT(board->getCase(Coordinate('H','1')) == knightP); //checks if knightP is in H1
  CPPUNIT_ASSERT(board->getCase(Coordinate('F','2')) == nullptr); //checks if knightP is not in F2
  CPPUNIT_ASSERT(knightP->_coords == Coordinate('H','1')); //checks coords of knightP

  //wrong move due to check
  game->changeTestCheck();

  CPPUNIT_ASSERT_EQUAL(knightF->move(Coordinate('F','6'), board, *game), false); // make knightF move to F5
  CPPUNIT_ASSERT(board->getCase(Coordinate('E','4')) == knightF); //checks if knightF is in E4
  CPPUNIT_ASSERT(board->getCase(Coordinate('F','6')) == knightM); //checks if knightC is in F5
  CPPUNIT_ASSERT(knightF->_coords == Coordinate('E','4'));//checks coords of KingF
  CPPUNIT_ASSERT(knightM->_coords == Coordinate('F','6'));//checks coords of KingM

  game->changeTestCheck();
  //out of bounds
  //CPPUNIT_ASSERT_THROW(knightK->move(Coordinate('I','6'), board, *game), std::out_of_range); // make knightK move to I5

}

void TestKing:: testCheckMove()
{
  //black eats white
  CPPUNIT_ASSERT_EQUAL(knightA->_checkMove(Coordinate('B','3'), board, *game), true);

  //black tries to eat black
  CPPUNIT_ASSERT_EQUAL(knightB->_checkMove(Coordinate('C','3'), board, *game), false);

  //wrong move
  CPPUNIT_ASSERT_EQUAL(knightE->_checkMove(Coordinate('G','7'), board, *game), false);

  //good move
  CPPUNIT_ASSERT_EQUAL(knightH->_checkMove(Coordinate('A','5'), board, *game), true);
  CPPUNIT_ASSERT_EQUAL(knightI->_checkMove(Coordinate('G','4'), board, *game), true);
  CPPUNIT_ASSERT_EQUAL(knightJ->_checkMove(Coordinate('F','5'), board, *game), true);
  CPPUNIT_ASSERT_EQUAL(knightL->_checkMove(Coordinate('D','5'), board, *game), true);
  CPPUNIT_ASSERT_EQUAL(knightD->_checkMove(Coordinate('B','6'), board, *game), true);
  CPPUNIT_ASSERT_EQUAL(knightN->_checkMove(Coordinate('B','7'), board, *game), true);
  CPPUNIT_ASSERT_EQUAL(knightO->_checkMove(Coordinate('F','4'), board, *game), true);
  CPPUNIT_ASSERT_EQUAL(knightP->_checkMove(Coordinate('H','1'), board, *game), true);
}

#endif
