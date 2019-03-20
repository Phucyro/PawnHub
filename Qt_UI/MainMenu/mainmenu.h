#ifndef MAINMENU_H
#define MAINMENU_H

#include "../../Communication/Socket.hpp"

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
    void on_play_button_clicked();

    void on_stats_button_clicked();

    void on_friends_button_clicked();

    void on_chat_button_clicked();

    void on_rules_button_clicked();

    void on_quit_button_clicked();

private:
    Ui::MainMenu *ui;
    ConnectionDialog *connect;
    LoginDialog *login;
    Socket* socket;

    void client_connect();
    void client_login();
};

#endif // MAINMENU_H
