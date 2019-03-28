#ifndef Chat_H
#define Chat_H

#include <QDialog>
//#include "../../Communication/Client.hpp"
//#include "../../Communication/CheckFormat.hpp"
//#include "../../Communication/Socket.hpp"
//#include "../../Communication/ClientFunctions.hpp"
#include "message.h"
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
    void displayChat(Client *client, std::string target);


private slots:
    void on_inputLineEdit_returnPressed();

    void on_sendPushButton_pressed();

    void on_quitPushButton_pressed();

    void on_changeChanPushButton_pressed();
    void setupChat();


private:
    Ui::Chat *ui;
    Client  *client;
};

#endif // Chat_H
