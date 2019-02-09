#include "config.hpp"
#include "BindSocket.hpp"
#include <queue>
#include <thread>

void startParty(int player1, int player2, int server){
  /*
    Lance la partie entre deux joueurs
    int player1 : File descriptor du premier joueur
    int player2 : File descriptor du deuxieme joueur
    int server  : File descriptor du serveur
  */
  std::cout << "La partie commence :" << std::endl;
  std::cout << "Joueur 1 (Blanc) fd : " << fd1 << std::endl;
  std::cout << "Joueur 2 (Noir) fd : " << fd2 << std::endl;

  int turn = 1;
  int turn_color = 0; // 0 : blanc | 1 : noir

  while (true){
    // Envoie le nombre de tour + tour couleur : format tour-couleur
    server.sendMessage(std::to_string(turn) + "-" + std::to_string(turn_color));
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
      int player_fd1 = players.front();
      players.pop();
      int player_fd2 = players.front();
      players.pop();
      std::thread partyThread(startParty, player_fd1, player_fd2, binding_socket.getFileDescriptor());
      partyThread.join();
    }



    // Operation serveur
  }

  return 0;
}
