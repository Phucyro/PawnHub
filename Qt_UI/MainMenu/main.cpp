//#include "mainmenu.h"
//#include "logindialog.h"
//#include "game.h"
//#include "gameWithAlice.h"
#include "gameWithoutChat.h"
//#include "gameWithoutChatWithAlice.h"
//#include "gameChoice.h"
//#include "friendTab.h"
//#include "statisticsTab.h"

#include "../../Communication/Socket.hpp"
#include "../../Communication/Client.hpp"
#include "../Modified_Files/ClientMessageHandler.hpp"
#include "../Modified_Files/ClientFunctions.hpp"

#include <QApplication>

#include <iostream>
#include <thread>

int main(int argc, char *argv[])
{
    try {
        QApplication a(argc, argv);

//        // Actual code
//        MainMenu w;
//        w.show();

        // Cheat code for game integration - change hostname for full effect
        GameWithoutChat game;
        Socket socket;
        socket.connectToServer("KryptonX");
        Client client(&socket);

        std::thread recvThread(receiveMessageHandler, &client);
        signIn(&socket, "Admin", "mdp");
        std::cout << client.readPipe() << std::endl;
        client.setName("Admin");
        playGame(&socket, "0");
        recvThread.join();

        std::cout << "Thread joined" << std::endl;
        game.show();

        return a.exec();
    }
    catch (std::runtime_error& error) {
        std::cout << error.what() << std::endl;
        return 1;
    }
}
