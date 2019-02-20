#include "config.hpp"
#include "BindSocket.hpp"
// #include "ServerMessageHandler.hpp"
#include "ServerMessageParser.hpp"
#include <map>
#include <thread>
// #include "Data.hpp"
// #include "Matchmaking.hpp"
#include "../GameLogic/Classic.hpp"
#include "../GameLogic/Player.hpp"


// typedef std::map<std::string, Player*> PlayersMap;

void startParty(Classic* game) {
  game->start();
}


int main(){
  // Data data("database.txt"); // bug makefile
  // Matchmaking matchmaking(4);
  // PlayersMap players_map;
  BindSocket binding_socket;

  char hostname[50];
  gethostname(hostname, 50);
  std::cout << "Hostname: " << hostname << std::endl;

  // Met le socket serveur en attente de connexions
  binding_socket.activate();

  while (true){
    // Accepte l'utilisateur dans le serveur et lui asssocie un socket
    Socket client_socket = binding_socket.createSocket();

    Player new_player(&client_socket);
    Classic new_game(&new_player, &new_player);
    // Traite la demande de connexion
    std::thread thread(startParty, &new_game);
    thread.detach();
    // sendBoard(client_socket, "hola");

  }

  return 0;
}
