#include "config.hpp"
#include "BindSocket.hpp"
#include <queue>
#include <thread>

void startParty(int fd1, int fd2){
  // Lance une partie
  std::cout << "La partie commence" << std::endl;
  std::cout << "Joueur 1 " << fd1 << std::endl;
  std::cout << "Joueur 2 " << fd2 << std::endl;

  while (true){
    // Demande input
  }
}


int main(){
  // Initialisation socket serveur
  sockaddr_in my_addr;
  my_addr.sin_family = AF_INET;
  my_addr.sin_port = htons(MYPORT);
  my_addr.sin_addr.s_addr = INADDR_ANY;
  memset(&(my_addr.sin_zero), '\0', 8);
  BindSocket binding_socket(my_addr);

  // Met le socket serveur en attente de connexions
  binding_socket.activate();

  while (true){
    std::queue<int> players; // Vecteur filedescriptors des joueurs connectes
    sockaddr_in their_addr;
    Socket client_socket = binding_socket.createSocket(their_addr);
    players.push(client_socket.getFileDescriptor()); // Ajoute le joueur
    std::cout << players.size() << std::endl;

    // Gere la demande du client avec des threads
    std::cout << "Connexion de " << inet_ntoa(their_addr.sin_addr) << std::endl;
    std::cout << "Connected to " << client_socket.getFileDescriptor() << std::endl;

    // Lance une partie avec les deux premiers joueurs arrives
    if (players.size() >= 1){
      int player1 = players.front();
      players.pop();
      int player2 = players.front();
      players.pop();
      std::thread partyThread(startParty, player1, player2);
      partyThread.join();
    }



    // Operation serveur
  }

  return 0;
}
