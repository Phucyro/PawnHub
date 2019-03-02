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
  bool exist = file.good();
  file.close();
  return exist;
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
  _dataMap[username] = UserData(password, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {}, {});
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
    std::vector<std::string> friends, friend_request;

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

    std::getline(file, data_line);
    friend_request = splitString(data_line, ' ');

    _dataMap[username] = UserData(password, classic, dark, horde, alice, friends, friend_request);
  }
  else {
    std::cerr << "[Error] Data open file read" << std::endl;
  }

  file.close();
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
    file << strVectorToStr(std::get<6>(_dataMap[username])) << std::endl; // Demande ami
    _dataMap.erase(username);
  }
  else {
    std::cerr << "[Error] Data open file write" << std::endl;
  }

  file.close();
}

Stat Data::getUserStat(const std::string username, const std::string gamemode){
  Stat user_stat;

  if (!containsAccount(username)) return Stat(); // Joueur inexistant

  if (_dataMap.find(username) != _dataMap.end()){
    if (gamemode == "Classic")
      user_stat = std::get<1>(_dataMap[username]);
    else if (gamemode == "Dark")
      user_stat = std::get<2>(_dataMap[username]);
    else if (gamemode == "Horde")
      user_stat = std::get<3>(_dataMap[username]);
    else
      user_stat = std::get<4>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    if (gamemode == "Classic")
      user_stat = std::get<1>(_dataMap[username]);
    else if (gamemode == "Dark")
      user_stat = std::get<2>(_dataMap[username]);
    else if (gamemode == "Horde")
      user_stat = std::get<3>(_dataMap[username]);
    else
      user_stat = std::get<4>(_dataMap[username]);
    saveUserData(username);
  }

  return user_stat;
}


bool Data::accceptFriendRequest(const std::string username, const std::string friend_name){
  //friend_name = celui qui a demande pour etre ami
  std::vector<std::string> request = getUserFriendRequest(username);

  if (std::find(request.begin(), request.end(), friend_name) == request.end()){
    return 0; // friend ne se trouve pas dans la liste de requete
  }

  std::vector<std::string> friends1 = getUserFriends(username);
  std::vector<std::string> friends2 = getUserFriends(friend_name);
  request.erase(std::remove(request.begin(), request.end(), friend_name), request.end());
  friends1.push_back(friend_name);
  friends2.push_back(username);

  if (_dataMap.find(username) != _dataMap.end()){ // Si connecte
    std::get<5>(_dataMap[username]) = friends1;
    std::get<6>(_dataMap[username]) = friends2;
  }
  else {
    loadUserData(username);
    std::get<5>(_dataMap[username]) = friends1;
    std::get<6>(_dataMap[username]) = request;
    saveUserData(username);
  }

  if (_dataMap.find(friend_name) != _dataMap.end()){ // Si connecte
    std::get<5>(_dataMap[friend_name]) = friends2;
  }
  else {
    loadUserData(friend_name);
    std::get<5>(_dataMap[friend_name]) = friends2;
    saveUserData(friend_name);
  }

  return 1; // Demande d'ami acceptee
}


int Data::sendFriendRequest(const std::string username, const std::string friend_name){
  if (friend_name == username){
    return -3; // Peut pas etre ami avec soi meme
  }
  if (!containsAccount(friend_name)){
    return -2; // Utilisateur inexistant
  }

  std::vector<std::string> friends = getUserFriends(username);
  std::vector<std::string> request = getUserFriendRequest(friend_name);

  if (std::find(friends.begin(), friends.end(), friend_name) != friends.end()){
    return -1; // Deja dans liste amis
  }
  if (std::find(request.begin(), request.end(), username) != request.end()){
    return 0; // Demande deja envoyee
  }

  std::vector<std::string> user_request = getUserFriendRequest(username);
  if (std::find(user_request.begin(), user_request.end(), friend_name) != user_request.end()){
    accceptFriendRequest(username, friend_name);
    return 1;
  }


  if (_dataMap.find(friend_name) != _dataMap.end()){ // Si ami connecte
    std::get<6>(_dataMap[friend_name]).push_back(username);
  }
  else {
    loadUserData(friend_name);
    std::get<6>(_dataMap[friend_name]).push_back(username);
    saveUserData(friend_name);
  }
  return 2; // Demande envoyee
}


bool Data::removeFriend(const std::string username, const std::string friend_name){
  std::vector<std::string> friends1 = getUserFriends(username);

  if (std::find(friends1.begin(), friends1.end(), friend_name) == friends1.end()){
    return 0; // Ami inexistant
  }

  std::vector<std::string> friends2 = getUserFriends(friend_name);

  // Supprime ami
  friends1.erase(std::remove(friends1.begin(), friends1.end(), friend_name), friends1.end());
  friends2.erase(std::remove(friends2.begin(), friends2.end(), username), friends2.end());

  if (_dataMap.find(username) != _dataMap.end()){ // Connecte
    std::get<5>(_dataMap[username]) = friends1;
  }
  else {
    loadUserData(username);
    std::get<5>(_dataMap[username]) = friends1;
    saveUserData(username);
  }

  if (_dataMap.find(friend_name) != _dataMap.end()){ // Connecte
    std::get<5>(_dataMap[friend_name]) = friends2;
  }
  else {
    loadUserData(friend_name);
    std::get<5>(_dataMap[friend_name]) = friends2;
    saveUserData(friend_name);
  }

  return 1;
}


std::vector<std::string> Data::getUserFriends(const std::string username){
  std::vector<std::string> friends;

  if (_dataMap.find(username) == _dataMap.end()){
    loadUserData(username);
    friends = std::get<5>(_dataMap[username]);
    saveUserData(username);
    return friends;
  }
  return std::get<5>(_dataMap[username]);
}


std::vector<std::string> Data::getUserFriendRequest(const std::string username){
  std::vector<std::string> request;

  if (_dataMap.find(username) == _dataMap.end()){
    loadUserData(username);
    request = std::get<6>(_dataMap[username]);
    saveUserData(username);
    return request;
  }
  return std::get<6>(_dataMap[username]);
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

std::vector<UserLadderData> Data::getLadder(const std::string gamemode){
  return _ladders[gamemode];
}
