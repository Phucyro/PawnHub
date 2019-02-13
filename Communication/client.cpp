#include "config.hpp"
#include "Socket.hpp"
#include "LoginClient.hpp"
//#include "../Display/board.cpp"


int main(){
  // Initialisation socket
  Socket socket;

  // Demande de connexion au serveur
  socket.connectToServer("127.0.0.1");

  // L'utilisateur doit s'identifier ou creer un compte
  authentification(&socket);

  /*
  // Ouvre la fenetre (ne marche pas makefile doit changer)
  Board board;
  board.init_ncurses();
  sleep(10);
  */

  return 0;
}
