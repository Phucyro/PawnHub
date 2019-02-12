#ifndef __TEST__BISHOP__HPP__
#define __TEST__BISHOP__HPP__

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Bishop.hpp"
#include "Coordinate.hpp"

class TestBishop: public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE (TestBishop);
	CPPUNIT_TEST (testCopyState);
	CPPUNIT_TEST (testMovePiece);
	CPPUNIT_TEST (testSetCase);
	CPPUNIT_TEST (testGetCase);
	CPPUNIT_TEST_SUITE_END ();

	private:
	Bishop bishopB;
  Bishop bishopW;

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
