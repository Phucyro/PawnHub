#include "gameWithoutChatWithAlice.h"
#include "ui_gameWithoutChatWithAlice.h"

#include "message.h"

#include "../Modified_Files/ClientGameControl.hpp"

#include <QThread>
#include <QCloseEvent>

#include <iostream>
#include <cstdlib>

GameWithoutChatWithAlice::GameWithoutChatWithAlice(QWidget *parent, Client* client_) :
    QDialog(parent),
    ui(new Ui::GameWithoutChatWithAlice),
    client(client_),
    control(nullptr),
    timer(new QTimer),
    remainingTime(new QTime(0, 0)),
    done(QTime(0, 0)),
    move("")
{
    ui->setupUi(this);
    connect(ui->board, static_cast<void(QButtonGroup::*)(QAbstractButton *)>(&QButtonGroup::buttonPressed), this, &GameWithoutChatWithAlice::boardButton_pressed);
    connect(ui->board_2, static_cast<void(QButtonGroup::*)(QAbstractButton *)>(&QButtonGroup::buttonPressed), this, &GameWithoutChatWithAlice::boardButton_pressed);

    timer->setTimerType(Qt::PreciseTimer);
    connect(timer, &QTimer::timeout, this, &GameWithoutChatWithAlice::update_time);
}

GameWithoutChatWithAlice::~GameWithoutChatWithAlice()
{
    if (timer != nullptr) timer->deleteLater();
    if (remainingTime != nullptr) delete remainingTime;
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

    this->exec();
}

void GameWithoutChatWithAlice::clear_board(bool is_second_board)
{
    QIcon empty;
    if (is_second_board)
    {
        foreach (QAbstractButton* button, ui->board_2->buttons())
        {
            button->setIcon(empty);
            button->setToolTip("");
        }
    }
    else
    {
        foreach (QAbstractButton* button, ui->board->buttons())
        {
            button->setIcon(empty);
            button->setToolTip("");
        }
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
    if (time.toInt() < 0)
    {
        ui->chgTimeLabel->setText("--:--:-");
    }
    else
    {
        *remainingTime = remainingTime->addMSecs(time.toInt());
        display_time();
    }
}

void GameWithoutChatWithAlice::set_piece(QIcon pieceIcon, QString piecePosition, QString pieceName) {
    findChild<QPushButton*>(piecePosition)->setIcon(pieceIcon);
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
      control->setRealTime();
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
      control->setGameOngoing(false);
      closeEvent(new QCloseEvent);
    }
    ui->chgUpdateLabel->setText(message);
    changeAds();
}

void GameWithoutChatWithAlice::get_move(QString)
{
    ui->chgUpdateLabel->setText("Your turn: please choose your move.");
    ui->moveConfirmButton->setEnabled(true);
    // run timer until move confirmed - ie receiveGoodMove signal emitted from ClientGameControl
    timer->start(100);
}

void GameWithoutChatWithAlice::get_promotion(QString)
{
    QString promotion;
    Message promotionEnquiry;
    promotionEnquiry.promotion_choice();
    promotionEnquiry.popup();
    connect(&promotionEnquiry, &Message::promotion_chosen, this, &GameWithoutChatWithAlice::promotion_declared);
}

void GameWithoutChatWithAlice::promotion_declared(QString promotion)
{
    promotion.resize(1);
    control->sendPromotion(promotion.toLower());
}

void GameWithoutChatWithAlice::pause_timer()
{
    timer->stop();
    display_time();
}


void GameWithoutChatWithAlice::display_time()
{
    ui->chgTimeLabel->setText(remainingTime->toString("mm:ss:z"));
}

void GameWithoutChatWithAlice::update_time()
{
    reduce_timer();
}

void GameWithoutChatWithAlice::reduce_timer(int time)
{
    *remainingTime = remainingTime->addMSecs(-time);
    display_time();
    if (*remainingTime == done)
    {
        timer->stop();
        control->sendMove("/tim");
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
    }

    ui->chgMoveLabel->setText(move);
    changeAds();

}

void GameWithoutChatWithAlice::on_surrendButton_pressed()
{
    control->sendMove("/end");
    show_update("giveup");
    ui->surrendButton->setEnabled(false);
}

void GameWithoutChatWithAlice::on_moveConfirmButton_clicked()
{
    if (move.size() == 4)
    {
        ui->chgUpdateLabel->setText("Move sent!");
        control->sendMove(move);
        move.clear();
        ui->chgMoveLabel->setText(move);
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

void GameWithoutChatWithAlice::on_premoveClearButton_clicked()
{
    control->sendMove("/del");
    ui->chgUpdateLabel->setText("Premoves cleared.");
}

void GameWithoutChatWithAlice::closeEvent(QCloseEvent* event)
{
    if (!control->isGameOngoing())
    {
        event->accept();
    }
    else
    {
        on_surrendButton_pressed();
    }
}

void GameWithoutChatWithAlice::changeAds(){
    int random = rand() % 4 + 1 ;

    QPixmap mypix;
    switch (random) {
        case 1:
        {
            mypix = QPixmap (":/jacopo.png");
            break;
        }
        case 2:
        {
            mypix = QPixmap (":/catmeme.jpg");
            break;
        }
        case 3:
        {
        mypix = QPixmap (":/francois.png");
            break;
        }
        case 4:
        {
        mypix = QPixmap (":/keno2.png");
            break;
        }
    }
    ui->imageLabel->setPixmap(mypix);

}

