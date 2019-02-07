#ifndef __TEST__COORDINATE__HPP__
#define __TEST__COORDINATE__HPP__

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include"Coordinate.hpp"

class TestCoordinate: public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE (TestCoordinate);
	CPPUNIT_TEST (testAbstractConstructor);
	CPPUNIT_TEST (testEqual);	
	CPPUNIT_TEST (testGetAbstractColumn);
	CPPUNIT_TEST (testGetAbstractRow);
	CPPUNIT_TEST_SUITE_END ();
	
	private:
	Coordinate *a, *b, *c, *d;
	
	protected:
	void testAbstractConstructor(void);
	void testEqual(void);
	void testGetAbstractColumn(void);
	void testGetAbstractRow(void);
	
	public:
	void setUp (void);
	void tearDown (void);
};

#endif
