//#include "../../Communication/Socket.hpp"

#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "connectiondialog.h"
#include "logindialog.h"

#include <QDesktopServices>
#include <QUrl>

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu),
    connect(new ConnectionDialog),
    login(new LoginDialog),
    socket(new Socket)
{
    client_connect();
    client_login();
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::client_connect() {
    bool connected = false;
    std::string hostname;
    ui->setupUi(this);
    do {
        hostname = (connect->askHostname()).toStdString();
        connected = socket->connectToServer(hostname);
        connected = true;
    } while (!connected);
}

void MainMenu::client_login() {
    QString username, password;
    login->getLoginDeets(username, password);
}

void MainMenu::on_play_button_clicked()
{

}

void MainMenu::on_stats_button_clicked()
{

}

void MainMenu::on_friends_button_clicked()
{

}

void MainMenu::on_chat_button_clicked()
{

}

void MainMenu::on_rules_button_clicked()
{
    QUrl url("https://en.wikipedia.org/wiki/Chess");
    QDesktopServices::openUrl(url);
}

void MainMenu::on_quit_button_clicked()
{
    exit(0);
}
