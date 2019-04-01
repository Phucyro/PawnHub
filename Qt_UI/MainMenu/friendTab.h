#ifndef FRIENDTAB_H
#define FRIENDTAB_H

#include <QDialog>

class Client;

namespace Ui {
class FriendTab;
}

class FriendTab : public QDialog
{
    Q_OBJECT

public:
    explicit FriendTab(Client* client, QWidget *parent = nullptr);
    ~FriendTab();

private slots:
    void on_removePushButton_pressed();
    void on_acceptPushButton_pressed();
    void on_denyPushButton_pressed();
    void on_addPushButton_pressed();
    void on_cancelPushButton_pressed();
    void on_inputLineEdit_returnPressed();
    void on_returnPushButton_pressed();
    void on_updatePushButton_clicked();

    void popup(QString, QString);

private:
    Ui::FriendTab *ui;
    Client* client;
};

#endif // FRIENDTAB_H
