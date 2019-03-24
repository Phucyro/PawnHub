/********************************************************************************
** Form generated from reading UI file 'gameChoiceStatistics.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMECHOICESTATISTICS_H
#define UI_GAMECHOICESTATISTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameChoiceStatistics
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

    void setupUi(QDialog *GameChoiceStatistics)
    {
        if (GameChoiceStatistics->objectName().isEmpty())
            GameChoiceStatistics->setObjectName(QString::fromUtf8("GameChoiceStatistics"));
        GameChoiceStatistics->resize(400, 400);
        GameChoiceStatistics->setMinimumSize(QSize(400, 400));
        GameChoiceStatistics->setMaximumSize(QSize(400, 400));
        label = new QLabel(GameChoiceStatistics);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 15, 381, 41));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Calvin.jpg")));
        label->setScaledContents(true);
        horizontalLayoutWidget = new QWidget(GameChoiceStatistics);
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


        retranslateUi(GameChoiceStatistics);

        QMetaObject::connectSlotsByName(GameChoiceStatistics);
    } // setupUi

    void retranslateUi(QDialog *GameChoiceStatistics)
    {
        GameChoiceStatistics->setWindowTitle(QApplication::translate("GameChoiceStatistics", "Dialog", nullptr));
        label->setText(QString());
        classicPushButton->setText(QApplication::translate("GameChoiceStatistics", "Classic", nullptr));
        darkPushButton->setText(QApplication::translate("GameChoiceStatistics", "Dark", nullptr));
        hordePushButton->setText(QApplication::translate("GameChoiceStatistics", "Horde", nullptr));
        alicePushButton->setText(QApplication::translate("GameChoiceStatistics", "Alice", nullptr));
        realTimeClassicPushButton->setText(QApplication::translate("GameChoiceStatistics", "RealTime Classic", nullptr));
        realTimeDarkPushButton->setText(QApplication::translate("GameChoiceStatistics", "RealTime Dark", nullptr));
        realTimeHordePushButton->setText(QApplication::translate("GameChoiceStatistics", "RealTime Horde", nullptr));
        realTimeAlicePushButton->setText(QApplication::translate("GameChoiceStatistics", "RealTime Alice", nullptr));
        returnPushButton->setText(QApplication::translate("GameChoiceStatistics", "Return", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameChoiceStatistics: public Ui_GameChoiceStatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMECHOICESTATISTICS_H
