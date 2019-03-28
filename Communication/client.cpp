#include <thread>
#include <unistd.h>
#include <sys/wait.h>
#include "config.hpp"
#include "Socket.hpp"
#include "Menu.hpp"
#include "../Display/MenuHandler/MenuHandler.hpp"
#include "Client.hpp"
#include "ClientMessageHandler.hpp"
#include "ClientFunctions.hpp"


int main(){
  try {
    // Connexion au serveur
    Socket* socket = new Socket;
    std::string hostname;
    bool good_hostname = false;

    while (!good_hostname) {
      std::cout << "Please enter hostname: ";
      std::cin >> hostname;
      std::cout << std::endl;
      good_hostname = socket->connectToServer(hostname);
    }

    Client* client = new Client(socket);
    MenuHandler* menu = new MenuHandler();

    std::thread receiveThread(receiveMessageHandler, menu, client);

    authentificationMenu(menu, client);
    initClientData(client);
    mainMenu(menu, client);
    quit(menu, client);
    receiveThread.join();
    delete menu;
  }
  catch(std::runtime_error& error) {
    std::cout << error.what() << std::endl;
    return 1;
  }
  return 0;
}
