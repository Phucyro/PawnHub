#include "Data.hpp"

Data::Data(const std::string path) : _path(path), _dataMap({}), _ladders({}), _mutex() {
  _ladders["Classic"] = {};
  _ladders["Dark"] = {};
  _ladders["Horde"] = {};
  _ladders["Alice"] = {};
  _ladders["RealTimeClassic"] = {};
  _ladders["RealTimeDark"] = {};
  _ladders["RealTimeHorde"] = {};
  _ladders["RealTimeAlice"] = {};
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

bool Data::isConnected(const std::string username){
  if (_dataMap.find(username) != _dataMap.end())
    return true;
  else
    return false;
}


bool Data::checkUserPassword(const std::string username, const std::string password){
  /*
  Renvoie true si les mots de passe correspondent sinon false
  Attention, il faut vérifier si un compte avec ce nom existe deja
  */

  loadUserData(username);
  std::string file_password = std::get<0>(_dataMap[username]);
  saveUserData(username);

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
  _dataMap[username] = UserData(password, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {}, {}, {}, 0.0);
  updateLadderOnWin("Classic", {username, {0,0,0}});
  updateLadderOnWin("Dark", {username, {0,0,0}});
  updateLadderOnWin("Horde", {username, {0,0,0}});
  updateLadderOnWin("Alice", {username, {0,0,0}});
  updateLadderOnWin("RealTimeClassic", {username, {0,0,0}});
  updateLadderOnWin("RealTimeDark", {username, {0,0,0}});
  updateLadderOnWin("RealTimeHorde", {username, {0,0,0}});
  updateLadderOnWin("RealTimeAlice", {username, {0,0,0}});
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
    Stat classic, dark, horde, alice,realTimeClassic,realTimeDark,realTimeHorde,realTimeAlice;
    std::vector<std::string> friends, their_requests, my_requests;
    double eloRank;

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

    std::getline(file, data_line);  // RT Classic
    realTimeClassic = toUIVector(splitString(data_line, ' '));

    std::getline(file, data_line); // RT Dark
    realTimeDark = toUIVector(splitString(data_line, ' '));

    std::getline(file, data_line); // RT Horde
    realTimeHorde = toUIVector(splitString(data_line, ' '));

    std::getline(file, data_line); // Rt Alice
    realTimeAlice = toUIVector(splitString(data_line, ' '));

    std::getline(file, data_line);
    friends = splitString(data_line, ' ');

    std::getline(file, data_line);
    their_requests = splitString(data_line, ' ');

    std::getline(file, data_line);
    my_requests = splitString(data_line, ' ');

    std::getline(file, data_line);
    eloRank = std::atof(data_line.c_str());

    _dataMap[username] = UserData(password, classic, dark, horde, alice, realTimeClassic,realTimeDark,realTimeHorde,realTimeAlice, friends, their_requests, my_requests, eloRank);
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
    file << unsignedIntVectorToStr(std::get<5>(_dataMap[username])) << std::endl; // RealTimeClassic
    file << unsignedIntVectorToStr(std::get<6>(_dataMap[username])) << std::endl; // RealTimeDark
    file << unsignedIntVectorToStr(std::get<7>(_dataMap[username])) << std::endl; // RealTimeHorde
    file << unsignedIntVectorToStr(std::get<8>(_dataMap[username])) << std::endl; // RealTimeAlice
    file << strVectorToStr(std::get<9>(_dataMap[username])) << std::endl; // Liste amis
    file << strVectorToStr(std::get<10>(_dataMap[username])) << std::endl; // Demande ami
    file << strVectorToStr(std::get<11>(_dataMap[username])) << std::endl; // Mes demandes
    file << std::fixed << std::setprecision(2) << std::get<12>(_dataMap[username]) << std::endl; //ELO rank
    _dataMap.erase(username);
  }
  else {
    std::cerr << "[Error] Data open file write" << std::endl;
  }

  file.close();
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

  _mutex.lock();
  if (_dataMap.find(friend_name) != _dataMap.end()){ // Si friend_name est connecte
    std::get<9>(_dataMap[friend_name]) = his_friends;
    std::get<11>(_dataMap[friend_name]) = his_sent_requests;
  }
  else {
    loadUserData(friend_name);
    std::get<9>(_dataMap[friend_name]) = his_friends;
    std::get<11>(_dataMap[friend_name]) = his_sent_requests;
    saveUserData(friend_name);
  }
  _mutex.unlock();

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    std::get<9>(_dataMap[username]) = my_friends;
    std::get<10>(_dataMap[username]) = my_requests; // Requete recue
  }
  else {
    loadUserData(username);
    std::get<9>(_dataMap[username]) = my_friends;
    std::get<10>(_dataMap[username]) = my_requests; // Requete recue
    saveUserData(username);
  }
  _mutex.unlock();

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

  _mutex.lock();
  if (_dataMap.find(friend_name) != _dataMap.end()){ // Si friend_name est connecte
    std::get<11>(_dataMap[friend_name]) = his_sent_requests;
  }
  else {
    loadUserData(friend_name);
    std::get<11>(_dataMap[friend_name]) = his_sent_requests;
    saveUserData(friend_name);
  }
  _mutex.unlock();

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    std::get<10>(_dataMap[username]) = my_requests; // Requete recue
  }
  else {
    loadUserData(username);
    std::get<10>(_dataMap[username]) = my_requests; // Requete recue
    saveUserData(username);
  }
  _mutex.unlock();

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
  _mutex.lock();
  if (_dataMap.find(friend_name) != _dataMap.end()){ // Si ami connecte
    std::get<10>(_dataMap[friend_name]).push_back(username);
  }
  else {
    loadUserData(friend_name);
    std::get<10>(_dataMap[friend_name]).push_back(username);
    saveUserData(friend_name);
  }
  _mutex.unlock();

  // Ajoute friend_name au demandes envoyees de username
  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    std::get<11>(_dataMap[username]).push_back(friend_name);
  }
  else {
    loadUserData(username);
    std::get<11>(_dataMap[username]).push_back(friend_name);
    saveUserData(username);
  }
  _mutex.unlock();

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

  _mutex.lock();
  if (_dataMap.find(friend_name) != _dataMap.end()){ // Si friend_name est connecte
    std::get<9>(_dataMap[friend_name]) = his_friends;
  }
  else {
    loadUserData(friend_name);
    std::get<9>(_dataMap[friend_name]) = his_friends;
    saveUserData(friend_name);
  }
  _mutex.unlock();

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    std::get<9>(_dataMap[username]) = my_friends;
  }
  else {
    loadUserData(username);
    std::get<9>(_dataMap[username]) = my_friends;
    saveUserData(username);
  }
  _mutex.unlock();

  return 1;
}

