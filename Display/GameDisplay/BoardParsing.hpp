#include <iostream>
#include <string>
#include <map>
#include <ncurses.h>
#include "../../Code/Coordinate.hpp"
#include "board.hpp"


#ifndef _BOARDPARSE_H_
#define _BOARDPARSE_H_
/*
board sent as list of piece and position, white then black
each piece 3 characters: representation symbol + position in two characters
separation for white and black by !
padding with #
*/
#define CHAR_NUM 3

std::map<const char,const char> pieceMap = {
  {'p', 'P'},
  {'r', 'R'},
  {'h', 'H'},
  {'b', 'B'},
  {'q', 'Q'},
  {'k', 'K'}
};

void separatePieces(unsigned int a, std::string message, std::string colour) {
  const char piece = pieceMap[message[a]];
  Coordinate coor(message[a+1], message[a+2]);
  int column = coor.getRealColumn();
  int line = coor.getRealRow();
  if (colour == "white") {
    attron(COLOR_PAIR(WHITE_PLAYER));
    mvprintw((line+1)*OFFSET, 1+((column+1)*OFFSET), "%c", piece);
    attroff(COLOR_PAIR(WHITE_PLAYER));
  }
  else {
    attron(COLOR_PAIR(BLACK_PLAYER));
    mvprintw((line+1)*OFFSET, 1+((column+1)*OFFSET), "%c", piece);
    attroff(COLOR_PAIR(BLACK_PLAYER));
  }
}

void stringToBoard(std::string message) {

  unsigned int a = 0;
  std::string colour = "white";
  while (message[a] != '!'){
    separatePieces(a, message, colour);
    a += CHAR_NUM;
  }
  a += 1;
  colour = "black";
  while (message[a] != '#'){
    separatePieces(a, message, colour);
    a += CHAR_NUM;
  }
}

void separateAlicePieces(unsigned a,std::string message,std::string colour) {
  const char piece = pieceMap[message[a]];
  Coordinate coor(message[a+1], message[a+2]);
  int column = coor.getRealColumn();
  int line = coor.getRealRow();
  if (colour == "white") {
    attron(COLOR_PAIR(WHITE_PLAYER));
    mvprintw(1+(line)*OFFSET, 54+((column+1)*OFFSET), "%c", piece);
    attroff(COLOR_PAIR(WHITE_PLAYER));
  }
  else {
    attron(COLOR_PAIR(BLACK_PLAYER));
    mvprintw(1+(line*OFFSET), 54+((column+1)*OFFSET), "%c", piece);
    attroff(COLOR_PAIR(BLACK_PLAYER));
  }
}

void aliceToBoard(std::string message) {
  unsigned int a = 0;
  std::string colour = "white";
  while (message[a] != '!'){
    separateAlicePieces(a, message, colour);
    a += CHAR_NUM;
  }
  a += 1;
  colour = "black";
  while (message[a] != '#'){
    separateAlicePieces(a, message, colour);
    a += CHAR_NUM;
  }
}

#endif
