/********************************************************************************
** Form generated from reading UI file 'gameChoice.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMECHOICE_H
#define UI_GAMECHOICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameChoice
{
public:
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *classicPushButton;
    QPushButton *darkPushButton;
    QPushButton *hordePushButton;
    QPushButton *alicePushButton;
    QPushButton *realTimeClassicPushButton;
    QPushButton *realTimeDarkPushButton;
    QPushButton *realTimeHordePushButton;
    QPushButton *realTimeAlicePushButton;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *GameChoice)
    {
        if (GameChoice->objectName().isEmpty())
            GameChoice->setObjectName(QString::fromUtf8("GameChoice"));
        GameChoice->resize(400, 400);
        GameChoice->setMinimumSize(QSize(400, 400));
        GameChoice->setMaximumSize(QSize(400, 400));
        label = new QLabel(GameChoice);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 15, 381, 41));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Calvin.jpg")));
        label->setScaledContents(true);
        horizontalLayoutWidget = new QWidget(GameChoice);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 70, 381, 321));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        classicPushButton = new QPushButton(horizontalLayoutWidget);
        classicPushButton->setObjectName(QString::fromUtf8("classicPushButton"));

        verticalLayout->addWidget(classicPushButton);

        darkPushButton = new QPushButton(horizontalLayoutWidget);
        darkPushButton->setObjectName(QString::fromUtf8("darkPushButton"));

        verticalLayout->addWidget(darkPushButton);

        hordePushButton = new QPushButton(horizontalLayoutWidget);
        hordePushButton->setObjectName(QString::fromUtf8("hordePushButton"));

        verticalLayout->addWidget(hordePushButton);

        alicePushButton = new QPushButton(horizontalLayoutWidget);
        alicePushButton->setObjectName(QString::fromUtf8("alicePushButton"));

        verticalLayout->addWidget(alicePushButton);

        realTimeClassicPushButton = new QPushButton(horizontalLayoutWidget);
        realTimeClassicPushButton->setObjectName(QString::fromUtf8("realTimeClassicPushButton"));

        verticalLayout->addWidget(realTimeClassicPushButton);

        realTimeDarkPushButton = new QPushButton(horizontalLayoutWidget);
        realTimeDarkPushButton->setObjectName(QString::fromUtf8("realTimeDarkPushButton"));

        verticalLayout->addWidget(realTimeDarkPushButton);

        realTimeHordePushButton = new QPushButton(horizontalLayoutWidget);
        realTimeHordePushButton->setObjectName(QString::fromUtf8("realTimeHordePushButton"));

        verticalLayout->addWidget(realTimeHordePushButton);

        realTimeAlicePushButton = new QPushButton(horizontalLayoutWidget);
        realTimeAlicePushButton->setObjectName(QString::fromUtf8("realTimeAlicePushButton"));

        verticalLayout->addWidget(realTimeAlicePushButton);


        horizontalLayout->addLayout(verticalLayout);

        plainTextEdit = new QPlainTextEdit(horizontalLayoutWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setReadOnly(true);

        horizontalLayout->addWidget(plainTextEdit);


        retranslateUi(GameChoice);

        QMetaObject::connectSlotsByName(GameChoice);
    } // setupUi

    void retranslateUi(QDialog *GameChoice)
    {
        GameChoice->setWindowTitle(QApplication::translate("GameChoice", "Dialog", nullptr));
        label->setText(QString());
        classicPushButton->setText(QApplication::translate("GameChoice", "Classic", nullptr));
        darkPushButton->setText(QApplication::translate("GameChoice", "Dark", nullptr));
        hordePushButton->setText(QApplication::translate("GameChoice", "Horde", nullptr));
        alicePushButton->setText(QApplication::translate("GameChoice", "Alice", nullptr));
        realTimeClassicPushButton->setText(QApplication::translate("GameChoice", "RealTime Classic", nullptr));
        realTimeDarkPushButton->setText(QApplication::translate("GameChoice", "RealTime Dark", nullptr));
        realTimeHordePushButton->setText(QApplication::translate("GameChoice", "RealTime Horde", nullptr));
        realTimeAlicePushButton->setText(QApplication::translate("GameChoice", "RealTime Alice", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameChoice: public Ui_GameChoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMECHOICE_H
