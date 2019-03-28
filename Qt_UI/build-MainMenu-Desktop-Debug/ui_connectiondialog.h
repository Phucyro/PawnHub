/********************************************************************************
** Form generated from reading UI file 'connectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONDIALOG_H
#define UI_CONNECTIONDIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConnectionDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *hostnameLabel;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *hostnameInput;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelPush;
    QPushButton *donePush;

    void setupUi(QDialog *ConnectionDialog)
    {
        if (ConnectionDialog->objectName().isEmpty())
            ConnectionDialog->setObjectName(QString::fromUtf8("ConnectionDialog"));
        ConnectionDialog->resize(364, 133);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ConnectionDialog->sizePolicy().hasHeightForWidth());
        ConnectionDialog->setSizePolicy(sizePolicy);
        ConnectionDialog->setLayoutDirection(Qt::LeftToRight);
        ConnectionDialog->setModal(false);
        verticalLayout_2 = new QVBoxLayout(ConnectionDialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        hostnameLabel = new QLabel(ConnectionDialog);
        hostnameLabel->setObjectName(QString::fromUtf8("hostnameLabel"));
        hostnameLabel->setLayoutDirection(Qt::LeftToRight);
        hostnameLabel->setAlignment(Qt::AlignCenter);
        hostnameLabel->setWordWrap(true);

        verticalLayout->addWidget(hostnameLabel);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        hostnameInput = new QLineEdit(ConnectionDialog);
        hostnameInput->setObjectName(QString::fromUtf8("hostnameInput"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(hostnameInput->sizePolicy().hasHeightForWidth());
        hostnameInput->setSizePolicy(sizePolicy1);
        hostnameInput->setMinimumSize(QSize(310, 20));
        hostnameInput->setMaximumSize(QSize(320, 30));
        hostnameInput->setLayoutDirection(Qt::LeftToRight);
        hostnameInput->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        hostnameInput->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        hostnameInput->setClearButtonEnabled(false);

        verticalLayout->addWidget(hostnameInput, 0, Qt::AlignHCenter);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancelPush = new QPushButton(ConnectionDialog);
        cancelPush->setObjectName(QString::fromUtf8("cancelPush"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cancelPush->sizePolicy().hasHeightForWidth());
        cancelPush->setSizePolicy(sizePolicy2);
        cancelPush->setAutoDefault(false);
        cancelPush->setFlat(false);

        horizontalLayout->addWidget(cancelPush);

        donePush = new QPushButton(ConnectionDialog);
        donePush->setObjectName(QString::fromUtf8("donePush"));
        sizePolicy2.setHeightForWidth(donePush->sizePolicy().hasHeightForWidth());
        donePush->setSizePolicy(sizePolicy2);
        donePush->setAutoDefault(false);

        horizontalLayout->addWidget(donePush);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(1, 1);

        retranslateUi(ConnectionDialog);

        cancelPush->setDefault(false);
        donePush->setDefault(true);


        QMetaObject::connectSlotsByName(ConnectionDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectionDialog)
    {
        ConnectionDialog->setWindowTitle(QApplication::translate("ConnectionDialog", "Connection", nullptr));
        hostnameLabel->setText(QApplication::translate("ConnectionDialog", "<html><head/><body><p align=\"center\">Please enter your local server's hostname:</p></body></html>", nullptr));
        cancelPush->setText(QApplication::translate("ConnectionDialog", "Cancel", nullptr));
        donePush->setText(QApplication::translate("ConnectionDialog", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectionDialog: public Ui_ConnectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONDIALOG_H
