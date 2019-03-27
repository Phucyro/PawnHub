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
    QPushButton *A1;
    QPushButton *A3;
    QPushButton *A2;
    QPushButton *A5;
    QPushButton *A4;
    QPushButton *A7;
    QPushButton *A6;
    QPushButton *A8;
    QPushButton *B8;
    QPushButton *B5;
    QPushButton *B6;
    QPushButton *B4;
    QPushButton *B7;
    QPushButton *B1;
    QPushButton *B2;
    QPushButton *B3;
    QPushButton *C7;
    QPushButton *D3;
    QPushButton *D2;
    QPushButton *C4;
    QPushButton *D1;
    QPushButton *C5;
    QPushButton *D5;
    QPushButton *C1;
    QPushButton *C8;
    QPushButton *D8;
    QPushButton *C3;
    QPushButton *D6;
    QPushButton *C6;
    QPushButton *D4;
    QPushButton *D7;
    QPushButton *C2;
    QPushButton *E2;
    QPushButton *E3;
    QPushButton *E7;
    QPushButton *G3;
    QPushButton *F8;
    QPushButton *F7;
    QPushButton *E4;
    QPushButton *G6;
    QPushButton *H2;
    QPushButton *E5;
    QPushButton *G5;
    QPushButton *H4;
    QPushButton *F6;
    QPushButton *F1;
    QPushButton *G2;
    QPushButton *E6;
    QPushButton *H1;
    QPushButton *F4;
    QPushButton *G4;
    QPushButton *F3;
    QPushButton *H7;
    QPushButton *E8;
    QPushButton *G7;
    QPushButton *H5;
    QPushButton *G8;
    QPushButton *H8;
    QPushButton *H3;
    QPushButton *E1;
    QPushButton *F2;
    QPushButton *G1;
    QPushButton *F5;
    QPushButton *H6;
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

        A1 = new QPushButton(GameWithoutChat);
        board = new QButtonGroup(GameWithoutChat);
        board->setObjectName(QString::fromUtf8("board"));
        board->setExclusive(true);
        board->addButton(A1);
        A1->setObjectName(QString::fromUtf8("A1"));
        A1->setEnabled(true);
        A1->setGeometry(QRect(250, 450, 50, 50));
        A1->setMinimumSize(QSize(50, 50));
        A1->setMaximumSize(QSize(50, 50));
        A1->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        A1->setIconSize(QSize(36, 36));
        A1->setFlat(false);
        A3 = new QPushButton(GameWithoutChat);
        board->addButton(A3);
        A3->setObjectName(QString::fromUtf8("A3"));
        A3->setEnabled(true);
        A3->setGeometry(QRect(250, 350, 50, 50));
        A3->setMinimumSize(QSize(50, 50));
        A3->setMaximumSize(QSize(50, 50));
        A3->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        A3->setIconSize(QSize(36, 36));
        A2 = new QPushButton(GameWithoutChat);
        board->addButton(A2);
        A2->setObjectName(QString::fromUtf8("A2"));
        A2->setEnabled(true);
        A2->setGeometry(QRect(250, 400, 50, 50));
        A2->setMinimumSize(QSize(50, 50));
        A2->setMaximumSize(QSize(50, 50));
        A2->setStyleSheet(QString::fromUtf8(""));
        A2->setIconSize(QSize(36, 36));
        A5 = new QPushButton(GameWithoutChat);
        board->addButton(A5);
        A5->setObjectName(QString::fromUtf8("A5"));
        A5->setEnabled(true);
        A5->setGeometry(QRect(250, 250, 50, 50));
        A5->setMinimumSize(QSize(50, 50));
        A5->setMaximumSize(QSize(50, 50));
        A5->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        A5->setIconSize(QSize(36, 36));
        A4 = new QPushButton(GameWithoutChat);
        board->addButton(A4);
        A4->setObjectName(QString::fromUtf8("A4"));
        A4->setEnabled(true);
        A4->setGeometry(QRect(250, 300, 50, 50));
        A4->setMinimumSize(QSize(50, 50));
        A4->setMaximumSize(QSize(50, 50));
        A4->setStyleSheet(QString::fromUtf8(""));
        A4->setIconSize(QSize(36, 36));
        A7 = new QPushButton(GameWithoutChat);
        board->addButton(A7);
        A7->setObjectName(QString::fromUtf8("A7"));
        A7->setEnabled(true);
        A7->setGeometry(QRect(250, 150, 50, 50));
        A7->setMinimumSize(QSize(50, 50));
        A7->setMaximumSize(QSize(50, 50));
        A7->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        A7->setIconSize(QSize(36, 36));
        A6 = new QPushButton(GameWithoutChat);
        board->addButton(A6);
        A6->setObjectName(QString::fromUtf8("A6"));
        A6->setEnabled(true);
        A6->setGeometry(QRect(250, 200, 50, 50));
        A6->setMinimumSize(QSize(50, 50));
        A6->setMaximumSize(QSize(50, 50));
        A6->setStyleSheet(QString::fromUtf8(""));
        A6->setIconSize(QSize(36, 36));
        A8 = new QPushButton(GameWithoutChat);
        board->addButton(A8);
        A8->setObjectName(QString::fromUtf8("A8"));
        A8->setEnabled(true);
        A8->setGeometry(QRect(250, 100, 50, 50));
        A8->setMinimumSize(QSize(50, 50));
        A8->setMaximumSize(QSize(50, 50));
        A8->setStyleSheet(QString::fromUtf8(""));
        A8->setIconSize(QSize(36, 36));
        B8 = new QPushButton(GameWithoutChat);
        board->addButton(B8);
        B8->setObjectName(QString::fromUtf8("B8"));
        B8->setEnabled(true);
        B8->setGeometry(QRect(300, 100, 50, 50));
        B8->setMinimumSize(QSize(50, 50));
        B8->setMaximumSize(QSize(50, 50));
        B8->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        B8->setIconSize(QSize(36, 36));
        B5 = new QPushButton(GameWithoutChat);
        board->addButton(B5);
        B5->setObjectName(QString::fromUtf8("B5"));
        B5->setEnabled(true);
        B5->setGeometry(QRect(300, 250, 50, 50));
        B5->setMinimumSize(QSize(50, 50));
        B5->setMaximumSize(QSize(50, 50));
        B5->setStyleSheet(QString::fromUtf8(""));
        B5->setIconSize(QSize(36, 36));
        B6 = new QPushButton(GameWithoutChat);
        board->addButton(B6);
        B6->setObjectName(QString::fromUtf8("B6"));
        B6->setEnabled(true);
        B6->setGeometry(QRect(300, 200, 50, 50));
        B6->setMinimumSize(QSize(50, 50));
        B6->setMaximumSize(QSize(50, 50));
        B6->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        B6->setIconSize(QSize(36, 36));
        B4 = new QPushButton(GameWithoutChat);
        board->addButton(B4);
        B4->setObjectName(QString::fromUtf8("B4"));
        B4->setEnabled(true);
        B4->setGeometry(QRect(300, 300, 50, 50));
        B4->setMinimumSize(QSize(50, 50));
        B4->setMaximumSize(QSize(50, 50));
        B4->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        B4->setIconSize(QSize(36, 36));
        B7 = new QPushButton(GameWithoutChat);
        board->addButton(B7);
        B7->setObjectName(QString::fromUtf8("B7"));
        B7->setEnabled(true);
        B7->setGeometry(QRect(300, 150, 50, 50));
        B7->setMinimumSize(QSize(50, 50));
        B7->setMaximumSize(QSize(50, 50));
        B7->setStyleSheet(QString::fromUtf8(""));
        B7->setIconSize(QSize(36, 36));
        B1 = new QPushButton(GameWithoutChat);
        board->addButton(B1);
        B1->setObjectName(QString::fromUtf8("B1"));
        B1->setEnabled(true);
        B1->setGeometry(QRect(300, 450, 50, 50));
        B1->setMinimumSize(QSize(50, 50));
        B1->setMaximumSize(QSize(50, 50));
        B1->setStyleSheet(QString::fromUtf8(""));
        B1->setIconSize(QSize(36, 36));
        B2 = new QPushButton(GameWithoutChat);
        board->addButton(B2);
        B2->setObjectName(QString::fromUtf8("B2"));
        B2->setEnabled(true);
        B2->setGeometry(QRect(300, 400, 50, 50));
        B2->setMinimumSize(QSize(50, 50));
        B2->setMaximumSize(QSize(50, 50));
        B2->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        B2->setIconSize(QSize(36, 36));
        B3 = new QPushButton(GameWithoutChat);
        board->addButton(B3);
        B3->setObjectName(QString::fromUtf8("B3"));
        B3->setEnabled(true);
        B3->setGeometry(QRect(300, 350, 50, 50));
        B3->setMinimumSize(QSize(50, 50));
        B3->setMaximumSize(QSize(50, 50));
        B3->setStyleSheet(QString::fromUtf8(""));
        B3->setIconSize(QSize(36, 36));
        C7 = new QPushButton(GameWithoutChat);
        board->addButton(C7);
        C7->setObjectName(QString::fromUtf8("C7"));
        C7->setEnabled(true);
        C7->setGeometry(QRect(350, 150, 50, 50));
        C7->setMinimumSize(QSize(50, 50));
        C7->setMaximumSize(QSize(50, 50));
        C7->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        C7->setIconSize(QSize(36, 36));
        D3 = new QPushButton(GameWithoutChat);
        board->addButton(D3);
        D3->setObjectName(QString::fromUtf8("D3"));
        D3->setEnabled(true);
        D3->setGeometry(QRect(400, 350, 50, 50));
        D3->setMinimumSize(QSize(50, 50));
        D3->setMaximumSize(QSize(50, 50));
        D3->setStyleSheet(QString::fromUtf8(""));
        D3->setIconSize(QSize(36, 36));
        D2 = new QPushButton(GameWithoutChat);
        board->addButton(D2);
        D2->setObjectName(QString::fromUtf8("D2"));
        D2->setEnabled(true);
        D2->setGeometry(QRect(400, 400, 50, 50));
        D2->setMinimumSize(QSize(50, 50));
        D2->setMaximumSize(QSize(50, 50));
        D2->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        D2->setIconSize(QSize(36, 36));
        C4 = new QPushButton(GameWithoutChat);
        board->addButton(C4);
        C4->setObjectName(QString::fromUtf8("C4"));
        C4->setEnabled(true);
        C4->setGeometry(QRect(350, 300, 50, 50));
        C4->setMinimumSize(QSize(50, 50));
        C4->setMaximumSize(QSize(50, 50));
        C4->setStyleSheet(QString::fromUtf8(""));
        C4->setIconSize(QSize(36, 36));
        D1 = new QPushButton(GameWithoutChat);
        board->addButton(D1);
        D1->setObjectName(QString::fromUtf8("D1"));
        D1->setEnabled(true);
        D1->setGeometry(QRect(400, 450, 50, 50));
        D1->setMinimumSize(QSize(50, 50));
        D1->setMaximumSize(QSize(50, 50));
        D1->setStyleSheet(QString::fromUtf8(""));
        D1->setIconSize(QSize(36, 36));
        C5 = new QPushButton(GameWithoutChat);
        board->addButton(C5);
        C5->setObjectName(QString::fromUtf8("C5"));
        C5->setEnabled(true);
        C5->setGeometry(QRect(350, 250, 50, 50));
        C5->setMinimumSize(QSize(50, 50));
        C5->setMaximumSize(QSize(50, 50));
        C5->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        C5->setIconSize(QSize(36, 36));
        D5 = new QPushButton(GameWithoutChat);
        board->addButton(D5);
        D5->setObjectName(QString::fromUtf8("D5"));
        D5->setEnabled(true);
        D5->setGeometry(QRect(400, 250, 50, 50));
        D5->setMinimumSize(QSize(50, 50));
        D5->setMaximumSize(QSize(50, 50));
        D5->setStyleSheet(QString::fromUtf8(""));
        D5->setIconSize(QSize(36, 36));
        C1 = new QPushButton(GameWithoutChat);
        board->addButton(C1);
        C1->setObjectName(QString::fromUtf8("C1"));
        C1->setEnabled(true);
        C1->setGeometry(QRect(350, 450, 50, 50));
        C1->setMinimumSize(QSize(50, 50));
        C1->setMaximumSize(QSize(50, 50));
        C1->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        C1->setIconSize(QSize(36, 36));
        C8 = new QPushButton(GameWithoutChat);
        board->addButton(C8);
        C8->setObjectName(QString::fromUtf8("C8"));
        C8->setEnabled(true);
        C8->setGeometry(QRect(350, 100, 50, 50));
        C8->setMinimumSize(QSize(50, 50));
        C8->setMaximumSize(QSize(50, 50));
        C8->setStyleSheet(QString::fromUtf8(""));
        C8->setIconSize(QSize(36, 36));
        D8 = new QPushButton(GameWithoutChat);
        board->addButton(D8);
        D8->setObjectName(QString::fromUtf8("D8"));
        D8->setEnabled(true);
        D8->setGeometry(QRect(400, 100, 50, 50));
        D8->setMinimumSize(QSize(50, 50));
        D8->setMaximumSize(QSize(50, 50));
        D8->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        D8->setIconSize(QSize(36, 36));
        C3 = new QPushButton(GameWithoutChat);
        board->addButton(C3);
        C3->setObjectName(QString::fromUtf8("C3"));
        C3->setEnabled(true);
        C3->setGeometry(QRect(350, 350, 50, 50));
        C3->setMinimumSize(QSize(50, 50));
        C3->setMaximumSize(QSize(50, 50));
        C3->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        C3->setIconSize(QSize(36, 36));
        D6 = new QPushButton(GameWithoutChat);
        board->addButton(D6);
        D6->setObjectName(QString::fromUtf8("D6"));
        D6->setEnabled(true);
        D6->setGeometry(QRect(400, 200, 50, 50));
        D6->setMinimumSize(QSize(50, 50));
        D6->setMaximumSize(QSize(50, 50));
        D6->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        D6->setIconSize(QSize(36, 36));
        C6 = new QPushButton(GameWithoutChat);
        board->addButton(C6);
        C6->setObjectName(QString::fromUtf8("C6"));
        C6->setEnabled(true);
        C6->setGeometry(QRect(350, 200, 50, 50));
        C6->setMinimumSize(QSize(50, 50));
        C6->setMaximumSize(QSize(50, 50));
        C6->setStyleSheet(QString::fromUtf8(""));
        C6->setIconSize(QSize(36, 36));
        D4 = new QPushButton(GameWithoutChat);
        board->addButton(D4);
        D4->setObjectName(QString::fromUtf8("D4"));
        D4->setEnabled(true);
        D4->setGeometry(QRect(400, 300, 50, 50));
        D4->setMinimumSize(QSize(50, 50));
        D4->setMaximumSize(QSize(50, 50));
        D4->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        D4->setIconSize(QSize(36, 36));
        D7 = new QPushButton(GameWithoutChat);
        board->addButton(D7);
        D7->setObjectName(QString::fromUtf8("D7"));
        D7->setEnabled(true);
        D7->setGeometry(QRect(400, 150, 50, 50));
        D7->setMinimumSize(QSize(50, 50));
        D7->setMaximumSize(QSize(50, 50));
        D7->setStyleSheet(QString::fromUtf8(""));
        D7->setIconSize(QSize(36, 36));
        C2 = new QPushButton(GameWithoutChat);
        board->addButton(C2);
        C2->setObjectName(QString::fromUtf8("C2"));
        C2->setEnabled(true);
        C2->setGeometry(QRect(350, 400, 50, 50));
        C2->setMinimumSize(QSize(50, 50));
        C2->setMaximumSize(QSize(50, 50));
        C2->setStyleSheet(QString::fromUtf8(""));
        C2->setIconSize(QSize(36, 36));
        E2 = new QPushButton(GameWithoutChat);
        board->addButton(E2);
        E2->setObjectName(QString::fromUtf8("E2"));
        E2->setEnabled(true);
        E2->setGeometry(QRect(450, 400, 50, 50));
        E2->setMinimumSize(QSize(50, 50));
        E2->setMaximumSize(QSize(50, 50));
        E2->setStyleSheet(QString::fromUtf8(""));
        E2->setIconSize(QSize(36, 36));
        E3 = new QPushButton(GameWithoutChat);
        board->addButton(E3);
        E3->setObjectName(QString::fromUtf8("E3"));
        E3->setEnabled(true);
        E3->setGeometry(QRect(450, 350, 50, 50));
        E3->setMinimumSize(QSize(50, 50));
        E3->setMaximumSize(QSize(50, 50));
        E3->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        E3->setIconSize(QSize(36, 36));
        E7 = new QPushButton(GameWithoutChat);
        board->addButton(E7);
        E7->setObjectName(QString::fromUtf8("E7"));
        E7->setEnabled(true);
        E7->setGeometry(QRect(450, 150, 50, 50));
        E7->setMinimumSize(QSize(50, 50));
        E7->setMaximumSize(QSize(50, 50));
        E7->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        E7->setIconSize(QSize(36, 36));
        G3 = new QPushButton(GameWithoutChat);
        board->addButton(G3);
        G3->setObjectName(QString::fromUtf8("G3"));
        G3->setEnabled(true);
        G3->setGeometry(QRect(550, 350, 50, 50));
        G3->setMinimumSize(QSize(50, 50));
        G3->setMaximumSize(QSize(50, 50));
        G3->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        G3->setIconSize(QSize(36, 36));
        F8 = new QPushButton(GameWithoutChat);
        board->addButton(F8);
        F8->setObjectName(QString::fromUtf8("F8"));
        F8->setEnabled(true);
        F8->setGeometry(QRect(500, 100, 50, 50));
        F8->setMinimumSize(QSize(50, 50));
        F8->setMaximumSize(QSize(50, 50));
        F8->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        F8->setIconSize(QSize(36, 36));
        F7 = new QPushButton(GameWithoutChat);
        board->addButton(F7);
        F7->setObjectName(QString::fromUtf8("F7"));
        F7->setEnabled(true);
        F7->setGeometry(QRect(500, 150, 50, 50));
        F7->setMinimumSize(QSize(50, 50));
        F7->setMaximumSize(QSize(50, 50));
        F7->setStyleSheet(QString::fromUtf8(""));
        F7->setIconSize(QSize(36, 36));
        E4 = new QPushButton(GameWithoutChat);
        board->addButton(E4);
        E4->setObjectName(QString::fromUtf8("E4"));
        E4->setEnabled(true);
        E4->setGeometry(QRect(450, 300, 50, 50));
        E4->setMinimumSize(QSize(50, 50));
        E4->setMaximumSize(QSize(50, 50));
        E4->setStyleSheet(QString::fromUtf8(""));
        E4->setIconSize(QSize(36, 36));
        G6 = new QPushButton(GameWithoutChat);
        board->addButton(G6);
        G6->setObjectName(QString::fromUtf8("G6"));
        G6->setEnabled(true);
        G6->setGeometry(QRect(550, 200, 50, 50));
        G6->setMinimumSize(QSize(50, 50));
        G6->setMaximumSize(QSize(50, 50));
        G6->setStyleSheet(QString::fromUtf8(""));
        G6->setIconSize(QSize(36, 36));
        H2 = new QPushButton(GameWithoutChat);
        board->addButton(H2);
        H2->setObjectName(QString::fromUtf8("H2"));
        H2->setEnabled(true);
        H2->setGeometry(QRect(600, 400, 50, 50));
        H2->setMinimumSize(QSize(50, 50));
        H2->setMaximumSize(QSize(50, 50));
        H2->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        H2->setIconSize(QSize(36, 36));
        E5 = new QPushButton(GameWithoutChat);
        board->addButton(E5);
        E5->setObjectName(QString::fromUtf8("E5"));
        E5->setEnabled(true);
        E5->setGeometry(QRect(450, 250, 50, 50));
        E5->setMinimumSize(QSize(50, 50));
        E5->setMaximumSize(QSize(50, 50));
        E5->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        E5->setIconSize(QSize(36, 36));
        G5 = new QPushButton(GameWithoutChat);
        board->addButton(G5);
        G5->setObjectName(QString::fromUtf8("G5"));
        G5->setEnabled(true);
        G5->setGeometry(QRect(550, 250, 50, 50));
        G5->setMinimumSize(QSize(50, 50));
        G5->setMaximumSize(QSize(50, 50));
        G5->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        G5->setIconSize(QSize(36, 36));
        H4 = new QPushButton(GameWithoutChat);
        board->addButton(H4);
        H4->setObjectName(QString::fromUtf8("H4"));
        H4->setEnabled(true);
        H4->setGeometry(QRect(600, 300, 50, 50));
        H4->setMinimumSize(QSize(50, 50));
        H4->setMaximumSize(QSize(50, 50));
        H4->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        H4->setIconSize(QSize(36, 36));
        F6 = new QPushButton(GameWithoutChat);
        board->addButton(F6);
        F6->setObjectName(QString::fromUtf8("F6"));
        F6->setEnabled(true);
        F6->setGeometry(QRect(500, 200, 50, 50));
        F6->setMinimumSize(QSize(50, 50));
        F6->setMaximumSize(QSize(50, 50));
        F6->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        F6->setIconSize(QSize(36, 36));
        F1 = new QPushButton(GameWithoutChat);
        board->addButton(F1);
        F1->setObjectName(QString::fromUtf8("F1"));
        F1->setEnabled(true);
        F1->setGeometry(QRect(500, 450, 50, 50));
        F1->setMinimumSize(QSize(50, 50));
        F1->setMaximumSize(QSize(50, 50));
        F1->setStyleSheet(QString::fromUtf8(""));
        F1->setIconSize(QSize(36, 36));
        G2 = new QPushButton(GameWithoutChat);
        board->addButton(G2);
        G2->setObjectName(QString::fromUtf8("G2"));
        G2->setEnabled(true);
        G2->setGeometry(QRect(550, 400, 50, 50));
        G2->setMinimumSize(QSize(50, 50));
        G2->setMaximumSize(QSize(50, 50));
        G2->setStyleSheet(QString::fromUtf8(""));
        G2->setIconSize(QSize(36, 36));
        E6 = new QPushButton(GameWithoutChat);
        board->addButton(E6);
        E6->setObjectName(QString::fromUtf8("E6"));
        E6->setEnabled(true);
        E6->setGeometry(QRect(450, 200, 50, 50));
        E6->setMinimumSize(QSize(50, 50));
        E6->setMaximumSize(QSize(50, 50));
        E6->setStyleSheet(QString::fromUtf8(""));
        E6->setIconSize(QSize(36, 36));
        H1 = new QPushButton(GameWithoutChat);
        board->addButton(H1);
        H1->setObjectName(QString::fromUtf8("H1"));
        H1->setEnabled(true);
        H1->setGeometry(QRect(600, 450, 50, 50));
        H1->setMinimumSize(QSize(50, 50));
        H1->setMaximumSize(QSize(50, 50));
        H1->setStyleSheet(QString::fromUtf8(""));
        H1->setIconSize(QSize(36, 36));
        F4 = new QPushButton(GameWithoutChat);
        board->addButton(F4);
        F4->setObjectName(QString::fromUtf8("F4"));
        F4->setEnabled(true);
        F4->setGeometry(QRect(500, 300, 50, 50));
        F4->setMinimumSize(QSize(50, 50));
        F4->setMaximumSize(QSize(50, 50));
        F4->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        F4->setIconSize(QSize(36, 36));
        G4 = new QPushButton(GameWithoutChat);
        board->addButton(G4);
        G4->setObjectName(QString::fromUtf8("G4"));
        G4->setEnabled(true);
        G4->setGeometry(QRect(550, 300, 50, 50));
        G4->setMinimumSize(QSize(50, 50));
        G4->setMaximumSize(QSize(50, 50));
        G4->setStyleSheet(QString::fromUtf8(""));
        G4->setIconSize(QSize(36, 36));
        F3 = new QPushButton(GameWithoutChat);
        board->addButton(F3);
        F3->setObjectName(QString::fromUtf8("F3"));
        F3->setEnabled(true);
        F3->setGeometry(QRect(500, 350, 50, 50));
        F3->setMinimumSize(QSize(50, 50));
        F3->setMaximumSize(QSize(50, 50));
        F3->setStyleSheet(QString::fromUtf8(""));
        F3->setIconSize(QSize(36, 36));
        H7 = new QPushButton(GameWithoutChat);
        board->addButton(H7);
        H7->setObjectName(QString::fromUtf8("H7"));
        H7->setEnabled(true);
        H7->setGeometry(QRect(600, 150, 50, 50));
        H7->setMinimumSize(QSize(50, 50));
        H7->setMaximumSize(QSize(50, 50));
        H7->setStyleSheet(QString::fromUtf8(""));
        H7->setIconSize(QSize(36, 36));
        E8 = new QPushButton(GameWithoutChat);
        board->addButton(E8);
        E8->setObjectName(QString::fromUtf8("E8"));
        E8->setEnabled(true);
        E8->setGeometry(QRect(450, 100, 50, 50));
        E8->setMinimumSize(QSize(50, 50));
        E8->setMaximumSize(QSize(50, 50));
        E8->setStyleSheet(QString::fromUtf8(""));
        E8->setIconSize(QSize(36, 36));
        G7 = new QPushButton(GameWithoutChat);
        board->addButton(G7);
        G7->setObjectName(QString::fromUtf8("G7"));
        G7->setEnabled(true);
        G7->setGeometry(QRect(550, 150, 50, 50));
        G7->setMinimumSize(QSize(50, 50));
        G7->setMaximumSize(QSize(50, 50));
        G7->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        G7->setIconSize(QSize(36, 36));
        H5 = new QPushButton(GameWithoutChat);
        board->addButton(H5);
        H5->setObjectName(QString::fromUtf8("H5"));
        H5->setEnabled(true);
        H5->setGeometry(QRect(600, 250, 50, 50));
        H5->setMinimumSize(QSize(50, 50));
        H5->setMaximumSize(QSize(50, 50));
        H5->setStyleSheet(QString::fromUtf8(""));
        H5->setIconSize(QSize(36, 36));
        G8 = new QPushButton(GameWithoutChat);
        board->addButton(G8);
        G8->setObjectName(QString::fromUtf8("G8"));
        G8->setEnabled(true);
        G8->setGeometry(QRect(550, 100, 50, 50));
        G8->setMinimumSize(QSize(50, 50));
        G8->setMaximumSize(QSize(50, 50));
        G8->setStyleSheet(QString::fromUtf8(""));
        G8->setIconSize(QSize(36, 36));
        H8 = new QPushButton(GameWithoutChat);
        board->addButton(H8);
        H8->setObjectName(QString::fromUtf8("H8"));
        H8->setEnabled(true);
        H8->setGeometry(QRect(600, 100, 50, 50));
        H8->setMinimumSize(QSize(50, 50));
        H8->setMaximumSize(QSize(50, 50));
        H8->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        H8->setIconSize(QSize(36, 36));
        H3 = new QPushButton(GameWithoutChat);
        board->addButton(H3);
        H3->setObjectName(QString::fromUtf8("H3"));
        H3->setEnabled(true);
        H3->setGeometry(QRect(600, 350, 50, 50));
        H3->setMinimumSize(QSize(50, 50));
        H3->setMaximumSize(QSize(50, 50));
        H3->setStyleSheet(QString::fromUtf8(""));
        H3->setIconSize(QSize(36, 36));
        E1 = new QPushButton(GameWithoutChat);
        board->addButton(E1);
        E1->setObjectName(QString::fromUtf8("E1"));
        E1->setEnabled(true);
        E1->setGeometry(QRect(450, 450, 50, 50));
        E1->setMinimumSize(QSize(50, 50));
        E1->setMaximumSize(QSize(50, 50));
        E1->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        E1->setIconSize(QSize(36, 36));
        F2 = new QPushButton(GameWithoutChat);
        board->addButton(F2);
        F2->setObjectName(QString::fromUtf8("F2"));
        F2->setEnabled(true);
        F2->setGeometry(QRect(500, 400, 50, 50));
        F2->setMinimumSize(QSize(50, 50));
        F2->setMaximumSize(QSize(50, 50));
        F2->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        F2->setIconSize(QSize(36, 36));
        G1 = new QPushButton(GameWithoutChat);
        board->addButton(G1);
        G1->setObjectName(QString::fromUtf8("G1"));
        G1->setEnabled(true);
        G1->setGeometry(QRect(550, 450, 50, 50));
        G1->setMinimumSize(QSize(50, 50));
        G1->setMaximumSize(QSize(50, 50));
        G1->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        G1->setIconSize(QSize(36, 36));
        F5 = new QPushButton(GameWithoutChat);
        board->addButton(F5);
        F5->setObjectName(QString::fromUtf8("F5"));
        F5->setEnabled(true);
        F5->setGeometry(QRect(500, 250, 50, 50));
        F5->setMinimumSize(QSize(50, 50));
        F5->setMaximumSize(QSize(50, 50));
        F5->setStyleSheet(QString::fromUtf8(""));
        F5->setIconSize(QSize(36, 36));
        H6 = new QPushButton(GameWithoutChat);
        board->addButton(H6);
        H6->setObjectName(QString::fromUtf8("H6"));
        H6->setEnabled(true);
        H6->setGeometry(QRect(600, 200, 50, 50));
        H6->setMinimumSize(QSize(50, 50));
        H6->setMaximumSize(QSize(50, 50));
        H6->setStyleSheet(QString::fromUtf8("background-color: rgb(169, 169, 169);"));
        H6->setIconSize(QSize(36, 36));
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
        A1->setText(QString());
        A3->setText(QString());
        A2->setText(QString());
        A5->setText(QString());
        A4->setText(QString());
        A7->setText(QString());
        A6->setText(QString());
        A8->setText(QString());
        B8->setText(QString());
        B5->setText(QString());
        B6->setText(QString());
        B4->setText(QString());
        B7->setText(QString());
        B1->setText(QString());
        B2->setText(QString());
        B3->setText(QString());
        C7->setText(QString());
        D3->setText(QString());
        D2->setText(QString());
        C4->setText(QString());
        D1->setText(QString());
        C5->setText(QString());
        D5->setText(QString());
        C1->setText(QString());
        C8->setText(QString());
        D8->setText(QString());
        C3->setText(QString());
        D6->setText(QString());
        C6->setText(QString());
        D4->setText(QString());
        D7->setText(QString());
        C2->setText(QString());
        E2->setText(QString());
        E3->setText(QString());
        E7->setText(QString());
        G3->setText(QString());
        F8->setText(QString());
        F7->setText(QString());
        E4->setText(QString());
        G6->setText(QString());
        H2->setText(QString());
        E5->setText(QString());
        G5->setText(QString());
        H4->setText(QString());
        F6->setText(QString());
        F1->setText(QString());
        G2->setText(QString());
        E6->setText(QString());
        H1->setText(QString());
        F4->setText(QString());
        G4->setText(QString());
        F3->setText(QString());
        H7->setText(QString());
        E8->setText(QString());
        G7->setText(QString());
        H5->setText(QString());
        G8->setText(QString());
        H8->setText(QString());
        H3->setText(QString());
        E1->setText(QString());
        F2->setText(QString());
        G1->setText(QString());
        F5->setText(QString());
        H6->setText(QString());
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
