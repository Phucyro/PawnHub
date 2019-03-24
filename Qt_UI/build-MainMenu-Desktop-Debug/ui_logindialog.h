/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

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

        horizontalLayout->addWidget(loginButton);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(usernameInput, passwordInput);
        QWidget::setTabOrder(passwordInput, signupButton);
        QWidget::setTabOrder(signupButton, loginButton);
        QWidget::setTabOrder(loginButton, cancelButton);

        retranslateUi(LoginDialog);

        loginButton->setDefault(true);


        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Log In", nullptr));
        label->setText(QApplication::translate("LoginDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600;\">Welcome!</span></p></body></html>", nullptr));
        usernameLabel->setText(QApplication::translate("LoginDialog", "Username:", nullptr));
        passwordLabel->setText(QApplication::translate("LoginDialog", "Password:", nullptr));
        cancelButton->setText(QApplication::translate("LoginDialog", "Cancel", nullptr));
        signupButton->setText(QApplication::translate("LoginDialog", "Sign Up", nullptr));
        loginButton->setText(QApplication::translate("LoginDialog", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
