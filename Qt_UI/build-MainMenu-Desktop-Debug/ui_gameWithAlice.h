/********************************************************************************
** Form generated from reading UI file 'gameWithAlice.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWITHALICE_H
#define UI_GAMEWITHALICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWithAlice
{
public:
    QGraphicsView *boardView;
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
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *chatText;
    QHBoxLayout *horizontalLayout;
    QLineEdit *sendingTextField;
    QPushButton *sendPushButton;
    QGraphicsView *boardView2;

    void setupUi(QDialog *GameWithAlice)
    {
        if (GameWithAlice->objectName().isEmpty())
            GameWithAlice->setObjectName(QString::fromUtf8("GameWithAlice"));
        GameWithAlice->resize(1200, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameWithAlice->sizePolicy().hasHeightForWidth());
        GameWithAlice->setSizePolicy(sizePolicy);
        GameWithAlice->setMinimumSize(QSize(1200, 600));
        GameWithAlice->setMaximumSize(QSize(1200, 800));
        boardView = new QGraphicsView(GameWithAlice);
        boardView->setObjectName(QString::fromUtf8("boardView"));
        boardView->setGeometry(QRect(230, 80, 400, 400));
        sizePolicy.setHeightForWidth(boardView->sizePolicy().hasHeightForWidth());
        boardView->setSizePolicy(sizePolicy);
        imageLabel = new QLabel(GameWithAlice);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setGeometry(QRect(10, 400, 201, 141));
        imageLabel->setPixmap(QPixmap(QString::fromUtf8(":/catmeme.jpg")));
        imageLabel->setScaledContents(true);
        formLayoutWidget_3 = new QWidget(GameWithAlice);
        formLayoutWidget_3->setObjectName(QString::fromUtf8("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(230, 490, 401, 61));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        takenLabel = new QLabel(formLayoutWidget_3);
        takenLabel->setObjectName(QString::fromUtf8("takenLabel"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, takenLabel);

        chgTakenLabel = new QLabel(formLayoutWidget_3);
        chgTakenLabel->setObjectName(QString::fromUtf8("chgTakenLabel"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, chgTakenLabel);

        verticalLayoutWidget = new QWidget(GameWithAlice);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 80, 201, 311));
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

        verticalLayoutWidget_2 = new QWidget(GameWithAlice);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(1050, 80, 101, 401));
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

        formLayoutWidget_5 = new QWidget(GameWithAlice);
        formLayoutWidget_5->setObjectName(QString::fromUtf8("formLayoutWidget_5"));
        formLayoutWidget_5->setGeometry(QRect(230, 10, 401, 61));
        formLayout_5 = new QFormLayout(formLayoutWidget_5);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        formLayout_5->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout_5->setFormAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        formLayout_5->setContentsMargins(0, 0, 0, 0);
        takenEnnemyLabel = new QLabel(formLayoutWidget_5);
        takenEnnemyLabel->setObjectName(QString::fromUtf8("takenEnnemyLabel"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, takenEnnemyLabel);

        chgTakenEnnemyLabel = new QLabel(formLayoutWidget_5);
        chgTakenEnnemyLabel->setObjectName(QString::fromUtf8("chgTakenEnnemyLabel"));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, chgTakenEnnemyLabel);

        verticalLayoutWidget_3 = new QWidget(GameWithAlice);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(640, 490, 401, 101));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        chatText = new QPlainTextEdit(verticalLayoutWidget_3);
        chatText->setObjectName(QString::fromUtf8("chatText"));
        chatText->setReadOnly(true);

        verticalLayout->addWidget(chatText);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        sendingTextField = new QLineEdit(verticalLayoutWidget_3);
        sendingTextField->setObjectName(QString::fromUtf8("sendingTextField"));

        horizontalLayout->addWidget(sendingTextField);

        sendPushButton = new QPushButton(verticalLayoutWidget_3);
        sendPushButton->setObjectName(QString::fromUtf8("sendPushButton"));

        horizontalLayout->addWidget(sendPushButton);


        verticalLayout->addLayout(horizontalLayout);

        boardView2 = new QGraphicsView(GameWithAlice);
        boardView2->setObjectName(QString::fromUtf8("boardView2"));
        boardView2->setGeometry(QRect(640, 80, 400, 400));
        sizePolicy.setHeightForWidth(boardView2->sizePolicy().hasHeightForWidth());
        boardView2->setSizePolicy(sizePolicy);

        retranslateUi(GameWithAlice);

        QMetaObject::connectSlotsByName(GameWithAlice);
    } // setupUi

    void retranslateUi(QDialog *GameWithAlice)
    {
        GameWithAlice->setWindowTitle(QApplication::translate("GameWithAlice", "Dialog", nullptr));
        imageLabel->setText(QString());
        takenLabel->setText(QApplication::translate("GameWithAlice", "TAKEN :", nullptr));
        chgTakenLabel->setText(QApplication::translate("GameWithAlice", "PQBR", nullptr));
        modeLabel->setText(QApplication::translate("GameWithAlice", "<html><head/><body><p>MODE:</p></body></html>", nullptr));
        chgModelabel->setText(QApplication::translate("GameWithAlice", "mode", nullptr));
        colourLabel->setText(QApplication::translate("GameWithAlice", "<html><head/><body><p>COLOUR:</p></body></html>", nullptr));
        chgColourLabel->setText(QApplication::translate("GameWithAlice", "colour", nullptr));
        lastMoveLabel->setText(QApplication::translate("GameWithAlice", "LAST MOVE:", nullptr));
        chgLastMovelabel->setText(QApplication::translate("GameWithAlice", "last move", nullptr));
        opponentNameLabel->setText(QApplication::translate("GameWithAlice", "OPPONENT NAME:", nullptr));
        chgOpponentNamelabel->setText(QApplication::translate("GameWithAlice", "opponent", nullptr));
        surrendButton->setText(QApplication::translate("GameWithAlice", "Surrend", nullptr));
        timeLabel->setText(QApplication::translate("GameWithAlice", "Time:", nullptr));
        chgTimeLabel->setText(QApplication::translate("GameWithAlice", "0:00", nullptr));
        checkUpdatelabel->setText(QApplication::translate("GameWithAlice", "TURN:", nullptr));
        turnLabel->setText(QApplication::translate("GameWithAlice", "Black", nullptr));
        takenEnnemyLabel->setText(QApplication::translate("GameWithAlice", "TAKEN :", nullptr));
        chgTakenEnnemyLabel->setText(QApplication::translate("GameWithAlice", "PQBR", nullptr));
        sendPushButton->setText(QApplication::translate("GameWithAlice", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWithAlice: public Ui_GameWithAlice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWITHALICE_H
