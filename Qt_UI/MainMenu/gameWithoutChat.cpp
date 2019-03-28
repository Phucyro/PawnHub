#include "gameWithoutChat.h"
#include "ui_gameWithoutChat.h"
#include "message.h"

#include "../Modified_Files/ClientGameControl.hpp"

#include <iostream>

GameWithoutChat::GameWithoutChat(QWidget *parent, Client* client_) :
    QDialog(parent),
    ui(new Ui::GameWithoutChat),
    client(client_),
    move("")
{
    ui->setupUi(this);
}

GameWithoutChat::~GameWithoutChat()
{
    delete ui;
}

void GameWithoutChat::start()
{
    QThread* thread = new QThread;
    ClientGameControl* control  = new ClientGameControl(client, this);
    control->moveToThread(thread);
    connect(thread, &QThread::started, control, &ClientGameControl::startParty);
    connect(control, &ClientGameControl::finished, thread, &QThread::quit);
    connect(thread, &QThread::finished, control, &ClientGameControl::deleteLater);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);
    thread->start();
//    // get start
//    control.handleMessage();
//    // get mode
//    control.handleMessage();
//    // get colour
//    control.handleMessage();

    this->exec();

//    while (gameOngoing)
//    {
//        run_turn(control);
//    }
}

//void GameWithoutChat::run_turn(ClientGameControl& control)
//{
//    // board
//    control.handleMessage();
//    // turn
//    control.handleMessage();
//    // askmove
//    control.handleMessage();
//    show_update();
//}

//void GameWithoutChat::set_gameOngoing(bool value)
//{
//    gameOngoing = value;
//}

void GameWithoutChat::clear_board()
{
    QIcon empty;
    foreach (QAbstractButton* button, ui->board->buttons())
    {
        button->setIcon(empty);
    }
}

void GameWithoutChat::set_mode(QString mode)
{
    ui->chgModeLabel->setText(mode);
}

void GameWithoutChat::set_colour(QString colour)
{
    ui->chgColourLabel->setText(colour);
}

void GameWithoutChat::set_turn(QString turn)
{
    ui->chgTurnLabel->setText(turn);
}

void GameWithoutChat::set_time(QString time)
{
    if (time < 0) ui->chgTimeLabel->setText("--:--");
    else
    {
        timer.reset(atoi(time.toStdString().c_str()));
        ui->chgTimeLabel->setText(QString::fromStdString(timer));
    }
}

void GameWithoutChat::set_piece(QIcon pieceIcon, QString piecePosition, QString pieceName) {
    findChild<QPushButton*>(piecePosition)->setIcon(pieceIcon);
//    findChild<QPushButton*>(piecePosition)->setEnabled(true);
    findChild<QPushButton*>(piecePosition)->setToolTip(pieceName);

//    probably to be erased
//    coordinateConversionMap->value(piecePosition)->setIcon(pieceIcon);
//    coordinateConversionMap->value(piecePosition)->setEnabled(true);
//    coordinateConversionMap->value(piecePosition)->setToolTip(pieceName);
}

void GameWithoutChat::show_update(QString message)
{
    if (message == "start") {
      message = "Game has started.";
     }
    else if (message == "alice") {
////        not sure yet
    }
    else if (message == "realtime") {
      emit is_realtime();
    }
    else if (message == "check") {
      message = "Check.\nProtect your king!";
    }
    else {
      if (message == "stalemate") {
        message = "Stalemate.";
      }
      else if (message == "surrend") {
        message = "You win!\nYour oppenent gave up :(";
      }
      else if (message == "timeout") {
          message = "Time's up!\nYou lost.";
      }
      else if (message == "giveup") {
          message = "You gave up.";
      }
      else if (message == "white"){
        message = "Checkmate\nWhite player won!";
      }
      else {
        message = "Checkmate\nBlack player won!";
      }
      emit game_ongoing_changed(false);
    }
    ui->chgUpdateLabel->setText(message);
}

void GameWithoutChat::get_move(QString)
{
    ui->chgUpdateLabel->setText("Your turn: please choose your move.");
    ui->moveConfirmButton->setEnabled(true);
    // run timer until move sent
}

void GameWithoutChat::get_promotion(QString)
{
    QString promotion;
    Message promotionEnquiry;
    promotionEnquiry.promotion_choice();
    promotionEnquiry.popup();
    promotion = promotionEnquiry.get_choice();
    emit promotion_declared(promotion);
}

