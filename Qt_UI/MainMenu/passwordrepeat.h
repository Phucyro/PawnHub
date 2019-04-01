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

    QString get_confirmation();

private slots:
    void on_doneButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::PasswordRepeat *ui;
    QString pwdConfirmation;
};

#endif // PASSWORDREPEAT_H
