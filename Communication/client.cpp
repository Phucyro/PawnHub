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


  try {
    socket.connectToServer(hostname);
    socket.sendMessage("4 0");
    // Thread gere messages recus
    // std::thread receive_thread(receiveMessageHandler, &socket);
    // receive_thread.detach();
    receiveMessageHandler(&socket);

    // Gere messages envoyes envoye par le client
    // sendMessageHandler(&socket, &client_username);
  }catch(std::string error){
    std::cout << error << std::endl;
    return 1;
  }

  return 0;
}