bool Data::cancelSentRequest(const std::string username, const std::string friend_name){
  std::vector<std::string> sent = getUserSentRequests(username);

  if (std::find(sent.begin(), sent.end(), friend_name) == sent.end()){
    return 0; // Aucune requete n'a ete envoye a friend_name
  }

  // Sinon annule la Requete
  std::vector<std::string> friend_request = getUserFriendRequests(friend_name);

  sent.erase(std::remove(sent.begin(), sent.end(), friend_name), sent.end());
  friend_request.erase(std::remove(friend_request.begin(), friend_request.end(), username), friend_request.end());

  _mutex.lock();
  if (_dataMap.find(friend_name) != _dataMap.end()){
    std::get<10>(_dataMap[friend_name]) = friend_request;
  }
  else {
    loadUserData(friend_name);
    std::get<10>(_dataMap[friend_name]) = friend_request;
    saveUserData(friend_name);
  }
  _mutex.unlock();

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    std::get<11>(_dataMap[username]) = sent;
  }
  else {
    loadUserData(username);
    std::get<11>(_dataMap[username]) = sent;
    saveUserData(username);
  }
  _mutex.unlock();

  return 1;
}


std::vector<std::string> Data::getUserFriends(const std::string username){
  std::vector<std::string> friends;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    friends = std::get<9>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    friends = std::get<9>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  return friends;
}