void GameWithoutChat::pause_timer()
{
    timer.pause();
    ui->chgTimeLabel->setText(QString::fromStdString(timer));
}

void GameWithoutChat::reduce_timer(int time)
{
    timer.remove(time);
    ui->chgTimeLabel->setText(QString::fromStdString(timer));
    if (!timer.get_remaining_time()){
        emit move_declared("/tim");
        show_update("timeout");
    }
}

void GameWithoutChat::on_boardButton_pushed(QPushButton* origin)
{
    if (move != "")
    {
        if (move.endsWith(origin->objectName()))
        {
            origin->setEnabled(true);
            move.chop(2);
        }
        else if (move.size() == 2)
        {
            move += origin->objectName();
        }
        else
        {
            ui->chgUpdateLabel->setText("Please send current move before adding another.");
        }
    }
    else
    {
        move += origin->objectName();
        on_initialPosition_chosen(origin);
    }

    ui->chgMoveLabel->setText(move);
}

void GameWithoutChat::on_initialPosition_chosen(QPushButton*)
{
    // get potential moves for piece here and enable relevant buttons
}

void GameWithoutChat::on_surrendButton_pressed()
{
    emit move_declared("/end");
    show_update("giveup");
    this->close();
}

void GameWithoutChat::on_moveConfirmButton_clicked()
{
    if (move.size() == 4)
    {
        ui->chgUpdateLabel->setText("Move sent!");
        move.clear();
        ui->chgMoveLabel->setText(move);
        emit move_declared(move);
    }
    else
    {
        ui->chgUpdateLabel->setText("Please choose initial and final positions of your piece by clicking on the board.");
    }
}


void GameWithoutChat::on_moveClearButton_clicked()
{
    move.clear();
    ui->chgMoveLabel->setText(move);
}

void GameWithoutChat::on_A1_pressed()
{
    on_boardButton_pushed(ui->A1);
}

void GameWithoutChat::on_A2_pressed()
{
    on_boardButton_pushed(ui->A2);
}

void GameWithoutChat::on_A3_pressed()
{
    on_boardButton_pushed(ui->A3);
}

void GameWithoutChat::on_A4_pressed()
{
    on_boardButton_pushed(ui->A4);
}

void GameWithoutChat::on_A5_pressed()
{
    on_boardButton_pushed(ui->A5);
}

void GameWithoutChat::on_A6_pressed()
{
    on_boardButton_pushed(ui->A6);
}

void GameWithoutChat::on_A7_pressed()
{
    on_boardButton_pushed(ui->A7);
}

void GameWithoutChat::on_A8_pressed()
{
    on_boardButton_pushed(ui->A8);
}

void GameWithoutChat::on_B1_pressed()
{
    on_boardButton_pushed(ui->B1);
}

void GameWithoutChat::on_B2_pressed()
{
    on_boardButton_pushed(ui->B2);
}

void GameWithoutChat::on_B3_pressed()
{
    on_boardButton_pushed(ui->B3);
}

void GameWithoutChat::on_B4_pressed()
{
    on_boardButton_pushed(ui->B4);
}

void GameWithoutChat::on_B5_pressed()
{
    on_boardButton_pushed(ui->B5);
}

void GameWithoutChat::on_B6_pressed()
{
    on_boardButton_pushed(ui->B6);
}

void GameWithoutChat::on_B7_pressed()
{
    on_boardButton_pushed(ui->B7);
}

void GameWithoutChat::on_B8_pressed()
{
    on_boardButton_pushed(ui->B8);
}

void GameWithoutChat::on_C1_pressed()
{
    on_boardButton_pushed(ui->C1);
}

void GameWithoutChat::on_C2_pressed()
{
    on_boardButton_pushed(ui->C2);
}

void GameWithoutChat::on_C3_pressed()
{
    on_boardButton_pushed(ui->C3);
}

void GameWithoutChat::on_C4_pressed()
{
    on_boardButton_pushed(ui->C4);
}

void GameWithoutChat::on_C5_pressed()
{
    on_boardButton_pushed(ui->C5);
}

void GameWithoutChat::on_C6_pressed()
{
    on_boardButton_pushed(ui->C6);
}

void GameWithoutChat::on_C7_pressed()
{
    on_boardButton_pushed(ui->C7);
}

void GameWithoutChat::on_C8_pressed()
{
    on_boardButton_pushed(ui->C8);
}

