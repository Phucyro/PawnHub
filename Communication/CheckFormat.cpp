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

bool checkFriendInputFormat(MenuHandler* menu, std::vector<std::string> input){
 bool correct = true;
 if (input.size() <= 1){
   menu->print_warning("Invalid command");
   correct = false;
 }
 else if (input[1].length() > 10){
   menu->print_warning("Username size range is 1 to 10 characters");
   correct = false;
 }
 else if (!checkInputFormat(input[1])){
   menu->print_warning("Username characters are limited to numbers and letters");
   correct = false;
 }
 menu->refresh_board();
 return correct;
}
