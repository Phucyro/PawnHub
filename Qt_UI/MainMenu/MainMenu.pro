#-------------------------------------------------
#
# Project created by QtCreator 2019-03-12T17:54:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MainMenu
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

INCLUDEPATH += ../../Communication ../Modified_Files
#DEPENDPATH += $$(INCLUDEPATH)   #Not sure what that does yet

SOURCES += \
        main.cpp \
        mainmenu.cpp \
    connectiondialog.cpp \
    logindialog.cpp \
    ../../Communication/Socket.cpp \
    ../../Communication/Client.cpp \
    ../../Communication/SplitString.cpp \
    ../Modified_Files/CheckFormat.cpp \
    ../Modified_Files/ClientGameControl.cpp \
    passwordrepeat.cpp \
    message.cpp \
    game.cpp \
    gameWithoutChat.cpp \
    gameWithoutChatWithAlice.cpp \
    gameWithAlice.cpp \
    gameChoiceStatistics.cpp \
    gameChoice.cpp \
    friendTab.cpp \
    statisticsTab.cpp \
    chat.cpp \
    gameRules.cpp \
    statisticsChoice.cpp

HEADERS += \
        mainmenu.h \
    connectiondialog.h \
    logindialog.h \
    ../../Communication/Socket.hpp \
    ../../Communication/Client.hpp \
    ../../Communication/SplitString.hpp \
    ../Modified_Files/ClientFunctions.hpp \
    ../Modified_Files/ClientHandler.hpp \
    ../Modified_Files/ClientMessageHandler.hpp \
    ../Modified_Files/CheckFormat.hpp \
    ../Modified_Files/ClientGameControl.hpp \
    ../Modified_Files/BoardParsing.hpp \
    ../Modified_Files/MoveParsing.hpp \
    passwordrepeat.h \
    message.h \
    game.h \
    gameWithoutChat.h \
    gameWithoutChatWithAlice.h \
    gameWithAlice.h \
    gameChoice.h \
    gameChoiceStatistics.h \
    friendTab.h \
    statisticsTab.h \
    chat.h \
    gameRules.h \
    statisticsChoice.h

FORMS += \
    connectiondialog.ui \
    logindialog.ui \
    passwordrepeat.ui \
    message.ui \
    mainmenu.ui \
    game.ui \
    gameWithoutChat.ui \
    gameWithAlice.ui \
    gameWithoutChatWithAlice.ui \
    gameChoiceStatistics.ui \
    friendTab.ui \
    statisticsTab.ui \
    chat.ui \
    gameRules.ui \
    gameChoice.ui \
    statisticsChoice.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    calvin.qrc \
    loremipsum.qrc \
    catmeme.qrc \
    chess_pieces.qrc

#DISTFILES +=
