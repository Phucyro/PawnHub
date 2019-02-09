#include "config.hpp"
#include "Socket.hpp"


int main(){
  // Initialisation socket
  Socket socket;

  // Demande de connexion au serveur
  socket.connectToServer("127.0.0.1");

  // Operations avec le serveur
  std::string message = socket.receiveMessage();
  std::cout << message << std::endl;

  socket.sendMessage("Wassup");

  return 0;
}
