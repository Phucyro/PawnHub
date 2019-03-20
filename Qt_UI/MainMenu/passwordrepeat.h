#ifndef PASSWORDREPEAT_H
#define PASSWORDREPEAT_H

#include <QDialog>

namespace Ui {
class PasswordRepeat;
}

class PasswordRepeat : public QDialog
{
    Q_OBJECT

public:
    explicit PasswordRepeat(QWidget *parent = nullptr);
    ~PasswordRepeat();

    bool checkPassword(QString);

private slots:
    void on_done_button_clicked();

private:
    Ui::PasswordRepeat *ui;
    QString password2;
};

#endif // PASSWORDREPEAT_H
