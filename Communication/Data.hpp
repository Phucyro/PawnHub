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
#include <mutex>
#include <cmath> //used in ELO calc

#define LADDERSIZE 10

typedef std::vector<unsigned int> Stat;
typedef std::tuple<std::string, Stat, double> UserLadderData;
typedef std::tuple<std::string, Stat, Stat, Stat, Stat, Stat, Stat, Stat, Stat,
  std::vector<std::string>, std::vector<std::string>, std::vector<std::string>,
  std::vector<double>> UserData;

class Data {
private:
  const std::string _path;
  std::map<std::string, UserData> _dataMap;
  std::map<std::string, std::vector<UserLadderData>> _ladders;
  std::map<std::string, std::mutex*> _mutexs;
  std::mutex _ladderMutex;

public:
  Data(const std::string path);
  ~Data();
  bool containsAccount(const std::string username);
  bool isConnected(const std::string username);
  bool checkUserPassword(const std::string username, const std::string password);
  bool createUserAccount(const std::string username, const std::string password);
  void loadUserData(const std::string username);
  void saveUserData(const std::string username);

  std::vector<std::string> getUserFriends(const std::string username);
  std::vector<std::string> getUserFriendRequests(const std::string username);
  std::vector<std::string> getUserSentRequests(const std::string username);
  bool accceptFriendRequest(const std::string username, const std::string friend_name);
  bool refuseFriendRequest(const std::string username, const std::string friend_name);
  int sendFriendRequest(const std::string username, const std::string friend_name); // A change si deco
  bool removeFriend(const std::string username, const std::string friend_name);
  bool cancelSentRequest(const std::string username, const std::string friend_name);

  void updateClassicStat(std::string username, int option);
  void updateDarkStat(std::string username, int option);
  void updateHordeStat(std::string username, int option);
  void updateAliceStat(std::string username, int option);
  void updateRTClassicStat(std::string username, int option);
  void updateRTDarkStat(std::string username, int option);
  void updateRTHordeStat(std::string username, int option);
  void updateRTAliceStat(std::string username, int option);

  bool isInLadder(const std::string gamemode, const std::string username);
  void updateLadder(const std::string gamemode, UserLadderData data);
  void init();
  std::vector<UserLadderData> getLadder(const std::string gamemode);
  void printLadder(const std::string gamemode);
  Stat getUserStat(const std::string username, const std::string gamemode);

  double getEloRating(std::string, unsigned int);
  void updateRating(const std::string, double, double, unsigned int);
  double getExpectedWin(double,double);

  void lockMutex(std::string username);
  void unlockMutex(std::string username);

};
#endif
