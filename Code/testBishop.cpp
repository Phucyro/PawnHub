#ifndef __TEST__BISHOP__CPP__
#define __TEST__BISHOP__CPP__

#include <exception>
#include "testBishop.hpp"
#include "Coordinate.hpp"
#include "Board.hpp"
#include "Game.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION (TestBishop);

void TestBishop :: setUp()
{
  game = new SimpleGame();
  board = new Board();
  //black eats white
	bishopA = new Bishop('b',Coordinate('A','1'));
  bishopG = new Bishop('w',Coordinate('B','2'));

  //black tries to eat black
  bishopB = new Bishop('b',Coordinate('B','1'));
  bishopC = new Bishop('b',Coordinate('C','2'));

  //piece in the way
  bishopD = new Bishop('b',Coordinate('D','1'));

  //wrong move
  bishopE = new Bishop('b',Coordinate('E','2'));

  //wrong move due to check
  bishopF = new Bishop('w',Coordinate('E','4'));
  bishopM = new Bishop('b',Coordinate('F','5'));

  //good move
  bishopH = new Bishop('w',Coordinate('C','7'));
  bishopI = new Bishop('w',Coordinate('H','2'));
  bishopJ = new Bishop('w',Coordinate('E','7'));
  bishopL = new Bishop('w',Coordinate('B','4'));

  //out of bounds move
  bishopK = new Bishop('w',Coordinate('E','1'));

}


void TestBishop :: tearDown()
{
	delete bishopA;
  delete bishopB;
  delete bishopC;
  delete bishopD;
  delete bishopE;
  delete bishopF;
  delete bishopG;
  delete bishopH;
  delete bishopI;
  delete bishopJ;
  delete bishopK;
  delete bishopL;
  delete bishopM;
  delete game;
  delete board
}


