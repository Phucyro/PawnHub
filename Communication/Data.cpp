#include "Data.hpp"

Data::Data(const std::string path) : _path(path), _dataMap({}), _ladders({}) {
  _ladders["Classic"] = {};
  _ladders["Dark"] = {};
  _ladders["Horde"] = {};
  _ladders["Alice"] = {};
  initLadder();
}


bool Data::containsAccount(const std::string username){
  const std::string full_path = _path + "/" + username + ".txt";
  std::ifstream file(full_path.c_str());
  return file.good();
}


bool Data::checkUserPassword(const std::string username, const std::string password){
  /*
  Renvoie true si les mots de passe correspondent sinon false
  Attention, il faut vérifier si un compte avec ce nom existe deja
  */
  loadUserData(username);
  std::string file_password = std::get<0>(_dataMap[username]);
  _dataMap.erase(username);

  if (file_password == password)
    return true;
  else
    return false;
}


bool Data::createUserAccount(const std::string username, const std::string password){
  /*
  Creer un nouveau compte utilisateur a partir d'un identifiant et d'un mot de passe
  Si le compte existe deja alors renvoie false sinon le cree et retourne true
  */
  if (containsAccount(username))
    return false;
  // Si peut ajouter ami deco il faut creer le fichier dès la création
  _dataMap[username] = UserData(password, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, std::vector<std::string>());
  saveUserData(username);
  return true;
}


void Data::loadUserData(const std::string username){
  /*
  Charge les données de l'utilisateur se trouvant dans un fichier texte
  */
  const std::string full_path = _path + "/" + username + ".txt";

  std::ifstream file(full_path.c_str());

  if (file){
    std::string data_line;
    std::string password;
    Stat classic, dark, horde, alice;
    std::vector<std::string> friends;

    std::getline(file, data_line);
    password = data_line;

    std::getline(file, data_line);
    classic = toUIVector(splitString(data_line, ' '));

    std::getline(file, data_line);
    dark = toUIVector(splitString(data_line, ' '));

    std::getline(file, data_line);
    horde = toUIVector(splitString(data_line, ' '));

    std::getline(file, data_line);
    alice = toUIVector(splitString(data_line, ' '));

    std::getline(file, data_line);
    friends = splitString(data_line, ' ');

    _dataMap[username] = UserData(password, classic, dark, horde, alice, friends);
  }
  else {
    std::cerr << "[Error] Data open file read" << std::endl;
  }
}


void Data::saveUserData(const std::string username){
  /*
  Sauvegarde les donnees de l'utilisateur en les copiant dans un fichier texte
  */
  const std::string full_path = _path + "/" + username + ".txt";
  std::ofstream file(full_path.c_str());

  if (file){
    file << std::get<0>(_dataMap[username]) << std::endl; // Mot de passe
    file << unsignedIntVectorToStr(std::get<1>(_dataMap[username])) << std::endl; // Classic
    file << unsignedIntVectorToStr(std::get<2>(_dataMap[username])) << std::endl; // Dark
    file << unsignedIntVectorToStr(std::get<3>(_dataMap[username])) << std::endl; // Horde
    file << unsignedIntVectorToStr(std::get<4>(_dataMap[username])) << std::endl; // Alice
    file << strVectorToStr(std::get<5>(_dataMap[username])) << std::endl; // Liste amis
    _dataMap.erase(username);
  }
  else {
    std::cerr << "[Error] Data open file write" << std::endl;
  }
}


bool Data::addUserFriend(const std::string username, const std::string friend_name){
  /*
  Ajoute un ami à la liste d'amis de l'utilisateur si cet ami ne se trouve pas encore
  dans la liste.
  */
  std::vector<std::string> friends = std::get<5>(_dataMap[username]);

  if (std::find(friends.begin(), friends.end(), friend_name) == friends.end()){
    std::get<5>(_dataMap[username]).push_back(friend_name);
    return true;
  }
  return false; //Deja dans la liste d'amis
}


std::vector<std::string> Data::getUserFriendsList(const std::string username){
  /*
  Renvoie la liste d'amis de l'utilisateur
  */
  return std::get<5>(_dataMap[username]);
}


unsigned int Data::getUserClassicWin(const std::string username){
  return std::get<1>(_dataMap[username])[0];
}

unsigned int Data::getUserClassicLose(const std::string username){
  return std::get<1>(_dataMap[username])[1];
}

unsigned int Data::getUserClassicDraw(const std::string username){
  return std::get<1>(_dataMap[username])[2];
}

unsigned int Data::getUserDarkWin(const std::string username){
  return std::get<2>(_dataMap[username])[0];
}

unsigned int Data::getUserDarkLose(const std::string username){
  return std::get<2>(_dataMap[username])[1];
}

unsigned int Data::getUserDarkDraw(const std::string username){
  return std::get<2>(_dataMap[username])[3];
}

unsigned int Data::getUserHordeWin(const std::string username){
  return std::get<3>(_dataMap[username])[0];
}

