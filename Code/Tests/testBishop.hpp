#ifndef __TEST__BISHOP__HPP__
#define __TEST__BISHOP__HPP__

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Bishop.hpp"
#include "Coordinate.hpp"
#include "SimpleGame.hpp"

class TestBishop: public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE (TestBishop);
	CPPUNIT_TEST (testMove);
	CPPUNIT_TEST (testCheckMove);
	CPPUNIT_TEST_SUITE_END ();

	private:
	Bishop *bishopA;
  Bishop *bishopB;
	Bishop *bishopC;
	Bishop *bishopD;
	Bishop *bishopE;
	Bishop *bishopF;
	Bishop *bishopG;
	Bishop *bishopH;
	Bishop *bishopI;
	Bishop *bishopJ;
	Bishop *bishopK;
	Bishop *bishopL;
	Bishop *bishopM;


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
