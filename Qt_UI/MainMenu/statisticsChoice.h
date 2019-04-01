#ifndef STATISTICSCHOICE_H
#define STATISTICSCHOICE_H

#include "../../Communication/Client.hpp"

#include <QDialog>

namespace Ui {
class StatisticsChoice;
}

class StatisticsChoice : public QDialog
{
    Q_OBJECT

public:
    explicit StatisticsChoice(Client *client, QWidget *parent = nullptr);
    ~StatisticsChoice();

private slots:
    void on_returnPushButton_pressed();

    void on_myStatsPushButton_pressed();

    void on_globalPushButton_pressed();

private:
    Ui::StatisticsChoice *ui;
    Client *client;
};

#endif // STATISTICSCHOICE_H
