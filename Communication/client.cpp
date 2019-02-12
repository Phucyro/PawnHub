#include "config.hpp"
#include "Socket.hpp"
#include "LoginClient.hpp"
// #include "StartPartyClient.hpp"


int main(){
  // Initialisation socket
  Socket socket;

  // Demande de connexion au serveur
  socket.connectToServer("127.0.0.1");

  // L'utilisateur doit s'identifier ou creer un compte
  connectRegister(&socket);

  return 0;
}
