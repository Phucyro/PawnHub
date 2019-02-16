#include "config.hpp"
#include "BindSocket.hpp"
#include "ServerMessageHandler.hpp"
#include <map>
#include <thread>
#include "Data.hpp"

int main(){
  Data data("database.txt"); // bug makefile
  data.load();

  BindSocket binding_socket;

  // Met le socket rveur en attente de connexions
  binding_socket.activate();

  while (true){
    // Accepte l'utilisateur dans le serveur et lui asssocie un socket
    Socket* client_socket = binding_socket.createSocket();

    // Traite la demande de connexion
    std::thread thread(receiveMessageHandler, client_socket, &data);
    thread.detach();
  }

  return 0;
}
