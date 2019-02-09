#include "config.hpp"
#include "BindSocket.hpp"
#include <queue>
#include <thread>

void startParty(Socket* white_player, Socket* black_player){
  // Lance une partie
  std::cout << "La partie commence : " << std::endl;

  unsigned int turn = 0; // Numero du tour actuel
  bool valid_move;

  // Le joueur blanc commence en premier (0)
  white_player->sendMessage("0");
  black_player->sendMessage("1");

  // Envoie le plateau aux deux joueurs
  white_player->sendBoard();
  black_player->sendBoard();

  while (true){
    // Envoie information sur le tour (couleur qui joue et numero)
    white_player->sendMessage(std::to_string(turn) + " " + "B");
    black_player->sendMessage(std::to_string(turn) + " " + "B");

    while (true){ // while (move pas valide && temps < limite)
      white_player->receiveMove();
      // Verifie si move valid_move et sors de la boucle si valide
      white_player->sendMessage(/*Move valide ou pas*/)
    }

    // Update le plateau
    white_player->sendBoard();
    black_player->sendBoard();

    // Verifie checkmate ou draw ?
    // if (checkmate || draw){ break; }

    // Envoie information sur le tour (couleur qui joue et numero)
    white_player->sendMessage(std::to_string(turn) + " " + "N");
    black_player->sendMessage(std::to_string(turn) + " " + "N");

    while (true){ // while (move pas valide && temps < limite)
      black_player->receiveMove();
    }

    // Update le plateau
    white_player->sendBoard();
    black_player->sendBoard();

    // Verifie checkmate ou draw ?
    // if (checkmate || draw){ break; }

    ++turn;
  }

  std::cout << "Fin de la partie" << std::endl;
  // Determiner le vainqueur
}


int main(){
  // Initialisation socket serveur
  BindSocket binding_socket;

  // Met le socket serveur en attente de connexions
  binding_socket.activate();

  while (true){
    // Accepte les joueurs dans le serveur
    Socket client_socket = binding_socket.createSocket();

    std::queue<int> players; // File de filedescriptors des joueurs connectes
    players.push(client_socket.getFileDescriptor()); // Ajoute joueur dans file

    // Lance une partie avec les deux premiers joueurs arrives via thread
    if (players.size() >= 1){ // 2 ne marche pas pour le moment
      std::cout << "Cree une nouvelle partie" << std::endl;
      Socket player1 = Socket(players.front());
      players.pop();
      Socket player2 = Socket(players.front());
      players.pop();
      std::thread partyThread(startParty, &player1, new Socket());
      partyThread.join();
    }



    // Operation serveur
  }

  return 0;
}
