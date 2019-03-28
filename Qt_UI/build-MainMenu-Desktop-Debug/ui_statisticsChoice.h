/********************************************************************************
** Form generated from reading UI file 'statisticsChoice.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICSCHOICE_H
#define UI_STATISTICSCHOICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatisticsChoice
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *myStatsPushButton;
    QPushButton *globalPushButton;
    QPushButton *returnPushButton;

    void setupUi(QDialog *StatisticsChoice)
    {
        if (StatisticsChoice->objectName().isEmpty())
            StatisticsChoice->setObjectName(QString::fromUtf8("StatisticsChoice"));
        StatisticsChoice->resize(400, 400);
        StatisticsChoice->setMinimumSize(QSize(400, 400));
        StatisticsChoice->setMaximumSize(QSize(400, 400));
        verticalLayoutWidget = new QWidget(StatisticsChoice);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 79, 381, 311));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        myStatsPushButton = new QPushButton(verticalLayoutWidget);
        myStatsPushButton->setObjectName(QString::fromUtf8("myStatsPushButton"));

        verticalLayout->addWidget(myStatsPushButton);

        globalPushButton = new QPushButton(verticalLayoutWidget);
        globalPushButton->setObjectName(QString::fromUtf8("globalPushButton"));

        verticalLayout->addWidget(globalPushButton);

        returnPushButton = new QPushButton(verticalLayoutWidget);
        returnPushButton->setObjectName(QString::fromUtf8("returnPushButton"));

        verticalLayout->addWidget(returnPushButton);


        retranslateUi(StatisticsChoice);

        QMetaObject::connectSlotsByName(StatisticsChoice);
    } // setupUi

    void retranslateUi(QDialog *StatisticsChoice)
    {
        StatisticsChoice->setWindowTitle(QApplication::translate("StatisticsChoice", "Dialog", nullptr));
        myStatsPushButton->setText(QApplication::translate("StatisticsChoice", "MyStats", nullptr));
        globalPushButton->setText(QApplication::translate("StatisticsChoice", "Global Stats", nullptr));
        returnPushButton->setText(QApplication::translate("StatisticsChoice", "Return", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatisticsChoice: public Ui_StatisticsChoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICSCHOICE_H
