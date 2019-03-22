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
    QPushButton *play_button;
    QPushButton *stats_button;
    QPushButton *friends_button;
    QPushButton *chat_button;
    QPushButton *rules_button;
    QPushButton *quit_button;
    QPlainTextEdit *plainTextEdit;
    QLabel *ad_banner;

    void setupUi(QWidget *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(504, 461);
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
        play_button = new QPushButton(MainMenu);
        play_button->setObjectName(QString::fromUtf8("play_button"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(play_button->sizePolicy().hasHeightForWidth());
        play_button->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(play_button);

        stats_button = new QPushButton(MainMenu);
        stats_button->setObjectName(QString::fromUtf8("stats_button"));
        sizePolicy.setHeightForWidth(stats_button->sizePolicy().hasHeightForWidth());
        stats_button->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(stats_button);

        friends_button = new QPushButton(MainMenu);
        friends_button->setObjectName(QString::fromUtf8("friends_button"));
        sizePolicy.setHeightForWidth(friends_button->sizePolicy().hasHeightForWidth());
        friends_button->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(friends_button);

        chat_button = new QPushButton(MainMenu);
        chat_button->setObjectName(QString::fromUtf8("chat_button"));
        sizePolicy.setHeightForWidth(chat_button->sizePolicy().hasHeightForWidth());
        chat_button->setSizePolicy(sizePolicy);
        chat_button->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(chat_button);

        rules_button = new QPushButton(MainMenu);
        rules_button->setObjectName(QString::fromUtf8("rules_button"));
        sizePolicy.setHeightForWidth(rules_button->sizePolicy().hasHeightForWidth());
        rules_button->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(rules_button);

        quit_button = new QPushButton(MainMenu);
        quit_button->setObjectName(QString::fromUtf8("quit_button"));
        sizePolicy.setHeightForWidth(quit_button->sizePolicy().hasHeightForWidth());
        quit_button->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(quit_button);


        horizontalLayout->addLayout(verticalLayout);

        plainTextEdit = new QPlainTextEdit(MainMenu);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy1);
        plainTextEdit->setReadOnly(true);
        plainTextEdit->setOverwriteMode(true);
        plainTextEdit->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout->addWidget(plainTextEdit);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);

        verticalLayout_2->addLayout(horizontalLayout);

        ad_banner = new QLabel(MainMenu);
        ad_banner->setObjectName(QString::fromUtf8("ad_banner"));
        ad_banner->setPixmap(QPixmap(QString::fromUtf8(":/Calvin.jpg")));
        ad_banner->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_2->addWidget(ad_banner);

        verticalLayout_2->setStretch(0, 5);
        verticalLayout_2->setStretch(1, 1);
        QWidget::setTabOrder(play_button, stats_button);
        QWidget::setTabOrder(stats_button, friends_button);
        QWidget::setTabOrder(friends_button, chat_button);
        QWidget::setTabOrder(chat_button, rules_button);
        QWidget::setTabOrder(rules_button, quit_button);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QWidget *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "Main Menu", nullptr));
        play_button->setText(QApplication::translate("MainMenu", "Play", nullptr));
        stats_button->setText(QApplication::translate("MainMenu", "Statistics", nullptr));
        friends_button->setText(QApplication::translate("MainMenu", "Friends List", nullptr));
        chat_button->setText(QApplication::translate("MainMenu", "Chat", nullptr));
        rules_button->setText(QApplication::translate("MainMenu", "View Rules", nullptr));
        quit_button->setText(QApplication::translate("MainMenu", "Quit", nullptr));
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
        ad_banner->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
