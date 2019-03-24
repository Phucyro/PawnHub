#ifndef GAMEWITHOUTCHAT_H
#define GAMEWITHOUTCHAT_H

#include <QDialog>

namespace Ui {
class GameWithoutChat;
}

class GameWithoutChat : public QDialog
{
    Q_OBJECT

public:
    explicit GameWithoutChat(QWidget *parent = nullptr);
    ~GameWithoutChat();

private slots:
    void on_surrendButton_pressed();

    void on_a8PushButton_pressed();
    void on_a7PushButton_pressed();
    void on_a6PushButton_pressed();
    void on_a5PushButton_pressed();
    void on_a4PushButton_pressed();
    void on_a3PushButton_pressed();
    void on_a2PushButton_pressed();
    void on_a1PushButton_pressed();

    void on_b8PushButton_pressed();
    void on_b7PushButton_pressed();
    void on_b6PushButton_pressed();
    void on_b5PushButton_pressed();
    void on_b4PushButton_pressed();
    void on_b3PushButton_pressed();
    void on_b2PushButton_pressed();
    void on_b1PushButton_pressed();

    void on_c8PushButton_pressed();
    void on_c7PushButton_pressed();
    void on_c6PushButton_pressed();
    void on_c5PushButton_pressed();
    void on_c4PushButton_pressed();
    void on_c3PushButton_pressed();
    void on_c2PushButton_pressed();
    void on_c1PushButton_pressed();

    void on_d8PushButton_pressed();
    void on_d7PushButton_pressed();
    void on_d6PushButton_pressed();
    void on_d5PushButton_pressed();
    void on_d4PushButton_pressed();
    void on_d3PushButton_pressed();
    void on_d2PushButton_pressed();
    void on_d1PushButton_pressed();

    void on_e8PushButton_pressed();
    void on_e7PushButton_pressed();
    void on_e6PushButton_pressed();
    void on_e5PushButton_pressed();
    void on_e4PushButton_pressed();
    void on_e3PushButton_pressed();
    void on_e2PushButton_pressed();
    void on_e1PushButton_pressed();

    void on_f8PushButton_pressed();
    void on_f7PushButton_pressed();
    void on_f6PushButton_pressed();
    void on_f5PushButton_pressed();
    void on_f4PushButton_pressed();
    void on_f3PushButton_pressed();
    void on_f2PushButton_pressed();
    void on_f1PushButton_pressed();

    void on_g8PushButton_pressed();
    void on_g7PushButton_pressed();
    void on_g6PushButton_pressed();
    void on_g5PushButton_pressed();
    void on_g4PushButton_pressed();
    void on_g3PushButton_pressed();
    void on_g2PushButton_pressed();
    void on_g1PushButton_pressed();

    void on_h8PushButton_pressed();
    void on_h7PushButton_pressed();
    void on_h6PushButton_pressed();
    void on_h5PushButton_pressed();
    void on_h4PushButton_pressed();
    void on_h3PushButton_pressed();
    void on_h2PushButton_pressed();
    void on_h1PushButton_pressed();

private:
    Ui::GameWithoutChat *ui;
};

#endif // GAMEWITHOUTCHAT_H
