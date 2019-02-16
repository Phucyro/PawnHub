#include "config.hpp"
#include "Socket.hpp"
#include "ClientMessageHandler.hpp"
#include <thread>


int main(){
  Socket socket;

  // Demande de connexion au serveur
  socket.connectToServer("127.0.0.1");

  // L'utilisateur doit s'identifier ou creer un compte
  //authentification(&socket);

  // Thread gere messages recus
  std::thread receive_thread(clientReceiveHandler, &socket);
  receive_thread.detach();

  // Gere messages envoyes envoye par le client
  clientSendHandler(&socket);

  return 0;
}
