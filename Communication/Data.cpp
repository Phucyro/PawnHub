#include "Data.hpp"
#include "SplitString.hpp"


Data::Data(std::string path) : _data({}), _path(path) {}


void Data::load(){
  std::ifstream file_stream(_path.c_str());

  if (file_stream){
  	std::string line;
  	std::vector<std::string> users_data;

  	while (getline(file_stream, line)){
  	  users_data = splitString(line, ' ');
  	  _data[users_data[0]] = UserData(users_data[1], atoi(users_data[2].c_str()),
        atoi(users_data[3].c_str()), atoi(users_data[4].c_str()),
        splitString(users_data[5].substr(1, users_data[5].length()-1), ','));
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
      std::string friends_string = "[";

      // Tranforme vecteur amis en texte
      for (unsigned int a = 0; a < std::get<4>(elem.second).size(); ++a){
        if (a == std::get<4>(elem.second).size()-1){
          friends_string += std::get<4>(elem.second)[a];
        }
        else {
          friends_string += (std::get<4>(elem.second)[a] + ",");
        }
      }

      friends_string += "]";

      file_stream << elem.first << " " <<       // Username
      std::get<0>(elem.second) << " " <<                  // Password
      std::to_string(std::get<1>(elem.second)) << " " <<  // Win
      std::to_string(std::get<2>(elem.second)) << " " <<  // Defeat
      std::to_string(std::get<3>(elem.second)) << " " <<  // Draw
      friends_string << std::endl;                   // Friends
    }
  }
  else {
    std::cerr << "[Error] Write data file" << std::endl;
  }
}


void Data::addAccount(std::string username, std::string password){
  _data[username] = UserData(password, 0, 0, 0, std::vector<std::string>());
}


bool Data::containsAccount(std::string username){
  if (_data.find(username) == _data.end()){
    return false;
  }
  else {
    return true;
  }
}


bool Data::checkPassword(std::string username, std::string password){
  if (std::get<0>(_data[username]) == password){
    return true;
  }
  else {
    return false;
  }
}
