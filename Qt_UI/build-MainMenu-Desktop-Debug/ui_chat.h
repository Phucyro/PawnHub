/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QPlainTextEdit *chatPlainTextEdit;
    QPushButton *changeChanPushButton;
    QPushButton *quitPushButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *inputLineEdit;
    QPushButton *sendPushButton;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *channelLabel;
    QLabel *chgChangeChannellabel;
    QListWidget *friendListWidget;

    void setupUi(QDialog *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QString::fromUtf8("Chat"));
        Chat->resize(800, 550);
        Chat->setMinimumSize(QSize(800, 550));
        Chat->setMaximumSize(QSize(800, 550));
        chatPlainTextEdit = new QPlainTextEdit(Chat);
        chatPlainTextEdit->setObjectName(QString::fromUtf8("chatPlainTextEdit"));
        chatPlainTextEdit->setGeometry(QRect(13, 39, 481, 411));
        chatPlainTextEdit->setFocusPolicy(Qt::NoFocus);
        chatPlainTextEdit->setReadOnly(true);
        changeChanPushButton = new QPushButton(Chat);
        changeChanPushButton->setObjectName(QString::fromUtf8("changeChanPushButton"));
        changeChanPushButton->setGeometry(QRect(680, 510, 111, 23));
        quitPushButton = new QPushButton(Chat);
        quitPushButton->setObjectName(QString::fromUtf8("quitPushButton"));
        quitPushButton->setGeometry(QRect(10, 510, 80, 23));
        horizontalLayoutWidget = new QWidget(Chat);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 460, 781, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        inputLineEdit = new QLineEdit(horizontalLayoutWidget);
        inputLineEdit->setObjectName(QString::fromUtf8("inputLineEdit"));

        horizontalLayout->addWidget(inputLineEdit);

        sendPushButton = new QPushButton(horizontalLayoutWidget);
        sendPushButton->setObjectName(QString::fromUtf8("sendPushButton"));

        horizontalLayout->addWidget(sendPushButton);

        horizontalLayoutWidget_2 = new QWidget(Chat);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 10, 160, 21));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        channelLabel = new QLabel(horizontalLayoutWidget_2);
        channelLabel->setObjectName(QString::fromUtf8("channelLabel"));

        horizontalLayout_2->addWidget(channelLabel);

        chgChangeChannellabel = new QLabel(horizontalLayoutWidget_2);
        chgChangeChannellabel->setObjectName(QString::fromUtf8("chgChangeChannellabel"));

        horizontalLayout_2->addWidget(chgChangeChannellabel);

        friendListWidget = new QListWidget(Chat);
        friendListWidget->setObjectName(QString::fromUtf8("friendListWidget"));
        friendListWidget->setGeometry(QRect(500, 40, 291, 411));

        retranslateUi(Chat);

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QDialog *Chat)
    {
        Chat->setWindowTitle(QApplication::translate("Chat", "Dialog", nullptr));
        changeChanPushButton->setText(QApplication::translate("Chat", "Change Channel", nullptr));
        quitPushButton->setText(QApplication::translate("Chat", "Quit", nullptr));
        sendPushButton->setText(QApplication::translate("Chat", "Send", nullptr));
        channelLabel->setText(QApplication::translate("Chat", "Canal :", nullptr));
        chgChangeChannellabel->setText(QApplication::translate("Chat", "XXX", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
