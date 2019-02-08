#include "config.hpp"
#include "BindSocket.hpp"


int main(){
  // Initialisation socket serveur
  BindSocket binding_socket;

  // Met le socket serveur en attente de connexions
  binding_socket.activate();

  while (true){
    Socket talking_socket = binding_socket.createSocket();

    // Fork et traite la demande du client
    if (!fork()){
      std::cout << "Connected to " << talking_socket.getFileDescriptor() << std::endl;
      // Operation serveur
    }
  }

  return 0;
}
