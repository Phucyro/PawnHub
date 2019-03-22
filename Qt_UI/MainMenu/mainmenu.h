#ifndef MAINMENU_H
#define MAINMENU_H

#include "../../Communication/Socket.hpp"
#include "../../Communication/Client.hpp"

#include <QWidget>

#include "connectiondialog.h"
#include "logindialog.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_playButton_clicked();
    void on_statsButton_clicked();
    void on_friendsButton_clicked();
    void on_chatButton_clicked();
    void on_rulesButton_clicked();
    void on_quitButton_clicked();

    void closeEvent();

private:
    Ui::MainMenu *ui;
    ConnectionDialog *connect;
    LoginDialog *login;
    Socket* socket;
    Client* client;

    void client_connect();
    void client_login();
};

#endif // MAINMENU_H
