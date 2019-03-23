#include "../../Communication/Socket.hpp"
#include "../../Communication/Client.hpp"
#include "../Modified_Files/ClientMessageHandler.hpp"

#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "connectiondialog.h"
#include "logindialog.h"
#include "gameWithoutChat.h"

#include <QDesktopServices>
#include <QUrl>

#include <thread>

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu),
    client(new Client(new Socket))
{
    ui->setupUi(this);
    client_connect();
    msgThread = std::thread(receiveMessageHandler, client);
    client_login();
}

MainMenu::~MainMenu()
{
    msgThread.join();
    delete client;
    delete ui;
}

void MainMenu::client_connect() {
    ConnectionDialog* connect = new ConnectionDialog;

    bool good_hostname = false;
    std::string hostname;
    do {
        hostname = (connect->ask_hostname()).toStdString();
        good_hostname = client->getSocket()->connectToServer(hostname);
    } while (!good_hostname);

    connect->close();
    delete connect;
}

void MainMenu::client_login() {
    LoginDialog* login = new LoginDialog;

    QString username, password;
    do
    {
        login->get_login_deets(client->getSocket(), username, password);
        std::cout << client->readPipe() << std::endl;
    }
    while (!(client->isIdentified()));

    login->close();
    delete login;

    client->setName(username.toStdString());
}

void MainMenu::on_playButton_clicked()
{
    GameWithoutChat* game = new GameWithoutChat;
    game->exec();
    delete game;
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
    closeEvent();
}

void MainMenu::closeEvent()
{
    exit(0);
}
