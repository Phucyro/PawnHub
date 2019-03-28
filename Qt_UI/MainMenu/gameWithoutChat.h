#ifndef GAMEWITHOUTCHAT_H
#define GAMEWITHOUTCHAT_H

#include <QDialog>
#include <QIcon>
#include <QThread>

#include "../../Communication/Timer.hpp"

class Client;
class ClientGameControl;

namespace Ui {
class GameWithoutChat;
}

class GameWithoutChat : public QDialog
{
    Q_OBJECT

public:
    explicit GameWithoutChat(QWidget *parent = nullptr, Client *client_=nullptr);
    ~GameWithoutChat();

    void start();
//    void run_turn(ClientGameControl&);

//    void set_gameOngoing(bool);

public slots:
    void set_mode(QString);
    void set_colour(QString);
    void set_turn(QString);
    void set_time(QString);
    void set_piece(QIcon, QString, QString);
    void show_update(QString="");

    void clear_board();
    void get_move(QString);
    void get_promotion(QString);

    void pause_timer();
    void reduce_timer(int);

signals:
    void move_declared(QString);
    void promotion_declared(QString);
    void game_ongoing_changed(bool);
    void is_realtime();

private slots:
    void on_surrendButton_pressed();

    void on_A1_pressed();
    void on_A2_pressed();
    void on_A3_pressed();
    void on_A4_pressed();
    void on_A5_pressed();
    void on_A6_pressed();
    void on_A7_pressed();
    void on_A8_pressed();

    void on_B1_pressed();
    void on_B2_pressed();
    void on_B3_pressed();
    void on_B4_pressed();
    void on_B5_pressed();
    void on_B6_pressed();
    void on_B7_pressed();
    void on_B8_pressed();

    void on_C1_pressed();
    void on_C2_pressed();
    void on_C3_pressed();
    void on_C4_pressed();
    void on_C5_pressed();
    void on_C6_pressed();
    void on_C7_pressed();
    void on_C8_pressed();

    void on_D1_pressed();
    void on_D2_pressed();
    void on_D3_pressed();
    void on_D4_pressed();
    void on_D5_pressed();
    void on_D6_pressed();
    void on_D7_pressed();
    void on_D8_pressed();

    void on_E1_pressed();
    void on_E2_pressed();
    void on_E3_pressed();
    void on_E4_pressed();
    void on_E5_pressed();
    void on_E6_pressed();
    void on_E7_pressed();
    void on_E8_pressed();

    void on_F1_pressed();
    void on_F2_pressed();
    void on_F3_pressed();
    void on_F4_pressed();
    void on_F5_pressed();
    void on_F6_pressed();
    void on_F7_pressed();
    void on_F8_pressed();

    void on_G1_pressed();
    void on_G2_pressed();
    void on_G3_pressed();
    void on_G4_pressed();
    void on_G5_pressed();
    void on_G6_pressed();
    void on_G7_pressed();
    void on_G8_pressed();

    void on_H1_pressed();
    void on_H2_pressed();
    void on_H3_pressed();
    void on_H4_pressed();
    void on_H5_pressed();
    void on_H6_pressed();
    void on_H7_pressed();
    void on_H8_pressed();

    void on_moveConfirmButton_clicked();

    void on_moveClearButton_clicked();

private:
    Ui::GameWithoutChat *ui;
    Client *client;
    Timer timer;
    QString move;

    void on_boardButton_pushed(QPushButton*);
    void on_position_chosen(QPushButton*);
    void on_initialPosition_chosen(QPushButton*);
};

#endif // GAMEWITHOUTCHAT_H
