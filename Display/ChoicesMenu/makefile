FLAGS= -std=c++17 -masm=intel -Wpedantic -Wall -Wextra -Wconversion -Weffc++ \
		-Wstrict-null-sentinel -Wold-style-cast -Wnoexcept -Wctor-dtor-privacy \
		-Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant \
		-Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override

LFLAGS= -pthread -lncurses

all: main clean

ChoicesMenu.o: ChoicesMenu.cpp ChoicesMenu.hpp
	g++ $(FLAGS) $< -c -o $@ $(LFLAGS)

main: main.cpp ChoicesMenu.o
	g++ $(FLAGS) $< -o $@ $(LFLAGS)

.PHONY: clean

clean:
	rm -f *.o *.out
