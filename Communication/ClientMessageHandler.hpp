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

    switch(msg[0][0]){
      case '1' : // [1] [resultat]
        signUpHandler(msg[1][0]);
        break;
      case '2' : // [2] [resultat]
        signInHandler(msg[1][0]);
        break;
      case '3' :
        chatHandler(msg[1], vectorToString(msg, 2));
        break;
    }
  }
}

void sendMessageHandler(Socket* socket){
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
        signIn(socket, msg[1], msg[2]);
        break;
      case '3' : // 3 [cible] [texte]
        chat(socket, msg[1], vectorToString(msg, 2));
        break;
    }
  }
}


#endif
