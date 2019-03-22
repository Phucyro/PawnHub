/********************************************************************************
** Form generated from reading UI file 'gameWithoutChat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWITHOUTCHAT_H
#define UI_GAMEWITHOUTCHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWithoutChat
{
public:
    QGraphicsView *graphicsView;
    QLabel *imageLabel;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QLabel *takenLabel;
    QLabel *chgTakenLabel;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout_4;
    QLabel *modeLabel;
    QLabel *chgModelabel;
    QLabel *colourLabel;
    QLabel *chgColourLabel;
    QLabel *lastMoveLabel;
    QLabel *chgLastMovelabel;
    QLabel *opponentNameLabel;
    QLabel *chgOpponentNamelabel;
    QPushButton *surrendButton;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout_2;
    QLabel *timeLabel;
    QLabel *chgTimeLabel;
    QLabel *checkUpdatelabel;
    QLabel *turnLabel;
    QWidget *formLayoutWidget_5;
    QFormLayout *formLayout_5;
    QLabel *takenEnnemyLabel;
    QLabel *chgTakenEnnemyLabel;

    void setupUi(QDialog *GameWithoutChat)
    {
        if (GameWithoutChat->objectName().isEmpty())
            GameWithoutChat->setObjectName(QString::fromUtf8("GameWithoutChat"));
        GameWithoutChat->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameWithoutChat->sizePolicy().hasHeightForWidth());
        GameWithoutChat->setSizePolicy(sizePolicy);
        GameWithoutChat->setMinimumSize(QSize(800, 600));
        GameWithoutChat->setMaximumSize(QSize(800, 800));
        graphicsView = new QGraphicsView(GameWithoutChat);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(250, 100, 400, 400));
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        imageLabel = new QLabel(GameWithoutChat);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setGeometry(QRect(20, 440, 221, 141));
        imageLabel->setPixmap(QPixmap(QString::fromUtf8(":/catmeme.jpg")));
        imageLabel->setScaledContents(true);
        formLayoutWidget_3 = new QWidget(GameWithoutChat);
        formLayoutWidget_3->setObjectName(QString::fromUtf8("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(250, 530, 401, 61));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        takenLabel = new QLabel(formLayoutWidget_3);
        takenLabel->setObjectName(QString::fromUtf8("takenLabel"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, takenLabel);

        chgTakenLabel = new QLabel(formLayoutWidget_3);
        chgTakenLabel->setObjectName(QString::fromUtf8("chgTakenLabel"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, chgTakenLabel);

        verticalLayoutWidget = new QWidget(GameWithoutChat);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 221, 401));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setHorizontalSpacing(20);
        formLayout_4->setVerticalSpacing(20);
        formLayout_4->setContentsMargins(-1, 20, -1, 20);
        modeLabel = new QLabel(verticalLayoutWidget);
        modeLabel->setObjectName(QString::fromUtf8("modeLabel"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, modeLabel);

        chgModelabel = new QLabel(verticalLayoutWidget);
        chgModelabel->setObjectName(QString::fromUtf8("chgModelabel"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, chgModelabel);

        colourLabel = new QLabel(verticalLayoutWidget);
        colourLabel->setObjectName(QString::fromUtf8("colourLabel"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, colourLabel);

        chgColourLabel = new QLabel(verticalLayoutWidget);
        chgColourLabel->setObjectName(QString::fromUtf8("chgColourLabel"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, chgColourLabel);

        lastMoveLabel = new QLabel(verticalLayoutWidget);
        lastMoveLabel->setObjectName(QString::fromUtf8("lastMoveLabel"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, lastMoveLabel);

        chgLastMovelabel = new QLabel(verticalLayoutWidget);
        chgLastMovelabel->setObjectName(QString::fromUtf8("chgLastMovelabel"));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, chgLastMovelabel);

        opponentNameLabel = new QLabel(verticalLayoutWidget);
        opponentNameLabel->setObjectName(QString::fromUtf8("opponentNameLabel"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, opponentNameLabel);

        chgOpponentNamelabel = new QLabel(verticalLayoutWidget);
        chgOpponentNamelabel->setObjectName(QString::fromUtf8("chgOpponentNamelabel"));

        formLayout_4->setWidget(3, QFormLayout::FieldRole, chgOpponentNamelabel);


        verticalLayout_2->addLayout(formLayout_4);

        surrendButton = new QPushButton(verticalLayoutWidget);
        surrendButton->setObjectName(QString::fromUtf8("surrendButton"));

        verticalLayout_2->addWidget(surrendButton);

        verticalLayoutWidget_2 = new QWidget(GameWithoutChat);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(660, 20, 131, 481));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setHorizontalSpacing(20);
        formLayout_2->setVerticalSpacing(20);
        formLayout_2->setContentsMargins(-1, 20, -1, 20);
        timeLabel = new QLabel(verticalLayoutWidget_2);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, timeLabel);

        chgTimeLabel = new QLabel(verticalLayoutWidget_2);
        chgTimeLabel->setObjectName(QString::fromUtf8("chgTimeLabel"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, chgTimeLabel);

        checkUpdatelabel = new QLabel(verticalLayoutWidget_2);
        checkUpdatelabel->setObjectName(QString::fromUtf8("checkUpdatelabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, checkUpdatelabel);

        turnLabel = new QLabel(verticalLayoutWidget_2);
        turnLabel->setObjectName(QString::fromUtf8("turnLabel"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, turnLabel);


        verticalLayout_3->addLayout(formLayout_2);

        formLayoutWidget_5 = new QWidget(GameWithoutChat);
        formLayoutWidget_5->setObjectName(QString::fromUtf8("formLayoutWidget_5"));
        formLayoutWidget_5->setGeometry(QRect(250, 30, 401, 61));
        formLayout_5 = new QFormLayout(formLayoutWidget_5);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        formLayout_5->setContentsMargins(0, 0, 0, 0);
        takenEnnemyLabel = new QLabel(formLayoutWidget_5);
        takenEnnemyLabel->setObjectName(QString::fromUtf8("takenEnnemyLabel"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, takenEnnemyLabel);

        chgTakenEnnemyLabel = new QLabel(formLayoutWidget_5);
        chgTakenEnnemyLabel->setObjectName(QString::fromUtf8("chgTakenEnnemyLabel"));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, chgTakenEnnemyLabel);


        retranslateUi(GameWithoutChat);

        QMetaObject::connectSlotsByName(GameWithoutChat);
    } // setupUi

    void retranslateUi(QDialog *GameWithoutChat)
    {
        GameWithoutChat->setWindowTitle(QApplication::translate("GameWithoutChat", "Dialog", nullptr));
        imageLabel->setText(QString());
        takenLabel->setText(QApplication::translate("GameWithoutChat", "TAKEN :", nullptr));
        chgTakenLabel->setText(QApplication::translate("GameWithoutChat", "PQBR", nullptr));
        modeLabel->setText(QApplication::translate("GameWithoutChat", "<html><head/><body><p>MODE:</p></body></html>", nullptr));
        chgModelabel->setText(QApplication::translate("GameWithoutChat", "mode", nullptr));
        colourLabel->setText(QApplication::translate("GameWithoutChat", "<html><head/><body><p>COLOUR:</p></body></html>", nullptr));
        chgColourLabel->setText(QApplication::translate("GameWithoutChat", "colour", nullptr));
        lastMoveLabel->setText(QApplication::translate("GameWithoutChat", "LAST MOVE:", nullptr));
        chgLastMovelabel->setText(QApplication::translate("GameWithoutChat", "last move", nullptr));
        opponentNameLabel->setText(QApplication::translate("GameWithoutChat", "OPPONENT NAME:", nullptr));
        chgOpponentNamelabel->setText(QApplication::translate("GameWithoutChat", "opponent", nullptr));
        surrendButton->setText(QApplication::translate("GameWithoutChat", "Surrend", nullptr));
        timeLabel->setText(QApplication::translate("GameWithoutChat", "Time:", nullptr));
        chgTimeLabel->setText(QApplication::translate("GameWithoutChat", "0:00", nullptr));
        checkUpdatelabel->setText(QApplication::translate("GameWithoutChat", "TURN:", nullptr));
        turnLabel->setText(QApplication::translate("GameWithoutChat", "Black", nullptr));
        takenEnnemyLabel->setText(QApplication::translate("GameWithoutChat", "TAKEN :", nullptr));
        chgTakenEnnemyLabel->setText(QApplication::translate("GameWithoutChat", "PQBR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWithoutChat: public Ui_GameWithoutChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWITHOUTCHAT_H
