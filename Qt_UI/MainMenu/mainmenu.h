#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

#include <thread>

class Client;

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_playButton_clicked();
    void on_statsButton_clicked();
    void on_friendsButton_clicked();
    void on_chatButton_clicked();
    void on_rulesButton_clicked();
    void on_quitButton_clicked();

    void closeEvent();

private:
    Ui::MainMenu *ui;
    Client* client;
    std::thread msgThread;

    void client_connect();
    void client_login();
};

#endif // MAINMENU_H
