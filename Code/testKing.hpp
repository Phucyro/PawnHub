#ifndef __TEST__KING__HPP__
#define __TEST__KING__HPP__

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "King.hpp"
#include "Pawn.hpp"
#include "Rook.hpp"
#include "Coordinate.hpp"
#include "SimpleGame.hpp"

class TestKing: public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE (TestKing);
	CPPUNIT_TEST (testMove);
	CPPUNIT_TEST (testCheckMove);
	CPPUNIT_TEST_SUITE_END ();

	private:
	King *kingA;
	King *kingB;
	Pawn *pawnC;
	King *kingE;
	Pawn *pawnG;
	King *kingH;
	King *kingI;
	King *kingL;
	Rook *Rook1;
  Rook *Rook2;


	SimpleGame *game;
	Board *board;

	protected:
	void testMove();
	void testCheckMove();

	public:
	void setUp();
	void tearDown();
};



#endif
