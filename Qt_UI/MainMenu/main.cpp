#include "mainmenu.h"
//#include "logindialog.h"
//#include "game.h"
//#include "gameWithAlice.h"
//#include "gameWithoutChat.h"
//#include "gameWithoutChatWithAlice.h"
//#include "gameChoice.h"
//#include "friendTab.h"
//#include "statisticsTab.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    try {
        QApplication a(argc, argv);
        MainMenu w;

        return a.exec();
    }
    catch (std::runtime_error& error) {
        std::cout << error.what() << std::endl;
        return 1;
    }
}
