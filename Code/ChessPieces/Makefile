FLAGS = -std=c++17 -masm=intel -fconcepts -mlong-double-128 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Wsign-conversion -Weffc++ -Wstrict-null-sentinel -Wold-style-cast -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override -lquadmath
OUT = compiled
CPP = Bishop.cpp
O = TestBishop.o
HPP = Bishop.hpp
CXX = g++

all: $(OUT) clean run

compiled : O
	$(CXX) $(FLAGS) $^ -o $(OUT)

TestBishop.o :
	$(CXX) $(FLAGS)

run : compiled
	./$<
clean:
	rm *.o

mrproper: clean
	rm -f test
.PHONY : clean
