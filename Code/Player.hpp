#ifndef __PLAYER__HPP__
#define __PLAYER__HPP__

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include "Game.hpp"
#include "Board.hpp"
class Socket{};
class Player{
	
	private :
	Socket *_sock;
	int *_pipe;
	
	public :
	Player(Socket* sock): _sock(sock), _pipe(nullptr){
		_pipe = new int[2];
		if ((pipe(_pipe)) == -1) throw std::runtime_error("Fail while constructing a pipe for an object of type 'Player': ");
	}
	Player(const Player&) = delete;
	Player(Player&& original): _sock(original._sock), _pipe(original._pipe){original._pipe = nullptr;}
	
	~Player(){
		delete[] _pipe;
		close(_pipe[0]);
		close(_pipe[1]);
	}
	
	Player& operator= (const Player&) = delete;
	Player& operator= (Player&& original);
	
	char* askMove();
	void showBoard(std::string);
	char askPromotion();
};

#endif
