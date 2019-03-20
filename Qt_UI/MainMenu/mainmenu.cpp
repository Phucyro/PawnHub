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
    if (connect) delete connect;
    if (login) delete login;
    delete socket;
}

void MainMenu::client_connect() {
    bool connected = false;
    std::string hostname;
    ui->setupUi(this);
    do {
        hostname = (connect->ask_hostname()).toStdString();
        connected = socket->connectToServer(hostname);
        connected = true;
    } while (!connected);
    delete connect;
}

void MainMenu::client_login() {
    QString username, password;
    login->get_login_deets(username, password);
}

void MainMenu::on_playButton_clicked()
{

}

void MainMenu::on_statsButton_clicked()
{

}

void MainMenu::on_friendsButton_clicked()
{

}

void MainMenu::on_chatButton_clicked()
{

}

void MainMenu::on_rulesButton_clicked()
{
    QUrl url("https://en.wikipedia.org/wiki/Chess");
    QDesktopServices::openUrl(url);
}

void MainMenu::on_quitButton_clicked()
{
    exit(0);
}
