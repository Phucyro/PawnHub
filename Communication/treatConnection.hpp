#ifndef _SERVERRECEIVEHANDLER_H_
#define _SERVERRECEIVEHANDLER_H_

#include "LoginServer.hpp"
#include "SplitString.hpp"
#include "Data.hpp"
#include <vector>
#include <string>


void receiveMessageHandler(Socket* client_socket, Data* data){
  bool quit = false;
  std::vector<std::string> message;

  try {
    while (!quit){
      message = splitString(client_socket->receiveMessage(), ' ');

      switch (message[0][0]){
        case '0' :
          quit = true;
          break;

        // Etc
      }
    }

  }
  catch (std::string const& error){
    std::cout << error << std::endl;
  }
}

#endif
