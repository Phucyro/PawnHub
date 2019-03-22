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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancel_button;
    QPushButton *signup_button;
    QPushButton *login_button;
    QWidget *layoutWidget1;
    QFormLayout *formLayout;
    QLabel *username_label;
    QLineEdit *username_edit;
    QLabel *password_label;
    QLineEdit *password_edit;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(401, 250);
        label = new QLabel(LoginDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 20, 101, 31));
        layoutWidget = new QWidget(LoginDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 210, 361, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        cancel_button = new QPushButton(layoutWidget);
        cancel_button->setObjectName(QString::fromUtf8("cancel_button"));
        cancel_button->setAutoDefault(false);

        horizontalLayout->addWidget(cancel_button);

        signup_button = new QPushButton(layoutWidget);
        signup_button->setObjectName(QString::fromUtf8("signup_button"));
        signup_button->setAutoDefault(false);

        horizontalLayout->addWidget(signup_button);

        login_button = new QPushButton(layoutWidget);
        login_button->setObjectName(QString::fromUtf8("login_button"));
        login_button->setAutoDefault(false);

        horizontalLayout->addWidget(login_button);

        layoutWidget1 = new QWidget(LoginDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(60, 90, 281, 58));
        formLayout = new QFormLayout(layoutWidget1);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        username_label = new QLabel(layoutWidget1);
        username_label->setObjectName(QString::fromUtf8("username_label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, username_label);

        username_edit = new QLineEdit(layoutWidget1);
        username_edit->setObjectName(QString::fromUtf8("username_edit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, username_edit);

        password_label = new QLabel(layoutWidget1);
        password_label->setObjectName(QString::fromUtf8("password_label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, password_label);

        password_edit = new QLineEdit(layoutWidget1);
        password_edit->setObjectName(QString::fromUtf8("password_edit"));
        password_edit->setEchoMode(QLineEdit::Password);
        password_edit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::FieldRole, password_edit);

        QWidget::setTabOrder(username_edit, password_edit);
        QWidget::setTabOrder(password_edit, signup_button);
        QWidget::setTabOrder(signup_button, login_button);
        QWidget::setTabOrder(login_button, cancel_button);

        retranslateUi(LoginDialog);

        login_button->setDefault(true);


        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Log In", nullptr));
        label->setText(QApplication::translate("LoginDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600;\">Welcome!</span></p></body></html>", nullptr));
        cancel_button->setText(QApplication::translate("LoginDialog", "Cancel", nullptr));
        signup_button->setText(QApplication::translate("LoginDialog", "Sign Up", nullptr));
        login_button->setText(QApplication::translate("LoginDialog", "Login", nullptr));
        username_label->setText(QApplication::translate("LoginDialog", "Username:", nullptr));
        password_label->setText(QApplication::translate("LoginDialog", "Password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
