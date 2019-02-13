#ifndef __TEST__BOARD__HPP__
#define __TEST__BOARD__HPP__

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Board.hpp"
#include "Game.hpp"
#include "Piece.hpp"

class P: public Piece{
	protected:

	public:
		P() :Piece('w',Coordinate('A','1')){}

		bool _checkMove(Coordinate, Board*, Game&) override {return true;}
};

class TestBoard: public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE (TestBoard);
	CPPUNIT_TEST (testCopyState);
	CPPUNIT_TEST (testMovePiece);
	CPPUNIT_TEST (testSetCase);
	CPPUNIT_TEST (testGetCase);
	CPPUNIT_TEST_SUITE_END ();

	private:
	Board* board;
	P *a, *b, *c, *d;

	protected:
	void testCopyState();
	void testMovePiece();
	void testSetCase();
	void testGetCase();

	public:
	void setUp();
	void tearDown();
};

#endif
