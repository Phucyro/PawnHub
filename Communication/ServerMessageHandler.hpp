#ifndef _SERVERRECEIVEHANDLER_H_
#define _SERVERRECEIVEHANDLER_H_

#include "SplitString.hpp"
#include "ServerHandler.hpp"
#include "Data.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <map>

typedef std::map<std::string, Socket*> SocketsMap;


void receiveMessageHandler(Socket* socket, Data* data, SocketsMap* sockets_map){
  bool quit = false;
  std::vector<std::string> msg;

  try {
    while (!quit){
      msg = splitString(socket->receiveMessage(), ' ');

      switch (msg[0][0]){
        case '0' : // [0]
          disconnect(&quit);
          break;
        case '1' : // [1] [username] [password]
          signUpHandler(socket, data, msg[1], msg[2]);
          break;
        case '2' : // [2] [username] [password]
          signInHandler(socket, sockets_map, data, msg[1], msg[2]);
          break;
        case '3' : // [3] [sender] [target] [text]
          chatHandler(sockets_map, msg[1], msg[2], vectorToString(msg, 3));
          break;
      }
    }

  }
  catch (std::string const& error){
    std::cout << error << std::endl;
  }

  // Supprime entree username : socket du client deconnecte
  for (auto elem : *sockets_map){
    if (elem.second == socket) sockets_map->erase(elem.first);
  }

  delete socket;

  std::cout << "Un client se deconnecte" << std::endl;

}

#endif
