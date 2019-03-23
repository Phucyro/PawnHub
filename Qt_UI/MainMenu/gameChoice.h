#ifndef GAMECHOICE_H
#define GAMECHOICE_H

#include <QDialog>

namespace Ui {
class GameChoice;
}

class GameChoice : public QDialog
{
    Q_OBJECT

public:
    explicit GameChoice(QWidget *parent = nullptr);
    ~GameChoice();

private:
    Ui::GameChoice *ui;

private slots:
    void on_classicPushButton_pressed();

    void on_darkPushButton_pressed();

    void on_hordePushButton_pressed();

    void on_alicePushButton_pressed();

    void on_realTimeClassicPushButton_pressed();

    void on_realTimeDarkPushButton_pressed();

    void on_realTimeHordePushButton_pressed();

    void on_realTimeAlicePushButton_pressed();
    void on_returnPushButton_pressed();
};

#endif // GAMECHOICE_H
