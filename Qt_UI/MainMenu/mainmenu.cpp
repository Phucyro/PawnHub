#include "mainmenu.h"
#include "ui_mainmenu.h"

#include <QDesktopServices>
#include <QUrl>

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_play_button_clicked()
{

}

void MainMenu::on_stats_button_clicked()
{

}

void MainMenu::on_friends_button_clicked()
{

}

void MainMenu::on_chat_button_clicked()
{

}

void MainMenu::on_rules_button_clicked()
{
    QUrl url("https://en.wikipedia.org/wiki/Chess");
    QDesktopServices::openUrl(url);
}
