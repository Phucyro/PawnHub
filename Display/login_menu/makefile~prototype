FLAGS= -std=c++17 -masm=intel -Wpedantic -Wall -Wextra -Wconversion -Weffc++ \
		-Wstrict-null-sentinel -Wold-style-cast -Wnoexcept -Wctor-dtor-privacy \
		-Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant \
		-Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override

LFLAGS= -pthread -lncurses

all: menu.o main.out

menu.o: menu.cpp menu.hpp
	g++ $(FLAGS) $< -c -o $@ $(LFLAGS)

main.out: main.cpp menu.o
	g++ $(FLAGS) $< -o $@ $(LFLAGS)

.PHONY: clean

clean:
	rm -f *.o *.out
