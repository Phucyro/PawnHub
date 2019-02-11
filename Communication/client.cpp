#include "config.hpp"
#include "Socket.hpp"
#include "LoginClient.hpp"
// #include "StartPartyClient.hpp"


int main(){
  // Initialisation socket
  Socket socket;

  // Demande de connexion au serveur
  socket.connectToServer("127.0.0.1");

  // Joueur connect'e

  // Identification
  connectRegister(&socket);

  return 0;
}
