#include "config.hpp"
#include "Socket.hpp"


int main(){
  // Initialisation socket
  sockaddr_in their_addr;
  their_addr.sin_family = AF_INET;
  their_addr.sin_port = htons(MYPORT);
  their_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(&(their_addr.sin_zero), '\0', 8);

  Socket socket;

  // Demande de connexion au serveur
  socket.connectToServer("127.0.0.1");

  // Operations avec le serveur
  
  return 0;
}
