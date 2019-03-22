/********************************************************************************
** Form generated from reading UI file 'statisicstab.ui'
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

QT_BEGIN_NAMESPACE

class Ui_StatisicsTab
{
public:

    void setupUi(QDialog *StatisicsTab)
    {
        if (StatisicsTab->objectName().isEmpty())
            StatisicsTab->setObjectName(QString::fromUtf8("StatisicsTab"));
        StatisicsTab->resize(800, 800);
        StatisicsTab->setMinimumSize(QSize(800, 800));
        StatisicsTab->setMaximumSize(QSize(800, 800));

        retranslateUi(StatisicsTab);

        QMetaObject::connectSlotsByName(StatisicsTab);
    } // setupUi

    void retranslateUi(QDialog *StatisicsTab)
    {
        StatisicsTab->setWindowTitle(QApplication::translate("StatisicsTab", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatisicsTab: public Ui_StatisicsTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISICSTAB_H
