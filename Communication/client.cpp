#include "config.hpp"
#include "Socket.hpp"
#include "ClientMessageHandler.hpp"
#include "MessageParser.hpp"
#include <thread>


int main(){
  Socket socket;
  std::string client_username;

  // Demande de connexion au serveur
  socket.connectToServer("frawni-thinks");

  // Thread gere messages recus
  std::thread receive_thread(receiveMessageHandler, &socket);
  receive_thread.detach();

  // Gere messages envoyes envoye par le client
  sendMessageHandler(&socket, &client_username);

  // handleMessage(socket);

  return 0;
}
