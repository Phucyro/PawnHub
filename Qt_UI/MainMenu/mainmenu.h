#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

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
    void on_play_button_clicked();

    void on_stats_button_clicked();

    void on_friends_button_clicked();

    void on_chat_button_clicked();

    void on_rules_button_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
