#include <iostream>
#include <string>
#include <map>
#include "Coordinate.hpp"


#ifndef _BOARDPARSE_H_
#define _BOARDPARSE_H_
/*
board sent as list of piece and position, white then black
each piece 3 characters: representation symbol + position in two characters
separation for white and black by !
padding with #
*/
#define CHAR_NUM 3

std::map<char, std::string> pieceMap = {
  {'p', "P"},
  {'r', "R"},
  {'h', "H"},
  {'b', "B"},
  {'q', "Q"},
  {'k', "K"}
};

void separatePieces(unsigned int a, std::string message, std::string colour) {
  std::cout << "Piece : " << pieceMap[message[a]];
  Coordinate coor(message[a+1], message[a+2]);
  std::cout << ", Position : " << coor.getAbstractColumn() << coor.getAbstractRow();
  std::cout << ", Position : " << coor.getRealColumn() << coor.getRealRow();
  std::cout << ", is " << colour << "." << std::endl;
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

std::string boardToString() {
  std::string msg = "pA2hA4rD5qC9kE1bF8!bA8qG4kD7#";
  return msg;
}

#endif
