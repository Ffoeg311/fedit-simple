#include "fedit.h"
#include "ui_fedit.h"

Fedit::Fedit(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Fedit)
{
    ui->setupUi(this);
}

Fedit::~Fedit()
{
    delete ui;
}
