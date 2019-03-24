#ifndef GAMECHOICESTATISTICS_H
#define GAMECHOICESTATISTICS_H

#include <QDialog>

namespace Ui {
class GameChoiceStatistics;
}

class GameChoiceStatistics : public QDialog
{
    Q_OBJECT

public:
    explicit GameChoiceStatistics(QWidget *parent = nullptr);
    ~GameChoiceStatistics();

private:
    Ui::GameChoiceStatistics *ui;
private slots:
    void on_classicPushButton_pressed();

    void on_darkPushButton_pressed();

    void on_hordePushButton_pressed();

    void on_alicePushButton_pressed();

    void on_realTimeClassicPushButton_pressed();

    void on_realTimeDarkPushButton_pressed();

    void on_realTimeHordePushButton_pressed();

    void on_realTimeAlicePushButton_pressed();

    void on_returnPushButton_pressed();
};

#endif // GAMECHOICESTATISTICS_H
