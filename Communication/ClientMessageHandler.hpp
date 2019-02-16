#ifndef _CLIENTMESSAGEHANDLER_H_
#define _CLIENTMESSAGEHANDLER_H_

#include <vector>
#include <string>
#include "Socket.hpp"
#include "SplitString.hpp"
#include "LoginClient.hpp"

void receiveMessageHandler(Socket* socket){
  std::vector<std::string> message;

  while (true){
    message = splitString(socket->receiveMessage(), ' ');

    switch(message[0][0]){
      case '1' :
        break;
    }
  }
}

void sendMessageHandler(Socket* socket){
  bool quit = false;
  std::string input;
  std::vector<std::string> message;

  while (!quit){
    std::cout << "Message : " << std::endl;
    std::cin >> input;
    message = splitString(input, ' ');

    switch(message[0][0]){
      case '0' : // 0 : quitter
        quit = true;
        break;
      case '1' : // 1 [name] [mdp1] [mdp2] : register
        signUp(socket, message[1], message[2], message[3]);
        break;
      case '2' : // 2 [name] [mdp] : login
        signIn(socket, message[1], message[2]);
        break;
    }
  }
}


#endif
