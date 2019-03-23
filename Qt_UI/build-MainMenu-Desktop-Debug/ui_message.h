/********************************************************************************
** Form generated from reading UI file 'message.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGE_H
#define UI_MESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Message
{
public:
    QGridLayout *gridLayout;
    QPushButton *button;
    QLabel *messageLabel;

    void setupUi(QDialog *Message)
    {
        if (Message->objectName().isEmpty())
            Message->setObjectName(QString::fromUtf8("Message"));
        Message->resize(309, 94);
        gridLayout = new QGridLayout(Message);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        button = new QPushButton(Message);
        button->setObjectName(QString::fromUtf8("button"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(button->sizePolicy().hasHeightForWidth());
        button->setSizePolicy(sizePolicy);

        gridLayout->addWidget(button, 1, 1, 1, 1);

        messageLabel = new QLabel(Message);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        messageLabel->setInputMethodHints(Qt::ImhNone);
        messageLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(messageLabel, 0, 0, 1, 2);


        retranslateUi(Message);

        QMetaObject::connectSlotsByName(Message);
    } // setupUi

    void retranslateUi(QDialog *Message)
    {
        Message->setWindowTitle(QApplication::translate("Message", "Oh no.", nullptr));
        button->setText(QApplication::translate("Message", "OK", nullptr));
        messageLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Message: public Ui_Message {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGE_H
