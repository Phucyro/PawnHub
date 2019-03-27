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
    void promotion_choice();
    QString get_choice();

private slots:
    void on_okButton_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Message *ui;
    QString choice;
};

#endif // MESSAGE_H
