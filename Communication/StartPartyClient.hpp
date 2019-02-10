#ifndef _STARTPARTYCLIENT_H_
#define _STARTPARTYCLIENT_H_

#include "Socket.hpp"

void startPartyClient(Socket* player){
  /*
  Lance une partie d'echec entre deux joueurs (code client)
  Socket* player : socket du joueur qui a lance la partie
  */

  int turn; // Numero du tour actuel
  bool valid_move = false; // Indique si move du joueur est valid_move
  bool play_first;

  std::cout << "La partie commence !" << std::endl;

  // 1.Le joueur qui recoit 1 commence en premier
  play_first = (player->receiveMessage() == "1");

  // 2.Recois le plateau
  player->receiveBoard();

  while (true){
    // 3.Recupere le numero du tour actuel
    turn = atoi(player->receiveMessage());

    // Verifie si c'est au tour du joueur
    if (turn % 2 == play_first){
      // 4.Le joueur peut jouer
      while (!valid_move){
        player->sendMessage(/* Move du joueur*/);
        valid_move = (player->receiveMessage() == "1");
      }

      valid_move = false; // Reset valid_move pour le prochain move
    }

    // 5.Update le plateau du joueurs
    player->receiveBoard();

    // 6.Verifie s'il y a eu checkmate ou partie nouvelle
    if (player->receiveMessage() == "1"){ break; }
  }

  // 11.Reception des resultats
  std::cout << "Le gagnant est : " << player->receiveMessage() << std::endl;
  std::cout << "Fin de la partie !" << std::endl;
}

#endif
