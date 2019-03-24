#include "gameWithoutChat.h"
#include "ui_gameWithoutChat.h"

GameWithoutChat::GameWithoutChat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWithoutChat)
{
    ui->setupUi(this);
    QMap<QString, QPushButton*> map =
    {
        {"A1", ui->a1PushButton},
        {"A2", ui->a2PushButton},
        {"A3", ui->a3PushButton},
        {"A4", ui->a4PushButton},
        {"A5", ui->a5PushButton},
        {"A6", ui->a6PushButton},
        {"A7", ui->a7PushButton},
        {"A8", ui->a8PushButton},

        {"B1", ui->b1PushButton},
        {"B2", ui->b2PushButton},
        {"B3", ui->b3PushButton},
        {"B4", ui->b4PushButton},
        {"B5", ui->b5PushButton},
        {"B6", ui->b6PushButton},
        {"B7", ui->b7PushButton},
        {"B8", ui->b8PushButton},

        {"C1", ui->c1PushButton},
        {"C2", ui->c2PushButton},
        {"C3", ui->c3PushButton},
        {"C4", ui->c4PushButton},
        {"C5", ui->c5PushButton},
        {"C6", ui->c6PushButton},
        {"C7", ui->c7PushButton},
        {"C8", ui->c8PushButton},

        {"D1", ui->d1PushButton},
        {"D2", ui->d2PushButton},
        {"D3", ui->d3PushButton},
        {"D4", ui->d4PushButton},
        {"D5", ui->d5PushButton},
        {"D6", ui->d6PushButton},
        {"D7", ui->d7PushButton},
        {"D8", ui->d8PushButton},

        {"E1", ui->e1PushButton},
        {"E2", ui->e2PushButton},
        {"E3", ui->e3PushButton},
        {"E4", ui->e4PushButton},
        {"E5", ui->e5PushButton},
        {"E6", ui->e6PushButton},
        {"E7", ui->e7PushButton},
        {"E8", ui->e8PushButton},

        {"F1", ui->f1PushButton},
        {"F2", ui->f2PushButton},
        {"F3", ui->f3PushButton},
        {"F4", ui->f4PushButton},
        {"F5", ui->f5PushButton},
        {"F6", ui->f6PushButton},
        {"F7", ui->f7PushButton},
        {"F8", ui->f8PushButton},

        {"G1", ui->g1PushButton},
        {"G2", ui->g2PushButton},
        {"G3", ui->g3PushButton},
        {"G4", ui->g4PushButton},
        {"G5", ui->g5PushButton},
        {"G6", ui->g6PushButton},
        {"G7", ui->g7PushButton},
        {"G8", ui->g8PushButton},

        {"H1", ui->h1PushButton},
        {"H2", ui->h2PushButton},
        {"H3", ui->h3PushButton},
        {"H4", ui->h4PushButton},
        {"H5", ui->h5PushButton},
        {"H6", ui->h6PushButton},
        {"H7", ui->h7PushButton},
        {"H8", ui->h8PushButton},
    };
    coordinateConversionMap = &map;
}

GameWithoutChat::~GameWithoutChat()
{
    coordinateConversionMap = nullptr;
    delete ui;
}

void GameWithoutChat::setPiece(QIcon pieceIcon, QString piecePosition, QString pieceName) {
    coordinateConversionMap->value(piecePosition)->setIcon(pieceIcon);
    coordinateConversionMap->value(piecePosition)->setEnabled(true);
    coordinateConversionMap->value(piecePosition)->setToolTip(pieceName);
}

void GameWithoutChat::on_button_pushed(QPushButton* origin)
{

}

void GameWithoutChat::on_initialPosition_chosen(QPushButton* origin)
{
    QString pieceName = origin->toolTip();

    move = origin->objectName();
    // get potential moves for piece here and enable relevant buttons

}

void GameWithoutChat::on_surrendButton_pressed()
{
    // send surrend
    this->close();
}

