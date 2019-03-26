/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QFormLayout *formLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameInput;
    QLabel *passwordLabel;
    QLineEdit *passwordInput;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QPushButton *signupButton;
    QPushButton *loginButton;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(401, 250);
        verticalLayout = new QVBoxLayout(LoginDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        label = new QLabel(LoginDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(2, -1, 2, -1);
        usernameLabel = new QLabel(LoginDialog);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, usernameLabel);

        usernameInput = new QLineEdit(LoginDialog);
        usernameInput->setObjectName(QString::fromUtf8("usernameInput"));

        formLayout->setWidget(2, QFormLayout::FieldRole, usernameInput);

        passwordLabel = new QLabel(LoginDialog);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, passwordLabel);

        passwordInput = new QLineEdit(LoginDialog);
        passwordInput->setObjectName(QString::fromUtf8("passwordInput"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(passwordInput->sizePolicy().hasHeightForWidth());
        passwordInput->setSizePolicy(sizePolicy);
        passwordInput->setEchoMode(QLineEdit::Password);
        passwordInput->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(3, QFormLayout::FieldRole, passwordInput);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cancelButton = new QPushButton(LoginDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setAutoDefault(false);

        horizontalLayout->addWidget(cancelButton);

        signupButton = new QPushButton(LoginDialog);
        signupButton->setObjectName(QString::fromUtf8("signupButton"));
        signupButton->setAutoDefault(false);

        horizontalLayout->addWidget(signupButton);

        loginButton = new QPushButton(LoginDialog);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setAutoDefault(false);
        loginButton->setDefault(true);

        horizontalLayout->addWidget(loginButton);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(usernameInput, passwordInput);
        QWidget::setTabOrder(passwordInput, signupButton);
        QWidget::setTabOrder(signupButton, loginButton);
        QWidget::setTabOrder(loginButton, cancelButton);

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Log In", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LoginDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600;\">Welcome!</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        usernameLabel->setText(QApplication::translate("LoginDialog", "Username:", 0, QApplication::UnicodeUTF8));
        passwordLabel->setText(QApplication::translate("LoginDialog", "Password:", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("LoginDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        signupButton->setText(QApplication::translate("LoginDialog", "Sign Up", 0, QApplication::UnicodeUTF8));
        loginButton->setText(QApplication::translate("LoginDialog", "Login", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
