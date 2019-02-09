#include <iostream>
#include <string>
#include <map>

/*
board sent as list of piece and position, white then black
each piece 3 characters: representation symbol + position in two characters
separation for white and black by !
padding with #
*/

std::map<char, std::string> pieceMap = {
  {'p', "Pawn"},
  {'r', "Rook"},
  {'k', "Knight"},
  {'b', "Bishop"},
  {'q', "Queen"},
  {'K', "King"}
};


void stringToBoard(std::string message) {
  unsigned int a = 0;
  while (message[a] != '!'){
    std::cout << "Piece : " << pieceMap[message[a]];
    std::cout << ", Position : " << message[a+1] << message[a+2];
    std::cout << ", is white." << std::endl;
    a += 3;
  }
  a += 1;
  while (message[a] != '#'){
    std::cout << "Piece : " << pieceMap[message[a]];
    std::cout << ", Position : " << message[a+1] << message[a+2];
    std::cout << ", is black." << std::endl;
    a += 3;
  }
}

std::string boardToString() {
  std::string msg = "pa2ka4r5dqc9Ke1bf8!ba8qg4Kd7#";
  return msg;
}
