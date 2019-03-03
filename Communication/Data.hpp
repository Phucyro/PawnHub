#ifndef _DATA_H_
#define _DATA_H_

#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include "SplitString.hpp"
#include <algorithm>
#include "dirent.h"

typedef std::vector<unsigned int> Stat;
typedef std::tuple<std::string, Stat, Stat, Stat, Stat, std::vector<std::string>, std::vector<std::string>, std::vector<std::string>> UserData;
typedef std::tuple<std::string, Stat> UserLadderData;

class Data {
private:
  const std::string _path;
  std::map<std::string, UserData> _dataMap;
  std::map<std::string, std::vector<UserLadderData>> _ladders;

public:
  Data(const std::string path);
  bool containsAccount(const std::string username);
  bool checkUserPassword(const std::string username, const std::string password);
  bool createUserAccount(const std::string username, const std::string password);
  void loadUserData(const std::string username);
  void saveUserData(const std::string username);
  Stat getUserStat(const std::string username, const std::string gamemode);

  std::vector<std::string> getUserFriends(const std::string username);
  std::vector<std::string> getUserFriendRequests(const std::string username);
  std::vector<std::string> getUserSentRequests(const std::string username);
  bool accceptFriendRequest(const std::string username, const std::string friend_name);
  bool refuseFriendRequest(const std::string username, const std::string friend_name);
  int sendFriendRequest(const std::string username, const std::string friend_name);
  bool removeFriend(const std::string username, const std::string friend_name);

  void addUserClassicWin(const std::string username);
  void addUserClassicLose(const std::string username);
  void addUserClassicDraw(const std::string username);
  void addUserDarkWin(const std::string username);
  void addUserDarkLose(const std::string username);
  void addUserDarkDraw(const std::string username);
  void addUserHordeWin(const std::string username);
  void addUserHordeLose(const std::string username);
  void addUserHordeDraw(const std::string username);
  void addUserAliceWin(const std::string username);
  void addUserAliceLose(const std::string username);
  void addUserAliceDraw(const std::string username);

  bool isInLadder(const std::string gamemode, const std::string username);
  void updateLadder(const std::string gamemode, UserLadderData data);
  void printLadder(const std::string gamemode);
  void initLadder();
  std::vector<UserLadderData> getLadder(const std::string gamemode);
};
#endif
