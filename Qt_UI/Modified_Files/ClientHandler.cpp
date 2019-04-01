#include "ClientHandler.hpp"
#include "../../Communication/SplitString.hpp"
#include "message.h"

ClientHandler::ClientHandler(Client* _client): QObject(), client(_client), mustQuit(false){}

ClientHandler::~ClientHandler(){
  client = nullptr;
}

void ClientHandler::quitHandler(){
    mustQuit = true;
}

void ClientHandler::signUpHandler(char msg){
  switch (msg){
    case '0' :
      client->writePipe("Someone already has this account name.\nPlease pick another one.");
      break;
    case '1' :
      client->writePipe("Successfully created account!");
      break;
  }
}


void ClientHandler::signInHandler(char msg){
  switch (msg){
    case '0' :
      client->writePipe("Account name does not exist.");
      break;
    case '1' :
      client->setIdentified(); // Ne sera pas affiche
      client->writePipe("Succesfully logged in.");
      break;
    case '2' :
      client->writePipe("Wrong password.\nPlease try again.");
      break;
    case '3' :
      client->writePipe("Someone is already logged into this account.");
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
    sigStartGame();
}

void ClientHandler::leaveQueueHandler(){
    Message m;
    m.set_title("Queue Left");
    m.set_text("You have left the queue correctly.");
    m.popup();
}

void ClientHandler::myStatHandler(QString pos, QString mode, QString stat, QString elo){
  client->writePipe(pos.toStdString() + " " + mode.toStdString() + " " + stat.toStdString() + " " + elo.toStdString());
}

void ClientHandler::ladderHandler(QString pos,QString username, QString stat, QString elo){
  client->writePipe(pos.toStdString() + " " + username.toStdString() + " " + stat.toStdString() + " " + elo.toStdString());
}

void ClientHandler::viewFriendsHandler(QString friend_name){
  client->addFriend(friend_name.toStdString());
}

void ClientHandler::viewFriendRequestHandler(QString username){
  client->addRecvRequest(username.toStdString());
}

void ClientHandler::acceptRefuseRequestHandler(QString option, QString res){
  if (option == "0") // Impossible normalement car gere lors du sendRequest
    client->writePipe("0You cannot befriend yourself.\nAt least not here.");
  else if (option == "1"){
    if (res == "0") // Est gere par le cote client actuellement
      client->writePipe("1You have not received a request from this account.");
    else
      client->writePipe("2This account has been added to your friends' list.");
  }
  else {
    if (res == "0") // Est gere par le cote client actuellement
      client->writePipe("1You have not received a request from this account.");
    else
      client->writePipe("3The account was removed from your friends' list.");
  }
}

void ClientHandler::sendFriendRequestHandler(QString res){
  switch (res[0].digitValue()){
    case 0 :
      client->writePipe("0Unknown account.");
      break;
    case 1 : // Gere du cote client actuellement
      client->writePipe("1This account is already in your friends' list.");
      break;
    case 2 : // Gere du cote client actuellement
      client->writePipe("2Friend request has already been sent out.\nMaybe they just don't like you.");
      break;
    case 3 :
      client->writePipe("3You are now friends.");
      break;
    case 4 :
      client->writePipe("4Friend request sent.");
      break;
  }
}

void ClientHandler::removeFriendHandler(QString res){
  switch (res[0].digitValue()){
    case 0 : // Gere actuellement du cote client
      client->writePipe("0This account is not in your friends' list.");
      break;
    case 1 :
      client->writePipe("1Account has been removed from your friends' list.");
      break;
  }
}

void ClientHandler::viewSentRequestHandler(QString username){
  client->addSentRequest(username.toStdString());
}

void ClientHandler::cancelRequestHandler(QString res){
  if (res == "0") // Gere actuellement du cote client
    client->writePipe("0No friend request has been sent to this account.");
  else
    client->writePipe("1Friend request cancelled.");
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

  while (!mustQuit){
    msg = splitString(client->getSocket()->receiveMessage(), '~');

    int choice = atoi(msg[0].c_str());

    switch(choice){
      case 0 :
        quitHandler();
        break;
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
        playGameHandler();
        break;
      case 5 :
        leaveQueueHandler();
        break;
      case 7 :
        myStatHandler(QString::fromStdString(msg[1]), QString::fromStdString(msg[2]), QString::fromStdString(msg[3]), QString::fromStdString(msg[4]));
        break;
      case 8 :
        ladderHandler(QString::fromStdString(msg[1]), QString::fromStdString(msg[2]), QString::fromStdString(msg[3]), QString::fromStdString(msg[4]));
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
      case 30 :
        client->writeGame(msg[1]);
        break;
    }
  }
  emit finished();
}

//void ClientHandler::quit(){
//	mustQuit = true;
//}
