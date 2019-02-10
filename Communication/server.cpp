#include "config.hpp"
#include "BindSocket.hpp"
#include <queue>
#include <thread>
// #include "startPartyServer.hpp"

int main(){
  // Initialisation socket serveur
  BindSocket binding_socket;

  // Met le socket serveur en attente de connexions
  binding_socket.activate();

  while (true){
    // Accepte les joueurs dans le serveur
    Socket client_socket = binding_socket.createSocket();

    std::queue<Socket> players; // Socket des joueurs connectes

    players.push(client_socket); // Ajoute socket joueur dans file

    // Lance une partie avec les deux premiers joueurs arrives via thread
    if (players.size() >= 2) {
      std::cout << "Cree une nouvelle partie" << std::endl;
      Socket player1 = Socket(players.front());
      players.pop();
      Socket player2 = Socket(players.front());
      players.pop();

      //std::thread partyThread(startPartyServer, &player1, new Socket());
      // partyThread.join();
    }
  }

  return 0;
}
