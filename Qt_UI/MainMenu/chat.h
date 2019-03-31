#ifndef Chat_H
#define Chat_H

#include "message.h"

#include <QDialog>

#include <string>

class Client;

namespace Ui {
class Chat;
}

class Chat : public QDialog
{
    Q_OBJECT

public:
    explicit Chat(Client *clients, QWidget *parent = nullptr);
    ~Chat();
    void showEvent(QShowEvent*);


public slots:
  void displayChat(QString target);


private slots:
    void on_sendPushButton_pressed();

    void on_quitPushButton_pressed();

    void on_changeChanPushButton_pressed();
    void setupChat();
    void reloadFriends();


    void on_friendListWidget_itemSelectionChanged();

private:
    Ui::Chat *ui;
    Client  *client;
};

#endif // Chat_H
