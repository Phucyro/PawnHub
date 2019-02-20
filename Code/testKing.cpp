#ifndef __TEST__KING__CPP__
#define __TEST__KING__CPP__

#include <exception>
#include <iostream>
#include "testKing.hpp"
#include "Coordinate.hpp"
#include "Board.hpp"
#include "Pawn.hpp"
#include "Rook.hpp"
#include "Game.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION (TestKing);

void TestKing :: setUp()
{
  game = new SimpleGame();
  board = new Board();
  //black eats white
	kingA = new King('b',Coordinate('A','1'));
  board->setCase(Coordinate('A','1'), kingA);
  pawnG = new Pawn('w',Coordinate('B','2'));
  board->setCase(Coordinate('B','2'),pawnG);

  //black tries to eat black
  kingB = new King('b',Coordinate('B','1'));
  board->setCase(Coordinate('B','1'), kingB);
  pawnC = new Pawn('b',Coordinate('C','2'));
  board->setCase(Coordinate('C','2'),pawnC);

  //wrong move
  kingE = new King('b',Coordinate('E','2'));
  board->setCase(Coordinate('E','2'),kingE);

  //good move
  kingH = new King('w',Coordinate('C','6'));
  board->setCase(Coordinate('C','6'), kingH);

  //roque
  kingI = new King('w',Coordinate('E','1'));
  board->setCase(Coordinate('E','1'),kingI);
  Rook1 = new Rook('w',Coordinate('H','1'));
  board->setCase(Coordinate('H','1'), Rook1);

  //grand roque
  kingL = new King('w', Coordinate('E', '8'));
  board->setCase(Coordinate('E', '8'), kingL);
  Rook2 = new Rook('w', Coordinate('A', '8'));
  board->setCase(Coordinate('A', '8'), Rook2);



  //out of bounds move
  //kingK = new King('w',Coordinate('H','8'));
  //board->setCase(Coordinate('H','8'),kingK);
}


void TestKing :: tearDown()
{
	delete kingA;
  delete kingB;
  delete pawnC;
  //delete kingD;
  delete kingE;
  //delete kingF;
  delete pawnG;
  delete kingH;
  delete kingI;
  //delete kingJ;
  //delete kingK;
  delete kingL;
  //delete kingM;
  //delete kingN;
  //delete kingO;
  //delete kingP;
  delete Rook1;
  delete Rook2;
  delete game;
  delete board;
}


