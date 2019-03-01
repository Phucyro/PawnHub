#include "config.hpp"
#include "Socket.hpp"
#include "ClientMessageHandler.hpp"
#include "ClientGameControl.hpp"
#include <thread>
#include <unistd.h>
#include <sys/wait.h>
#include "../Display/MenuHandler/MenuHandler.hpp"
#include "ClientFunctions.hpp"


void chooseGamemode(MenuHandler* menu, Socket* socket){
  menu->init_choicesw();
  int choice = menu->get_choice({"Classic", "Dark", "Horde", "Alice", "Retourner au menu principal"});
  char whatev[2] = "!";
  switch (choice){
    case 0 :
      playGame(socket, "0");
      receiveMessageHandler(menu, socket, whatev);
      break;
    case 1 :
      playGame(socket, "1");
      receiveMessageHandler(menu, socket, whatev);
      break;
    case 2 :
      playGame(socket, "2");
      receiveMessageHandler(menu, socket, whatev);
      break;
    case 3 :
      playGame(socket, "3");
      receiveMessageHandler(menu, socket, whatev);
      break;
    case 4 :
      //retour
      break;
  }
}

void waitingLine(MenuHandler* menu, Socket* socket){
  menu->init_choicesw();
  int choice = menu->get_choice({"Quitter"});
}

void gameMenu(MenuHandler* menu, Socket* socket){
  bool end = false;
  while (!end){
    menu->init_choicesw();
    int choice = menu->get_choice({"Jouer", "Ami", "Statistique", "Chat", "Quitter"});
    switch (choice){
      case 0 :
        chooseGamemode(menu, socket);
        break;
      case 1 :
        break;
      case 2 :
        break;
      case 3 :
        break;
      case 4 :
        end = true;
    }
  }
}


void authentification(MenuHandler* menu, Socket* socket, int pipe_fd[]){
  char response[10] = "!";

  while (response[0] != '3'){
    menu->clear_windows();

    // Affiche message d'erreur s'il y en a un
    switch(response[0]){
      case '0' :
        menu->print_warning("Le nom de compte a deja été pris");
        break;
      case '1' :
        menu->print_warning("Compte créé avec succes");
        break;
      case '2' :
        menu->print_warning("Nom de compte inexistant");
        break;
      case '4' :
        menu->print_warning("Mauvais mot de passe");
    }

    menu->init_choicesw();
    int choice = menu->get_choice({"Connexion", "Inscription"});

    menu->clear_windows();
    menu->init_dataw();

    std::string username, password, confirmation;

    if (choice == 0){ // Veut se connecter
      username = menu->get_infos("Nom d'utilisateur :");
      menu->init_dataw();
      password = menu->get_infos("Mot de passe :");
      signIn(socket, username, password);
    }
    else {
      username = menu->get_infos("Nom d'utilisateur :");
      menu->init_dataw();
      password = menu->get_infos("Mot de passe :");
      menu->init_dataw();
      confirmation = menu->get_infos("Confirmer mot de passe :");
      signUp(socket, username, password, confirmation);
    }
    // read(pipe_fd[0], response, 10);
    receiveMessageHandler(menu, socket, response);
  }
  menu->clear_windows();
}



int main(){
  Socket socket;
  MenuHandler* menuHandler = new MenuHandler();
  int pipe_fd[2];
  pipe(pipe_fd); // close ?

  // Demande de connexion au serveur
  std::string hostname;
  std::cout << "Please enter hostname: ";
  std::cin >> hostname;
  std::cout << std::endl;


  try {
    socket.connectToServer(hostname);

    // Thread gere messages recus
    // std::thread receive_thread(receiveMessageHandler, menuHandler, &socket, pipe_fd);
    // receive_thread.detach();

    authentification(menuHandler, &socket, pipe_fd);
    gameMenu(menuHandler, &socket);

    quit(menuHandler, &socket);
    delete menuHandler;

  } catch(std::string error) {
    std::cout << error << std::endl;
    return 1;
  }
  return 0;
}