void GameWithoutChat::on_a8PushButton_pressed()
{

}
void GameWithoutChat::on_a7PushButton_pressed()
{

}
void GameWithoutChat::on_a6PushButton_pressed()
{

}
void GameWithoutChat::on_a5PushButton_pressed()
{

}
void GameWithoutChat::on_a4PushButton_pressed()
{

}
void GameWithoutChat::on_a3PushButton_pressed()
{

}
void GameWithoutChat::on_a2PushButton_pressed()
{

}
void GameWithoutChat::on_a1PushButton_pressed()
{

}
void GameWithoutChat::on_b8PushButton_pressed()
{

}
void GameWithoutChat::on_b7PushButton_pressed()
{

}
void GameWithoutChat::on_b6PushButton_pressed()
{

}
void GameWithoutChat::on_b5PushButton_pressed()
{

}
void GameWithoutChat::on_b4PushButton_pressed()
{

}
void GameWithoutChat::on_b3PushButton_pressed()
{

}
void GameWithoutChat::on_b2PushButton_pressed()
{

}
void GameWithoutChat::on_b1PushButton_pressed()
{

}
void GameWithoutChat::on_c8PushButton_pressed()
{

}
void GameWithoutChat::on_c7PushButton_pressed()
{

}
void GameWithoutChat::on_c6PushButton_pressed()
{

}
void GameWithoutChat::on_c5PushButton_pressed()
{

}
void GameWithoutChat::on_c4PushButton_pressed()
{

}
void GameWithoutChat::on_c3PushButton_pressed()
{

}
void GameWithoutChat::on_c2PushButton_pressed()
{

}
void GameWithoutChat::on_c1PushButton_pressed()
{

}
void GameWithoutChat::on_d8PushButton_pressed()
{

}
void GameWithoutChat::on_d7PushButton_pressed()
{

}
void GameWithoutChat::on_d6PushButton_pressed()
{

}
void GameWithoutChat::on_d5PushButton_pressed()
{

}
void GameWithoutChat::on_d4PushButton_pressed()
{

}
void GameWithoutChat::on_d3PushButton_pressed()
{

}
void GameWithoutChat::on_d2PushButton_pressed()
{

}
void GameWithoutChat::on_d1PushButton_pressed()
{

}
void GameWithoutChat::on_e8PushButton_pressed()
{

}
void GameWithoutChat::on_e7PushButton_pressed()
{

}
void GameWithoutChat::on_e6PushButton_pressed()
{

}
void GameWithoutChat::on_e5PushButton_pressed()
{

}
void GameWithoutChat::on_e4PushButton_pressed()
{

}
void GameWithoutChat::on_e3PushButton_pressed()
{

}
void GameWithoutChat::on_e2PushButton_pressed()
{

}
void GameWithoutChat::on_e1PushButton_pressed()
{

}
void GameWithoutChat::on_f8PushButton_pressed()
{

}
void GameWithoutChat::on_f7PushButton_pressed()
{

}
void GameWithoutChat::on_f6PushButton_pressed()
{

}
void GameWithoutChat::on_f5PushButton_pressed()
{

}
void GameWithoutChat::on_f4PushButton_pressed()
{

}
void GameWithoutChat::on_f3PushButton_pressed()
{

}
void GameWithoutChat::on_f2PushButton_pressed()
{

}
void GameWithoutChat::on_f1PushButton_pressed()
{

}
void GameWithoutChat::on_g8PushButton_pressed()
{

}
void GameWithoutChat::on_g7PushButton_pressed()
{

}
void GameWithoutChat::on_g6PushButton_pressed()
{

}
void GameWithoutChat::on_g5PushButton_pressed()
{

}
void GameWithoutChat::on_g4PushButton_pressed()
{

}
void GameWithoutChat::on_g3PushButton_pressed()
{

}
void GameWithoutChat::on_g2PushButton_pressed()
{

}
void GameWithoutChat::on_g1PushButton_pressed()
{

}
void GameWithoutChat::on_h8PushButton_pressed()
{

}
void GameWithoutChat::on_h7PushButton_pressed()
{

}
void GameWithoutChat::on_h6PushButton_pressed()
{

}
void GameWithoutChat::on_h5PushButton_pressed()
{

}
void GameWithoutChat::on_h4PushButton_pressed()
{

}
void GameWithoutChat::on_h3PushButton_pressed()
{

}
void GameWithoutChat::on_h2PushButton_pressed()
{

}
void GameWithoutChat::on_h1PushButton_pressed()
{

}
