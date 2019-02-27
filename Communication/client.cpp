#include "config.hpp"
#include "Socket.hpp"
#include "ClientMessageHandler.hpp"
#include "ClientGameControl.hpp"
#include <thread>
#include <unistd.h>
#include <sys/wait.h>
#include "../Display/MenuHandler/MenuHandler.hpp"
#include <fstream>

std::ofstream file("debuggage.txt");

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
      file << "Avant sign" << std::endl;
      signIn(socket, username, password);
      file << "Apres sign" << std::endl;
    }
    else {
      username = menu->get_infos("Nom d'utilisateur :");
      menu->init_dataw();
      password = menu->get_infos("Mot de passe :");
      menu->init_dataw();
      confirmation = menu->get_infos("Confirmer mot de passe :");
      signUp(socket, username, password, confirmation);
    }
    read(pipe_fd[0], response, 10);
  }
  menu->end_windows();
}



int main(){
  Socket socket;
  MenuHandler* menuHandler = new MenuHandler();
  int pipe_fd[2];
  pipe(pipe_fd); // close ?

  // Demande de connexion au serveur
  socket.connectToServer("ductrung-Lenovo-YOGA-510-14IKB");

  // Thread gere messages recus
  std::thread receive_thread(receiveMessageHandler, menuHandler, &socket, pipe_fd);
  receive_thread.detach();

  authentification(menuHandler, &socket, pipe_fd);

  while (true){}
  std::cout << "Authentification enfin réussie" << std::endl;

  return 0;
}
