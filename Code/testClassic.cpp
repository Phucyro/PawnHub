#include <iostream>
#include "Classic.hpp"
#include "../Communication/Socket.hpp"

int main(){
	Socket s1 = Socket(), s2 = Socket();
	Player player1 = Player(), player2 = Player();
	player1.setSocket(&s1);
	player2.setSocket(&s2);
	Classic game = Classic(&player1, &player2);
	game.start();
	std::cout<<"Winner is player "<<(game.getWinner() == &player1 ? "w":"b")<<std::endl;
	
	return 0;
}
