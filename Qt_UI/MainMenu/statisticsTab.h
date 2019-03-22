#ifndef STATISTICSTAB_H
#define STATISTICSTAB_H

#include <QDialog>

namespace Ui {
class StatisticsTab;
}

class StatisticsTab : public QDialog
{
    Q_OBJECT

public:
    explicit StatisticsTab(QWidget *parent = nullptr);
    ~StatisticsTab();

private slots:
    void on_returnPushButton_pressed();

private:
    Ui::StatisticsTab *ui;
};

#endif // STATISTICSTAB_H
