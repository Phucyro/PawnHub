#ifndef __TEST__BISHOP__CPP__
#define __TEST__BISHOP__CPP__

#include "testBishop.hpp"
#include "Coordinate.hpp"
#include "Board.hpp"
#include "Game.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION (TestBishop);

void TestBishop :: setUp()
{
  coords = new Coordinate('A','1');
	bishopB = new Bishop('B',coords);
  bishopW = new Bishop('W','4','4');
}


void TestBishop :: tearDown()
{
	delete bishopB;
  delete bishopW;
}


void TestBishop :: testMove()
{

}

void TestBishop:: testCheckMove()
{

}

void TestBishop:: testGetColor()
{

}

void TestBishop:: testToString()
{

}

void TestBishop:: testChangeIsTaken()
{

}

void TestBishop:: testIsTaken()
{

}

void TestBishop :: testMovePiece()
{
	CPPUNIT_ASSERT_EQUAL (board->movePiece(Coordinate(0,0), Coordinate(5,2)), b);
	CPPUNIT_ASSERT (!(board->_state[0][0]));
	CPPUNIT_ASSERT_EQUAL (board->_state[5][2], a);
	CPPUNIT_ASSERT (!(board->movePiece(Coordinate(4,4), Coordinate(4,3))));
	CPPUNIT_ASSERT (!(board->_state[4][4]));
	CPPUNIT_ASSERT_EQUAL (board->_state[4][3], d);
}


void TestBoard :: testSetCase()
{
	board->setCase(Coordinate(2,3), d);
	CPPUNIT_ASSERT_EQUAL (board->_state[2][3], d);
}


void TestBoard :: testGetCase()
{
	CPPUNIT_ASSERT_EQUAL (board->getCase(Coordinate(0,0)), a);
	CPPUNIT_ASSERT (!(board->getCase(Coordinate(7,1))));
}

#endif
