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
    // Accepte l'utilisateur dans le serveur
    Socket client_socket = binding_socket.createSocket();

    // Demande a l'identifiant de se connecter ou de s'inscrire
    treatConnection(&client_socket);

    std::cout << "La demande a ete traitee" << std::endl;

  }

  return 0;
}
