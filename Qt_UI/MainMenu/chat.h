#ifndef Chat_H
#define Chat_H

#include <QDialog>
#include "message.h"
#include <string>
#include "../Modified_Files/ClientFunctions.hpp"
#include "../Modified_Files/CheckFormat.hpp"

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

private slots:
    void on_inputLineEdit_returnPressed();

    void on_sendPushButton_pressed();

    void on_quitPushButton_pressed();

    void on_changeChanPushButton_pressed();
    void setupChat();
    void displayChat(std::string target);


private:
    Ui::Chat *ui;
    Client  *client;
};

#endif // Chat_H
