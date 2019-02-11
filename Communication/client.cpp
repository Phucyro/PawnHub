#include "config.hpp"
#include "Socket.hpp"
#include "LoginClient.hpp"
// #include "StartPartyClient.hpp"


int main(){
  // Initialisation socket
  Socket socket;

  // Demande de connexion au serveur
  socket.connectToServer("127.0.0.1");

  // Le joueur s'est connecte au serveur
  // bool connected = true;
  // bool sign_in = false;

  // L'utilisateur doit s'identifier ou creer un compte
  connectRegister(&socket);


  // Lance une partie
  /* StartPartyClient(&socket); */

  return 0;
}
