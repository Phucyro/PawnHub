#ifndef _STARTPARTYSERVER_H_
#define _STARTPARTYSERVER_H_

#include "Socket.hpp"

void startPartyServer(Socket* white_player, Socket* black_player){
  /*
  Lance une partie d'echec entre deux joueurs (code serveur)
  Socket* white_player : Socket du premier joueur
  Socket* black_player : Socket du deuxieme joueur
  */

  int turn = 1; // Numero du tour actuel
  bool valid_move = false; // Indique si move du joueur est valide

  std::cout << "La partie commence !" << std::endl;

  // 1.Le joueur blanc commence en premier (1 = first)
  white_player->sendMessage("1");
  black_player->sendMessage("0");

  // 2.Envoie le plateau aux deux joueurs
  white_player->sendBoard();
  black_player->sendBoard();

  while (true){
    // 3.Envoie le numero du tour actuel au deux joueurs
    white_player->sendMessage(std::to_string(turn));
    black_player->sendMessage(std::to_string(turn));

    // 4.Le joueur blanc peut jouer
    while (!valid_move){
      white_player->receiveMove();
      /* Verifie si le move est correcte */
      white_player->sendMessage(/* Dis si move ok ou non*/);
    }

    valid_move = false; // Met move = false pour le joueur noir

    // 5.Update le plateau chez les deux joueurs
    white_player->sendBoard();
    black_player->sendBoard();

    // 6.Verifie si checkmate ou partie nulle
    white_player->sendMessage(/* Partie se termine ? */);
    black_player->sendMessage(/* Partie se termine ? */);
    if (/* checkmate || draw */) { break; }


    ++turn; // Au tour du deuxieme joueur

    // 7.Envoie le numero du tour actuel au deux joueurs
    white_player->sendMessage(std::to_string(turn));
    black_player->sendMessage(std::to_string(turn));

    // 8.Le joueur noir peut jouer
    while (!valid_move){
      black_player->receiveMove();
      /* Verifie si le move est correcte */
      black_player->sendMessage(/* Dis si move ok ou non*/);
    }

    valid_move = false; // Met move = false pour le joueur noir

    // 9.Update le plateau chez les deux joueurs
    white_player->sendBoard();
    black_player->sendBoard();

    // 10.Verifie si checkmate ou partie nulle
    if (/* checkmate || draw */){ break; }

    ++turn;
  }

  // 11.Envoi des résultats
  white_player->sendMessage(/* Envoie le gagnant */);
  black_player->sendMessage(/* Envoie le gagnant */);

  std::cout << "Fin de la partie !" << std::endl;
}

#endif
