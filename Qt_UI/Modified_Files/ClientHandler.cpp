#include "ClientHandler.hpp"
#include "../../Communication/SplitString.hpp"

ClientHandler::ClientHandler(Client* _client): QObject(), client(_client){}

ClientHandler::~ClientHandler(){
  client = nullptr;
}

void ClientHandler::signUpHandler(char msg){
  switch (msg){
    case '0' :
      client->writePipe("Le nom de compte a deja été pris");
      break;
    case '1' :
      client->writePipe("Compte créé avec succes");
      break;
  }
}


void ClientHandler::signInHandler(char msg){
  switch (msg){
    case '0' :
      client->writePipe("Nom de compte inexistant");
      break;
    case '1' :
      client->setIdentified(); // Ne sera pas affiche
      client->writePipe("Connexion réussie");
      break;
    case '2' :
      client->writePipe("Mauvais mot de passe");
      break;
    case '3' :
      client->writePipe("Ce compte est déjà utilisé par quelqu'un");
      break;
  }
}


void ClientHandler::chatHandler(QString sender, QString target, QString msg){
  client->updateConversation(target.toStdString(), sender.toStdString(), msg.toStdString());

  if (client->isChatting() && client->isChattingWith(target.toStdString())){
    sigDisplayChat(target);
  }
}


void ClientHandler::playGameHandler(){
//  menu->clear_windows();
//  menu->end_windows();
//  std::cout << "Vous avez rejoint une file d'attente" << std::endl;
//  ClientGameControl control(*(client->getSocket()));
  client->writePipe("EndGame");
}

void ClientHandler::leaveQueueHandler(){
  //std::cout << "Vous avez quitte une file d'attente" << std::endl;
}

void ClientHandler::myStatHandler(QString pos, QString mode, QString stat){
  client->writePipe(pos.toStdString() + " " + mode.toStdString() + " " + stat.toStdString());
}

void ClientHandler::ladderHandler(QString pos,QString username, QString stat){
  client->writePipe(pos.toStdString() + " " + username.toStdString() + " " + stat.toStdString());
}

void ClientHandler::viewFriendsHandler(QString friend_name){
  client->addFriend(friend_name.toStdString());
}

void ClientHandler::viewFriendRequestHandler(QString username){
  client->addRecvRequest(username.toStdString());
}

void ClientHandler::acceptRefuseRequestHandler(QString option, QString res){
  if (option == "0") // Impossible normalement car gere lors du sendRequest
    client->writePipe("0Vous ne pouvez pas être amis avec vous même");
  else if (option == "1"){
    if (res == "0") // Est gere par le cote client actuellement
      client->writePipe("1Vous n'avez pas recu de demande de cet utilisateur");
    else
      client->writePipe("2Cet utilisateur a été ajouté à vos amis");
  }
  else {
    if (res == "0") // Est gere par le cote client actuellement
      client->writePipe("1Vous n'avez pas recu de demande cet utilisateur");
    else
      client->writePipe("3Cet utilisateur a été retiré de la liste");
  }
}

void ClientHandler::sendFriendRequestHandler(QString res){
  switch (res[0].digitValue()){
    case '0' :
      client->writePipe("0Utilisateur inexistant");
      break;
    case '1' : // Gere du cote client actuellement
      client->writePipe("1Utilisateur déjà dans la liste d'amis");
      break;
    case '2' : // Gere du cote client actuellement
      client->writePipe("2Demande d'ami déjà envoyé");
      break;
    case '3' :
      client->writePipe("3Vous êtes tout les deux devenus amis");
      break;
    case '4' :
      client->writePipe("4Demande d'ami envoyé");
      break;
  }
}

void ClientHandler::removeFriendHandler(QString res){
  switch (res[0].digitValue()){
    case '0' : // Gere actuellement du cote client
      client->writePipe("0Cet utilisateur ne fait pas partie de vos amis");
      break;
    case '1' :
      client->writePipe("1Utilisateur retiré de votre liste d'amis");
      break;
  }
}

void ClientHandler::viewSentRequestHandler(QString username){
  client->addSentRequest(username.toStdString());
}

void ClientHandler::cancelRequestHandler(QString res){
  if (res == "0") // Gere actuellement du cote client
    client->writePipe("0Aucune requete n'a été envoyé à ce joueur");
  else
    client->writePipe("1La demande d'ami a été annulée");
}

void ClientHandler::updateFriendsListHandler(QString friend_name, QString option){
  if (option == "0"){ // Retire l'ami
    client->removeFriend(friend_name.toStdString());
  }
  else if (option == "1"){ // Ajoute l'ami
    client->addFriend(friend_name.toStdString());
  }
}

void ClientHandler::updateRecvRequestHandler(QString friend_name, QString option){
  if (option == "0"){ // Retire l'ami
    client->removeRecvRequest(friend_name.toStdString());
  }
  else if (option == "1"){ // Ajoute l'ami
    client->addRecvRequest(friend_name.toStdString());
  }
}

void ClientHandler::updateSentRequestHandler(QString friend_name, QString option){
  if (option == "0"){ // Retire l'ami
    client->removeSentRequest(friend_name.toStdString());
  }
  else if (option == "1"){ // Ajoute l'ami
    client->addSentRequest(friend_name.toStdString());
  }
}

void ClientHandler::receiveMessageHandler(){
  std::vector<std::string> msg;
  bool in_game = false;

  while (!in_game){
    msg = splitString(client->getSocket()->receiveMessage(), '~');

    if (std::isalpha(msg[0][0])){
       client->writePipe(strVectorToStr(msg));
       continue;
    }

    int choice = atoi(msg[0].c_str());

    switch(choice){
      case 1 : // [1] [resultat]
        signUpHandler(msg[1][0]);
        break;
      case 2 : // [2] [resultat]
        signInHandler(msg[1][0]);
        break;
      case 3 : // [3] [sender] [target] [text]
        chatHandler(QString::fromStdString(msg[1]), QString::fromStdString(msg[2]), QString::fromStdString(msg[3]));
        break;
      case 4 :
//        playGameHandler(client);
        in_game = true;
        break;
      case 5 :
        leaveQueueHandler();
        break;
      case 7 :
        myStatHandler(QString::fromStdString(msg[1]), QString::fromStdString(msg[2]), QString::fromStdString(msg[3]));
        break;
      case 8 :
        ladderHandler(QString::fromStdString(msg[1]), QString::fromStdString(msg[2]), QString::fromStdString(msg[3]));
        break;
      case 9 :
        viewFriendsHandler(QString::fromStdString(msg[1]));
        break;
      case 10 :
        viewFriendRequestHandler(QString::fromStdString(msg[1]));
        break;
      case 11 :
        acceptRefuseRequestHandler(QString::fromStdString(msg[1]), QString::fromStdString(msg[2]));
        break;
      case 12 :
        sendFriendRequestHandler(QString::fromStdString(msg[1]));
        break;
      case 13 :
        removeFriendHandler(QString::fromStdString(msg[1]));
        break;
      case 14 :
        viewSentRequestHandler(QString::fromStdString(msg[1]));
        break;
      case 15 :
        cancelRequestHandler(QString::fromStdString(msg[1]));
        break;
      case 16 :
        updateFriendsListHandler(QString::fromStdString(msg[1]), QString::fromStdString(msg[2]));
        break;
      case 17 :
        updateRecvRequestHandler(QString::fromStdString(msg[1]), QString::fromStdString(msg[2]));
        break;
      case 18 :
        updateSentRequestHandler(QString::fromStdString(msg[1]), QString::fromStdString(msg[2]));
        break;
    }
  }
  emit finished();
}
