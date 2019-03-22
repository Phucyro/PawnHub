#ifndef GAMEWITHOUTCHATWITHALICE_H
#define GAMEWITHOUTCHATWITHALICE_H

#include <QDialog>

namespace Ui {
class GameWithoutChatWithAlice;
}

class GameWithoutChatWithAlice : public QDialog
{
    Q_OBJECT

public:
    explicit GameWithoutChatWithAlice(QWidget *parent = nullptr);
    ~GameWithoutChatWithAlice();

private:
    Ui::GameWithoutChatWithAlice *ui;
};

#endif // GAMEWITHOUTCHATWITHALICE_H
