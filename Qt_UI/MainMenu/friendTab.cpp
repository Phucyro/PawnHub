#include "friendTab.h"
#include "ui_friendTab.h"
#include "message.h"
#include "ui_message.h"


FriendTab::FriendTab(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FriendTab)
{
    ui->setupUi(this);
}

FriendTab::~FriendTab()
{
    delete ui;
}

void FriendTab::on_removePushButton_pressed()
{
    QListWidgetItem *it = ui->outgoingListWidget->takeItem(ui->outgoingListWidget->currentRow());
    delete it;
}

void FriendTab::on_addPushButton_pressed()
{
    if(ui->inputLineEdit->text() != "" && ui->inputLineEdit->text() != "Guest" ){
        ui->outgoingListWidget->addItem(ui->inputLineEdit->text());
        ui->inputLineEdit->clear();
    }else{
        Message* m = new Message();
        m->set_text("Please input at least something(not Guest) and not just empty space..");
        m->set_title("Oh No: Empty Field or Guest Detected");
        m->popup();
        ui->addPushButton->setDown(false);
    }

}

void FriendTab::on_cancelPushButton_pressed()
{
    QListWidgetItem *it = ui->outgoingListWidget->takeItem(ui->outgoingListWidget->currentRow());
    delete it;
}

void FriendTab::on_acceptPushButton_pressed()
{
    QListWidgetItem *it = ui->incomingListWidget->takeItem(ui->incomingListWidget->currentRow());
    ui->friendListWidget->addItem(it);
    delete it;
}

void FriendTab::on_denyPushButton_pressed()
{
    QListWidgetItem *it = ui->incomingListWidget->takeItem(ui->incomingListWidget->currentRow());
    delete it;
}



void FriendTab::on_inputLineEdit_returnPressed()
{
    if(ui->inputLineEdit->text() != "" && ui->inputLineEdit->text() != "Guest" ){
        ui->outgoingListWidget->addItem(ui->inputLineEdit->text());
        ui->inputLineEdit->clear();
    }else{
        Message* m = new Message();
        m->set_text("Please input at least something(not Guest) and not just empty space..");
        m->set_title("Oh No: Empty Field or Guest Detected");
        m->popup();
        ui->addPushButton->setDown(false);
    }
}

void FriendTab::on_returnPushButton_pressed()
{
    exit(0);
}
