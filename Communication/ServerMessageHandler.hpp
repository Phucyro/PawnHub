#ifndef _SERVERRECEIVEHANDLER_H_
#define _SERVERRECEIVEHANDLER_H_

#include "SplitString.hpp"
#include "ServerHandler.hpp"
#include "Matchmaking.hpp"
#include "Data.hpp"
#include "../Code/Player.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <map>

typedef std::map<std::string, Player*> PlayersMap;


void inline receiveMessageHandler(Socket* socket, Data* data, PlayersMap* players_map, Matchmaking* matchmaking){
  bool quit = false;
  std::vector<std::string> msg;
  Player* player = new Player(socket);
  try {
    while (!quit){
      msg = splitString(socket->receiveMessage(), ' ');
      std::cout << "Received Message " << msg[0] + " " + msg[1] << std::endl;

      switch (msg[0][0]){
        case '0' : // [0]
          disconnect(&quit);
          break;
        case '1' : // [1] [username] [password]
          signUpHandler(socket, data, msg[1], msg[2]);
          break;
        case '2' : // [2] [username] [password]
          signInHandler(socket, players_map, data, player, msg[1], msg[2]);
          break;
        case '3' : // [3] [sender] [target] [text]
          //chatHandler(players_map, msg[1], msg[2], vectorToString(msg, 3));
          break;
        case '4' :
          playGameHandler(matchmaking, player, msg[1]);
          break;
        case '5' :
          leaveQueueHandler(matchmaking, player);
          break;
      }
    }
  }
  catch (std::string const& error){
    std::cout << error << std::endl;
    // Supprime l'entrée username : Player()
  std::cout << "Deconnexion de " << player->getName() << std::endl;
  if (player->getQueueNumber() != -1) matchmaking->removePlayer(player);
  player->getSocket()->closeSocket();
  players_map->erase(player->getName());
  data->saveUserData(player->getName());
  }


}

#endif
