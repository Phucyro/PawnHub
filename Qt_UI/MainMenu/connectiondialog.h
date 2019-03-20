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

    QString askHostname();

private slots:
    void on_done_push_clicked();

    void on_cancel_push_clicked();

private:
    Ui::ConnectionDialog *ui;
    QString hostname;

};

#endif // CONNECTIONDIALOG_H