void TestBishop :: testMove()
{
  //black eats white
  CPPUNIT_ASSERT_EQUAL(bishopA->move(Coordinate('B','2'), board, game), true); // make bishopA move to B2
  CPPUNIT_ASSERT_EQUAL(board->getCase(Coordinate('B','2')),bishopA); //checks if bishopA is in B2
  CPPUNIT_ASSERT(bishopG->isTaken()); //checks if bishopG was taken correctly
  CPPUNIT_ASSERT(bishopA->_coords == Coordinate('B','2')); //checks coords of BishopA

  //black tries to eat black
  CPPUNIT_ASSERT_EQUAL(bishopB->move(Coordinate('C','2'), board, game), false); //checks if BishopB can take the place of BishopC
  CPPUNIT_ASSERT_EQUAL(board->getCase(Coordinate('B','1')),bishopB); //checks if bishopB is in B1
  CPPUNIT_ASSERT_EQUAL(board->getCase(Coordinate('C','2')),bishopC); //checks if bishopC is in C2
  CPPUNIT_ASSERT(bishopB->_coords == Coordinate('B','1'));//checks coords of BishopB
  CPPUNIT_ASSERT(bishopC->_coords == Coordinate('C','2'));//checks coords of BishopC

  //piece in the way
  CPPUNIT_ASSERT_EQUAL(bishoD->move(Coordinate('F','3'), board, game), false);//checks if BishopD can pass over the place of BishopE
  CPPUNIT_ASSERT(bishopD->_coords == Coordinate('D','1'));//checks coords of BishopD
  CPPUNIT_ASSERT_EQUAL(board->getCase(Coordinate('F','3')),nullptr); //checks if bishopD is not in F3
  CPPUNIT_ASSERT_EQUAL(board->getCase(Coordinate('D','1')),bishopD); //checks if bishopD is in D1

  //wrong move
  CPPUNIT_ASSERT_EQUAL(bishopE->move(Coordinate('G','7'), board, game), false);
  CPPUNIT_ASSERT(bishopE->_coords == Coordinate('E','2'));//checks coords of BishopE
  CPPUNIT_ASSERT_EQUAL(board->getCase(Coordinate('G','7')),nullptr); //checks if bishopE is not in G7
  CPPUNIT_ASSERT_EQUAL(board->getCase(Coordinate('E','2')),bishopE); //checks if bishopE is in E2

  //good move
  CPPUNIT_ASSERT_EQUAL(bishopH->move(Coordinate('A','5'), board, game), true); // make bishopA move to A5
  CPPUNIT_ASSERT_EQUAL(board->getCase(Coordinate('A','5')),bishopH); //checks if bishopH is in A5
  CPPUNIT_ASSERT_EQUAL(board->getCase(Coordinate('C','7')),nullptr); //checks if bishopH is not in C7
  CPPUNIT_ASSERT(bishopH->_coords == Coordinate('A','5')); //checks coords of BishopH

  CPPUNIT_ASSERT_EQUAL(bishopI->move(Coordinate('G','3'), board, game), true); // make bishopH move to G3
  CPPUNIT_ASSERT_EQUAL(board->getCase(Coordinate('G','3')),bishopI); //checks if bishopH is in G3
  CPPUNIT_ASSERT_EQUAL(board->getCase(Coordinate('H','2')),nullptr); //checks if bishopH is not in H2
  CPPUNIT_ASSERT(bishopI->_coords == Coordinate('G','3')); //checks coords of BishopH

  CPPUNIT_ASSERT_EQUAL(bishopJ->move(Coordinate('G','5'), board, game), true); // make bishopJ move to G5
  CPPUNIT_ASSERT_EQUAL(board->getCase(Coordinate('G','5')),bishopJ); //checks if bishopJ is in G5
  CPPUNIT_ASSERT_EQUAL(board->getCase(Coordinate('E','7')),nullptr); //checks if bishopJ is not in E7
  CPPUNIT_ASSERT(bishopJ->_coords == Coordinate('G','5')); //checks coords of BishopJ

  CPPUNIT_ASSERT_EQUAL(bishopL->move(Coordinate('D','6'), board, game), true); // make bishopL move to D6
  CPPUNIT_ASSERT_EQUAL(board->getCase(Coordinate('D','6')),bishopL); //checks if bishopL is in D6
  CPPUNIT_ASSERT_EQUAL(board->getCase(Coordinate('B','4')),nullptr); //checks if bishopL is not in B4
  CPPUNIT_ASSERT(bishopL->_coords == Coordinate('D','6')); //checks coords of BishopL


  //out of bounds
  CPPUNIT_ASSERT_THROW(bishopK->move(Coordinate('I','5'), board, game), std::out_of_range); // make bishopK move to I5

  //wrong move due to check
  game->changeTestCheck();

  CPPUNIT_ASSERT_EQUAL(bishopF->move(Coordinate('F','5'), board, game), false); // make bishopF move to F5
  CPPUNIT_ASSERT_EQUAL(board->getCase(Coordinate('E','4')),bishopF); //checks if bishopF is in E4
  CPPUNIT_ASSERT_EQUAL(board->getCase(Coordinate('F','5')),bishopM); //checks if bishopC is in F5
  CPPUNIT_ASSERT(bishopF->_coords == Coordinate('E','4'));//checks coords of BishopF
  CPPUNIT_ASSERT(bishopM->_coords == Coordinate('F','5'));//checks coords of BishopM

}

void TestBishop:: testCheckMove()
{
  //black eats white
  CPPUNIT_ASSERT_EQUAL(bishopA->_checkMove(Coordinate('B','2'), board, game), true)

  //black tries to eat black
  CPPUNIT_ASSERT_EQUAL(bishopB->_checkMove(Coordinate('C','2'), board, game), false);

  //piece in the way
  CPPUNIT_ASSERT_EQUAL(bishopD->_checkMove(Coordinate('F','3'), board, game), false);

  //wrong move
  CPPUNIT_ASSERT_EQUAL(bishopE->_checkMove(Coordinate('G','7'), board, game), false);

  //good move
  CPPUNIT_ASSERT_EQUAL(bishopH->_checkMove(Coordinate('A','5'), board, game), true);
  CPPUNIT_ASSERT_EQUAL(bishopI->_checkMove(Coordinate('G','3'), board, game), true);
  CPPUNIT_ASSERT_EQUAL(bishopJ->_checkMove(Coordinate('G','5'), board, game), true);
  CPPUNIT_ASSERT_EQUAL(bishopL->_checkMove(Coordinate('D','6'), board, game), true);

  //wrong move due to check
  game->changeTestCheck();
  CPPUNIT_ASSERT_EQUAL(bishopF->_checkMove(Coordinate('F','5'), board, game), false);
}

#endif
