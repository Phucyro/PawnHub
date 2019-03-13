#include "display.h"
#include "ui_display.h"

Display::Display(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Display)
{
    ui->setupUi(this);
}

Display::~Display()
{
    delete ui;
}

void Display::setText(QString string)
{
    ui->label->setText(string);
}
