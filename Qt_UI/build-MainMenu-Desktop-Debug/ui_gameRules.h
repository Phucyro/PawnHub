/********************************************************************************
** Form generated from reading UI file 'gameRules.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMERULES_H
#define UI_GAMERULES_H

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

class Ui_GameRules
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
    QPushButton *returnPushButton;
    QPlainTextEdit *rulesTextEdit;

    void setupUi(QDialog *GameRules)
    {
        if (GameRules->objectName().isEmpty())
            GameRules->setObjectName(QString::fromUtf8("GameRules"));
        GameRules->resize(400, 400);
        GameRules->setMinimumSize(QSize(400, 400));
        GameRules->setMaximumSize(QSize(400, 400));
        label = new QLabel(GameRules);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 15, 381, 41));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Calvin.jpg")));
        label->setScaledContents(true);
        horizontalLayoutWidget = new QWidget(GameRules);
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

        returnPushButton = new QPushButton(horizontalLayoutWidget);
        returnPushButton->setObjectName(QString::fromUtf8("returnPushButton"));

        verticalLayout->addWidget(returnPushButton);


        horizontalLayout->addLayout(verticalLayout);

        rulesTextEdit = new QPlainTextEdit(horizontalLayoutWidget);
        rulesTextEdit->setObjectName(QString::fromUtf8("rulesTextEdit"));
        rulesTextEdit->setReadOnly(true);

        horizontalLayout->addWidget(rulesTextEdit);


        retranslateUi(GameRules);

        QMetaObject::connectSlotsByName(GameRules);
    } // setupUi

    void retranslateUi(QDialog *GameRules)
    {
        GameRules->setWindowTitle(QApplication::translate("GameRules", "Dialog", nullptr));
        label->setText(QString());
        classicPushButton->setText(QApplication::translate("GameRules", "Classic", nullptr));
        darkPushButton->setText(QApplication::translate("GameRules", "Dark", nullptr));
        hordePushButton->setText(QApplication::translate("GameRules", "Horde", nullptr));
        alicePushButton->setText(QApplication::translate("GameRules", "Alice", nullptr));
        realTimeClassicPushButton->setText(QApplication::translate("GameRules", "RealTime Classic", nullptr));
        realTimeDarkPushButton->setText(QApplication::translate("GameRules", "RealTime Dark", nullptr));
        realTimeHordePushButton->setText(QApplication::translate("GameRules", "RealTime Horde", nullptr));
        realTimeAlicePushButton->setText(QApplication::translate("GameRules", "RealTime Alice", nullptr));
        returnPushButton->setText(QApplication::translate("GameRules", "Return", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameRules: public Ui_GameRules {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMERULES_H
