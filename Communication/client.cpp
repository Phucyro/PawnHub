#include <thread>
#include <unistd.h>
#include <sys/wait.h>
#include "config.hpp"
#include "Socket.hpp"
#include "Menu.hpp"
#include "../Display/MenuHandler/MenuHandler.hpp"


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

    MenuHandler* menu = new MenuHandler();
    authentificationMenu(menu, socket);
    mainMenu(menu, socket);

    quit(menu, socket);
    delete menu;
    delete socket;

  } catch(std::runtime_error& error) {
    std::cout << error.what() << std::endl;
    return 1;
  }
  return 0;
}
