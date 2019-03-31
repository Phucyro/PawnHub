#include "mainmenu.h"
#include "ui_mainmenu.h"

#include "connectiondialog.h"
#include "logindialog.h"
#include "gameChoice.h"
#include "gameRules.h"
#include "statisticsChoice.h"
#include "friendTab.h"
#include "chat.h"

#include "../../Communication/Socket.hpp"
#include "../../Communication/Client.hpp"
#include "../Modified_Files/ClientHandler.hpp"
#include "../Modified_Files/ClientFunctions.hpp"

#include <QDesktopServices>
#include <QUrl>
#include <QThread>

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu),
    client(new Client(new Socket)),
    msgThread(new QThread),
    chat(new Chat (client)),
    handler(new ClientHandler(client))

{
    ui->setupUi(this);
    client_connect();

    handler->moveToThread(msgThread);
    connect(msgThread, &QThread::started, handler, &ClientHandler::receiveMessageHandler);
    connect(handler, &ClientHandler::finished, msgThread, &QThread::quit);
    connect(msgThread, &QThread::finished, handler, &ClientHandler::deleteLater);
    connect(msgThread, &QThread::finished, msgThread, &QThread::deleteLater);
    connect(handler, &ClientHandler::sigDisplayChat, chat, &Chat::displayChat);
    msgThread->start();

    client_login();
    initClientData(client);

}

MainMenu::~MainMenu()
{
    if (msgThread!= nullptr)
    {
      msgThread->deleteLater();
    }
    delete client;
    delete  ui;
}

void MainMenu::client_connect() {
    ConnectionDialog* connect = new ConnectionDialog;

    bool good_hostname = false;
    std::string hostname;
    do {
        hostname = (connect->ask_hostname()).toStdString();
        good_hostname = client->getSocket()->connectToServer(hostname);

        if (!good_hostname){
            Message* m = new Message();
            m->set_text("Hostname not found");
            m->set_title("Oh no: Something is Wrong");
            m->popup();
        }

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

        // si vous voulez mettre ca, au moins changez le message recu en anglais, vu que le RESTE du jeu est en anglais
        // svp
        QString message = QString::fromStdString(client->readPipe());
        if (!(message == "Succesfully logged in."))
        {
             Message* m = new Message();
             m->set_text(message);
             if (message == "Successfully created account!")
             {
                m->set_title("Signed Up");
                signIn(client->getSocket(), username.toStdString(), password.toStdString());
             }
             else m->set_title("Oh no: Something is Wrong");
             m->popup();
        }


    }
    while (!(client->isIdentified()));

    login->close();
    delete login;

    client->setName(username.toStdString());

}

void MainMenu::on_playButton_clicked()
{
    GameChoice* choice = new GameChoice(nullptr, client);
    connect(handler, &ClientHandler::sigStartGame, choice, &GameChoice::closeMessage);
    this->hide();
    choice->exec();
    delete choice;
    this->show();
}

void MainMenu::on_statsButton_clicked()
{
    StatisticsChoice* stats = new StatisticsChoice(client);
    stats->exec();
    stats->deleteLater();
}

void MainMenu::on_friendsButton_clicked()
{
    FriendTab* friendsTab = new FriendTab(client);
    this->hide();
    friendsTab->exec();
    this->show();
    friendsTab->deleteLater();
}

void MainMenu::on_chatButton_clicked()
{
    this->hide();
    chat->exec();
    this->show();
}

void MainMenu::on_rulesButton_clicked()
{
    GameRules* rules = new GameRules;
    this->hide();
    rules->exec();
    this->show();
    rules->deleteLater();
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
