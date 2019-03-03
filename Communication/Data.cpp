#include "Data.hpp"

Data::Data(const std::string path) : _path(path), _dataMap({}), _ladders({}) {
  _ladders["Classic"] = {};
  _ladders["Dark"] = {};
  _ladders["Horde"] = {};
  _ladders["Alice"] = {};
  initLadder();
}


bool Data::containsAccount(const std::string username){
  /*
  Renvoie true si un compte avec username comme identifiant existe sur le
  serveur sinon false
  */
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
  _dataMap[username] = UserData(password, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {}, {}, {});
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
    std::vector<std::string> friends, their_requests, my_requests;

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
    their_requests = splitString(data_line, ' ');

    std::getline(file, data_line);
    my_requests = splitString(data_line, ' ');

    _dataMap[username] = UserData(password, classic, dark, horde, alice, friends, their_requests, my_requests);
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
    file << strVectorToStr(std::get<7>(_dataMap[username])) << std::endl; // Mes demandes
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
  std::vector<std::string> my_requests = getUserFriendRequests(username); // recue

  if (std::find(my_requests.begin(), my_requests.end(), friend_name) == my_requests.end()){
    return 0; // username n'a pas recu de demande de friend_name
  }

  // Sinon accepte la demande
  std::vector<std::string> my_friends = getUserFriends(username);
  std::vector<std::string> his_friends = getUserFriends(friend_name);
  std::vector<std::string> his_sent_requests = getUserSentRequests(friend_name);

  his_sent_requests.erase(std::remove(his_sent_requests.begin(), his_sent_requests.end(), username), his_sent_requests.end());
  my_requests.erase(std::remove(my_requests.begin(), my_requests.end(), friend_name), my_requests.end());
  my_friends.push_back(friend_name);
  his_friends.push_back(username);

  if (_dataMap.find(friend_name) != _dataMap.end()){ // Si friend_name est connecte
    std::get<5>(_dataMap[friend_name]) = his_friends;
    std::get<7>(_dataMap[friend_name]) = his_sent_requests;
  }
  else {
    loadUserData(friend_name);
    std::get<5>(_dataMap[friend_name]) = his_friends;
    std::get<7>(_dataMap[friend_name]) = his_sent_requests;
    saveUserData(friend_name);
  }

  std::get<5>(_dataMap[username]) = my_friends;
  std::get<6>(_dataMap[username]) = my_requests; // Requete recue

  return 1;
}


bool Data::refuseFriendRequest(const std::string username, const std::string friend_name){
  std::vector<std::string> my_requests = getUserFriendRequests(username); // recue

  if (std::find(my_requests.begin(), my_requests.end(), friend_name) == my_requests.end()){
    return 0; // username n'a pas recu de demande de friend_name
  }

  // Sinon refuse la demande
  std::vector<std::string> his_sent_requests = getUserSentRequests(friend_name);

  his_sent_requests.erase(std::remove(his_sent_requests.begin(), his_sent_requests.end(), username), his_sent_requests.end());
  my_requests.erase(std::remove(my_requests.begin(), my_requests.end(), friend_name), my_requests.end());

  if (_dataMap.find(friend_name) != _dataMap.end()){ // Si friend_name est connecte
    std::get<7>(_dataMap[friend_name]) = his_sent_requests;
  }
  else {
    loadUserData(friend_name);
    std::get<7>(_dataMap[friend_name]) = his_sent_requests;
    saveUserData(friend_name);
  }

  std::get<6>(_dataMap[username]) = my_requests; // Requete recue

  return 1;
}


int Data::sendFriendRequest(const std::string username, const std::string friend_name){
  /*
  Traite la demande d'ami de username qui veut devenir ami avec friend_name
  */
  if (!containsAccount(friend_name)){
    return 0; // Utilisateur inexistant
  }

  std::vector<std::string> friends = getUserFriends(username);
  std::vector<std::string> my_requests = getUserSentRequests(username);

  if (std::find(friends.begin(), friends.end(), friend_name) != friends.end()){
    return 1; // Deja dans liste amis
  }

  if (std::find(my_requests.begin(), my_requests.end(), friend_name) != my_requests.end()){
    return 2; // Demande deja envoyee
  }

  // S'il envoit une demande et qu'il a deja recu une demande alors ils deviennent amis
  std::vector<std::string> his_requests = getUserSentRequests(friend_name);
  if (std::find(his_requests.begin(), his_requests.end(), username) != his_requests.end()){
    accceptFriendRequest(username, friend_name);
    accceptFriendRequest(friend_name, username);
    return 3;
  }

  // Sinon envoie la demande
  if (_dataMap.find(friend_name) != _dataMap.end()){ // Si ami connecte
    std::get<6>(_dataMap[friend_name]).push_back(username);
  }
  else {
    loadUserData(friend_name);
    std::get<6>(_dataMap[friend_name]).push_back(username);
    saveUserData(friend_name);
  }

  // Ajoute friend_name au demandes envoyees de username
  std::get<7>(_dataMap[username]).push_back(friend_name);

  return 4; // Demande envoyee
}


bool Data::removeFriend(const std::string username, const std::string friend_name){
  std::vector<std::string> my_friends = getUserFriends(username);

  if (std::find(my_friends.begin(), my_friends.end(), friend_name) == my_friends.end()){
    return 0; // friend_name ne fait pas partie de la liste d'amis de username
  }

  // Sinon enleve friend_name de la liste d'amis de username
  std::vector<std::string> his_friends = getUserFriends(friend_name);

  my_friends.erase(std::remove(my_friends.begin(), my_friends.end(), friend_name), my_friends.end());
  his_friends.erase(std::remove(his_friends.begin(), his_friends.end(), username), his_friends.end());

  if (_dataMap.find(friend_name) != _dataMap.end()){ // Si friend_name est connecte
    std::get<5>(_dataMap[friend_name]) = his_friends;
  }
  else {
    loadUserData(friend_name);
    std::get<5>(_dataMap[friend_name]) = his_friends;
    saveUserData(friend_name);
  }

  std::get<5>(_dataMap[username]) = my_friends;

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


std::vector<std::string> Data::getUserFriendRequests(const std::string username){
  std::vector<std::string> requests;

  if (_dataMap.find(username) == _dataMap.end()){
    loadUserData(username);
    requests = std::get<6>(_dataMap[username]);
    saveUserData(username);
    return requests;
  }
  return std::get<6>(_dataMap[username]);
}

std::vector<std::string> Data::getUserSentRequests(const std::string username){
  std::vector<std::string> requests_sent;

  if (_dataMap.find(username) == _dataMap.end()){
    loadUserData(username);
    requests_sent = std::get<7>(_dataMap[username]);
    saveUserData(username);
    return requests_sent;
  }
  return std::get<7>(_dataMap[username]);
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
