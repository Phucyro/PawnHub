#include "config.hpp"
#include "BindSocket.hpp"
#include "ServerMessageHandler.hpp"
#include <map>
#include <thread>
#include <list>
#include <iterator>
#include <mutex>
#include "Data.hpp"
#include "Matchmaking.hpp"
#include "ServerGameControl.hpp"
#include "ExecInfoThread.hpp"

void delFinishedThread(std::list<ExecInfoThread*>&);
typedef std::map<std::string, Player*> PlayersMap;
extern Data data("Database"); // bug makefile

int main(){
  std::list<ExecInfoThread*> connectedPlayer;
  std::list<ExecInfoThread*>::iterator it;
  ExecInfoThread *infoThread;
  char hostname[50];
  gethostname(hostname, 50);
  std::cout << "Hostname: " << hostname << std::endl;

  BindSocket binding_socket;
  Matchmaking matchmaking(8);
  PlayersMap players_map;
  std::mutex playerMapMutex;

  // Met le socket serveur en attente de connexions
  binding_socket.activate();

  while (true){
    try {
      // Accepte l'utilisateur dans le serveur et lui asssocie un socket
      Socket* client_socket = binding_socket.createSocket();

      // Traite la demande de connexion
      infoThread = new ExecInfoThread();
      std::thread *thread = new std::thread(receiveMessageHandler, client_socket, &data, &players_map, &playerMapMutex, &matchmaking, infoThread);
      infoThread->setThread(thread);
      connectedPlayer.push_back(infoThread);
    }
    catch (std::runtime_error& error) {
      std::cout << error.what() << std::endl;
      continue;
    }
    delFinishedThread(connectedPlayer);
  }

  for (it = connectedPlayer.begin(); it != connectedPlayer.end(); ++it){
  	(*it)->getThread()->join();
  	delete (*it)->getThread();
  	delete *it;
  }

  return 0;
}
