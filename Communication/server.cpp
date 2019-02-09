#include "config.hpp"
#include "BindSocket.hpp"
#include <queue>
#include <thread>

void startParty(int fd1, int fd2){
  // Lance une partie
  std::cout << "La partie commence" << std::endl;
  std::cout << "Joueur 1 " << fd1 << std::endl;
  std::cout << "Joueur 2 " << fd2 << std::endl;
}


int main(){
  // Initialisation socket serveur
  BindSocket binding_socket;

  // Met le socket serveur en attente de connexions
  binding_socket.activate();

  while (true){
    std::queue<int> players; // Vecteur filedescriptors des joueurs connectes
    Socket client_socket = binding_socket.createSocket();
    players.push(client_socket.getFileDescriptor());

    // Gere la demande du client avec des threads
    std::cout << "Connected to " << client_socket.getFileDescriptor() << std::endl;

    // Lance une partie avec les deux premiers joueurs arrives
    if (players.size() >= 2){
      int player1 = players.front();
      players.pop();
      int player2 = players.front();
      players.pop();
      std::thread partyThread(startParty, player1, player2);
    }

    // Operation serveur
  }

  return 0;
}
