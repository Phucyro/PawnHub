/********************************************************************************
** Form generated from reading UI file 'message.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
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
    QPushButton *pushButton_2;
    QPushButton *pushButton_1;
    QLabel *messageLabel;
    QPushButton *okButton;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Message)
    {
        if (Message->objectName().isEmpty())
            Message->setObjectName(QString::fromUtf8("Message"));
        Message->resize(309, 94);
        gridLayout = new QGridLayout(Message);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_2 = new QPushButton(Message);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);
        pushButton_2->setFlat(true);

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_1 = new QPushButton(Message);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setEnabled(false);
        pushButton_1->setAutoDefault(true);
        pushButton_1->setFlat(true);

        gridLayout->addWidget(pushButton_1, 1, 0, 1, 1);

        messageLabel = new QLabel(Message);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        messageLabel->setInputMethodHints(Qt::ImhNone);
        messageLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(messageLabel, 0, 0, 1, 4);

        okButton = new QPushButton(Message);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(okButton, 1, 3, 1, 1);

        pushButton_3 = new QPushButton(Message);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(false);
        pushButton_3->setFlat(true);

        gridLayout->addWidget(pushButton_3, 1, 2, 1, 1);


        retranslateUi(Message);

        QMetaObject::connectSlotsByName(Message);
    } // setupUi

    void retranslateUi(QDialog *Message)
    {
        Message->setWindowTitle(QApplication::translate("Message", "Oh no.", nullptr));
        pushButton_2->setText(QString());
        pushButton_1->setText(QString());
        messageLabel->setText(QString());
        okButton->setText(QApplication::translate("Message", "OK", nullptr));
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Message: public Ui_Message {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGE_H
