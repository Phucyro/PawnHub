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
    void set_okButton(QString);
    void popup();
    void promotion_choice();
    QString get_choice();
    bool getCancel();

public slots:
    void closeEvent(QCloseEvent*);

signals:
    void promotion_chosen(QString);

private slots:
    void on_okButton_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Message *ui;
    QString promotion;
    bool is_promotion;
    bool cancel;
};

#endif // MESSAGE_H
