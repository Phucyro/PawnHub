#include "config.hpp"
#include "Socket.hpp"


int main(){
  // Initialisation socket
  Socket socket;

  // Demande de connexion au serveur
  socket.connectToServer("127.0.0.1");

  // Operations avec le serveur
  bool connected = true;

  while (connected){
  }


  return 0;
}
