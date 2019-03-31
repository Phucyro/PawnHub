#ifndef GAMEWITHOUTCHATWITHALICE_H
#define GAMEWITHOUTCHATWITHALICE_H

#include "../../Communication/Timer.hpp"

#include <QDialog>
#include <QIcon>
#include <QAbstractButton>

class Client;
class ClientGameControl;

namespace Ui {
class GameWithoutChatWithAlice;
}

class GameWithoutChatWithAlice : public QDialog
{
    Q_OBJECT

public:
    explicit GameWithoutChatWithAlice(QWidget *parent = nullptr, Client *client_=nullptr);
    ~GameWithoutChatWithAlice();

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
    void reduce_timer(int);

private slots:
    void boardButton_pressed(QAbstractButton*);
    void promotion_declared(QString);
    void on_surrendButton_pressed();
    void on_moveConfirmButton_clicked();
    void on_moveClearButton_clicked();

private:
    Ui::GameWithoutChatWithAlice *ui;
    Client *client;
    ClientGameControl *control;
    Timer timer;
    QString move;

    void on_initialPosition_chosen(QAbstractButton*);
};

#endif // GAMEWITHOUTCHATWITHALICE_H