std::vector<std::string> Data::getUserFriendRequests(const std::string username){
  std::vector<std::string> requests;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    requests = std::get<10>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    requests = std::get<10>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  return requests;
}

std::vector<std::string> Data::getUserSentRequests(const std::string username){
  std::vector<std::string> requests_sent;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    requests_sent = std::get<11>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    requests_sent = std::get<11>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  return requests_sent;
}


void Data::addUserClassicWin(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<1>(_dataMap[username])[0]); //pass 1 and 0 over param?
    stat = std::get<1>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<1>(_dataMap[username])[0]);
    stat = std::get<1>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnWin("Classic", {username, stat}); //can be a type in game passed over param?
}

void Data::addUserClassicLose(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<1>(_dataMap[username])[1]);
    stat = std::get<1>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<1>(_dataMap[username])[1]);
    stat = std::get<1>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnLoseDraw("Classic", {username, stat});
}

void Data::addUserClassicDraw(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<1>(_dataMap[username])[2]);
    stat = std::get<1>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<1>(_dataMap[username])[2]);
    stat = std::get<1>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnLoseDraw("Classic", {username, stat});
}

void Data::addUserDarkWin(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<2>(_dataMap[username])[0]);
    stat = std::get<2>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<2>(_dataMap[username])[0]);
    stat = std::get<2>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnWin("Dark", {username, stat});
}

void Data::addUserDarkLose(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<2>(_dataMap[username])[1]);
    stat = std::get<2>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<2>(_dataMap[username])[1]);
    stat = std::get<2>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnLoseDraw("Dark", {username, stat});
}

void Data::addUserDarkDraw(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<2>(_dataMap[username])[2]);
    stat = std::get<2>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<2>(_dataMap[username])[2]);
    stat = std::get<2>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnLoseDraw("Dark", {username, stat});
}

void Data::addUserHordeWin(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<3>(_dataMap[username])[0]);
    stat = std::get<3>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<3>(_dataMap[username])[0]);
    stat = std::get<3>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnWin("Horde", {username, stat});
}

void Data::addUserHordeLose(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<3>(_dataMap[username])[1]);
    stat = std::get<3>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<3>(_dataMap[username])[1]);
    stat = std::get<3>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnLoseDraw("Horde", {username, stat});
}

void Data::addUserHordeDraw(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<3>(_dataMap[username])[2]);
    stat = std::get<3>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<3>(_dataMap[username])[2]);
    stat = std::get<3>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnLoseDraw("Horde", {username, stat});
}

void Data::addUserAliceWin(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<4>(_dataMap[username])[0]);
    stat = std::get<4>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<4>(_dataMap[username])[0]);
    stat = std::get<4>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnWin("Alice", {username, stat});
}

void Data::addUserAliceLose(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<4>(_dataMap[username])[1]);
    stat = std::get<4>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<4>(_dataMap[username])[1]);
    stat = std::get<4>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnLoseDraw("Alice", {username, stat});
}

void Data::addUserAliceDraw(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<4>(_dataMap[username])[2]);
    stat = std::get<4>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<4>(_dataMap[username])[2]);
    stat = std::get<4>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnLoseDraw("Alice", {username, stat});
}

void Data::addUserRealTimeClassicWin(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<5>(_dataMap[username])[0]);
    stat = std::get<5>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<5>(_dataMap[username])[0]);
    stat = std::get<5>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnWin("RealTimeClassic", {username, stat});
}

void Data::addUserRealTimeClassicLose(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<5>(_dataMap[username])[1]);
    stat = std::get<5>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<5>(_dataMap[username])[1]);
    stat = std::get<5>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnLoseDraw("RealTimeClassic", {username, stat});
}

void Data::addUserRealTimeClassicDraw(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<5>(_dataMap[username])[2]);
    stat = std::get<5>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<5>(_dataMap[username])[2]);
    stat = std::get<5>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnLoseDraw("RealTimeClassic", {username, stat});
}

