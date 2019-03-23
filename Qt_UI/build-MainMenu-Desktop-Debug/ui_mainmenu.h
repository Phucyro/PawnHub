/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *playButton;
    QPushButton *statsButton;
    QPushButton *friendsButton;
    QPushButton *chatButton;
    QPushButton *rulesButton;
    QPushButton *quitButton;
    QPlainTextEdit *plainTextEdit;
    QLabel *adBanner;

    void setupUi(QWidget *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(504, 461);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainMenu->sizePolicy().hasHeightForWidth());
        MainMenu->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(MainMenu);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        horizontalLayout->setContentsMargins(2, -1, 2, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        playButton = new QPushButton(MainMenu);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(playButton->sizePolicy().hasHeightForWidth());
        playButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(playButton);

        statsButton = new QPushButton(MainMenu);
        statsButton->setObjectName(QString::fromUtf8("statsButton"));
        sizePolicy1.setHeightForWidth(statsButton->sizePolicy().hasHeightForWidth());
        statsButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(statsButton);

        friendsButton = new QPushButton(MainMenu);
        friendsButton->setObjectName(QString::fromUtf8("friendsButton"));
        sizePolicy1.setHeightForWidth(friendsButton->sizePolicy().hasHeightForWidth());
        friendsButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(friendsButton);

        chatButton = new QPushButton(MainMenu);
        chatButton->setObjectName(QString::fromUtf8("chatButton"));
        sizePolicy1.setHeightForWidth(chatButton->sizePolicy().hasHeightForWidth());
        chatButton->setSizePolicy(sizePolicy1);
        chatButton->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(chatButton);

        rulesButton = new QPushButton(MainMenu);
        rulesButton->setObjectName(QString::fromUtf8("rulesButton"));
        sizePolicy1.setHeightForWidth(rulesButton->sizePolicy().hasHeightForWidth());
        rulesButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(rulesButton);

        quitButton = new QPushButton(MainMenu);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        sizePolicy1.setHeightForWidth(quitButton->sizePolicy().hasHeightForWidth());
        quitButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(quitButton);


        horizontalLayout->addLayout(verticalLayout);

        plainTextEdit = new QPlainTextEdit(MainMenu);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy2);
        plainTextEdit->setReadOnly(true);
        plainTextEdit->setOverwriteMode(true);
        plainTextEdit->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout->addWidget(plainTextEdit);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);

        verticalLayout_2->addLayout(horizontalLayout);

        adBanner = new QLabel(MainMenu);
        adBanner->setObjectName(QString::fromUtf8("adBanner"));
        adBanner->setPixmap(QPixmap(QString::fromUtf8(":/Calvin.jpg")));
        adBanner->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_2->addWidget(adBanner);

        verticalLayout_2->setStretch(0, 5);
        verticalLayout_2->setStretch(1, 1);
        QWidget::setTabOrder(playButton, statsButton);
        QWidget::setTabOrder(statsButton, friendsButton);
        QWidget::setTabOrder(friendsButton, chatButton);
        QWidget::setTabOrder(chatButton, rulesButton);
        QWidget::setTabOrder(rulesButton, quitButton);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QWidget *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "Main Menu", nullptr));
        playButton->setText(QApplication::translate("MainMenu", "Play", nullptr));
        statsButton->setText(QApplication::translate("MainMenu", "Statistics", nullptr));
        friendsButton->setText(QApplication::translate("MainMenu", "Friends List", nullptr));
        chatButton->setText(QApplication::translate("MainMenu", "Chat", nullptr));
        rulesButton->setText(QApplication::translate("MainMenu", "View Rules", nullptr));
        quitButton->setText(QApplication::translate("MainMenu", "Quit", nullptr));
        plainTextEdit->setPlainText(QApplication::translate("MainMenu", "Helloooo\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"Wassup?", nullptr));
        adBanner->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
