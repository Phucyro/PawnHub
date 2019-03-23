#include "gameWithoutChatWithAlice.h"
#include "ui_gameWithoutChatWithAlice.h"

GameWithoutChatWithAlice::GameWithoutChatWithAlice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWithoutChatWithAlice)
{
    ui->setupUi(this);
}

GameWithoutChatWithAlice::~GameWithoutChatWithAlice()
{
    delete ui;
}

void GameWithoutChatWithAlice::on_surrendButton_pressed()
{
    exit(0);
}
