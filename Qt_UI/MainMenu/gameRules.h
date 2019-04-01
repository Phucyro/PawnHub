#ifndef GAMERULES_H
#define GAMERULES_H

#include <QDialog>

namespace Ui {
class GameRules;
}

class GameRules : public QDialog
{
    Q_OBJECT

public:
    explicit GameRules(QWidget *parent = nullptr);
    ~GameRules();

private:
    Ui::GameRules *ui;

private slots:
    void on_classicPushButton_pressed();

    void on_darkPushButton_pressed();

    void on_hordePushButton_pressed();

    void on_alicePushButton_pressed();

    void on_realTimePushButton_pressed();

    void on_returnPushButton_pressed();
};

#endif // GAMERULES_H