void GameWithoutChat::on_D1_pressed()
{
    on_boardButton_pushed(ui->D1);
}

void GameWithoutChat::on_D2_pressed()
{
    on_boardButton_pushed(ui->D2);
}

void GameWithoutChat::on_D3_pressed()
{
    on_boardButton_pushed(ui->D3);
}

void GameWithoutChat::on_D4_pressed()
{
    on_boardButton_pushed(ui->D4);
}

void GameWithoutChat::on_D5_pressed()
{
    on_boardButton_pushed(ui->D5);
}

void GameWithoutChat::on_D6_pressed()
{
    on_boardButton_pushed(ui->D6);
}

void GameWithoutChat::on_D7_pressed()
{
    on_boardButton_pushed(ui->D7);
}

void GameWithoutChat::on_D8_pressed()
{
    on_boardButton_pushed(ui->D8);
}

void GameWithoutChat::on_E1_pressed()
{
    on_boardButton_pushed(ui->E1);
}

void GameWithoutChat::on_E2_pressed()
{
    on_boardButton_pushed(ui->E2);
}

void GameWithoutChat::on_E3_pressed()
{
    on_boardButton_pushed(ui->E3);
}

void GameWithoutChat::on_E4_pressed()
{
    on_boardButton_pushed(ui->E4);
}

void GameWithoutChat::on_E5_pressed()
{
    on_boardButton_pushed(ui->E5);
}

void GameWithoutChat::on_E6_pressed()
{
    on_boardButton_pushed(ui->E6);
}

void GameWithoutChat::on_E7_pressed()
{
    on_boardButton_pushed(ui->E7);
}

void GameWithoutChat::on_E8_pressed()
{
    on_boardButton_pushed(ui->E8);
}

void GameWithoutChat::on_F1_pressed()
{
    on_boardButton_pushed(ui->F1);
}

void GameWithoutChat::on_F2_pressed()
{
    on_boardButton_pushed(ui->F2);
}

void GameWithoutChat::on_F3_pressed()
{
    on_boardButton_pushed(ui->F3);
}

void GameWithoutChat::on_F4_pressed()
{
    on_boardButton_pushed(ui->F4);
}

void GameWithoutChat::on_F5_pressed()
{
    on_boardButton_pushed(ui->F5);
}

void GameWithoutChat::on_F6_pressed()
{
    on_boardButton_pushed(ui->F6);
}

void GameWithoutChat::on_F7_pressed()
{
    on_boardButton_pushed(ui->F7);
}

void GameWithoutChat::on_F8_pressed()
{
    on_boardButton_pushed(ui->F8);
}

void GameWithoutChat::on_G1_pressed()
{
    on_boardButton_pushed(ui->G1);
}

void GameWithoutChat::on_G2_pressed()
{
    on_boardButton_pushed(ui->G2);
}

void GameWithoutChat::on_G3_pressed()
{
    on_boardButton_pushed(ui->G3);
}

void GameWithoutChat::on_G4_pressed()
{
    on_boardButton_pushed(ui->G4);
}

void GameWithoutChat::on_G5_pressed()
{
    on_boardButton_pushed(ui->G5);
}

void GameWithoutChat::on_G6_pressed()
{
    on_boardButton_pushed(ui->G6);
}

void GameWithoutChat::on_G7_pressed()
{
    on_boardButton_pushed(ui->G7);
}

void GameWithoutChat::on_G8_pressed()
{
    on_boardButton_pushed(ui->G8);
}

void GameWithoutChat::on_H1_pressed()
{
    on_boardButton_pushed(ui->H1);
}

void GameWithoutChat::on_H2_pressed()
{
    on_boardButton_pushed(ui->H2);
}

void GameWithoutChat::on_H3_pressed()
{
    on_boardButton_pushed(ui->H3);
}

void GameWithoutChat::on_H4_pressed()
{
    on_boardButton_pushed(ui->H4);
}

void GameWithoutChat::on_H5_pressed()
{
    on_boardButton_pushed(ui->H5);
}

void GameWithoutChat::on_H6_pressed()
{
    on_boardButton_pushed(ui->H6);
}

void GameWithoutChat::on_H7_pressed()
{
    on_boardButton_pushed(ui->H7);
}

void GameWithoutChat::on_H8_pressed()
{
    on_boardButton_pushed(ui->H8);
}
