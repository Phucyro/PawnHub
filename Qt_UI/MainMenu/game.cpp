#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
}

Game::~Game()
{
    delete ui;
}

void Game::on_sendPushButton_pressed()
{
    ui->chatText->appendPlainText(ui->sendingTextField->text());
    ui->sendingTextField->clear();
}

void Game::on_sendingTextField_returnPressed()
{
    ui->chatText->appendPlainText(ui->sendingTextField->text());
    ui->sendingTextField->clear();
}

void Game::on_surrendButton_pressed()
{
    close();
}
