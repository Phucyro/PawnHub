#ifndef __TEST__BOARD__CPP__
#define __TEST__BOARD__CPP__

#include"testBoard.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION (TestBoard);

void TestBoard :: setUp()
{
	board = new Board();
	a = new Piece();
	b = new Piece();
	c = new Piece();
	d = new Piece();
	board->_state[0][0] = a;
	board->_state[5][2] = b;
	board->_state[4][6] = c;
	board->_state[4][4] = d;
}


void TestBoard :: tearDown()
{
	delete board;
	delete a;
	delete b;
	delete c;
	delete d;
}




void TestBoard :: testCopyState()
{
	Board copy = Board();
	copy._copyState(*board);
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			CPPUNIT_ASSERT_EQUAL (board->_state[i][j], copy._state[i][j]);
		}
	}
}


void TestBoard :: testMovePiece()
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



















































