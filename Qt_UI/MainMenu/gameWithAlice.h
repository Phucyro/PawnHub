#ifndef GAMEWITHALICE_H
#define GAMEWITHALICE_H

#include <QDialog>

namespace Ui {
class GameWithAlice;
}

class GameWithAlice : public QDialog
{
    Q_OBJECT

public:
    explicit GameWithAlice(QWidget *parent = nullptr);
    ~GameWithAlice();

private slots:
    void on_sendPushButton_pressed();

    void on_sendingTextField_returnPressed();

    void on_surrendButton_pressed();

private:
    Ui::GameWithAlice *ui;
};

#endif // GAMEWITHALICE_H
