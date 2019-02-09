#include "config.hpp"
#include "BindSocket.hpp"
#include <queue>
#include <thread>

void startParty(Socket socket1, Socket socket2){
  // Lance une partie
  std::cout << "La partie commence" << std::endl;
  std::cout << "Joueur 1 " << socket1.getFileDescriptor() << std::endl;
  std::cout << "Joueur 2 " << socket2.getFileDescriptor() << std::endl;

  while (true){
    // Demande input
  }
}


int main(){
  // Initialisation socket serveur
  BindSocket binding_socket;

  // Met le socket serveur en attente de connexions
  binding_socket.activate();

  while (true){
    std::queue<int> players; // Vecteur filedescriptors des joueurs connectes
    Socket client_socket = binding_socket.createSocket();
    players.push(client_socket.getFileDescriptor()); // Ajoute le joueur
    std::cout << players.size() << std::endl;

    // Gere la demande du client avec des threads
    std::cout << "Connected to " << client_socket.getFileDescriptor() << std::endl;

    // Lance une partie avec les deux premiers joueurs arrives
    if (players.size() >= 1){
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
