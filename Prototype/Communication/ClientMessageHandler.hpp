#ifndef _CLIENTMESSAGEHANDLER_H_
#define _CLIENTMESSAGEHANDLER_H_

#include <vector>
#include <string>
#include "Socket.hpp"
#include "SplitString.hpp"
#include "ClientFunctions.hpp"
#include "ClientHandler.hpp"

void receiveMessageHandler(Socket* socket){
  std::vector<std::string> msg;

  while (true){
    msg = splitString(socket->receiveMessage(), ' ');

    for(unsigned int a = 0; a < msg.size(); ++a){
      std::cout << msg[a] << std::endl;
    }

    switch(msg[0][0]){
      case '1' : // [1] [resultat]
        signUpHandler(msg[1][0]);
        break;
      case '2' : // [2] [resultat]
        signInHandler(msg[1][0]);
        break;
      case '3' : // [3] [sender] [target] [text]
        chatHandler(msg[1], msg[2], vectorToString(msg, 2));
        break;
      case '4' :
        playGameHandler();
        break;
      case '5' :
        leaveQueueHandler();
        break;
      case 'A' :
        askMoveHandler();
        break;
      case 'B' :
        askPromotionHandler();
        break;
      case 'C' :
        boardHandler(msg[1]);
    }
  }
}

void sendMessageHandler(Socket* socket, std::string* client_username){
  bool leave_game = false;
  std::string input;
  std::vector<std::string> msg;

  while (!leave_game){
    std::cout << "Message : " << std::endl;
    std::getline(std::cin, input);
    msg = splitString(input, ' ');

    switch (msg[0][0]){
      case '0' : // 0 : quitter
        quit(socket, &leave_game);
        break;
      case '1' : // 1 [name] [mdp1] [mdp2] : register
        signUp(socket, msg[1], msg[2], msg[3]);
        break;
      case '2' : // 2 [name] [mdp] : login
        signIn(socket, msg[1], msg[2], client_username);
        break;
      case '3' : // 3 [sender] [target] [msg]
        chat(socket, *client_username, msg[1], vectorToString(msg, 2));
        break;
      case '4' : // 4 [gamemode]
        playGame(socket, msg[1]);
        break;
      case '5' :
        leaveQueue(socket);
        break;
      case 'A' :
        giveMove(socket, msg[1]);
        break;
      case 'B' :
        givePromotion(socket, msg[1]);
    }
  }
}


#endif
