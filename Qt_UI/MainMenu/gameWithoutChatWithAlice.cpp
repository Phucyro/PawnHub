#include "gameWithoutChatWithAlice.h"
#include "ui_gameWithoutChatWithAlice.h"

#include "message.h"

#include "../Modified_Files/ClientGameControl.hpp"

#include <QThread>

#include <iostream>

GameWithoutChatWithAlice::GameWithoutChatWithAlice(QWidget *parent, Client* client_) :
    QDialog(parent),
    ui(new Ui::GameWithoutChatWithAlice),
    client(client_),
    control(nullptr),
    timer(),
    move("")
{
    ui->setupUi(this);
    connect(ui->board, static_cast<void(QButtonGroup::*)(QAbstractButton *)>(&QButtonGroup::buttonPressed), this, &GameWithoutChatWithAlice::boardButton_pressed);
    connect(ui->board_2, static_cast<void(QButtonGroup::*)(QAbstractButton *)>(&QButtonGroup::buttonPressed), this, &GameWithoutChatWithAlice::boardButton_pressed);
}

GameWithoutChatWithAlice::~GameWithoutChatWithAlice()
{
    if (control != nullptr) control->deleteLater();
    delete ui;
}

void GameWithoutChatWithAlice::start()
{
    QThread* thread = new QThread;
    control  = new ClientGameControl(client, this);
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

//void GameWithoutChatWithAlice::run_turn(ClientGameControl& control)
//{
//    // board
//    control.handleMessage();
//    // turn
//    control.handleMessage();
//    // askmove
//    control.handleMessage();
//    show_update();
//}

//void GameWithoutChatWithAlice::set_gameOngoing(bool value)
//{
//    gameOngoing = value;
//}

void GameWithoutChatWithAlice::clear_board()
{
    QIcon empty;
    foreach (QAbstractButton* button, ui->board->buttons())
    {
        button->setIcon(empty);
        button->setToolTip("");
    }
    foreach (QAbstractButton* button, ui->board_2->buttons())
    {
        button->setIcon(empty);
        button->setToolTip("");
    }
}

void GameWithoutChatWithAlice::set_mode(QString mode)
{
    ui->chgModeLabel->setText(mode);
}

void GameWithoutChatWithAlice::set_colour(QString colour)
{
    ui->chgColourLabel->setText(colour);
}

void GameWithoutChatWithAlice::set_turn(QString turn)
{
    ui->chgTurnLabel->setText(turn);
}

void GameWithoutChatWithAlice::set_time(QString time)
{
    if (time < 0) ui->chgTimeLabel->setText("--:--");
    else
    {
        timer.reset(atoi(time.toStdString().c_str()));
        ui->chgTimeLabel->setText(QString::fromStdString(timer));
    }
}
void GameWithoutChatWithAlice::set_piece(QIcon pieceIcon, QString piecePosition, QString pieceName) {
    findChild<QPushButton*>(piecePosition)->setIcon(pieceIcon);
//    findChild<QPushButton*>(piecePosition)->setEnabled(true);
    findChild<QPushButton*>(piecePosition)->setToolTip(pieceName);
}

void GameWithoutChatWithAlice::show_update(QString message)
{
    if (message == "start") {
      message = "Game has started.";
     }
    else if (message == "alice") {
      message = "Game has started.";
    }
    else if (message == "realtime") {
      message = "Game has started.";
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

void GameWithoutChatWithAlice::get_move(QString)
{
    ui->chgUpdateLabel->setText("Your turn: please choose your move.");
    ui->moveConfirmButton->setEnabled(true);
    // run timer until move sent
}

void GameWithoutChatWithAlice::get_promotion(QString)
{
    QString promotion;
    Message promotionEnquiry;
    promotionEnquiry.promotion_choice();
    promotionEnquiry.popup();
    promotion = promotionEnquiry.get_choice();
    emit promotion_declared(promotion);
}

void GameWithoutChatWithAlice::pause_timer()
{
    timer.pause();
    ui->chgTimeLabel->setText(QString::fromStdString(timer));
}

void GameWithoutChatWithAlice::reduce_timer(int time)
{
    timer.remove(time);
    ui->chgTimeLabel->setText(QString::fromStdString(timer));
    if (!timer.get_remaining_time()){
        emit move_declared("/tim");
        show_update("timeout");
    }
}

void GameWithoutChatWithAlice::boardButton_pressed(QAbstractButton* origin)
{
    QString position = origin->objectName();
    if (position.endsWith("_2")) position.chop(2);
    if (move != "")
    {
        if (move.endsWith(position))
        {
            origin->setEnabled(true);
            move.chop(2);
        }
        else if (move.size() == 2)
        {
            move += position;
        }
        else
        {
            ui->chgUpdateLabel->setText("Please send current move before adding another.");
        }
    }
    else
    {
        move += position;
        on_initialPosition_chosen(origin);
    }

    ui->chgMoveLabel->setText(move);
}

void GameWithoutChatWithAlice::on_initialPosition_chosen(QAbstractButton*)
{
    // get potential moves for piece here and enable relevant buttons
}

void GameWithoutChatWithAlice::on_surrendButton_pressed()
{
    emit move_declared("/end");
    show_update("giveup");
    this->close();
}

void GameWithoutChatWithAlice::on_moveConfirmButton_clicked()
{
    if (move.size() == 4)
    {
        ui->chgUpdateLabel->setText("Move sent!");
        ui->chgMoveLabel->setText(move);
        control->sendMove(move);
        move.clear();
    }
    else
    {
        ui->chgUpdateLabel->setText("Please choose initial and final positions of your piece by clicking on the board.");
    }
}


void GameWithoutChatWithAlice::on_moveClearButton_clicked()
{
    move.clear();
    ui->chgMoveLabel->setText(move);
}
