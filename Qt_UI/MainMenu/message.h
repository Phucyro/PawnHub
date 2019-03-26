#ifndef MESSAGE_H
#define MESSAGE_H

#include <QDialog>

namespace Ui {
class Message;
}

class Message : public QDialog
{
    Q_OBJECT

public:
    explicit Message(QWidget *parent = nullptr);
    ~Message();

    void set_text(QString);
    void set_title(QString);
    void popup();

private slots:
    void on_button_clicked();

private:
    Ui::Message *ui;
};

#endif // MESSAGE_H