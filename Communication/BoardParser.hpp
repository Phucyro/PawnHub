#include <iostream>
#include <string>
#include <map>

/*
board sent as list of piece and position, white then black
each piece 3 characters: representation symbol + position in two characters
separation for white and black by !
padding with #
*/
#define CHAR_NUM 3

std::map<char, std::string> pieceMap = {
  {'p', "Pawn"},
  {'r', "Rook"},
  {'k', "Knight"},
  {'b', "Bishop"},
  {'q', "Queen"},
  {'K', "King"}
};

void separatePieces(unsigned int a, std::string message, std::string colour) {
  std::cout << "Piece : " << pieceMap[message[a]];
  std::cout << ", Position : " << message[a+1] << message[a+2];
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
  std::string msg = "pa2ka4r5dqc9Ke1bf8!ba8qg4Kd7#";
  return msg;
}
