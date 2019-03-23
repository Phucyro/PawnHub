#ifndef Chat_H
#define Chat_H

#include <QDialog>

namespace Ui {
class Chat;
}

class Chat : public QDialog
{
    Q_OBJECT

public:
    explicit Chat(QWidget *parent = nullptr);
    ~Chat();

private slots:
    void on_inputLineEdit_returnPressed();

    void on_sendPushButton_pressed();

    void on_quitPushButton_pressed();

    void on_changeChanPushButton_pressed();

private:
    Ui::Chat *ui;
};

#endif // Chat_H
