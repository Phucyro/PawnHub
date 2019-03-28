#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include "../../Communication/Socket.hpp"
//#include "../../Communication/ClientGameControl.hpp"
#include "../../Communication/Client.hpp"
#include "chat.h"
#include <string>
#include <stdlib.h>


class ClientHandler : public QObject {

  Q_OBJECT

public:
  ClientHandler(Client*);
  ~ClientHandler();


public slots :
  void receiveMessageHandler();
  // chatHandler();
  void quit();

signals :
  void finished();
  void sigDisplayChat(QString);

private:
  void signUpHandler(char);
  void signInHandler(char);
  void chatHandler(QString, QString, QString);
  void playGameHandler();
  void leaveQueueHandler();
  void myStatHandler(QString, QString, QString);
  void ladderHandler(QString, QString, QString);
  void viewFriendsHandler(QString);
  void viewFriendRequestHandler(QString);
  void acceptRefuseRequestHandler(QString, QString);
  void sendFriendRequestHandler(QString);
  void removeFriendHandler(QString);
  void viewSentRequestHandler(QString);
  void cancelRequestHandler(QString);
  void updateFriendsListHandler(QString, QString);
  void updateRecvRequestHandler(QString, QString);
  void updateSentRequestHandler(QString, QString);

  Client* client;
  bool mustQuit;

};
#endif