void Data::addUserRealTimeDarkWin(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<6>(_dataMap[username])[0]);
    stat = std::get<6>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<6>(_dataMap[username])[0]);
    stat = std::get<6>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnWin("RealTimeDark", {username, stat});
}

void Data::addUserRealTimeDarkLose(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<6>(_dataMap[username])[1]);
    stat = std::get<6>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<6>(_dataMap[username])[1]);
    stat = std::get<6>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnLoseDraw("RealTimeDark", {username, stat});
}

void Data::addUserRealTimeDarkDraw(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<6>(_dataMap[username])[2]);
    stat = std::get<6>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<6>(_dataMap[username])[2]);
    stat = std::get<6>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnLoseDraw("RealTimeDark", {username, stat});
}

void Data::addUserRealTimeHordeWin(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<7>(_dataMap[username])[0]);
    stat = std::get<7>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<7>(_dataMap[username])[0]);
    stat = std::get<7>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnWin("RealTimeHorde", {username, stat});
}

void Data::addUserRealTimeHordeLose(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<7>(_dataMap[username])[1]);
    stat = std::get<7>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<7>(_dataMap[username])[1]);
    stat = std::get<7>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnLoseDraw("RealTimeHorde", {username, stat});
}

void Data::addUserRealTimeHordeDraw(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<7>(_dataMap[username])[2]);
    stat = std::get<7>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<7>(_dataMap[username])[2]);
    stat = std::get<7>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnLoseDraw("RealTimeHorde", {username, stat});
}

void Data::addUserRealTimeAliceWin(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<8>(_dataMap[username])[0]);
    stat = std::get<8>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<8>(_dataMap[username])[0]);
    stat = std::get<8>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnWin("RealTimeAlice", {username, stat});
}

void Data::addUserRealTimeAliceLose(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<8>(_dataMap[username])[1]);
    stat = std::get<8>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<8>(_dataMap[username])[1]);
    stat = std::get<8>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnLoseDraw("RealTimeAlice", {username, stat});
}

void Data::addUserRealTimeAliceDraw(const std::string username){
  Stat stat;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    ++(std::get<8>(_dataMap[username])[2]);
    stat = std::get<8>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    ++(std::get<8>(_dataMap[username])[2]);
    stat = std::get<8>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  updateLadderOnLoseDraw("RealTimeAlice", {username, stat});
}



bool Data::isInLadder(const std::string gamemode, const std::string username){
  for (unsigned int a = 0; a < _ladders[gamemode].size(); ++a)
    if (std::get<0>(_ladders[gamemode][a]) == username)
      return true;
  return false;
}


void Data::updateLadderOnWin(const std::string gamemode, UserLadderData data){
  if (_ladders[gamemode].size() == 0){
    _ladders[gamemode].push_back(data);
    return;
  }

  unsigned int a = 0;

  while (a < _ladders[gamemode].size() && std::get<1>(data)[0] >= std::get<1>(_ladders[gamemode][a])[0]){
    if (std::get<0>(data) == std::get<0>(_ladders[gamemode][a])){
      _ladders[gamemode].erase(_ladders[gamemode].begin()+a);
      --a;
    }
    ++a;
  }

  _ladders[gamemode].insert(_ladders[gamemode].begin()+a, data);

  if (_ladders[gamemode].size() > 10){
    _ladders[gamemode].erase(_ladders[gamemode].begin());
  }

}


