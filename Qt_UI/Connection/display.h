#ifndef DISPLAY_H
#define DISPLAY_H

#include <QWidget>

namespace Ui {
class Display;
}

class Display : public QWidget
{
    Q_OBJECT

public:
    explicit Display(QWidget *parent = nullptr);
    ~Display();

    void setText(QString);

private:
    Ui::Display *ui;
};

#endif // DISPLAY_H
