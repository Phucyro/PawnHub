#ifndef CLIENTMESSAGEHANDLER_H
#define CLIENTMESSAGEHANDLER_H

#include <vector>
#include <string>
#include "../../Communication/SplitString.hpp"
#include "ClientHandler.hpp"
#include <stdlib.h>


class Socket;
class Client;
class Chat;

void receiveMessageHandler(Client* client,Chat *chat){
  std::vector<std::string> msg;
  bool in_game = false;

  while (!in_game){
    msg = splitString(client->getSocket()->receiveMessage(), '~');

    if (std::isalpha(msg[0][0])){
       client->writePipe(strVectorToStr(msg));
       continue;
    }

    int choice = atoi(msg[0].c_str());

    switch(choice){
      case 1 : // [1] [resultat]
        signUpHandler(client, msg[1][0]);
        break;
      case 2 : // [2] [resultat]
        signInHandler(client, msg[1][0]);
        break;
      case 3 : // [3] [sender] [target] [text]
        chatHandler(client, msg[1], msg[2], msg[3],chat);
        break;
      case 4 :
//        playGameHandler(client);
        in_game = true;
        break;
      case 5 :
        leaveQueueHandler();
        break;
      case 7 :
        myStatHandler(client, msg[1], msg[2], msg[3]);
        break;
      case 8 :
        ladderHandler(client, msg[1], msg[2], msg[3]);
        break;
      case 9 :
        viewFriendsHandler(client, msg[1]);
        break;
      case 10 :
        viewFriendRequestHandler(client, msg[1]);
        break;
      case 11 :
        acceptRefuseRequestHandler(client, msg[1], msg[2]);
        break;
      case 12 :
        sendFriendRequestHandler(client, msg[1]);
        break;
      case 13 :
        removeFriendHandler(client, msg[1]);
        break;
      case 14 :
        viewSentRequestHandler(client, msg[1]);
        break;
      case 15 :
        cancelRequestHandler(client, msg[1]);
        break;
      case 16 :
        updateFriendsListHandler(client, msg[1], msg[2]);
        break;
      case 17 :
        updateRecvRequestHandler(client, msg[1], msg[2]);
        break;
      case 18 :
        updateSentRequestHandler(client, msg[1], msg[2]);
        break;
    }
  }
}

#endif
