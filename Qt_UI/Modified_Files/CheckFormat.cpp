#include "CheckFormat.hpp"


int checkFormat(std::string username, std::string password, std::string confirmation){
  if (username == "Guest" || username == "all"){
    return 0;
  }

  if (password != confirmation) return 1;

  if (username.length() == 0 || username.length() > 10 || password.length() == 0 || password.length() > 10){
    return 2;
  }

  for (unsigned int a = 0; a < username.length(); ++a){
    if (!isalpha(username[a]) && !isdigit(username[a])) return 3;
  }

  for (unsigned int a = 0; a < password.length(); ++a){
    if (password[a] == '|' || password[a] == '~') return 4;
  }

  return 5;
}

bool checkInputFormat(std::string message){
  for (unsigned int a = 0; a < message.length(); ++a){
    if (message[a] == '|' || message[a] == '~') return false;
  }
  return true;
}

bool checkFriendInputFormat(std::string input){
  bool correct = true;
  if (input.size() > 10){
//    menu->print_warning("La taille des noms est limitée à 10 caractères");
    correct = false;
  }
  else if (!checkInputFormat(input)){
//    menu->print_warning("Les caractères | et ~ sont interdits");
    correct = false;
  }
  return correct;
}
