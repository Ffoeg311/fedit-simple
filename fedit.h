#ifndef FEDIT_H
#define FEDIT_H

#include <QMainWindow>

namespace Ui {
class Fedit;
}

class Fedit : public QMainWindow
{
    Q_OBJECT

public:
    explicit Fedit(QWidget *parent = 0);
    ~Fedit();

private:
    Ui::Fedit *ui;
};

#endif // FEDIT_H
