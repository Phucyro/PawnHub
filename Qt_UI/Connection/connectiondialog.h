#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include <QDialog>

#include "display.h"

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

private:
    Ui::ConnectionDialog *ui;
    Display *display;
    QString hostname;

};

#endif // CONNECTIONDIALOG_H
