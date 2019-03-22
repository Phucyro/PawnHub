#ifndef _CHECKFORMAT_H_
#define _CHECKFORMAT_H_

#include <string>
#include "../Display/MenuHandler/MenuHandler.hpp"


int checkFormat(std::string username, std::string password, std::string confirmation);
bool checkInputFormat(std::string message);
bool checkFriendInputFormat(MenuHandler* menu, std::vector<std::string> input);

#endif
