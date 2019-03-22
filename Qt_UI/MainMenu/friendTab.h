#ifndef FRIENDTAB_H
#define FRIENDTAB_H

#include <QDialog>

namespace Ui {
class FriendTab;
}

class FriendTab : public QDialog
{
    Q_OBJECT

public:
    explicit FriendTab(QWidget *parent = nullptr);
    ~FriendTab();

private slots:
    void on_removePushButton_pressed();

    void on_cancelPushButton_pressed();

    void on_acceptPushButton_pressed();

    void on_denyPushButton_pressed();

    void on_addPushButton_pressed();

    void on_inputLineEdit_returnPressed();

    void on_returnPushButton_pressed();

private:
    Ui::FriendTab *ui;
};

#endif // FRIENDTAB_H
