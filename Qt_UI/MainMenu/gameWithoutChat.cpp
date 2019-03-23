#include "gameWithoutChat.h"
#include "ui_gameWithoutChat.h"

GameWithoutChat::GameWithoutChat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWithoutChat)
{
    ui->setupUi(this);
}

GameWithoutChat::~GameWithoutChat()
{
    delete ui;
}

void GameWithoutChat::on_surrendButton_pressed()
{
    exit(0);
}
