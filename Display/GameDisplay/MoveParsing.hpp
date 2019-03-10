#include <iostream>
#include <string>

std::string moveToString(int* move) {
  std::string  translated_move;
  for (int i = 0; i < 4; ++i) {
    if ((i % 2) == 0 && move[i] > 96 && move[0] != 47) {//47 is '/'
      // We want the capital letter, so must translate if small given
      translated_move = translated_move.append(1, char(move[i] - 32));
    }
    else {
      translated_move = translated_move.append(1, char(move[i]));
    }
  }
  return translated_move;
}
