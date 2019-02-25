#ifndef __TEST__ROOK__HPP__
#define __TEST__ROOK__HPP__

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Rook.hpp"
#include "Coordinate.hpp"
#include "SimpleGame.hpp"

class TestRook: public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE (TestRook);
	CPPUNIT_TEST (testMove);
	CPPUNIT_TEST (testCheckMove);
	CPPUNIT_TEST_SUITE_END ();

	private:
	Rook *rookA;
  Rook *rookB;
	Rook *rookC;
	Rook *rookD;
	Rook *rookE;
	Rook *rookF;
	Rook *rookG;
	Rook *rookH;
	Rook *rookI;
	Rook *rookJ;
	Rook *rookK;
	Rook *rookL;
	Rook *rookM;


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
