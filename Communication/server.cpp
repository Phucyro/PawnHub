#include "config.hpp"
#include "BindSocket.hpp"


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
    sockaddr_in their_addr;
    Socket talking_socket = binding_socket.createSocket(their_addr);

    // Fork et traite la demande du client
    if (!fork()){
      std::cout << "Connexion de " << inet_ntoa(their_addr.sin_addr) << std::endl;
      std::cout << "Connected to " << talking_socket.getFileDescriptor() << std::endl;
      // Operation serveur
    }
  }

  return 0;
}
