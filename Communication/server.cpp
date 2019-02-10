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

    std::queue<int> players; // File de filedescriptors des joueurs connectes

    // Duc:
    // Ici on a un probleme, parce que c'est stupide comme operation:
    // tu gardes juste le int du file decriptor, pour plus tard re-creer un Socket
    // sachant qu'on veut un Socket, afin d' envoyer/recevoir des messages etc
    // apparemment push ne marche pas avec des objets, donc essaie de voir si tu as une autre solution?
    players.push(client_socket.getFileDescriptor()); // Ajoute joueur dans file

    // Lance une partie avec les deux premiers joueurs arrives via thread
    if (players.size() >= 1) { // 2 ne marche pas pour le moment
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
