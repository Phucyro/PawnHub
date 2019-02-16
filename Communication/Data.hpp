#ifndef _DATA_H_
#define _DATA_H_

#include <map>
#include <vector>
#include <fstream>
#include <iostream>

class Data {
private:
  std::map<std::string, std::string> _data;
  std::string const _path;

public:
  Data(std::string file_path);
  void load();
  void write();
  void addAccount(std::string username, std::string password);
};

#endif