void TestKing :: testMove()
{
  //black eats white
  CPPUNIT_ASSERT_EQUAL(kingA->move(Coordinate('B','2'), board, *game), true); // make kingA move to B2
  CPPUNIT_ASSERT(board->getCase(Coordinate('B','2')) == kingA); //checks if kingA is in B3
  CPPUNIT_ASSERT(pawnG->isTaken()); //checks if kingG was taken correctly
  CPPUNIT_ASSERT(kingA->getCoord() == Coordinate('B','2')); //checks coords of KingA

  //black tries to eat black
  CPPUNIT_ASSERT_EQUAL(kingB->move(Coordinate('C','3'), board, *game), false); //checks if KingB can take the place of KingC
  CPPUNIT_ASSERT(board->getCase(Coordinate('B','1')) == kingB); //checks if kingB is in B1
  CPPUNIT_ASSERT(board->getCase(Coordinate('C','2')) == pawnC); //checks if pawnC is in C3
  CPPUNIT_ASSERT(kingB->getCoord() == Coordinate('B','1'));//checks coords of KingB
  CPPUNIT_ASSERT(pawnC->getCoord() == Coordinate('C','2'));//checks coords of KingC

  //wrong move
  CPPUNIT_ASSERT_EQUAL(kingE->move(Coordinate('G','7'), board, *game), false);
  CPPUNIT_ASSERT(kingE->getCoord() == Coordinate('E','2'));//checks coords of KingE
  CPPUNIT_ASSERT(board->getCase(Coordinate('G','7')) == nullptr); //checks if kingE is not in G7
  CPPUNIT_ASSERT(board->getCase(Coordinate('E','2')) == kingE); //checks if kingE is in E2

  //good move

  CPPUNIT_ASSERT_EQUAL(kingH->move(Coordinate('C','7'), board, *game), true); // make kingA move to A5 -2 -1
  CPPUNIT_ASSERT(board->getCase(Coordinate('C','7')) == kingH); //checks if kingH is in A5
  CPPUNIT_ASSERT(board->getCase(Coordinate('C','6')) == nullptr); //checks if kingH is not in C6
  CPPUNIT_ASSERT(kingH->getCoord() == Coordinate('C','7')); //checks coords of KingH

  //roque fail
  game->changeTestCheck();
  CPPUNIT_ASSERT_EQUAL(kingI->move(Coordinate('G','1'), board, *game), false); // make kingH move to G4 -1  2
  CPPUNIT_ASSERT(board->getCase(Coordinate('G','1')) == nullptr); //checks if kingH is in G
  CPPUNIT_ASSERT(board->getCase(Coordinate('E','1')) == kingI); //checks if kingH is not in H2
  CPPUNIT_ASSERT(kingI->getCoord() == Coordinate('E','1')); //checks coords of KingH
  CPPUNIT_ASSERT(board->getCase(Coordinate('H','1')) == Rook1); //checks if Rook is in f5
  CPPUNIT_ASSERT(board->getCase(Coordinate('F','1')) == nullptr); //checks if Rook is not in E7
  CPPUNIT_ASSERT(Rook1->getCoord() == Coordinate('H','1')); //checks coords of KingJ

  //good move
  game->changeTestCheck();
  CPPUNIT_ASSERT_EQUAL(kingE->move(Coordinate('E', '3'), board, *game), true);
  CPPUNIT_ASSERT(board->getCase(Coordinate('E','2')) == nullptr); //checks if kingH is in G
  CPPUNIT_ASSERT(board->getCase(Coordinate('E','3')) == kingE); //checks if kingH is not in H2
  CPPUNIT_ASSERT(kingE->getCoord() == Coordinate('E','3')); //checks coords of KingH

  //roque success
  CPPUNIT_ASSERT_EQUAL(kingI->move(Coordinate('G','1'), board, *game), true); // make kingH move to G4 -1  2
  CPPUNIT_ASSERT(board->getCase(Coordinate('G','1')) == kingI); //checks if kingH is in G
  CPPUNIT_ASSERT(board->getCase(Coordinate('E','1')) == nullptr); //checks if kingH is not in H2
  CPPUNIT_ASSERT(kingI->getCoord() == Coordinate('G','1')); //checks coords of KingH
  CPPUNIT_ASSERT(board->getCase(Coordinate('F','1')) == Rook1); //checks if Rook is in f5
  CPPUNIT_ASSERT(board->getCase(Coordinate('H','1')) == nullptr); //checks if Rook is not in E7
  CPPUNIT_ASSERT(Rook1->getCoord() == Coordinate('F','1')); //checks coords of KingJ

  //grand roque fail
  game->changeTestCheck();
  CPPUNIT_ASSERT_EQUAL(kingL->move(Coordinate('C','8'), board, *game), false); // make kingL move to D5  2  1
  CPPUNIT_ASSERT(board->getCase(Coordinate('C','8')) == nullptr); //checks if kingL is in D5
  CPPUNIT_ASSERT(board->getCase(Coordinate('E','8')) == kingL); //checks if kingL is not in B4
  CPPUNIT_ASSERT(kingL->getCoord() == Coordinate('E','8')); //checks coords of KingL

  //grand roque success
  game->changeTestCheck();
  CPPUNIT_ASSERT_EQUAL(kingL->move(Coordinate('C','8'), board, *game), true); // make kingL move to D5  2  1
  CPPUNIT_ASSERT(board->getCase(Coordinate('C','8')) == kingL); //checks if kingL is in D5
  CPPUNIT_ASSERT(board->getCase(Coordinate('E','8')) == nullptr); //checks if kingL is not in B4
  CPPUNIT_ASSERT(kingL->getCoord() == Coordinate('C','8')); //checks coords of KingL
  CPPUNIT_ASSERT(board->getCase(Coordinate('D','8')) == Rook2); //checks if Rook is in f5
  CPPUNIT_ASSERT(board->getCase(Coordinate('A','8')) == nullptr); //checks if Rook is not in E7
  CPPUNIT_ASSERT(Rook2->getCoord() == Coordinate('D','8')); //checks coords of KingJ

/*
  CPPUNIT_ASSERT_EQUAL(kingD->move(Coordinate('B','6'), board, *game), true); // make kingD move to B6  1  2
  CPPUNIT_ASSERT(board->getCase(Coordinate('B','6')) == kingD); //checks if kingD is in B6
  CPPUNIT_ASSERT(board->getCase(Coordinate('A','4')) == nullptr); //checks if kingD is not in A4
  CPPUNIT_ASSERT(kingD->getCoord() == Coordinate('B','6')); //checks coords of KingD

  CPPUNIT_ASSERT_EQUAL(kingN->move(Coordinate('B','7'), board, *game), true); // make kingN move to B7 -2  1
  CPPUNIT_ASSERT(board->getCase(Coordinate('B','7')) == kingN); //checks if kingN is in B7
  CPPUNIT_ASSERT(board->getCase(Coordinate('D','6')) == nullptr); //checks if kingN is not in D6
  CPPUNIT_ASSERT(kingN->getCoord() == Coordinate('B','7')); //checks coords of KingN

  CPPUNIT_ASSERT_EQUAL(kingO->move(Coordinate('F','4'), board, *game), true); // make kingO move to F4 -1 -2
  CPPUNIT_ASSERT(board->getCase(Coordinate('F','4')) == kingO); //checks if kingO is in F4
  CPPUNIT_ASSERT(board->getCase(Coordinate('G','6')) == nullptr); //checks if kingO is not in G6
  CPPUNIT_ASSERT(kingO->getCoord() == Coordinate('F','4')); //checks coords of kingO

  CPPUNIT_ASSERT_EQUAL(kingP->move(Coordinate('H','1'), board, *game), true); // make kingP move to H1 2 -1
  CPPUNIT_ASSERT(board->getCase(Coordinate('H','1')) == kingP); //checks if kingP is in H1
  CPPUNIT_ASSERT(board->getCase(Coordinate('F','2')) == nullptr); //checks if kingP is not in F2
  CPPUNIT_ASSERT(kingP->getCoord() == Coordinate('H','1')); //checks coords of kingP

  //wrong move due to check
  game->changeTestCheck();

  CPPUNIT_ASSERT_EQUAL(kingF->move(Coordinate('F','6'), board, *game), false); // make kingF move to F5
  CPPUNIT_ASSERT(board->getCase(Coordinate('E','4')) == kingF); //checks if kingF is in E4
  CPPUNIT_ASSERT(board->getCase(Coordinate('F','6')) == kingM); //checks if pawnC is in F5
  CPPUNIT_ASSERT(kingF->getCoord() == Coordinate('E','4'));//checks coords of KingF
  CPPUNIT_ASSERT(kingM->getCoord() == Coordinate('F','6'));//checks coords of KingM

  game->changeTestCheck();
  //out of bounds
  //CPPUNIT_ASSERT_THROW(kingK->move(Coordinate('I','6'), board, *game), std::out_of_range); // make kingK move to I5
*/
}

void TestKing:: testCheckMove()
{
  //black eats white
  CPPUNIT_ASSERT_EQUAL(kingA->_checkMove(Coordinate('B','2'), board, *game), true);

  //black tries to eat black
  CPPUNIT_ASSERT_EQUAL(kingB->_checkMove(Coordinate('C','3'), board, *game), false);

  //wrong move
  CPPUNIT_ASSERT_EQUAL(kingE->_checkMove(Coordinate('G','7'), board, *game), false);

  //good move
  CPPUNIT_ASSERT_EQUAL(kingE->_checkMove(Coordinate('E','3'), board, *game), true);
  CPPUNIT_ASSERT_EQUAL(kingI->_checkMove(Coordinate('G','1'), board, *game), true);
  CPPUNIT_ASSERT_EQUAL(kingL->_checkMove(Coordinate('C','8'), board, *game), true);
}

#endif
