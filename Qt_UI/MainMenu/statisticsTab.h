#ifndef STATISTICSTAB_H
#define STATISTICSTAB_H

#include "../../Communication/Client.hpp"

#include <QDialog>

namespace Ui {
class StatisticsTab;
}

class StatisticsTab : public QDialog
{
    Q_OBJECT

public:
    explicit StatisticsTab(int type,Client *client,int gamemode, QWidget *parent = nullptr);
    ~StatisticsTab();
    int getGamemode();

private slots:
    void on_returnPushButton_pressed();
    void setupMyStats();
    void setupGlobalStats();

private:
    Ui::StatisticsTab *ui;
    int type;
    Client* client;
    int gamemode;
};

#endif // STATISTICSTAB_H
