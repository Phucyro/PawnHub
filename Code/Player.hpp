#ifndef __PLAYER__HPP__
#define __PLAYER__HPP__

#include "Game.hpp"
#include "Board.hpp"
class Player{// TODO to link hthe game with the comm part
	public :
	char* askMove(){return new char('a');}
	void showBoard(Board*){}
};

#endif
