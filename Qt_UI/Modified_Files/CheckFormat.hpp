#ifndef _CHECKFORMAT_H_
#define _CHECKFORMAT_H_

#include <string>
#include <vector>


int checkFormat(std::string username, std::string password, std::string confirmation);
bool checkInputFormat(std::string message);
bool checkFriendInputFormat(std::vector<std::string> input);

#endif
