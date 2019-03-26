#include "friendTab.h"
#include "ui_friendTab.h"
#include "message.h"
#include "ui_message.h"

#include "../Modified_Files/ClientFunctions.hpp"
#include "../Modified_Files/CheckFormat.hpp"

FriendTab::FriendTab(Client* clients, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FriendTab),
    client(clients)
{
    ui->setupUi(this);
    on_updatePushButton_clicked();
}

FriendTab::~FriendTab()
{
    delete ui;
}

void FriendTab::on_removePushButton_pressed()
{
    QListWidgetItem *it = ui->friendListWidget->takeItem(ui->friendListWidget->currentRow());
    if (it){
        removeFriend(client->getSocket(), it->text().toStdString());
        client->removeFriend(it->text().toStdString());
        client->readPipe();
        delete it;
    }
}

void FriendTab::on_addPushButton_pressed()
{
    if(ui->inputLineEdit->text() != "" && ui->inputLineEdit->text() != "Guest"){
        if(!checkFriendInputFormat(ui->inputLineEdit->text().toStdString())){
            popup("Invalid Name", "A name must have between 1 and 10 characters and they must be digits or letters.");
            ui->addPushButton->setDown(false);
        }
        else{
            sendFriendRequest(client->getSocket(), ui->inputLineEdit->text().toStdString());
            std::string feedback = client->readPipe();
            if(feedback[0] == '3'){
                client->addFriend(ui->inputLineEdit->text().toStdString());
                client->removeRecvRequest(ui->inputLineEdit->text().toStdString());
                ui->friendListWidget->addItem(ui->inputLineEdit->text());
            }
            else if(feedback[0] != '4'){
                popup("Error", QString::fromStdString(feedback.erase(0,1)));
            }
            else {
                ui->outgoingListWidget->addItem(ui->inputLineEdit->text());
                client->addSentRequest(ui->inputLineEdit->text().toStdString());
            }
       }
    }
    else{
        popup("Oh No: Empty Field or Guest Detected", "Please input at least something(not Guest) and not just empty space..");
        ui->addPushButton->setDown(false);
    }
    ui->inputLineEdit->clear();
}

void FriendTab::on_cancelPushButton_pressed()
{
    QListWidgetItem *it = ui->outgoingListWidget->takeItem(ui->outgoingListWidget->currentRow());
    if (it){
        cancelRequest(client->getSocket(), it->text().toStdString());
        client->removeSentRequest(it->text().toStdString());
        client->readPipe();
    }
    delete it;
}

void FriendTab::on_acceptPushButton_pressed()
{
    QListWidgetItem *it = ui->incomingListWidget->takeItem(ui->incomingListWidget->currentRow());
    if (it){
        acceptRefuseRequest(client->getSocket(), it->text().toStdString(),"1");
        std::string feedback = client->readPipe();
        if(feedback[0] != '2') {
            popup("Error", QString::fromStdString(feedback.erase(0,1)));
            delete it;
        }
        else {
            client->removeRecvRequest(it->text().toStdString());
            client->addFriend(it->text().toStdString());
            ui->friendListWidget->addItem(it);
        }
    }
}

void FriendTab::on_denyPushButton_pressed()
{
    QListWidgetItem *it = ui->incomingListWidget->takeItem(ui->incomingListWidget->currentRow());
    if (it){
        acceptRefuseRequest(client->getSocket(), it->text().toStdString(),"0");
        client->removeRecvRequest(it->text().toStdString());
        std::string feedback = client->readPipe();
        if(feedback[0] != '3') popup("Error", QString::fromStdString(feedback.erase(0,1)));
        delete it;
    }
}



void FriendTab::on_inputLineEdit_returnPressed()
{
    on_addPushButton_pressed();
}

void FriendTab::on_updatePushButton_clicked()
{
    std::vector<std::string> list = client->getFriends();
    auto it = list.begin();
    ui->friendListWidget->clear();
    for (;it != list.end(); ++it) ui->friendListWidget->addItem(QString::fromStdString(*it));

    list = client->getRecvRequest();
    it = list.begin();
    ui->incomingListWidget->clear();
    for (;it != list.end(); ++it) ui->incomingListWidget->addItem(QString::fromStdString(*it));

    list = client->getSentRequest();
    it = list.begin();
    ui->outgoingListWidget->clear();
    for (;it != list.end(); ++it) ui->outgoingListWidget->addItem(QString::fromStdString(*it));
}

void FriendTab::popup(QString title, QString message)
{
    Message* m = new Message();
    m->set_text(message);
    m->set_title(title);
    m->popup();
}

void FriendTab::on_returnPushButton_pressed()
{
    close();
}
