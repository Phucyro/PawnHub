#include "config.hpp"
#include "Socket.hpp"
#include "ClientMessageHandler.hpp"
#include "ClientGameControl.hpp"
#include <thread>


int main(){
  Socket socket;
  std::string client_username;

  // Demande de connexion au serveur
  std::string hostname;
  std::cout << "Please enter hostname: ";
  std::cin >> hostname;
  std::cout << std::endl;
  socket.connectToServer(hostname);


  socket.sendMessage("4 0");
  // Thread gere messages recus
  // std::thread receive_thread(receiveMessageHandler, &socket);
  // receive_thread.detach();
  receiveMessageHandler(&socket);

  // Gere messages envoyes envoye par le client
  // sendMessageHandler(&socket, &client_username);

  return 0;
}
