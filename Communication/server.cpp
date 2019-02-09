#include "config.hpp"
#include "BindSocket.hpp"
#include <queue>
#include <thread>

void startParty(Socket white_player, Socket black_player){
  // Lance une partie
  std::cout << "La partie commence" << std::endl;
  std::cout << "Joueur 1 " << white_player.getFileDescriptor() << std::endl;
  std::cout << "Joueur 2 " << black_player.getFileDescriptor() << std::endl;

  int turn = 1;
  int turn_color = 0;

  while (true){
    // Envoie le nombre de tour + tour couleur : format tour-couleur
    white_player.sendMessage(std::to_string(turn) + "-" + std::to_string(turn_color));
    turn_color = (turn_color == 0)
    ++turn;
  }
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
      Socket player1 = Socket(players.front());
      players.pop();
      Socket player2 = Socket(players.front());
      players.pop();
      std::thread partyThread(startParty, player1, player2);
      partyThread.join();
    }



    // Operation serveur
  }

  return 0;
}
