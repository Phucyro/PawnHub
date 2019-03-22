/********************************************************************************
** Form generated from reading UI file 'connectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
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
    QLabel *hostname_label;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *hostname_input;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel_push;
    QPushButton *done_push;

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

        hostname_label = new QLabel(ConnectionDialog);
        hostname_label->setObjectName(QString::fromUtf8("hostname_label"));
        hostname_label->setLayoutDirection(Qt::LeftToRight);
        hostname_label->setAlignment(Qt::AlignCenter);
        hostname_label->setWordWrap(true);

        verticalLayout->addWidget(hostname_label);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        hostname_input = new QLineEdit(ConnectionDialog);
        hostname_input->setObjectName(QString::fromUtf8("hostname_input"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(hostname_input->sizePolicy().hasHeightForWidth());
        hostname_input->setSizePolicy(sizePolicy1);
        hostname_input->setMinimumSize(QSize(310, 20));
        hostname_input->setMaximumSize(QSize(320, 30));
        hostname_input->setLayoutDirection(Qt::LeftToRight);
        hostname_input->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        hostname_input->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        hostname_input->setClearButtonEnabled(false);

        verticalLayout->addWidget(hostname_input, 0, Qt::AlignHCenter);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancel_push = new QPushButton(ConnectionDialog);
        cancel_push->setObjectName(QString::fromUtf8("cancel_push"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cancel_push->sizePolicy().hasHeightForWidth());
        cancel_push->setSizePolicy(sizePolicy2);
        cancel_push->setAutoDefault(false);
        cancel_push->setFlat(false);

        horizontalLayout->addWidget(cancel_push);

        done_push = new QPushButton(ConnectionDialog);
        done_push->setObjectName(QString::fromUtf8("done_push"));
        sizePolicy2.setHeightForWidth(done_push->sizePolicy().hasHeightForWidth());
        done_push->setSizePolicy(sizePolicy2);
        done_push->setAutoDefault(false);

        horizontalLayout->addWidget(done_push);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(1, 1);

        retranslateUi(ConnectionDialog);

        cancel_push->setDefault(false);
        done_push->setDefault(true);


        QMetaObject::connectSlotsByName(ConnectionDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectionDialog)
    {
        ConnectionDialog->setWindowTitle(QApplication::translate("ConnectionDialog", "Connection", nullptr));
        hostname_label->setText(QApplication::translate("ConnectionDialog", "<html><head/><body><p align=\"center\">Please enter your local server's hostname:</p></body></html>", nullptr));
        cancel_push->setText(QApplication::translate("ConnectionDialog", "Cancel", nullptr));
        done_push->setText(QApplication::translate("ConnectionDialog", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectionDialog: public Ui_ConnectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONDIALOG_H
