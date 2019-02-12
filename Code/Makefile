FLAGS= -std=c++14 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Wstrict-null-sentinel -Wold-style-cast -Weffc++ -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override -Woverloaded-virtual -Winline

all: mainTest

mainTest: testCoordinate.o testBoard.o Board.o Coordinate.o Game.o mainTest.cpp PieceTest.hpp Player.hpp
	g++ $(FLAGS) testBoard.o PieceTest.hpp Coordinate.o Board.o Player.hpp testCoordinate.o Game.o mainTest.cpp -o mainTest -lcppunit

testCoordinate.o: testCoordinate.cpp testCoordinate.hpp Coordinate.hpp
	g++ -c $(FLAGS) testCoordinate.cpp -lcppunit

testBoard.o: testBoard.cpp testBoard.hpp PieceTest.hpp Board.hpp Coordinate.hpp
	g++ -c $(FLAGS) testBoard.cpp -lcppunit


Coordinate.o: Coordinate.cpp Coordinate.hpp
	g++ -c $(FLAGS) Coordinate.cpp

Board.o: Board.cpp Board.hpp Coordinate.hpp PieceTest.hpp
	g++ -c $(FLAGS) Board.cpp

Game.o: Board.hpp Coordinate.hpp PieceTest.hpp Player.hpp Game.hpp Game.cpp
	g++ -c $(FLAGS) Game.cpp


