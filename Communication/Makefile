FLAGS= -std=c++17 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Weffc++ -Wstrict-null-sentinel -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override

CXX= g++

CONFIG= config.hpp
SOCKETS= Socket.o BindSocket.o

CLIENT_LFLAGS= -lpthread -lncurses
SERVER_LFLAGS= -lpthread

all: test_server test_client clean

test_server: test.cpp $(SOCKETS) $(CONFIG)
	$(CXX) $(FLAGS) -o $@ $^

test_client: test_client.cpp $(SOCKETS) $(CONFIG)
	$(CXX) $(FLAGS) -o $@ $^

%.o: %.cpp %.hpp
	$(CXX) $(FLAGS) -c -o $@ $<

clean:
	rm -f *.o

deepclean: clean
	rm -f test_server test_client
