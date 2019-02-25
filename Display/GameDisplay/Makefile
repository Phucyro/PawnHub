FLAGS= -std=c++17 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Weffc++ \
		-Wstrict-null-sentinel -Wold-style-cast -Wnoexcept -Wctor-dtor-privacy \
		-Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant \
		-Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override

LFLAGS= -pthread -lncurses

all: board.o main.out

board.o: board.cpp board.hpp BoardParsing.hpp Coordinate.o
	g++ $(FLAGS) $< -c -o $@ $(LFLAGS)

Coordinate.o: Coordinate.cpp Coordinate.hpp
	g++ $(FLAGS) $< -c -o $@

main.out: main.cpp board.o
	g++ $(FLAGS) $< -o $@ $(LFLAGS)

.PHONY: clean

clean:
	rm -f *.o *.out
