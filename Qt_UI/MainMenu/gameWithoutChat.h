#ifndef GAMEWITHOUTCHAT_H
#define GAMEWITHOUTCHAT_H

#include <QDialog>

namespace Ui {
class GameWithoutChat;
}

class GameWithoutChat : public QDialog
{
    Q_OBJECT

public:
    explicit GameWithoutChat(QWidget *parent = nullptr);
    ~GameWithoutChat();

private:
    Ui::GameWithoutChat *ui;
};

#endif // GAMEWITHOUTCHAT_H
