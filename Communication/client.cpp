#include "config.hpp"
#include "Socket.hpp"
#include "ClientGameControl.hpp"
#include <thread>
#include <unistd.h>
#include <sys/wait.h>
#include "Menu.hpp"



int main(){
  Socket socket;
  MenuHandler* menu = new MenuHandler();

  // Demande de connexion au serveur
  std::string hostname;
  std::cout << "Please enter hostname: ";
  std::cin >> hostname;
  std::cout << std::endl;


  try {
    socket.connectToServer(hostname);

    authentificationMenu(menu, &socket);
    mainMenu(menu, &socket);

    quit(menu, &socket);
    delete menu;

  } catch(std::string error) {
    std::cout << error << std::endl;
    return 1;
  }
  return 0;
}
