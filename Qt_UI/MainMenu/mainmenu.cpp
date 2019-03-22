#include "../../Communication/Socket.hpp"
#include "../../Communication/Client.hpp"
#include "../Modified_Files/ClientMessageHandler.hpp"

#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "connectiondialog.h"
#include "logindialog.h"

#include <QDesktopServices>
#include <QUrl>

#include <thread>

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu),
    connect(new ConnectionDialog),
    login(new LoginDialog),
    socket(new Socket),
    client(new Client(socket))
{
    ui->setupUi(this);
    client_connect();
    std::thread receiveThread(receiveMessageHandler, client);
    client_login();
}

MainMenu::~MainMenu()
{
    delete ui;
    if (connect != nullptr) delete connect;
    if (login != nullptr) delete login;
    delete client;
}

void MainMenu::client_connect() {
    bool good_hostname = false;
    std::string hostname;
    do {
        hostname = (connect->ask_hostname()).toStdString();
        good_hostname = socket->connectToServer(hostname);
    } while (!good_hostname);
    connect->close();
}

void MainMenu::client_login() {
    QString username, password;
    do
    {
        login->get_login_deets(socket, username, password);
        std::cout << client->readPipe() << std::endl;
    }
    while (!(client->isIdentified()));
    login->close();
    client->setName(username.toStdString());
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
    closeEvent();
}

void MainMenu::closeEvent()
{
    exit(0);
}
