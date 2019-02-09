FLAGS= -std=c++14 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Weffc++ -Wstrict-null-sentinel -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override

CXX= g++

CONFIG= config.hpp
SOCKETS= Socket.o BindSocket.o

all: server client clean

run: all
	./server

client: client.o $(SOCKETS) $(CONFIG)
	$(CXX) $(FLAGS) -o $@ $^

server: server.o $(SOCKETS) $(CONFIG)
	$(CXX) $(FLAGS) -o $@ $^ -lpthread

%.o: %.cpp %.hpp
	$(CXX) $(FLAGS) -c -o $@ $<

clean:
	rm -f *.o

deepclean: clean
	rm -f server client
