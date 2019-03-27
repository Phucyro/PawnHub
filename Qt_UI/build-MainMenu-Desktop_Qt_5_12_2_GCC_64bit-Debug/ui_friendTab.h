/********************************************************************************
** Form generated from reading UI file 'friendTab.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDTAB_H
#define UI_FRIENDTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendTab
{
public:
    QPushButton *returnPushButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *incomingRequestLabel;
    QListWidget *incomingListWidget;
    QPushButton *acceptPushButton;
    QPushButton *denyPushButton;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_1;
    QLabel *friendListLabel;
    QListWidget *friendListWidget;
    QPushButton *removePushButton;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *outgoingRequestLabel;
    QListWidget *outgoingListWidget;
    QPushButton *cancelPushButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *inputLineEdit;
    QPushButton *addPushButton;
    QPushButton *updatePushButton;
    QLabel *adsLabel;

    void setupUi(QDialog *FriendTab)
    {
        if (FriendTab->objectName().isEmpty())
            FriendTab->setObjectName(QString::fromUtf8("FriendTab"));
        FriendTab->resize(650, 600);
        FriendTab->setMinimumSize(QSize(650, 600));
        FriendTab->setMaximumSize(QSize(650, 600));
        returnPushButton = new QPushButton(FriendTab);
        returnPushButton->setObjectName(QString::fromUtf8("returnPushButton"));
        returnPushButton->setGeometry(QRect(20, 550, 80, 23));
        returnPushButton->setFocusPolicy(Qt::NoFocus);
        verticalLayoutWidget = new QWidget(FriendTab);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(429, 40, 201, 481));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        incomingRequestLabel = new QLabel(verticalLayoutWidget);
        incomingRequestLabel->setObjectName(QString::fromUtf8("incomingRequestLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        incomingRequestLabel->setFont(font);

        verticalLayout_3->addWidget(incomingRequestLabel);

        incomingListWidget = new QListWidget(verticalLayoutWidget);
        incomingListWidget->setObjectName(QString::fromUtf8("incomingListWidget"));

        verticalLayout_3->addWidget(incomingListWidget);

        acceptPushButton = new QPushButton(verticalLayoutWidget);
        acceptPushButton->setObjectName(QString::fromUtf8("acceptPushButton"));
        acceptPushButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout_3->addWidget(acceptPushButton);

        denyPushButton = new QPushButton(verticalLayoutWidget);
        denyPushButton->setObjectName(QString::fromUtf8("denyPushButton"));
        denyPushButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout_3->addWidget(denyPushButton);

        verticalLayoutWidget_2 = new QWidget(FriendTab);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(20, 41, 191, 451));
        verticalLayout_1 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_1->setObjectName(QString::fromUtf8("verticalLayout_1"));
        verticalLayout_1->setContentsMargins(0, 0, 0, 0);
        friendListLabel = new QLabel(verticalLayoutWidget_2);
        friendListLabel->setObjectName(QString::fromUtf8("friendListLabel"));
        friendListLabel->setFont(font);

        verticalLayout_1->addWidget(friendListLabel);

        friendListWidget = new QListWidget(verticalLayoutWidget_2);
        friendListWidget->setObjectName(QString::fromUtf8("friendListWidget"));

        verticalLayout_1->addWidget(friendListWidget);

        removePushButton = new QPushButton(verticalLayoutWidget_2);
        removePushButton->setObjectName(QString::fromUtf8("removePushButton"));
        removePushButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout_1->addWidget(removePushButton);

        verticalLayoutWidget_3 = new QWidget(FriendTab);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(219, 41, 201, 451));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        outgoingRequestLabel = new QLabel(verticalLayoutWidget_3);
        outgoingRequestLabel->setObjectName(QString::fromUtf8("outgoingRequestLabel"));
        outgoingRequestLabel->setFont(font);

        verticalLayout_2->addWidget(outgoingRequestLabel);

        outgoingListWidget = new QListWidget(verticalLayoutWidget_3);
        outgoingListWidget->setObjectName(QString::fromUtf8("outgoingListWidget"));

        verticalLayout_2->addWidget(outgoingListWidget);

        cancelPushButton = new QPushButton(verticalLayoutWidget_3);
        cancelPushButton->setObjectName(QString::fromUtf8("cancelPushButton"));
        cancelPushButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(cancelPushButton);

        horizontalLayoutWidget = new QWidget(FriendTab);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 490, 401, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        inputLineEdit = new QLineEdit(horizontalLayoutWidget);
        inputLineEdit->setObjectName(QString::fromUtf8("inputLineEdit"));
        inputLineEdit->setClearButtonEnabled(true);

        horizontalLayout->addWidget(inputLineEdit);

        addPushButton = new QPushButton(horizontalLayoutWidget);
        addPushButton->setObjectName(QString::fromUtf8("addPushButton"));
        addPushButton->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(addPushButton);

        updatePushButton = new QPushButton(horizontalLayoutWidget);
        updatePushButton->setObjectName(QString::fromUtf8("updatePushButton"));

        horizontalLayout->addWidget(updatePushButton);

        adsLabel = new QLabel(FriendTab);
        adsLabel->setObjectName(QString::fromUtf8("adsLabel"));
        adsLabel->setGeometry(QRect(130, 540, 501, 51));
        adsLabel->setPixmap(QPixmap(QString::fromUtf8(":/Calvin.jpg")));
        adsLabel->setScaledContents(true);

        retranslateUi(FriendTab);

        QMetaObject::connectSlotsByName(FriendTab);
    } // setupUi

    void retranslateUi(QDialog *FriendTab)
    {
        FriendTab->setWindowTitle(QApplication::translate("FriendTab", "Friends", nullptr));
        returnPushButton->setText(QApplication::translate("FriendTab", "Return", nullptr));
        incomingRequestLabel->setText(QApplication::translate("FriendTab", "Incoming Requests:", nullptr));
        acceptPushButton->setText(QApplication::translate("FriendTab", "Accept", nullptr));
        denyPushButton->setText(QApplication::translate("FriendTab", "Deny", nullptr));
        friendListLabel->setText(QApplication::translate("FriendTab", "Friend List", nullptr));
        removePushButton->setText(QApplication::translate("FriendTab", "Remove", nullptr));
        outgoingRequestLabel->setText(QApplication::translate("FriendTab", "Outgoing Requests", nullptr));
        cancelPushButton->setText(QApplication::translate("FriendTab", "Cancel", nullptr));
        addPushButton->setText(QApplication::translate("FriendTab", "Add", nullptr));
        updatePushButton->setText(QApplication::translate("FriendTab", "Update", nullptr));
        adsLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FriendTab: public Ui_FriendTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDTAB_H
