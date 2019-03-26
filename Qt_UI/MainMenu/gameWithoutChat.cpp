#include "gameWithoutChat.h"
#include "ui_gameWithoutChat.h"

#include "../Modified_Files/ClientGameControl.hpp"

//#include <iostream>

GameWithoutChat::GameWithoutChat(QWidget *parent, Socket* socket_) :
    QDialog(parent),
    ui(new Ui::GameWithoutChat),
    socket(socket_),
    move("")
{
    ui->setupUi(this);
    QMap<QString, QPushButton*> map =
    {
        {"A1", ui->A1},
        {"A2", ui->A2},
        {"A3", ui->A3},
        {"A4", ui->A4},
        {"A5", ui->A5},
        {"A6", ui->A6},
        {"A7", ui->A7},
        {"A8", ui->A8},

        {"B1", ui->B1},
        {"B2", ui->B2},
        {"B3", ui->B3},
        {"B4", ui->B4},
        {"B5", ui->B5},
        {"B6", ui->B6},
        {"B7", ui->B7},
        {"B8", ui->B8},

        {"C1", ui->C1},
        {"C2", ui->C2},
        {"C3", ui->C3},
        {"C4", ui->C4},
        {"C5", ui->C5},
        {"C6", ui->C6},
        {"C7", ui->C7},
        {"C8", ui->C8},

        {"D1", ui->D1},
        {"D2", ui->D2},
        {"D3", ui->D3},
        {"D4", ui->D4},
        {"D5", ui->D5},
        {"D6", ui->D6},
        {"D7", ui->D7},
        {"D8", ui->D8},

        {"E1", ui->E1},
        {"E2", ui->E2},
        {"E3", ui->E3},
        {"E4", ui->E4},
        {"E5", ui->E5},
        {"E6", ui->E6},
        {"E7", ui->E7},
        {"E8", ui->E8},

        {"F1", ui->F1},
        {"F2", ui->F2},
        {"F3", ui->F3},
        {"F4", ui->F4},
        {"F5", ui->F5},
        {"F6", ui->F6},
        {"F7", ui->F7},
        {"F8", ui->F8},

        {"G1", ui->G1},
        {"G2", ui->G2},
        {"G3", ui->G3},
        {"G4", ui->G4},
        {"G5", ui->G5},
        {"G6", ui->G6},
        {"G7", ui->G7},
        {"G8", ui->G8},

        {"H1", ui->H1},
        {"H2", ui->H2},
        {"H3", ui->H3},
        {"H4", ui->H4},
        {"H5", ui->H5},
        {"H6", ui->H6},
        {"H7", ui->H7},
        {"H8", ui->H8},
    };
    coordinateConversionMap = &map;
}

GameWithoutChat::~GameWithoutChat()
{
    coordinateConversionMap = nullptr;
    delete ui;
}

void GameWithoutChat::start()
{
    ClientGameControl control(socket, this);
}

void GameWithoutChat::set_colour(QString colour)
{
    ui->chgColourLabel->setText(colour);
}

void GameWithoutChat::set_turn(QString turn)
{
    ui->chgTurnLabel->setText(turn);
}

void GameWithoutChat::set_piece(QIcon pieceIcon, QString piecePosition, QString pieceName) {
    coordinateConversionMap->value(piecePosition)->setIcon(pieceIcon);
    coordinateConversionMap->value(piecePosition)->setEnabled(true);
    coordinateConversionMap->value(piecePosition)->setToolTip(pieceName);
}

void GameWithoutChat::show_update(QString message)
{
    ui->chgUpdateLabel->setText(message);
}

QString GameWithoutChat::get_promotion()
{
    QString promotion;
//    Message
    return promotion;
}

void GameWithoutChat::on_button_pushed(QPushButton* origin)
{
    if (move != "")
    {
        if (origin->objectName() == move)
        {
            origin->setEnabled(true);
            move = "";
        }
        else
        {
            move += origin->objectName();
            on_initialPosition_chosen(origin);
        }
    }
    else
    {
        move += origin->objectName();
    }
}

void GameWithoutChat::on_initialPosition_chosen(QPushButton* origin)
{
    // get potential moves for piece here and enable relevant buttons
}

void GameWithoutChat::on_surrendButton_pressed()
{
    // send surrend
    this->close();
}

void GameWithoutChat::on_A1_pressed()
{
    on_button_pushed(ui->A1);
}

void GameWithoutChat::on_A2_pressed()
{
    on_button_pushed(ui->A2);
}

void GameWithoutChat::on_A3_pressed()
{
    on_button_pushed(ui->A3);
}

void GameWithoutChat::on_A4_pressed()
{
    on_button_pushed(ui->A4);
}

void GameWithoutChat::on_A5_pressed()
{
    on_button_pushed(ui->A5);
}

void GameWithoutChat::on_A6_pressed()
{
    on_button_pushed(ui->A6);
}

void GameWithoutChat::on_A7_pressed()
{
    on_button_pushed(ui->A7);
}

void GameWithoutChat::on_A8_pressed()
{
    on_button_pushed(ui->A8);
}

void GameWithoutChat::on_B1_pressed()
{
    on_button_pushed(ui->B1);
}

void GameWithoutChat::on_B2_pressed()
{
    on_button_pushed(ui->B2);
}

void GameWithoutChat::on_B3_pressed()
{
    on_button_pushed(ui->B3);
}

