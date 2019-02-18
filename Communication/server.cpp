#include "config.hpp"
#include "BindSocket.hpp"
#include "ServerMessageHandler.hpp"
#include "MessageParser.hpp"
#include <map>
#include <thread>
#include "Data.hpp"
#include "../Code/Player.hpp"


typedef std::map<std::string, Player*> PlayersMap;


int main(){
  Data data("database.txt"); // bug makefile
  data.load();

  PlayersMap players_map;

  BindSocket binding_socket;

  // Met le socket rveur en attente de connexions
  binding_socket.activate();

  while (true){
    // Accepte l'utilisateur dans le serveur et lui asssocie un socket
    Socket client_socket = binding_socket.createSocket();

    // Traite la demande de connexion
<<<<<<< HEAD
    std::thread thread(receiveMessageHandler, client_socket, &data, &players_map);
=======
    std::thread thread(receiveMessageHandler, &client_socket, &data, &sockets_map);
>>>>>>> 5ae7db643a0a893c9bd59ae4bd89e9bd1cec210d
    thread.detach();
    // sendBoard(client_socket, "hola");
  }

  return 0;
}
