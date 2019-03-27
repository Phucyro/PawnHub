/********************************************************************************
** Form generated from reading UI file 'passwordrepeat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDREPEAT_H
#define UI_PASSWORDREPEAT_H

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

class Ui_PasswordRepeat
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *passwordInput;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QPushButton *doneButton;

    void setupUi(QDialog *PasswordRepeat)
    {
        if (PasswordRepeat->objectName().isEmpty())
            PasswordRepeat->setObjectName(QString::fromUtf8("PasswordRepeat"));
        PasswordRepeat->resize(309, 128);
        verticalLayout_2 = new QVBoxLayout(PasswordRepeat);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label = new QLabel(PasswordRepeat);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        passwordInput = new QLineEdit(PasswordRepeat);
        passwordInput->setObjectName(QString::fromUtf8("passwordInput"));
        passwordInput->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(passwordInput);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancelButton = new QPushButton(PasswordRepeat);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(cancelButton);

        doneButton = new QPushButton(PasswordRepeat);
        doneButton->setObjectName(QString::fromUtf8("doneButton"));
        sizePolicy.setHeightForWidth(doneButton->sizePolicy().hasHeightForWidth());
        doneButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(doneButton);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(1, 1);
        QWidget::setTabOrder(passwordInput, cancelButton);
        QWidget::setTabOrder(cancelButton, doneButton);

        retranslateUi(PasswordRepeat);
        QObject::connect(passwordInput, SIGNAL(returnPressed()), doneButton, SLOT(click()));

        QMetaObject::connectSlotsByName(PasswordRepeat);
    } // setupUi

    void retranslateUi(QDialog *PasswordRepeat)
    {
        PasswordRepeat->setWindowTitle(QApplication::translate("PasswordRepeat", "Checking Password", nullptr));
        label->setText(QApplication::translate("PasswordRepeat", "Please type your password a second time:", nullptr));
        cancelButton->setText(QApplication::translate("PasswordRepeat", "Cancel", nullptr));
        doneButton->setText(QApplication::translate("PasswordRepeat", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PasswordRepeat: public Ui_PasswordRepeat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDREPEAT_H
