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

INCLUDEPATH += ../../Communication
#DEPENDPATH += $$(INCLUDEPATH)   #Not sure what that does yet

SOURCES += \
        main.cpp \
        mainmenu.cpp \
    connectiondialog.cpp \
    logindialog.cpp \
    ../../Communication/socket.cpp \
    passwordrepeat.cpp \
    message.cpp \
    game.cpp \
    gameWithoutChat.cpp \
    gameWithoutChatWithAlice.cpp \
    gameWithAlice.cpp \
    gameChoiceStatistics.cpp \
    gameChoice.cpp \
    friendTab.cpp \
    statisticsTab.cpp

HEADERS += \
        mainmenu.h \
    connectiondialog.h \
    logindialog.h \
    ../../Communication/socket.hpp \
    passwordrepeat.h \
    message.h \
    game.h \
    gameWithoutChat.h \
    gameWithoutChatWithAlice.h \
    gameWithAlice.h \
    gameChoice.h \
    gameChoiceStatistics.h \
    friendTab.h \
    statisticsTab.h

FORMS += \
    connectiondialog.ui \
    logindialog.ui \
    passwordrepeat.ui \
    message.ui \
<<<<<<< HEAD
    message.ui \
    mainmenu.ui \
    game.ui \
    gameWithoutChat.ui \
    gameWithAlice.ui \
    gameWithoutChatWithAlice.ui \
    gameChoice.ui \
    gameChoiceStatistics.ui \
    friendTab.ui \
    statisticsTab.ui
=======
    mainmenu.ui
>>>>>>> 801415dcb49c478e36ccb6cef5532774701e67d3

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    calvin.qrc \
    loremipsum.qrc \
    catmeme.qrc

DISTFILES +=
