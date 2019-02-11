#include "config.hpp"
#include "BindSocket.hpp"
#include <queue>
#include <thread>
#include "LoginServer.hpp"

// #include "startPartyServer.hpp"

int main(){
  // Initialisation socket serveur
  BindSocket binding_socket;

  // Met le socket serveur en attente de connexions
  binding_socket.activate();

  while (true){
    // Accepte l'utilisateur dans le serveur et lui asssocie un socket
    Socket client_socket = binding_socket.createSocket();

    // Demande a l'identifiant de se connecter ou de s'inscrire
    std::thread connection_thread(treatConnection, &client_socket);
    connection_thread.join();
    std::cout << "Un joueur s'est identifi'e" << std::endl;

  }

  return 0;
}
