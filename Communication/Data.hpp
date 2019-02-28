#ifndef _DATA_H_
#define _DATA_H_

#include <map>
#include <vector>
#include <fstream>
#include <iostream>

typedef std::tuple<std::string, int, int, int, std::vector<std::string>> UserData;

class Data {
private:
  std::map<std::string, UserData> _data;
  std::string const _path;

public:
  Data(std::string file_path);
  void load();
  void write();
  void addAccount(std::string username, std::string password);
  bool containsAccount(std::string username);
  bool checkPassword(std::string username, std::string password);
};

#endif