unsigned int Data::getUserHordeLose(const std::string username){
  return std::get<3>(_dataMap[username])[1];
}

unsigned int Data::getUserHordeDraw(const std::string username){
  return std::get<3>(_dataMap[username])[2];
}

unsigned int Data::getUserAliceWin(const std::string username){
  return std::get<4>(_dataMap[username])[0];
}

unsigned int Data::getUserAliceLose(const std::string username){
  return std::get<4>(_dataMap[username])[1];
}

unsigned int Data::getUserAliceDraw(const std::string username){
  return std::get<4>(_dataMap[username])[2];
}


void Data::addUserClassicWin(const std::string username){
  ++(std::get<1>(_dataMap[username])[0]);
  updateLadder("Classic", {username, std::get<1>(_dataMap[username])});
}

void Data::addUserClassicLose(const std::string username){
  ++(std::get<1>(_dataMap[username])[1]);
}

void Data::addUserClassicDraw(const std::string username){
  ++(std::get<1>(_dataMap[username])[2]);
}

void Data::addUserDarkWin(const std::string username){
  ++(std::get<2>(_dataMap[username])[0]);
  updateLadder("Dark", {username, std::get<2>(_dataMap[username])});
}

void Data::addUserDarkLose(const std::string username){
  ++(std::get<2>(_dataMap[username])[1]);
}

void Data::addUserDarkDraw(const std::string username){
  ++(std::get<2>(_dataMap[username])[2]);
}

void Data::addUserHordeWin(const std::string username){
  ++(std::get<3>(_dataMap[username])[0]);
  updateLadder("Horde", {username, std::get<3>(_dataMap[username])});
}

void Data::addUserHordeLose(const std::string username){
  ++(std::get<3>(_dataMap[username])[1]);
}

void Data::addUserHordeDraw(const std::string username){
  ++(std::get<3>(_dataMap[username])[2]);
}

void Data::addUserAliceWin(const std::string username){
  ++(std::get<4>(_dataMap[username])[0]);
  updateLadder("Alice", {username, std::get<4>(_dataMap[username])});
}

void Data::addUserAliceLose(const std::string username){
  ++(std::get<4>(_dataMap[username])[1]);
}

void Data::addUserAliceDraw(const std::string username){
  ++(std::get<4>(_dataMap[username])[2]);
}


bool Data::isInLadder(const std::string gamemode, const std::string username){
  for (unsigned int a = 0; a < _ladders[gamemode].size(); ++a)
    if (std::get<0>(_ladders[gamemode][a]) == username)
      return true;
  return false;
}


void Data::updateLadder(const std::string gamemode, UserLadderData data){
  if (_ladders[gamemode].size() == 0){
    _ladders[gamemode].push_back(data);
  }
  else {
    long unsigned int pos = _ladders[gamemode].size();

    while (pos != 0 && std::get<1>(data)[0] > std::get<1>(_ladders[gamemode][pos-1])[0]){
      // Si le joueur se trouvait dans le classement, le supprime et le replace
      if (std::get<0>(data) == std::get<0>(_ladders[gamemode][pos-1])){
        _ladders[gamemode].erase(_ladders[gamemode].begin() + pos-1);
        if (pos != 1) --pos;
      }
      --pos;
    }

    // Ajoute l'utilisateur au classement si joueur manquant dans top 10 ou si il a assez de points
    if (pos != _ladders[gamemode].size() || (_ladders[gamemode].size() < 10 && !isInLadder(gamemode, std::get<0>(data))))
      _ladders[gamemode].insert(_ladders[gamemode].begin() + pos, data);

    // Supprime le joueur avec le moints de points si il y a plus de 10 joueurs
    if (_ladders[gamemode].size() > 10)
      _ladders[gamemode].pop_back();
  }
}


void Data::printLadder(const std::string gamemode){
  std::cout << "Classement du mode : " << gamemode << std::endl;
  for (unsigned int a = 0; a < _ladders[gamemode].size(); ++a){
    std::cout << a << ") " << std::get<0>(_ladders[gamemode][a]) << " " <<
    std::get<1>(_ladders[gamemode][a])[0] << " points" << std::endl;
   }
}

void Data::initLadder(){
  DIR* directory = opendir(_path.c_str());
  struct dirent* entry;

  if (directory != NULL){
    while ((entry = readdir(directory)) != NULL){
      const std::string filename = std::string(entry->d_name);
      if (filename != "." && filename != ".."){
        const std::string username = filename.substr(0, filename.length()-4);
        loadUserData(username);
        updateLadder("Classic", {username, std::get<1>(_dataMap[username])});
        updateLadder("Dark",    {username, std::get<2>(_dataMap[username])});
        updateLadder("Horde",   {username, std::get<3>(_dataMap[username])});
        updateLadder("Alice",   {username, std::get<4>(_dataMap[username])});
        _dataMap.erase(username);

      }
    }
    closedir(directory);
  }
  else {
    std::cerr << "[Error] Open directory" << std::endl;
  }
}
