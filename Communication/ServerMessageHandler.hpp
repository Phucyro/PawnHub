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
#include <stdlib.h>

typedef std::map<std::string, Player*> PlayersMap;


void inline receiveMessageHandler(Socket* socket, Data* data, PlayersMap* players_map, Matchmaking* matchmaking){
  bool quit = false;
  std::vector<std::string> msg;
  Player* player = new Player(socket);

  try {
    while (!quit){
      msg = splitString(socket->receiveMessage(), '~');

      std::cout << "[ServerMessageHandler] Received Message " << msg[0] + " " + msg[1] << std::endl;

     /* if (std::isalpha(msg[0][0])){
        player->writeControlPipe(strVectorToStr(msg));
        continue;
      }*/

      int choice = atoi(msg[0].c_str());

      switch (choice){
        case 0 : // [0]
          disconnect(&quit);
          break;
        case 1 : // [1] [username] [password]
          signUpHandler(socket, data, msg[1], msg[2]);
          break;
        case 2 : // [2] [username] [password]
          signInHandler(socket, players_map, data, player, msg[1], msg[2]);
          break;
        case 3 : // [3] [sender] [target] [text]
          chatHandler(players_map, player, msg[1], msg[2]);
          break;
        case 4 :
          playGameHandler(matchmaking, player, msg[1]);
          break;
        case 5 :
          leaveQueueHandler(matchmaking, player);
          break;
        case 7 :
          myStatHandler(player, data);
          break;
        case 8 :
          ladderHandler(socket, data, msg[1]);
          break;
        case 9 :
          viewFriendsHandler(player, data);
          break;
        case 10 :
          viewFriendRequestHandler(player, data);
          break;
        case 11 :
          acceptRefuseRequestHandler(player, data, msg[1], msg[2]);
          break;
        case 12 :
          sendFriendRequestHandler(player, data, msg[1]);
          break;
        case 13 :
          removeFriendHandler(player, data, msg[1]);
          break;
        case 14 :
          viewSentRequestHandler(player, data);
          break;
        case 15 :
          cancelRequestHandler(player, data, msg[1]);
          break;
        case 20 :
          socket->sendMessage("20~stopChat");
          break;
        case 30 :
          std::cout<<msg[1]<<std::endl;
          player->writeControlPipe(msg[1]);
          player->activateControlRecv();
          break;
      }
    }
  }
  catch (std::runtime_error& error){
    std::cout << error.what() << std::endl;
    // Supprime l'entrée username : Player()
  }
  player->surrend();
  player->waitEndGame();
  std::cout << "Deconnexion de " << player->getName() << std::endl;

  if (player->getQueueNumber() != -1)
    matchmaking->removePlayer(player);

  players_map->erase(player->getName());

  if (player->getName() != "Guest"){
    data->lockMutex();
    data->saveUserData(player->getName());
    data->unlockMutex();
  }

  delete player;
}

#endif
