all: mainTest

mainTest: testCoordinate.o testBoard.o Board.o Coordinate.o mainTest.cpp Piece.hpp
	g++ -Wall testBoard.o Piece.hpp Coordinate.o Board.o testCoordinate.o mainTest.cpp -o mainTest -lcppunit

testCoordinate.o: testCoordinate.cpp testCoordinate.hpp Coordinate.hpp
	g++ -c -Wall testCoordinate.cpp -lcppunit

testBoard.o: testBoard.cpp testBoard.hpp Piece.hpp Board.hpp Coordinate.hpp
	g++ -c -Wall testBoard.cpp -lcppunit


Coordinate.o: Coordinate.cpp Coordinate.hpp
	g++ -c -Wall Coordinate.cpp

Board.o: Board.cpp Board.hpp Coordinate.hpp Piece.hpp
	g++ -c -Wall Board.cpp
