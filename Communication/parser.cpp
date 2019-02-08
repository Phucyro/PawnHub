#include <iostream>
#include <string>
#include <map>

int main(){
  // Message Recu (piece : symbol, pos, pos, color)
  std::string msg = "pa2Bka4Nr5dBqc9BKe1Nbf8B!";

  // Dictionnaire clé : Symbole et valeur = Nom piece
  std::map<char, std::string> pieceName;
  pieceName['p'] = "Pawn";
  pieceName['r'] = "Rook";
  pieceName['k'] = "Knight";
  pieceName['b'] = "Bishop";
  pieceName['q'] = "Queen";
  pieceName['K'] = "King";

  unsigned int a = 0;

  while (msg[a] != '!'){
    std::cout << "Piece : " << pieceName[msg[a]] << std::endl;
    std::cout << "Position : " << msg[a+1] << "-" << msg[a+2] << std::endl;
    std::string pieceColor = (msg[a+3] == 'B') ? "Blanc" : "Noir";
    std::cout << "Couleur : " << pieceColor << std::endl << std::endl;
    a += 4;
  }

  return 0;
}
