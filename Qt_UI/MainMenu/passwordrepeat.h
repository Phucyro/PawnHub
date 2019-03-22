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

    bool check_password(QString);

private slots:
    void on_doneButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::PasswordRepeat *ui;
    bool matched;
    QString password1, password2;
};

#endif // PASSWORDREPEAT_H
