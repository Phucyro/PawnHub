#include "../../Communication/Socket.hpp"
#include "../../Communication/Client.hpp"
#include "../Modified_Files/ClientMessageHandler.hpp"
#include "../Modified_Files/ClientFunctions.hpp"

#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "connectiondialog.h"
#include "logindialog.h"
#include "gameChoice.h"
#include "gameRules.h"
#include "statisticsChoice.h"
#include "friendTab.h"
#include "chat.h"

#include <QDesktopServices>
#include <QUrl>

#include <thread>

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu),
    client(new Client(new Socket)),
    chat(new Chat (client))
{
    ui->setupUi(this);
    client_connect();
    msgThread = new std::thread(receiveMessageHandler, client,chat);
    client_login();
}

MainMenu::~MainMenu()
{
    msgThread->join();
    delete msgThread;
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
    initClientData(client);
}

void MainMenu::on_playButton_clicked()
{
    GameChoice* choice = new GameChoice(nullptr, client, msgThread);
    this->hide();
    choice->exec();
    delete choice;

    if (msgThread == nullptr)
    {
        msgThread = new std::thread(receiveMessageHandler, client,chat);
    }

    this->show();
}

void MainMenu::on_statsButton_clicked()
{
    StatisticsChoice* stats = new StatisticsChoice(client);
    this->hide();
    stats->exec();
    this->show();
    delete stats;
}

void MainMenu::on_friendsButton_clicked()
{
    FriendTab* friendsTab = new FriendTab(client);
    this->hide();
    friendsTab->exec();
    this->show();
    delete friendsTab;
}

void MainMenu::on_chatButton_clicked()
{
    Chat* chat = new Chat(client);
    this->hide();
    chat->exec();
    delete chat;
    this->show();
}

void MainMenu::on_rulesButton_clicked()
{
    GameRules* rules = new GameRules;
    this->hide();
    rules->exec();
    this->show();
    delete rules;
}

void MainMenu::on_quitButton_clicked()
{
    closeEvent();
}

void MainMenu::closeEvent()
{
    quit(client);
    exit(0);
}


