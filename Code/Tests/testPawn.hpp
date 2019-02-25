#ifndef __TEST__PAWN__HPP__
#define __TEST__PAWN__HPP__

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Pawn.hpp"
#include "Coordinate.hpp"
#include "SimpleGame.hpp"

class TestPawn: public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE (TestPawn);
	CPPUNIT_TEST (testMove);
	CPPUNIT_TEST (testCheckMove);
	CPPUNIT_TEST_SUITE_END ();

	private:
	Pawn *pawnA;
  Pawn *pawnB;
	Pawn *pawnC;
	Pawn *pawnD;
	Pawn *pawnE;
	Pawn *pawnF;
	Pawn *pawnG;
	Pawn *pawnH;
	Pawn *pawnI;
	Pawn *pawnJ;
	Pawn *pawnK;
	Pawn *pawnL;
	Pawn *pawnM;


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