void Data::updateLadderOnLoseDraw(const std::string gamemode, UserLadderData data){
  unsigned int a = 0;
  bool found = false;

  while (a < _ladders[gamemode].size() && !found && std::get<1>(data)[0] <= std::get<1>(_ladders[gamemode][a])[0]){
    if (std::get<0>(data) == std::get<0>(_ladders[gamemode][a])){
      _ladders[gamemode][a] = data;
      found = true;
    }

    ++a;
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
        updateLadderOnWin("Classic", {username, std::get<1>(_dataMap[username])});
        updateLadderOnWin("Dark",    {username, std::get<2>(_dataMap[username])});
        updateLadderOnWin("Horde",   {username, std::get<3>(_dataMap[username])});
        updateLadderOnWin("Alice",   {username, std::get<4>(_dataMap[username])});
        updateLadderOnWin("RealTimeClassic", {username, std::get<5>(_dataMap[username])});
        updateLadderOnWin("RealTimeDark",    {username, std::get<6>(_dataMap[username])});
        updateLadderOnWin("RealTimeHorde",   {username, std::get<7>(_dataMap[username])});
        updateLadderOnWin("RealTimeAlice",   {username, std::get<8>(_dataMap[username])});
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


void Data::printLadder(const std::string gamemode){
  std::cout << "Classement du mode : " << gamemode << std::endl;
  for (unsigned int a = 0; a < _ladders[gamemode].size(); ++a){
    std::cout << a << ") " << std::get<0>(_ladders[gamemode][a]) << " " <<
    std::get<1>(_ladders[gamemode][a])[0] << " " <<
    std::get<1>(_ladders[gamemode][a])[1] << " " <<
    std::get<1>(_ladders[gamemode][a])[2] << " points" << std::endl;
   }
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
    else  if (gamemode == "Alice")
      user_stat = std::get<4>(_dataMap[username]);
    else if (gamemode == "RealTimeClassic")
      user_stat = std::get<5>(_dataMap[username]);
    else if (gamemode == "RealTimeDark")
      user_stat = std::get<6>(_dataMap[username]);
    else if (gamemode == "RealTimeHorde")
      user_stat = std::get<7>(_dataMap[username]);
    else
      user_stat = std::get<8>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    if (gamemode == "Classic")
      user_stat = std::get<1>(_dataMap[username]);
    else if (gamemode == "Dark")
      user_stat = std::get<2>(_dataMap[username]);
    else if (gamemode == "Horde")
      user_stat = std::get<3>(_dataMap[username]);
    else  if (gamemode == "Alice")
      user_stat = std::get<4>(_dataMap[username]);
    else if (gamemode == "RealTimeClassic")
      user_stat = std::get<5>(_dataMap[username]);
    else if (gamemode == "RealTimeDark")
      user_stat = std::get<6>(_dataMap[username]);
    else if (gamemode == "RealTimeHorde")
      user_stat = std::get<7>(_dataMap[username]);
    else
      user_stat = std::get<8>(_dataMap[username]);
    saveUserData(username);
  }

  return user_stat;
}

double Data::getEloRating(std::string username){
  double eloRating;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    eloRating = std::get<12>(_dataMap[username]);
  }
  else {
    loadUserData(username);
    eloRating = std::get<12>(_dataMap[username]);
    saveUserData(username);
  }
  _mutex.unlock();

  return eloRating;
}


double Data::expectedWin(double ratingA,double ratingB){
  //formula to calculate expected win depending on ELO rating
  return 1/(1+pow(10,((ratingB-ratingA)/400)));
}

void Data::updateRating(const std::string username, double expectedWin, double score){
  //formula to update ELO depending of win expectation
  double eloRating;
  double calc;

  _mutex.lock();
  if (_dataMap.find(username) != _dataMap.end()){
    eloRating = std::get<12>(_dataMap[username]);
    calc = (eloRating + 32 * (score - expectedWin)); //formule magique de Arpad Elo
    if(calc<=0) calc = 0;// no negative ELO
    eloRating = calc;
    std::get<12>(_dataMap[username]) = eloRating;
  }
  else {
    loadUserData(username);
    eloRating = std::get<12>(_dataMap[username]);
    eloRating = (eloRating + 32 * (score - expectedWin)); //formule magique de Arpad Elo
    if(calc<=0) calc = 0; // no negative ELO
    eloRating = calc;
    std::get<12>(_dataMap[username]) = eloRating;
    saveUserData(username);
  }
  _mutex.unlock();

}

void Data::lockMutex(){
  _mutex.lock();
}

void Data::unlockMutex(){
  _mutex.unlock();
}
