#ifndef GAMEWITHOUTCHAT_H
#define GAMEWITHOUTCHAT_H

#include "../../Communication/Timer.hpp"

#include <QDialog>
#include <QIcon>
#include <QAbstractButton>
#include <QTimer>
#include <QTime>

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
    void reduce_timer(int=100);

    void closeEvent(QCloseEvent*);

private slots:
    void update_time();
    void boardButton_pressed(QAbstractButton*);
    void promotion_declared(QString);
    void on_surrendButton_pressed();
    void on_moveConfirmButton_clicked();
    void on_moveClearButton_clicked();

private:
    Ui::GameWithoutChat *ui;
    Client *client;
    ClientGameControl *control;
    QTimer *timer;
    QTime *remainingTime;
    QTime done;
    QString move;

    void display_time();
    void on_initialPosition_chosen(QAbstractButton*);
};

#endif // GAMEWITHOUTCHAT_H
