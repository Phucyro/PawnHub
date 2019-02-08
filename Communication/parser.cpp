#include <iostream>
#include <string>
#include <map>

int main(){
  // Blanc puis noir et piece = char, pos1, pos2
  std::string msg = "pa2ka4r5dqc9Ke1bf8";

  // Dictionnaire clé : Symbole et valeur = Nom piece
  std::map<char, std::string> pieceName;
  pieceName['p'] = "Pawn";
  pieceName['r'] = "Rook";
  pieceName['k'] = "Knight";
  pieceName['b'] = "Bishop";
  pieceName['q'] = "Queen";
  pieceName['K'] = "King";


  for (unsigned int a = 0; a < msg.length(); a += 3){
    std::cout << "Piece : " << pieceName[msg[a]] << std::endl;
    std::cout << "Position : " << msg[a+1] << "-" << msg[a+2] << std::endl;
    std::cout << std::endl;
  }



  return 0;
}
