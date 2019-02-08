FLAGS= -std=c++14 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Weffc++ -Wstrict-null-sentinel -Wold-style-cast -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override

CXX= g++

CONFIG= config.hpp

all: run

run: server client
	./$<

client: client.cpp $(CONFIG)
	$(CXX) $(FLAGS) $< -o $@

server: serveur.cpp $(CONFIG)
	$(CXX) $(FLAGS) $< -o $@
