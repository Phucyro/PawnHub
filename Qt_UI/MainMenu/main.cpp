#include "mainmenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    try {
        QApplication a(argc, argv);
        MainMenu w;
        w.show();

        return a.exec();
    }
    catch (std::runtime_error) {
        return 1;
    }
}
