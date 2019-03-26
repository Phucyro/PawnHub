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
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
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
    QLabel *chgModeLabel;
    QLabel *colourLabel;
    QLabel *chgColourLabel;
    QLabel *lastMoveLabel;
    QLabel *chgLastMoveLabel;
    QLabel *opponentNameLabel;
    QLabel *chgOpponentNameLabel;
    QPushButton *surrendButton;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout_2;
    QLabel *timeLabel;
    QLabel *chgTimeLabel;
    QLabel *checkUpdateLabel;
    QLabel *turnLabel;
    QWidget *formLayoutWidget_5;
    QFormLayout *formLayout_5;
    QLabel *takenEnnemyLabel;
    QLabel *chgTakenEnnemyLabel;
    QPushButton *a1PushButton;
    QPushButton *a3PushButton;
    QPushButton *a2PushButton;
    QPushButton *a5PushButton;
    QPushButton *a4PushButton;
    QPushButton *a7PushButton;
    QPushButton *a6PushButton;
    QPushButton *a8PushButton;
    QPushButton *b8PushButton;
    QPushButton *b5PushButton;
    QPushButton *b6PushButton;
    QPushButton *b4PushButton;
    QPushButton *b7PushButton;
    QPushButton *b1PushButton;
    QPushButton *b2PushButton;
    QPushButton *b3PushButton;
    QPushButton *c7PushButton;
    QPushButton *d3PushButton;
    QPushButton *d2PushButton;
    QPushButton *c4PushButton;
    QPushButton *d1PushButton;
    QPushButton *c5PushButton;
    QPushButton *d5PushButton;
    QPushButton *c1PushButton;
    QPushButton *c8PushButton;
    QPushButton *d8PushButton;
    QPushButton *c3PushButton;
    QPushButton *d6PushButton;
    QPushButton *c6PushButton;
    QPushButton *d4PushButton;
    QPushButton *d7PushButton;
    QPushButton *c2PushButton;
    QPushButton *e2PushButton;
    QPushButton *e3PushButton;
    QPushButton *e7PushButton;
    QPushButton *g3PushButton;
    QPushButton *f8PushButton;
    QPushButton *f7PushButton;
    QPushButton *e4PushButton;
    QPushButton *g6PushButton;
    QPushButton *h2PushButton;
    QPushButton *e5PushButton;
    QPushButton *g5PushButton;
    QPushButton *h4PushButton;
    QPushButton *f6PushButton;
    QPushButton *f1PushButton;
    QPushButton *g2PushButton;
    QPushButton *e6PushButton;
    QPushButton *h1PushButton;
    QPushButton *f4PushButton;
    QPushButton *g4PushButton;
    QPushButton *f3PushButton;
    QPushButton *h7PushButton;
    QPushButton *e8PushButton;
    QPushButton *g7PushButton;
    QPushButton *h5PushButton;
    QPushButton *g8PushButton;
    QPushButton *h8PushButton;
    QPushButton *h3PushButton;
    QPushButton *e1PushButton;
    QPushButton *f2PushButton;
    QPushButton *g1PushButton;
    QPushButton *f5PushButton;
    QPushButton *h6PushButton;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_1;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_A;
    QLabel *label_B;
    QLabel *label_C;
    QLabel *label_D;
    QLabel *label_E;
    QLabel *label_F;
    QLabel *label_G;
    QLabel *label_H;
    QButtonGroup *board;

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

        chgModeLabel = new QLabel(verticalLayoutWidget);
        chgModeLabel->setObjectName(QString::fromUtf8("chgModeLabel"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, chgModeLabel);

        colourLabel = new QLabel(verticalLayoutWidget);
        colourLabel->setObjectName(QString::fromUtf8("colourLabel"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, colourLabel);

        chgColourLabel = new QLabel(verticalLayoutWidget);
        chgColourLabel->setObjectName(QString::fromUtf8("chgColourLabel"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, chgColourLabel);

        lastMoveLabel = new QLabel(verticalLayoutWidget);
        lastMoveLabel->setObjectName(QString::fromUtf8("lastMoveLabel"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, lastMoveLabel);

        chgLastMoveLabel = new QLabel(verticalLayoutWidget);
        chgLastMoveLabel->setObjectName(QString::fromUtf8("chgLastMoveLabel"));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, chgLastMoveLabel);

        opponentNameLabel = new QLabel(verticalLayoutWidget);
        opponentNameLabel->setObjectName(QString::fromUtf8("opponentNameLabel"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, opponentNameLabel);

        chgOpponentNameLabel = new QLabel(verticalLayoutWidget);
        chgOpponentNameLabel->setObjectName(QString::fromUtf8("chgOpponentNameLabel"));

        formLayout_4->setWidget(3, QFormLayout::FieldRole, chgOpponentNameLabel);


        verticalLayout_2->addLayout(formLayout_4);

        surrendButton = new QPushButton(verticalLayoutWidget);
        surrendButton->setObjectName(QString::fromUtf8("surrendButton"));

        verticalLayout_2->addWidget(surrendButton);

        verticalLayoutWidget_2 = new QWidget(GameWithoutChat);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(680, 20, 111, 481));
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

        checkUpdateLabel = new QLabel(verticalLayoutWidget_2);
        checkUpdateLabel->setObjectName(QString::fromUtf8("checkUpdateLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, checkUpdateLabel);

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

        a1PushButton = new QPushButton(GameWithoutChat);
        board = new QButtonGroup(GameWithoutChat);
        board->setObjectName(QString::fromUtf8("board"));
        board->setExclusive(true);
        board->addButton(a1PushButton);
        a1PushButton->setObjectName(QString::fromUtf8("a1PushButton"));
        a1PushButton->setEnabled(false);
        a1PushButton->setGeometry(QRect(250, 450, 50, 50));
        a1PushButton->setMinimumSize(QSize(50, 50));
        a1PushButton->setMaximumSize(QSize(50, 50));
        a1PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        a1PushButton->setIconSize(QSize(36, 36));
        a1PushButton->setFlat(false);
        a3PushButton = new QPushButton(GameWithoutChat);
        board->addButton(a3PushButton);
        a3PushButton->setObjectName(QString::fromUtf8("a3PushButton"));
        a3PushButton->setEnabled(false);
        a3PushButton->setGeometry(QRect(250, 350, 50, 50));
        a3PushButton->setMinimumSize(QSize(50, 50));
        a3PushButton->setMaximumSize(QSize(50, 50));
        a3PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        a3PushButton->setIconSize(QSize(36, 36));
        a2PushButton = new QPushButton(GameWithoutChat);
        board->addButton(a2PushButton);
        a2PushButton->setObjectName(QString::fromUtf8("a2PushButton"));
        a2PushButton->setEnabled(false);
        a2PushButton->setGeometry(QRect(250, 400, 50, 50));
        a2PushButton->setMinimumSize(QSize(50, 50));
        a2PushButton->setMaximumSize(QSize(50, 50));
        a2PushButton->setStyleSheet(QString::fromUtf8(""));
        a2PushButton->setIconSize(QSize(36, 36));
        a5PushButton = new QPushButton(GameWithoutChat);
        board->addButton(a5PushButton);
        a5PushButton->setObjectName(QString::fromUtf8("a5PushButton"));
        a5PushButton->setEnabled(false);
        a5PushButton->setGeometry(QRect(250, 250, 50, 50));
        a5PushButton->setMinimumSize(QSize(50, 50));
        a5PushButton->setMaximumSize(QSize(50, 50));
        a5PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        a5PushButton->setIconSize(QSize(36, 36));
        a4PushButton = new QPushButton(GameWithoutChat);
        board->addButton(a4PushButton);
        a4PushButton->setObjectName(QString::fromUtf8("a4PushButton"));
        a4PushButton->setEnabled(false);
        a4PushButton->setGeometry(QRect(250, 300, 50, 50));
        a4PushButton->setMinimumSize(QSize(50, 50));
        a4PushButton->setMaximumSize(QSize(50, 50));
        a4PushButton->setStyleSheet(QString::fromUtf8(""));
        a4PushButton->setIconSize(QSize(36, 36));
        a7PushButton = new QPushButton(GameWithoutChat);
        board->addButton(a7PushButton);
        a7PushButton->setObjectName(QString::fromUtf8("a7PushButton"));
        a7PushButton->setEnabled(false);
        a7PushButton->setGeometry(QRect(250, 150, 50, 50));
        a7PushButton->setMinimumSize(QSize(50, 50));
        a7PushButton->setMaximumSize(QSize(50, 50));
        a7PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        a7PushButton->setIconSize(QSize(36, 36));
        a6PushButton = new QPushButton(GameWithoutChat);
        board->addButton(a6PushButton);
        a6PushButton->setObjectName(QString::fromUtf8("a6PushButton"));
        a6PushButton->setEnabled(false);
        a6PushButton->setGeometry(QRect(250, 200, 50, 50));
        a6PushButton->setMinimumSize(QSize(50, 50));
        a6PushButton->setMaximumSize(QSize(50, 50));
        a6PushButton->setStyleSheet(QString::fromUtf8(""));
        a6PushButton->setIconSize(QSize(36, 36));
        a8PushButton = new QPushButton(GameWithoutChat);
        board->addButton(a8PushButton);
        a8PushButton->setObjectName(QString::fromUtf8("a8PushButton"));
        a8PushButton->setEnabled(false);
        a8PushButton->setGeometry(QRect(250, 100, 50, 50));
        a8PushButton->setMinimumSize(QSize(50, 50));
        a8PushButton->setMaximumSize(QSize(50, 50));
        a8PushButton->setStyleSheet(QString::fromUtf8(""));
        a8PushButton->setIconSize(QSize(36, 36));
        b8PushButton = new QPushButton(GameWithoutChat);
        board->addButton(b8PushButton);
        b8PushButton->setObjectName(QString::fromUtf8("b8PushButton"));
        b8PushButton->setEnabled(false);
        b8PushButton->setGeometry(QRect(300, 100, 50, 50));
        b8PushButton->setMinimumSize(QSize(50, 50));
        b8PushButton->setMaximumSize(QSize(50, 50));
        b8PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        b8PushButton->setIconSize(QSize(36, 36));
        b5PushButton = new QPushButton(GameWithoutChat);
        board->addButton(b5PushButton);
        b5PushButton->setObjectName(QString::fromUtf8("b5PushButton"));
        b5PushButton->setEnabled(false);
        b5PushButton->setGeometry(QRect(300, 250, 50, 50));
        b5PushButton->setMinimumSize(QSize(50, 50));
        b5PushButton->setMaximumSize(QSize(50, 50));
        b5PushButton->setStyleSheet(QString::fromUtf8(""));
        b5PushButton->setIconSize(QSize(36, 36));
        b6PushButton = new QPushButton(GameWithoutChat);
        board->addButton(b6PushButton);
        b6PushButton->setObjectName(QString::fromUtf8("b6PushButton"));
        b6PushButton->setEnabled(false);
        b6PushButton->setGeometry(QRect(300, 200, 50, 50));
        b6PushButton->setMinimumSize(QSize(50, 50));
        b6PushButton->setMaximumSize(QSize(50, 50));
        b6PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        b6PushButton->setIconSize(QSize(36, 36));
        b4PushButton = new QPushButton(GameWithoutChat);
        board->addButton(b4PushButton);
        b4PushButton->setObjectName(QString::fromUtf8("b4PushButton"));
        b4PushButton->setEnabled(false);
        b4PushButton->setGeometry(QRect(300, 300, 50, 50));
        b4PushButton->setMinimumSize(QSize(50, 50));
        b4PushButton->setMaximumSize(QSize(50, 50));
        b4PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        b4PushButton->setIconSize(QSize(36, 36));
        b7PushButton = new QPushButton(GameWithoutChat);
        board->addButton(b7PushButton);
        b7PushButton->setObjectName(QString::fromUtf8("b7PushButton"));
        b7PushButton->setEnabled(false);
        b7PushButton->setGeometry(QRect(300, 150, 50, 50));
        b7PushButton->setMinimumSize(QSize(50, 50));
        b7PushButton->setMaximumSize(QSize(50, 50));
        b7PushButton->setStyleSheet(QString::fromUtf8(""));
        b7PushButton->setIconSize(QSize(36, 36));
        b1PushButton = new QPushButton(GameWithoutChat);
        board->addButton(b1PushButton);
        b1PushButton->setObjectName(QString::fromUtf8("b1PushButton"));
        b1PushButton->setEnabled(false);
        b1PushButton->setGeometry(QRect(300, 450, 50, 50));
        b1PushButton->setMinimumSize(QSize(50, 50));
        b1PushButton->setMaximumSize(QSize(50, 50));
        b1PushButton->setStyleSheet(QString::fromUtf8(""));
        b1PushButton->setIconSize(QSize(36, 36));
        b2PushButton = new QPushButton(GameWithoutChat);
        board->addButton(b2PushButton);
        b2PushButton->setObjectName(QString::fromUtf8("b2PushButton"));
        b2PushButton->setEnabled(false);
        b2PushButton->setGeometry(QRect(300, 400, 50, 50));
        b2PushButton->setMinimumSize(QSize(50, 50));
        b2PushButton->setMaximumSize(QSize(50, 50));
        b2PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        b2PushButton->setIconSize(QSize(36, 36));
        b3PushButton = new QPushButton(GameWithoutChat);
        board->addButton(b3PushButton);
        b3PushButton->setObjectName(QString::fromUtf8("b3PushButton"));
        b3PushButton->setEnabled(false);
        b3PushButton->setGeometry(QRect(300, 350, 50, 50));
        b3PushButton->setMinimumSize(QSize(50, 50));
        b3PushButton->setMaximumSize(QSize(50, 50));
        b3PushButton->setStyleSheet(QString::fromUtf8(""));
        b3PushButton->setIconSize(QSize(36, 36));
        c7PushButton = new QPushButton(GameWithoutChat);
        board->addButton(c7PushButton);
        c7PushButton->setObjectName(QString::fromUtf8("c7PushButton"));
        c7PushButton->setEnabled(false);
        c7PushButton->setGeometry(QRect(350, 150, 50, 50));
        c7PushButton->setMinimumSize(QSize(50, 50));
        c7PushButton->setMaximumSize(QSize(50, 50));
        c7PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        c7PushButton->setIconSize(QSize(36, 36));
        d3PushButton = new QPushButton(GameWithoutChat);
        board->addButton(d3PushButton);
        d3PushButton->setObjectName(QString::fromUtf8("d3PushButton"));
        d3PushButton->setEnabled(false);
        d3PushButton->setGeometry(QRect(400, 350, 50, 50));
        d3PushButton->setMinimumSize(QSize(50, 50));
        d3PushButton->setMaximumSize(QSize(50, 50));
        d3PushButton->setStyleSheet(QString::fromUtf8(""));
        d3PushButton->setIconSize(QSize(36, 36));
        d2PushButton = new QPushButton(GameWithoutChat);
        board->addButton(d2PushButton);
        d2PushButton->setObjectName(QString::fromUtf8("d2PushButton"));
        d2PushButton->setEnabled(false);
        d2PushButton->setGeometry(QRect(400, 400, 50, 50));
        d2PushButton->setMinimumSize(QSize(50, 50));
        d2PushButton->setMaximumSize(QSize(50, 50));
        d2PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        d2PushButton->setIconSize(QSize(36, 36));
        c4PushButton = new QPushButton(GameWithoutChat);
        board->addButton(c4PushButton);
        c4PushButton->setObjectName(QString::fromUtf8("c4PushButton"));
        c4PushButton->setEnabled(false);
        c4PushButton->setGeometry(QRect(350, 300, 50, 50));
        c4PushButton->setMinimumSize(QSize(50, 50));
        c4PushButton->setMaximumSize(QSize(50, 50));
        c4PushButton->setStyleSheet(QString::fromUtf8(""));
        c4PushButton->setIconSize(QSize(36, 36));
        d1PushButton = new QPushButton(GameWithoutChat);
        board->addButton(d1PushButton);
        d1PushButton->setObjectName(QString::fromUtf8("d1PushButton"));
        d1PushButton->setEnabled(false);
        d1PushButton->setGeometry(QRect(400, 450, 50, 50));
        d1PushButton->setMinimumSize(QSize(50, 50));
        d1PushButton->setMaximumSize(QSize(50, 50));
        d1PushButton->setStyleSheet(QString::fromUtf8(""));
        d1PushButton->setIconSize(QSize(36, 36));
        c5PushButton = new QPushButton(GameWithoutChat);
        board->addButton(c5PushButton);
        c5PushButton->setObjectName(QString::fromUtf8("c5PushButton"));
        c5PushButton->setEnabled(false);
        c5PushButton->setGeometry(QRect(350, 250, 50, 50));
        c5PushButton->setMinimumSize(QSize(50, 50));
        c5PushButton->setMaximumSize(QSize(50, 50));
        c5PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        c5PushButton->setIconSize(QSize(36, 36));
        d5PushButton = new QPushButton(GameWithoutChat);
        board->addButton(d5PushButton);
        d5PushButton->setObjectName(QString::fromUtf8("d5PushButton"));
        d5PushButton->setEnabled(false);
        d5PushButton->setGeometry(QRect(400, 250, 50, 50));
        d5PushButton->setMinimumSize(QSize(50, 50));
        d5PushButton->setMaximumSize(QSize(50, 50));
        d5PushButton->setStyleSheet(QString::fromUtf8(""));
        d5PushButton->setIconSize(QSize(36, 36));
        c1PushButton = new QPushButton(GameWithoutChat);
        board->addButton(c1PushButton);
        c1PushButton->setObjectName(QString::fromUtf8("c1PushButton"));
        c1PushButton->setEnabled(false);
        c1PushButton->setGeometry(QRect(350, 450, 50, 50));
        c1PushButton->setMinimumSize(QSize(50, 50));
        c1PushButton->setMaximumSize(QSize(50, 50));
        c1PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        c1PushButton->setIconSize(QSize(36, 36));
        c8PushButton = new QPushButton(GameWithoutChat);
        board->addButton(c8PushButton);
        c8PushButton->setObjectName(QString::fromUtf8("c8PushButton"));
        c8PushButton->setEnabled(false);
        c8PushButton->setGeometry(QRect(350, 100, 50, 50));
        c8PushButton->setMinimumSize(QSize(50, 50));
        c8PushButton->setMaximumSize(QSize(50, 50));
        c8PushButton->setStyleSheet(QString::fromUtf8(""));
        c8PushButton->setIconSize(QSize(36, 36));
        d8PushButton = new QPushButton(GameWithoutChat);
        board->addButton(d8PushButton);
        d8PushButton->setObjectName(QString::fromUtf8("d8PushButton"));
        d8PushButton->setEnabled(false);
        d8PushButton->setGeometry(QRect(400, 100, 50, 50));
        d8PushButton->setMinimumSize(QSize(50, 50));
        d8PushButton->setMaximumSize(QSize(50, 50));
        d8PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        d8PushButton->setIconSize(QSize(36, 36));
        c3PushButton = new QPushButton(GameWithoutChat);
        board->addButton(c3PushButton);
        c3PushButton->setObjectName(QString::fromUtf8("c3PushButton"));
        c3PushButton->setEnabled(false);
        c3PushButton->setGeometry(QRect(350, 350, 50, 50));
        c3PushButton->setMinimumSize(QSize(50, 50));
        c3PushButton->setMaximumSize(QSize(50, 50));
        c3PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        c3PushButton->setIconSize(QSize(36, 36));
        d6PushButton = new QPushButton(GameWithoutChat);
        board->addButton(d6PushButton);
        d6PushButton->setObjectName(QString::fromUtf8("d6PushButton"));
        d6PushButton->setEnabled(false);
        d6PushButton->setGeometry(QRect(400, 200, 50, 50));
        d6PushButton->setMinimumSize(QSize(50, 50));
        d6PushButton->setMaximumSize(QSize(50, 50));
        d6PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        d6PushButton->setIconSize(QSize(36, 36));
        c6PushButton = new QPushButton(GameWithoutChat);
        board->addButton(c6PushButton);
        c6PushButton->setObjectName(QString::fromUtf8("c6PushButton"));
        c6PushButton->setEnabled(false);
        c6PushButton->setGeometry(QRect(350, 200, 50, 50));
        c6PushButton->setMinimumSize(QSize(50, 50));
        c6PushButton->setMaximumSize(QSize(50, 50));
        c6PushButton->setStyleSheet(QString::fromUtf8(""));
        c6PushButton->setIconSize(QSize(36, 36));
        d4PushButton = new QPushButton(GameWithoutChat);
        board->addButton(d4PushButton);
        d4PushButton->setObjectName(QString::fromUtf8("d4PushButton"));
        d4PushButton->setEnabled(false);
        d4PushButton->setGeometry(QRect(400, 300, 50, 50));
        d4PushButton->setMinimumSize(QSize(50, 50));
        d4PushButton->setMaximumSize(QSize(50, 50));
        d4PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        d4PushButton->setIconSize(QSize(36, 36));
        d7PushButton = new QPushButton(GameWithoutChat);
        board->addButton(d7PushButton);
        d7PushButton->setObjectName(QString::fromUtf8("d7PushButton"));
        d7PushButton->setEnabled(false);
        d7PushButton->setGeometry(QRect(400, 150, 50, 50));
        d7PushButton->setMinimumSize(QSize(50, 50));
        d7PushButton->setMaximumSize(QSize(50, 50));
        d7PushButton->setStyleSheet(QString::fromUtf8(""));
        d7PushButton->setIconSize(QSize(36, 36));
        c2PushButton = new QPushButton(GameWithoutChat);
        board->addButton(c2PushButton);
        c2PushButton->setObjectName(QString::fromUtf8("c2PushButton"));
        c2PushButton->setEnabled(false);
        c2PushButton->setGeometry(QRect(350, 400, 50, 50));
        c2PushButton->setMinimumSize(QSize(50, 50));
        c2PushButton->setMaximumSize(QSize(50, 50));
        c2PushButton->setStyleSheet(QString::fromUtf8(""));
        c2PushButton->setIconSize(QSize(36, 36));
        e2PushButton = new QPushButton(GameWithoutChat);
        board->addButton(e2PushButton);
        e2PushButton->setObjectName(QString::fromUtf8("e2PushButton"));
        e2PushButton->setEnabled(false);
        e2PushButton->setGeometry(QRect(450, 400, 50, 50));
        e2PushButton->setMinimumSize(QSize(50, 50));
        e2PushButton->setMaximumSize(QSize(50, 50));
        e2PushButton->setStyleSheet(QString::fromUtf8(""));
        e2PushButton->setIconSize(QSize(36, 36));
        e3PushButton = new QPushButton(GameWithoutChat);
        board->addButton(e3PushButton);
        e3PushButton->setObjectName(QString::fromUtf8("e3PushButton"));
        e3PushButton->setEnabled(false);
        e3PushButton->setGeometry(QRect(450, 350, 50, 50));
        e3PushButton->setMinimumSize(QSize(50, 50));
        e3PushButton->setMaximumSize(QSize(50, 50));
        e3PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        e3PushButton->setIconSize(QSize(36, 36));
        e7PushButton = new QPushButton(GameWithoutChat);
        board->addButton(e7PushButton);
        e7PushButton->setObjectName(QString::fromUtf8("e7PushButton"));
        e7PushButton->setEnabled(false);
        e7PushButton->setGeometry(QRect(450, 150, 50, 50));
        e7PushButton->setMinimumSize(QSize(50, 50));
        e7PushButton->setMaximumSize(QSize(50, 50));
        e7PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        e7PushButton->setIconSize(QSize(36, 36));
        g3PushButton = new QPushButton(GameWithoutChat);
        board->addButton(g3PushButton);
        g3PushButton->setObjectName(QString::fromUtf8("g3PushButton"));
        g3PushButton->setEnabled(false);
        g3PushButton->setGeometry(QRect(550, 350, 50, 50));
        g3PushButton->setMinimumSize(QSize(50, 50));
        g3PushButton->setMaximumSize(QSize(50, 50));
        g3PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        g3PushButton->setIconSize(QSize(36, 36));
        f8PushButton = new QPushButton(GameWithoutChat);
        board->addButton(f8PushButton);
        f8PushButton->setObjectName(QString::fromUtf8("f8PushButton"));
        f8PushButton->setEnabled(false);
        f8PushButton->setGeometry(QRect(500, 100, 50, 50));
        f8PushButton->setMinimumSize(QSize(50, 50));
        f8PushButton->setMaximumSize(QSize(50, 50));
        f8PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        f8PushButton->setIconSize(QSize(36, 36));
        f7PushButton = new QPushButton(GameWithoutChat);
        board->addButton(f7PushButton);
        f7PushButton->setObjectName(QString::fromUtf8("f7PushButton"));
        f7PushButton->setEnabled(false);
        f7PushButton->setGeometry(QRect(500, 150, 50, 50));
        f7PushButton->setMinimumSize(QSize(50, 50));
        f7PushButton->setMaximumSize(QSize(50, 50));
        f7PushButton->setStyleSheet(QString::fromUtf8(""));
        f7PushButton->setIconSize(QSize(36, 36));
        e4PushButton = new QPushButton(GameWithoutChat);
        board->addButton(e4PushButton);
        e4PushButton->setObjectName(QString::fromUtf8("e4PushButton"));
        e4PushButton->setEnabled(false);
        e4PushButton->setGeometry(QRect(450, 300, 50, 50));
        e4PushButton->setMinimumSize(QSize(50, 50));
        e4PushButton->setMaximumSize(QSize(50, 50));
        e4PushButton->setStyleSheet(QString::fromUtf8(""));
        e4PushButton->setIconSize(QSize(36, 36));
        g6PushButton = new QPushButton(GameWithoutChat);
        board->addButton(g6PushButton);
        g6PushButton->setObjectName(QString::fromUtf8("g6PushButton"));
        g6PushButton->setEnabled(false);
        g6PushButton->setGeometry(QRect(550, 200, 50, 50));
        g6PushButton->setMinimumSize(QSize(50, 50));
        g6PushButton->setMaximumSize(QSize(50, 50));
        g6PushButton->setStyleSheet(QString::fromUtf8(""));
        g6PushButton->setIconSize(QSize(36, 36));
        h2PushButton = new QPushButton(GameWithoutChat);
        board->addButton(h2PushButton);
        h2PushButton->setObjectName(QString::fromUtf8("h2PushButton"));
        h2PushButton->setEnabled(false);
        h2PushButton->setGeometry(QRect(600, 400, 50, 50));
        h2PushButton->setMinimumSize(QSize(50, 50));
        h2PushButton->setMaximumSize(QSize(50, 50));
        h2PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        h2PushButton->setIconSize(QSize(36, 36));
        e5PushButton = new QPushButton(GameWithoutChat);
        board->addButton(e5PushButton);
        e5PushButton->setObjectName(QString::fromUtf8("e5PushButton"));
        e5PushButton->setEnabled(false);
        e5PushButton->setGeometry(QRect(450, 250, 50, 50));
        e5PushButton->setMinimumSize(QSize(50, 50));
        e5PushButton->setMaximumSize(QSize(50, 50));
        e5PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        e5PushButton->setIconSize(QSize(36, 36));
        g5PushButton = new QPushButton(GameWithoutChat);
        board->addButton(g5PushButton);
        g5PushButton->setObjectName(QString::fromUtf8("g5PushButton"));
        g5PushButton->setEnabled(false);
        g5PushButton->setGeometry(QRect(550, 250, 50, 50));
        g5PushButton->setMinimumSize(QSize(50, 50));
        g5PushButton->setMaximumSize(QSize(50, 50));
        g5PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        g5PushButton->setIconSize(QSize(36, 36));
        h4PushButton = new QPushButton(GameWithoutChat);
        board->addButton(h4PushButton);
        h4PushButton->setObjectName(QString::fromUtf8("h4PushButton"));
        h4PushButton->setEnabled(false);
        h4PushButton->setGeometry(QRect(600, 300, 50, 50));
        h4PushButton->setMinimumSize(QSize(50, 50));
        h4PushButton->setMaximumSize(QSize(50, 50));
        h4PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        h4PushButton->setIconSize(QSize(36, 36));
        f6PushButton = new QPushButton(GameWithoutChat);
        board->addButton(f6PushButton);
        f6PushButton->setObjectName(QString::fromUtf8("f6PushButton"));
        f6PushButton->setEnabled(false);
        f6PushButton->setGeometry(QRect(500, 200, 50, 50));
        f6PushButton->setMinimumSize(QSize(50, 50));
        f6PushButton->setMaximumSize(QSize(50, 50));
        f6PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        f6PushButton->setIconSize(QSize(36, 36));
        f1PushButton = new QPushButton(GameWithoutChat);
        board->addButton(f1PushButton);
        f1PushButton->setObjectName(QString::fromUtf8("f1PushButton"));
        f1PushButton->setEnabled(false);
        f1PushButton->setGeometry(QRect(500, 450, 50, 50));
        f1PushButton->setMinimumSize(QSize(50, 50));
        f1PushButton->setMaximumSize(QSize(50, 50));
        f1PushButton->setStyleSheet(QString::fromUtf8(""));
        f1PushButton->setIconSize(QSize(36, 36));
        g2PushButton = new QPushButton(GameWithoutChat);
        board->addButton(g2PushButton);
        g2PushButton->setObjectName(QString::fromUtf8("g2PushButton"));
        g2PushButton->setEnabled(false);
        g2PushButton->setGeometry(QRect(550, 400, 50, 50));
        g2PushButton->setMinimumSize(QSize(50, 50));
        g2PushButton->setMaximumSize(QSize(50, 50));
        g2PushButton->setStyleSheet(QString::fromUtf8(""));
        g2PushButton->setIconSize(QSize(36, 36));
        e6PushButton = new QPushButton(GameWithoutChat);
        board->addButton(e6PushButton);
        e6PushButton->setObjectName(QString::fromUtf8("e6PushButton"));
        e6PushButton->setEnabled(false);
        e6PushButton->setGeometry(QRect(450, 200, 50, 50));
        e6PushButton->setMinimumSize(QSize(50, 50));
        e6PushButton->setMaximumSize(QSize(50, 50));
        e6PushButton->setStyleSheet(QString::fromUtf8(""));
        e6PushButton->setIconSize(QSize(36, 36));
        h1PushButton = new QPushButton(GameWithoutChat);
        board->addButton(h1PushButton);
        h1PushButton->setObjectName(QString::fromUtf8("h1PushButton"));
        h1PushButton->setEnabled(false);
        h1PushButton->setGeometry(QRect(600, 450, 50, 50));
        h1PushButton->setMinimumSize(QSize(50, 50));
        h1PushButton->setMaximumSize(QSize(50, 50));
        h1PushButton->setStyleSheet(QString::fromUtf8(""));
        h1PushButton->setIconSize(QSize(36, 36));
        f4PushButton = new QPushButton(GameWithoutChat);
        board->addButton(f4PushButton);
        f4PushButton->setObjectName(QString::fromUtf8("f4PushButton"));
        f4PushButton->setEnabled(false);
        f4PushButton->setGeometry(QRect(500, 300, 50, 50));
        f4PushButton->setMinimumSize(QSize(50, 50));
        f4PushButton->setMaximumSize(QSize(50, 50));
        f4PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        f4PushButton->setIconSize(QSize(36, 36));
        g4PushButton = new QPushButton(GameWithoutChat);
        board->addButton(g4PushButton);
        g4PushButton->setObjectName(QString::fromUtf8("g4PushButton"));
        g4PushButton->setEnabled(false);
        g4PushButton->setGeometry(QRect(550, 300, 50, 50));
        g4PushButton->setMinimumSize(QSize(50, 50));
        g4PushButton->setMaximumSize(QSize(50, 50));
        g4PushButton->setStyleSheet(QString::fromUtf8(""));
        g4PushButton->setIconSize(QSize(36, 36));
        f3PushButton = new QPushButton(GameWithoutChat);
        f3PushButton->setObjectName(QString::fromUtf8("f3PushButton"));
        f3PushButton->setEnabled(false);
        f3PushButton->setGeometry(QRect(500, 350, 50, 50));
        f3PushButton->setMinimumSize(QSize(50, 50));
        f3PushButton->setMaximumSize(QSize(50, 50));
        f3PushButton->setStyleSheet(QString::fromUtf8(""));
        f3PushButton->setIconSize(QSize(36, 36));
        h7PushButton = new QPushButton(GameWithoutChat);
        board->addButton(h7PushButton);
        h7PushButton->setObjectName(QString::fromUtf8("h7PushButton"));
        h7PushButton->setEnabled(false);
        h7PushButton->setGeometry(QRect(600, 150, 50, 50));
        h7PushButton->setMinimumSize(QSize(50, 50));
        h7PushButton->setMaximumSize(QSize(50, 50));
        h7PushButton->setStyleSheet(QString::fromUtf8(""));
        h7PushButton->setIconSize(QSize(36, 36));
        e8PushButton = new QPushButton(GameWithoutChat);
        board->addButton(e8PushButton);
        e8PushButton->setObjectName(QString::fromUtf8("e8PushButton"));
        e8PushButton->setEnabled(false);
        e8PushButton->setGeometry(QRect(450, 100, 50, 50));
        e8PushButton->setMinimumSize(QSize(50, 50));
        e8PushButton->setMaximumSize(QSize(50, 50));
        e8PushButton->setStyleSheet(QString::fromUtf8(""));
        e8PushButton->setIconSize(QSize(36, 36));
        g7PushButton = new QPushButton(GameWithoutChat);
        board->addButton(g7PushButton);
        g7PushButton->setObjectName(QString::fromUtf8("g7PushButton"));
        g7PushButton->setEnabled(false);
        g7PushButton->setGeometry(QRect(550, 150, 50, 50));
        g7PushButton->setMinimumSize(QSize(50, 50));
        g7PushButton->setMaximumSize(QSize(50, 50));
        g7PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        g7PushButton->setIconSize(QSize(36, 36));
        h5PushButton = new QPushButton(GameWithoutChat);
        board->addButton(h5PushButton);
        h5PushButton->setObjectName(QString::fromUtf8("h5PushButton"));
        h5PushButton->setEnabled(false);
        h5PushButton->setGeometry(QRect(600, 250, 50, 50));
        h5PushButton->setMinimumSize(QSize(50, 50));
        h5PushButton->setMaximumSize(QSize(50, 50));
        h5PushButton->setStyleSheet(QString::fromUtf8(""));
        h5PushButton->setIconSize(QSize(36, 36));
        g8PushButton = new QPushButton(GameWithoutChat);
        board->addButton(g8PushButton);
        g8PushButton->setObjectName(QString::fromUtf8("g8PushButton"));
        g8PushButton->setEnabled(false);
        g8PushButton->setGeometry(QRect(550, 100, 50, 50));
        g8PushButton->setMinimumSize(QSize(50, 50));
        g8PushButton->setMaximumSize(QSize(50, 50));
        g8PushButton->setStyleSheet(QString::fromUtf8(""));
        g8PushButton->setIconSize(QSize(36, 36));
        h8PushButton = new QPushButton(GameWithoutChat);
        board->addButton(h8PushButton);
        h8PushButton->setObjectName(QString::fromUtf8("h8PushButton"));
        h8PushButton->setEnabled(false);
        h8PushButton->setGeometry(QRect(600, 100, 50, 50));
        h8PushButton->setMinimumSize(QSize(50, 50));
        h8PushButton->setMaximumSize(QSize(50, 50));
        h8PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        h8PushButton->setIconSize(QSize(36, 36));
        h3PushButton = new QPushButton(GameWithoutChat);
        board->addButton(h3PushButton);
        h3PushButton->setObjectName(QString::fromUtf8("h3PushButton"));
        h3PushButton->setEnabled(false);
        h3PushButton->setGeometry(QRect(600, 350, 50, 50));
        h3PushButton->setMinimumSize(QSize(50, 50));
        h3PushButton->setMaximumSize(QSize(50, 50));
        h3PushButton->setStyleSheet(QString::fromUtf8(""));
        h3PushButton->setIconSize(QSize(36, 36));
        e1PushButton = new QPushButton(GameWithoutChat);
        board->addButton(e1PushButton);
        e1PushButton->setObjectName(QString::fromUtf8("e1PushButton"));
        e1PushButton->setEnabled(false);
        e1PushButton->setGeometry(QRect(450, 450, 50, 50));
        e1PushButton->setMinimumSize(QSize(50, 50));
        e1PushButton->setMaximumSize(QSize(50, 50));
        e1PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        e1PushButton->setIconSize(QSize(36, 36));
        f2PushButton = new QPushButton(GameWithoutChat);
        board->addButton(f2PushButton);
        f2PushButton->setObjectName(QString::fromUtf8("f2PushButton"));
        f2PushButton->setEnabled(false);
        f2PushButton->setGeometry(QRect(500, 400, 50, 50));
        f2PushButton->setMinimumSize(QSize(50, 50));
        f2PushButton->setMaximumSize(QSize(50, 50));
        f2PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        f2PushButton->setIconSize(QSize(36, 36));
        g1PushButton = new QPushButton(GameWithoutChat);
        board->addButton(g1PushButton);
        g1PushButton->setObjectName(QString::fromUtf8("g1PushButton"));
        g1PushButton->setEnabled(false);
        g1PushButton->setGeometry(QRect(550, 450, 50, 50));
        g1PushButton->setMinimumSize(QSize(50, 50));
        g1PushButton->setMaximumSize(QSize(50, 50));
        g1PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        g1PushButton->setIconSize(QSize(36, 36));
        f5PushButton = new QPushButton(GameWithoutChat);
        board->addButton(f5PushButton);
        f5PushButton->setObjectName(QString::fromUtf8("f5PushButton"));
        f5PushButton->setEnabled(false);
        f5PushButton->setGeometry(QRect(500, 250, 50, 50));
        f5PushButton->setMinimumSize(QSize(50, 50));
        f5PushButton->setMaximumSize(QSize(50, 50));
        f5PushButton->setStyleSheet(QString::fromUtf8(""));
        f5PushButton->setIconSize(QSize(36, 36));
        h6PushButton = new QPushButton(GameWithoutChat);
        board->addButton(h6PushButton);
        h6PushButton->setObjectName(QString::fromUtf8("h6PushButton"));
        h6PushButton->setEnabled(false);
        h6PushButton->setGeometry(QRect(600, 200, 50, 50));
        h6PushButton->setMinimumSize(QSize(50, 50));
        h6PushButton->setMaximumSize(QSize(50, 50));
        h6PushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        h6PushButton->setIconSize(QSize(36, 36));
        verticalLayoutWidget_3 = new QWidget(GameWithoutChat);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(649, 100, 21, 401));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(verticalLayoutWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_8);

        label_7 = new QLabel(verticalLayoutWidget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_7);

        label_6 = new QLabel(verticalLayoutWidget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_6);

        label_5 = new QLabel(verticalLayoutWidget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_5);

        label_4 = new QLabel(verticalLayoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        label_1 = new QLabel(verticalLayoutWidget_3);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_1);

        horizontalLayoutWidget = new QWidget(GameWithoutChat);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(250, 500, 401, 21));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_A = new QLabel(horizontalLayoutWidget);
        label_A->setObjectName(QString::fromUtf8("label_A"));
        label_A->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_A);

        label_B = new QLabel(horizontalLayoutWidget);
        label_B->setObjectName(QString::fromUtf8("label_B"));
        label_B->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_B);

        label_C = new QLabel(horizontalLayoutWidget);
        label_C->setObjectName(QString::fromUtf8("label_C"));
        label_C->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_C);

        label_D = new QLabel(horizontalLayoutWidget);
        label_D->setObjectName(QString::fromUtf8("label_D"));
        label_D->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_D);

        label_E = new QLabel(horizontalLayoutWidget);
        label_E->setObjectName(QString::fromUtf8("label_E"));
        label_E->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_E);

        label_F = new QLabel(horizontalLayoutWidget);
        label_F->setObjectName(QString::fromUtf8("label_F"));
        label_F->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_F);

        label_G = new QLabel(horizontalLayoutWidget);
        label_G->setObjectName(QString::fromUtf8("label_G"));
        label_G->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_G);

        label_H = new QLabel(horizontalLayoutWidget);
        label_H->setObjectName(QString::fromUtf8("label_H"));
        label_H->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_H);


        retranslateUi(GameWithoutChat);

        QMetaObject::connectSlotsByName(GameWithoutChat);
    } // setupUi

    void retranslateUi(QDialog *GameWithoutChat)
    {
        GameWithoutChat->setWindowTitle(QApplication::translate("GameWithoutChat", "Chess", nullptr));
        imageLabel->setText(QString());
        takenLabel->setText(QApplication::translate("GameWithoutChat", "TAKEN :", nullptr));
        chgTakenLabel->setText(QApplication::translate("GameWithoutChat", "PQBR", nullptr));
        modeLabel->setText(QApplication::translate("GameWithoutChat", "<html><head/><body><p>MODE:</p></body></html>", nullptr));
        chgModeLabel->setText(QApplication::translate("GameWithoutChat", "mode", nullptr));
        colourLabel->setText(QApplication::translate("GameWithoutChat", "<html><head/><body><p>COLOUR:</p></body></html>", nullptr));
        chgColourLabel->setText(QApplication::translate("GameWithoutChat", "colour", nullptr));
        lastMoveLabel->setText(QApplication::translate("GameWithoutChat", "LAST MOVE:", nullptr));
        chgLastMoveLabel->setText(QApplication::translate("GameWithoutChat", "last move", nullptr));
        opponentNameLabel->setText(QApplication::translate("GameWithoutChat", "OPPONENT NAME:", nullptr));
        chgOpponentNameLabel->setText(QApplication::translate("GameWithoutChat", "opponent", nullptr));
        surrendButton->setText(QApplication::translate("GameWithoutChat", "Surrend", nullptr));
        timeLabel->setText(QApplication::translate("GameWithoutChat", "Time:", nullptr));
        chgTimeLabel->setText(QApplication::translate("GameWithoutChat", "0:00", nullptr));
        checkUpdateLabel->setText(QApplication::translate("GameWithoutChat", "TURN:", nullptr));
        turnLabel->setText(QApplication::translate("GameWithoutChat", "Black", nullptr));
        takenEnnemyLabel->setText(QApplication::translate("GameWithoutChat", "TAKEN :", nullptr));
        chgTakenEnnemyLabel->setText(QApplication::translate("GameWithoutChat", "PQBR", nullptr));
        a1PushButton->setText(QString());
        a3PushButton->setText(QString());
        a2PushButton->setText(QString());
        a5PushButton->setText(QString());
        a4PushButton->setText(QString());
        a7PushButton->setText(QString());
        a6PushButton->setText(QString());
        a8PushButton->setText(QString());
        b8PushButton->setText(QString());
        b5PushButton->setText(QString());
        b6PushButton->setText(QString());
        b4PushButton->setText(QString());
        b7PushButton->setText(QString());
        b1PushButton->setText(QString());
        b2PushButton->setText(QString());
        b3PushButton->setText(QString());
        c7PushButton->setText(QString());
        d3PushButton->setText(QString());
        d2PushButton->setText(QString());
        c4PushButton->setText(QString());
        d1PushButton->setText(QString());
        c5PushButton->setText(QString());
        d5PushButton->setText(QString());
        c1PushButton->setText(QString());
        c8PushButton->setText(QString());
        d8PushButton->setText(QString());
        c3PushButton->setText(QString());
        d6PushButton->setText(QString());
        c6PushButton->setText(QString());
        d4PushButton->setText(QString());
        d7PushButton->setText(QString());
        c2PushButton->setText(QString());
        e2PushButton->setText(QString());
        e3PushButton->setText(QString());
        e7PushButton->setText(QString());
        g3PushButton->setText(QString());
        f8PushButton->setText(QString());
        f7PushButton->setText(QString());
        e4PushButton->setText(QString());
        g6PushButton->setText(QString());
        h2PushButton->setText(QString());
        e5PushButton->setText(QString());
        g5PushButton->setText(QString());
        h4PushButton->setText(QString());
        f6PushButton->setText(QString());
        f1PushButton->setText(QString());
        g2PushButton->setText(QString());
        e6PushButton->setText(QString());
        h1PushButton->setText(QString());
        f4PushButton->setText(QString());
        g4PushButton->setText(QString());
        f3PushButton->setText(QString());
        h7PushButton->setText(QString());
        e8PushButton->setText(QString());
        g7PushButton->setText(QString());
        h5PushButton->setText(QString());
        g8PushButton->setText(QString());
        h8PushButton->setText(QString());
        h3PushButton->setText(QString());
        e1PushButton->setText(QString());
        f2PushButton->setText(QString());
        g1PushButton->setText(QString());
        f5PushButton->setText(QString());
        h6PushButton->setText(QString());
        label_8->setText(QApplication::translate("GameWithoutChat", "8", nullptr));
        label_7->setText(QApplication::translate("GameWithoutChat", "7", nullptr));
        label_6->setText(QApplication::translate("GameWithoutChat", "6", nullptr));
        label_5->setText(QApplication::translate("GameWithoutChat", "5", nullptr));
        label_4->setText(QApplication::translate("GameWithoutChat", "4", nullptr));
        label_3->setText(QApplication::translate("GameWithoutChat", "3", nullptr));
        label_2->setText(QApplication::translate("GameWithoutChat", "2", nullptr));
        label_1->setText(QApplication::translate("GameWithoutChat", "1", nullptr));
        label_A->setText(QApplication::translate("GameWithoutChat", "A", nullptr));
        label_B->setText(QApplication::translate("GameWithoutChat", "B", nullptr));
        label_C->setText(QApplication::translate("GameWithoutChat", "C", nullptr));
        label_D->setText(QApplication::translate("GameWithoutChat", "D", nullptr));
        label_E->setText(QApplication::translate("GameWithoutChat", "E", nullptr));
        label_F->setText(QApplication::translate("GameWithoutChat", "F", nullptr));
        label_G->setText(QApplication::translate("GameWithoutChat", "G", nullptr));
        label_H->setText(QApplication::translate("GameWithoutChat", "H", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWithoutChat: public Ui_GameWithoutChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWITHOUTCHAT_H
