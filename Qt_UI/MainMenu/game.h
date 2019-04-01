#ifndef GAME_H
#define GAME_H

#include <QDialog>

namespace Ui {
class Game;
}

class Game : public QDialog
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

private slots:
    void on_sendPushButton_pressed();

    void on_sendingTextField_returnPressed();

    void on_surrendButton_pressed();

private:
    Ui::Game *ui;
};

#endif // GAME_H
