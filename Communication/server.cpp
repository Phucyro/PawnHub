#include "config.hpp"
#include "BindSocket.hpp"
#include "ServerMessageHandler.hpp"
#include <map>
#include <thread>
#include "Data.hpp"
#include "Matchmaking.hpp"
#include "ServerGameControl.hpp"


typedef std::map<std::string, Player*> PlayersMap;


int main(){
  char hostname[50];
  gethostname(hostname, 50);
  std::cout << "Hostname: " << hostname << std::endl;

  try {
    Data data("Database"); // bug makefile
    Matchmaking matchmaking(4);
    PlayersMap players_map;
    BindSocket binding_socket;

    // Met le socket serveur en attente de connexions
    binding_socket.activate();

    while (true){
      // Accepte l'utilisateur dans le serveur et lui asssocie un socket
      Socket* client_socket = binding_socket.createSocket();

      // Traite la demande de connexion
      std::thread thread(receiveMessageHandler, client_socket, &data, &players_map, &matchmaking);
      thread.detach();
    //   Player* player = new Player(client_socket);
    //   matchmaking.addPlayer(player, 0);
    //
    //   matchmaking.check(0);
    }
  } catch (std::runtime_error& error) {
    std::cout << error.what() << std::endl;
    return 1;
  }

  return 0;
}
