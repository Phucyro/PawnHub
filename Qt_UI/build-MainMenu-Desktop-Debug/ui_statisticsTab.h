/********************************************************************************
** Form generated from reading UI file 'statisticsTab.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICSTAB_H
#define UI_STATISTICSTAB_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_StatisticsTab
{
public:
    QTableWidget *staisticsTableWidget;
    QPushButton *returnPushButton;

    void setupUi(QDialog *StatisticsTab)
    {
        if (StatisticsTab->objectName().isEmpty())
            StatisticsTab->setObjectName(QString::fromUtf8("StatisticsTab"));
        StatisticsTab->resize(600, 600);
        StatisticsTab->setMinimumSize(QSize(600, 600));
        StatisticsTab->setMaximumSize(QSize(600, 600));
        staisticsTableWidget = new QTableWidget(StatisticsTab);
        staisticsTableWidget->setObjectName(QString::fromUtf8("staisticsTableWidget"));
        staisticsTableWidget->setGeometry(QRect(10, 10, 580, 530));
        returnPushButton = new QPushButton(StatisticsTab);
        returnPushButton->setObjectName(QString::fromUtf8("returnPushButton"));
        returnPushButton->setGeometry(QRect(10, 550, 80, 23));

        retranslateUi(StatisticsTab);

        QMetaObject::connectSlotsByName(StatisticsTab);
    } // setupUi

    void retranslateUi(QDialog *StatisticsTab)
    {
        StatisticsTab->setWindowTitle(QApplication::translate("StatisticsTab", "Game Statistics", 0, QApplication::UnicodeUTF8));
        returnPushButton->setText(QApplication::translate("StatisticsTab", "Return", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StatisticsTab: public Ui_StatisticsTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICSTAB_H
