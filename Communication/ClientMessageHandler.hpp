#ifndef _CLIENTMESSAGEHANDLER_H_
#define _CLIENTMESSAGEHANDLER_H_

#include <vector>
#include <string>
#include "Socket.hpp"
#include "SplitString.hpp"
#include "ClientFunctions.hpp"
#include "ClientHandler.hpp"
#include "../Display/MenuHandler/MenuHandler.hpp"
#include <stdlib.h>

void receiveMessageHandler(MenuHandler* menu, Socket* socket, bool* b_option, std::vector<std::string>* v_option){
  std::vector<std::string> msg;

  msg = splitString(socket->receiveMessage(), '~');

  int choice = atoi(msg[0].c_str());

  switch(choice){
    case 1 : // [1] [resultat]
      signUpHandler(menu, msg[1][0]);
      break;
    case 2 : // [2] [resultat]
      signInHandler(menu, msg[1][0], b_option);
      break;
    case 3 : // [3] [sender] [target] [text]
      //chatHandler(msg[1], msg[2], vectorToString(msg, 2));
      break;
    case 4 :
      menu->clear_windows();
      menu->end_windows();
      playGameHandler(socket);
      break;
    case 5 :
      leaveQueueHandler();
      break;
    case 7 :
      myStatHandler(menu, msg[1], msg[2], msg[3]);
      break;
    case 8 :
      ladderHandler(menu, msg[1], msg[2], msg[3]);
      break;
    case 9 :
      viewFriendsHandler(menu, msg[1], b_option, v_option);
      break;
    case 10 :
      viewFriendRequestHandler(menu, msg[1], b_option, v_option);
      break;
    case 11 :
      acceptRefuseRequestHandler(menu, msg[1], msg[2]);
      break;
    case 12 :
      sendFriendRequestHandler(menu, msg[1]);
      break;
    case 13 :
      removeFriendHandler(menu, msg[1]);
      break;
  }
}

#endif
