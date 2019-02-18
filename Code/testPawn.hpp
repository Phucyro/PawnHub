#ifndef __TEST__PAWN__HPP__
#define __TEST__PAWN__HPP__

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Pawn.hpp"
#include "Coordinate.hpp"
#include "Game.hpp"

class SimpleGame: public Game
{
	private:
	bool _testCheck;

	protected:
		void _initBoard() override{}
		void _nextTurn() override{}
		bool _isFinish() override{return true;}

	public:
	SimpleGame() : Game(nullptr, 0), _testCheck(false){}
	bool changeTestCheck(){_testCheck = !_testCheck;}
	bool testCheck(const char&, const unsigned&) override {return _testCheck;}

};

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
