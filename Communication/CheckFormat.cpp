#include "CheckFormat.hpp"


int checkFormat(std::string username, std::string password, std::string confirmation){
  if (username == "Guest" || username == "all"){
    return 0;
  }

  if (password != confirmation) return 1;

  if (username.length() == 0 || username.length() > 10 || password.length() > 10){
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
