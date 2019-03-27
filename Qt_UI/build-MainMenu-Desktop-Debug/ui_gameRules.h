/********************************************************************************
** Form generated from reading UI file 'gameRules.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMERULES_H
#define UI_GAMERULES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameRules
{
public:
    QLabel *adsLabel;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *classicPushButton;
    QPushButton *darkPushButton;
    QPushButton *hordePushButton;
    QPushButton *alicePushButton;
    QPushButton *realTimePushButton;
    QPushButton *returnPushButton;
    QPlainTextEdit *rulesTextEdit;

    void setupUi(QDialog *GameRules)
    {
        if (GameRules->objectName().isEmpty())
            GameRules->setObjectName(QString::fromUtf8("GameRules"));
        GameRules->resize(600, 600);
        GameRules->setMinimumSize(QSize(600, 600));
        GameRules->setMaximumSize(QSize(600, 600));
        adsLabel = new QLabel(GameRules);
        adsLabel->setObjectName(QString::fromUtf8("adsLabel"));
        adsLabel->setGeometry(QRect(10, 15, 571, 41));
        adsLabel->setPixmap(QPixmap(QString::fromUtf8(":/Calvin.jpg")));
        adsLabel->setScaledContents(true);
        horizontalLayoutWidget = new QWidget(GameRules);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 70, 581, 521));
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

        realTimePushButton = new QPushButton(horizontalLayoutWidget);
        realTimePushButton->setObjectName(QString::fromUtf8("realTimePushButton"));

        verticalLayout->addWidget(realTimePushButton);

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
        GameRules->setWindowTitle(QApplication::translate("GameRules", "Dialog", 0, QApplication::UnicodeUTF8));
        adsLabel->setText(QString());
        classicPushButton->setText(QApplication::translate("GameRules", "Classic", 0, QApplication::UnicodeUTF8));
        darkPushButton->setText(QApplication::translate("GameRules", "Dark", 0, QApplication::UnicodeUTF8));
        hordePushButton->setText(QApplication::translate("GameRules", "Horde", 0, QApplication::UnicodeUTF8));
        alicePushButton->setText(QApplication::translate("GameRules", "Alice", 0, QApplication::UnicodeUTF8));
        realTimePushButton->setText(QApplication::translate("GameRules", "RealTime", 0, QApplication::UnicodeUTF8));
        returnPushButton->setText(QApplication::translate("GameRules", "Return", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GameRules: public Ui_GameRules {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMERULES_H
