#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget * wdg = new QWidget(this);
    QVBoxLayout *vlay = new QVBoxLayout(wdg);
    QPushButton *btn1 = new QPushButton("Log In");
    vlay->addWidget(btn1);
    QPushButton *btn2 = new QPushButton("Sign Up");
    vlay->addWidget(btn2);
    QPushButton *btn3 = new QPushButton("Quit");
    vlay->addWidget(btn3);
    wdg->setLayout(vlay);
    setCentralWidget(wdg);
}

MainWindow::~MainWindow()
{
    delete ui;
}
