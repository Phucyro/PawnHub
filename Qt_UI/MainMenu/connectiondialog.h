#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include <QDialog>

namespace Ui {
class ConnectionDialog;
}

class ConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionDialog(QWidget *parent = nullptr);
    ~ConnectionDialog();

    QString ask_hostname();

private slots:
    void on_donePush_clicked();

    void on_cancelPush_clicked();

private:
    Ui::ConnectionDialog *ui;
    QString hostname;

};

#endif // CONNECTIONDIALOG_H
