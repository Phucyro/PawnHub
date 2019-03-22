/********************************************************************************
** Form generated from reading UI file 'statisicsTab.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISICSTAB_H
#define UI_STATISICSTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_StatisicsTab
{
public:
    QTableView *StatisticsTableView;
    QPushButton *returnPushButton;

    void setupUi(QDialog *StatisicsTab)
    {
        if (StatisicsTab->objectName().isEmpty())
            StatisicsTab->setObjectName(QString::fromUtf8("StatisicsTab"));
        StatisicsTab->resize(800, 600);
        StatisicsTab->setMinimumSize(QSize(800, 600));
        StatisicsTab->setMaximumSize(QSize(800, 600));
        StatisticsTableView = new QTableView(StatisicsTab);
        StatisticsTableView->setObjectName(QString::fromUtf8("StatisticsTableView"));
        StatisticsTableView->setGeometry(QRect(10, 10, 780, 550));
        StatisticsTableView->setMinimumSize(QSize(780, 550));
        StatisticsTableView->setMaximumSize(QSize(780, 550));
        returnPushButton = new QPushButton(StatisicsTab);
        returnPushButton->setObjectName(QString::fromUtf8("returnPushButton"));
        returnPushButton->setGeometry(QRect(10, 570, 80, 23));

        retranslateUi(StatisicsTab);

        QMetaObject::connectSlotsByName(StatisicsTab);
    } // setupUi

    void retranslateUi(QDialog *StatisicsTab)
    {
        StatisicsTab->setWindowTitle(QApplication::translate("StatisicsTab", "Dialog", nullptr));
        returnPushButton->setText(QApplication::translate("StatisicsTab", "Return", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatisicsTab: public Ui_StatisicsTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISICSTAB_H