void GameWithoutChat::on_B4_pressed()
{
    on_button_pushed(ui->B4);
}

void GameWithoutChat::on_B5_pressed()
{
    on_button_pushed(ui->B5);
}

void GameWithoutChat::on_B6_pressed()
{
    on_button_pushed(ui->B6);
}

void GameWithoutChat::on_B7_pressed()
{
    on_button_pushed(ui->B7);
}

void GameWithoutChat::on_B8_pressed()
{
    on_button_pushed(ui->B8);
}

void GameWithoutChat::on_C1_pressed()
{
    on_button_pushed(ui->C1);
}

void GameWithoutChat::on_C2_pressed()
{
    on_button_pushed(ui->C2);
}

void GameWithoutChat::on_C3_pressed()
{
    on_button_pushed(ui->C3);
}

void GameWithoutChat::on_C4_pressed()
{
    on_button_pushed(ui->C4);
}

void GameWithoutChat::on_C5_pressed()
{
    on_button_pushed(ui->C5);
}

void GameWithoutChat::on_C6_pressed()
{
    on_button_pushed(ui->C6);
}

void GameWithoutChat::on_C7_pressed()
{
    on_button_pushed(ui->C7);
}

void GameWithoutChat::on_C8_pressed()
{
    on_button_pushed(ui->C8);
}

void GameWithoutChat::on_D1_pressed()
{
    on_button_pushed(ui->D1);
}

void GameWithoutChat::on_D2_pressed()
{
    on_button_pushed(ui->D2);
}

void GameWithoutChat::on_D3_pressed()
{
    on_button_pushed(ui->D3);
}

void GameWithoutChat::on_D4_pressed()
{
    on_button_pushed(ui->D4);
}

void GameWithoutChat::on_D5_pressed()
{
    on_button_pushed(ui->D5);
}

void GameWithoutChat::on_D6_pressed()
{
    on_button_pushed(ui->D6);
}

void GameWithoutChat::on_D7_pressed()
{
    on_button_pushed(ui->D7);
}

void GameWithoutChat::on_D8_pressed()
{
    on_button_pushed(ui->D8);
}

void GameWithoutChat::on_E1_pressed()
{
    on_button_pushed(ui->E1);
}

void GameWithoutChat::on_E2_pressed()
{
    on_button_pushed(ui->E2);
}

void GameWithoutChat::on_E3_pressed()
{
    on_button_pushed(ui->E3);
}

void GameWithoutChat::on_E4_pressed()
{
    on_button_pushed(ui->E4);
}

void GameWithoutChat::on_E5_pressed()
{
    on_button_pushed(ui->E5);
}

void GameWithoutChat::on_E6_pressed()
{
    on_button_pushed(ui->E6);
}

void GameWithoutChat::on_E7_pressed()
{
    on_button_pushed(ui->E7);
}

void GameWithoutChat::on_E8_pressed()
{
    on_button_pushed(ui->E8);
}

void GameWithoutChat::on_F1_pressed()
{
    on_button_pushed(ui->F1);
}

void GameWithoutChat::on_F2_pressed()
{
    on_button_pushed(ui->F2);
}

void GameWithoutChat::on_F3_pressed()
{
    on_button_pushed(ui->F3);
}

void GameWithoutChat::on_F4_pressed()
{
    on_button_pushed(ui->F4);
}

void GameWithoutChat::on_F5_pressed()
{
    on_button_pushed(ui->F5);
}

void GameWithoutChat::on_F6_pressed()
{
    on_button_pushed(ui->F6);
}

void GameWithoutChat::on_F7_pressed()
{
    on_button_pushed(ui->F7);
}

void GameWithoutChat::on_F8_pressed()
{
    on_button_pushed(ui->F8);
}

void GameWithoutChat::on_G1_pressed()
{
    on_button_pushed(ui->G1);
}

void GameWithoutChat::on_G2_pressed()
{
    on_button_pushed(ui->G2);
}

void GameWithoutChat::on_G3_pressed()
{
    on_button_pushed(ui->G3);
}

void GameWithoutChat::on_G4_pressed()
{
    on_button_pushed(ui->G4);
}

void GameWithoutChat::on_G5_pressed()
{
    on_button_pushed(ui->G5);
}

void GameWithoutChat::on_G6_pressed()
{
    on_button_pushed(ui->G6);
}

void GameWithoutChat::on_G7_pressed()
{
    on_button_pushed(ui->G7);
}

void GameWithoutChat::on_G8_pressed()
{
    on_button_pushed(ui->G8);
}

void GameWithoutChat::on_H1_pressed()
{
    on_button_pushed(ui->H1);
}

void GameWithoutChat::on_H2_pressed()
{
    on_button_pushed(ui->H2);
}

void GameWithoutChat::on_H3_pressed()
{
    on_button_pushed(ui->H3);
}

void GameWithoutChat::on_H4_pressed()
{
    on_button_pushed(ui->H4);
}

void GameWithoutChat::on_H5_pressed()
{
    on_button_pushed(ui->H5);
}

void GameWithoutChat::on_H6_pressed()
{
    on_button_pushed(ui->H6);
}

void GameWithoutChat::on_H7_pressed()
{
    on_button_pushed(ui->H7);
}

void GameWithoutChat::on_H8_pressed()
{
    on_button_pushed(ui->H8);
}
