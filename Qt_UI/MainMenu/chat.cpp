#include "chat.h"
#include "ui_chat.h"


//#include "../../Communication/Client.hpp"
#include "../Modified_Files/ClientFunctions.hpp"
#include "../Modified_Files/CheckFormat.hpp"

Chat::Chat(Client *clients,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Chat),
    client(clients)
{
    ui->setupUi(this);
}

Chat::~Chat()
{
    delete ui;
}

void Chat::setupChat(){
    ui->chgChangeChannellabel->setText(QString::fromStdString(client->getIsChattingWith()));
    client->setIsChatting(true);
    displayChat(client->getIsChattingWith());
}

void Chat::displayChat(std::string target){
    Conversation conv = client->getConversation(target);

    ui->chatPlainTextEdit->clear(); //clears chat box
    ui->inputLineEdit->clear(); //clears input box

    // Fills chat box with conversation
    for (unsigned int a = 0; a < conv.size(); ++a)
    {
        std::string text = std::get<0>(conv[a]) + " : " + std::get<1>(conv[a]);
        ui->chatPlainTextEdit->appendPlainText(QString::fromStdString(text));
    }
}

void Chat::on_sendPushButton_pressed()
{
    if (!checkInputFormat(ui->inputLineEdit->text().toStdString())){
        Message* m = new Message();
                 m->set_text("The caracters '|' and '~' are forbidden");
                 m->set_title("Oh No: Wrong Characters detected");
                 m->popup();
    }

    chat(client->getSocket(), client->getIsChattingWith(), ui->inputLineEdit->text().toStdString());

    ui->chatPlainTextEdit->appendPlainText(ui->inputLineEdit->text());
    ui->inputLineEdit->clear();
}

void Chat::on_inputLineEdit_returnPressed()
{
    if (!checkInputFormat(ui->inputLineEdit->text().toStdString())){
        Message* m = new Message();
                 m->set_text("The caracters '|' and '~' are forbidden");
                 m->set_title("Oh No: Wrong Characters detected");
                 m->popup();
    }

    chat(client->getSocket(), client->getIsChattingWith(), ui->inputLineEdit->text().toStdString());

    ui->chatPlainTextEdit->appendPlainText(ui->inputLineEdit->text());
    ui->inputLineEdit->clear();
}

void Chat::on_quitPushButton_pressed()
{
    client->setIsChatting(false);
    close();
}

void Chat::on_changeChanPushButton_pressed()
{
    if(ui->friendListWidget->currentItem()->text().length() > 10){
        Message* m = new Message();
                 m->set_text("The username size is maximum 10 letters");
                 m->set_title("Oh No: Username size too big");
                 m->popup();
    }else if (ui->friendListWidget->currentItem()->text() == ui->chgChangeChannellabel->text()){
        Message* m = new Message();
                 m->set_text("Duhh you are already in that channel");
                 m->set_title("Oh No: Same channel error");
                 m->popup();
    }else if(ui->friendListWidget->currentItem()->text().toStdString() == client->getName()){
        Message* m = new Message();
                 m->set_text("How are you supposed to talk with yourself, are you schizophrenic? (please don't be offended)");
                 m->set_title("Oh No: Talk to yourself error");
                 m->popup();
    }else if (!client->isFriendWith(ui->friendListWidget->currentItem()->text().toStdString()) && ui->friendListWidget->currentItem()->text() != "all"){
        Message* m = new Message();
                 m->set_text("You are not befriended with that person ?");
                 m->set_title("Oh No: Not befriended error");
                 m->popup();
    }else{
        client->setIsChattingWith(ui->friendListWidget->currentItem()->text().toStdString());
        displayChat(ui->friendListWidget->currentItem()->text().toStdString());
        ui->chatPlainTextEdit->clear();
    }
}
