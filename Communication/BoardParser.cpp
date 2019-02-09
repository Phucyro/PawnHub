#include <iostream>
#include <string>
#include <map>

class BoardParser {
private:
  static std::map<char, std::string> createPieceMap() {
    std::map<char, std::string> m;
    m['p'] = "Pawn";
    m['r'] = "Rook";
    m['k'] = "Knight";
    m['b'] = "Bishop";
    m['q'] = "Queen";
    m['K'] = "King";
    return m;
  }
  const std::map<char, std::string> pieceMap = createPieceMap();
};
