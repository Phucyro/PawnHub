#include "Data.hpp"


Data::Data(std::string path) : _data({}), _path(path) {}

void Data::load(){
  std::ifstream file_stream(_path.c_str());

  if (file_stream){
	std::string line;
	std::vector<std::string> users_data;

	while (getline(file_stream, line)){
	  users_data = splitString(line, ' ');
	  _data[users_data[0]] = users_data[1];
	}
  }
   else {
    std::cerr << "[Error] Open data file" << std::endl;
    exit(1);
   }
}

void Data::write(){
  std::ofstream file_stream(_path.c_str());

  if (file_stream){
    for (auto elem : _data){
      file_stream << elem.first << " " << elem.second << std::endl;
    }
  }
  else {
    std::cerr << "[Error] Write data file" << std::endl;
  }
}

void Data::addAccount(std::string username, std::string password){
  _data[username] = password;
}
