#include "fedit.h"
#include "ui_fedit.h"
#include <QFileDialog>
#include <iostream> //for testing

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

/*Methods for the textEditorPage buttons*/

void Fedit::on_openButtonEditor_clicked()
{
    std::cout << "hello open button" << std::endl; //SC
    switchToOpenWidget();
}

void Fedit::on_saveButtonEditor_clicked()
{
    std::cout << "hello save button" << std::endl; //SC
}

void Fedit::on_searchButtonEdit_clicked()
{
    std::cout << "hello search button" << std::endl; //SC
}

/*Methods for openFilePage buttons*/

void Fedit::on_cancelButton_ow_clicked()
{
    //std::cout << "hello cancel button" << std::endl; //SC
    switchToEditorWidget();
}

void Fedit::on_openButton_ow_clicked()
{
    //std::cout << "hello open button" << std::endl; //SC
}

/*Helper methods*/

void Fedit::switchToOpenWidget()
{
    QFileDialog::getOpenFileName(this,
         tr("Open File"));
}

void Fedit::switchToEditorWidget(){
    std::cout << "switching" << std::endl; //SC
    ui->stackedWidget->setCurrentWidget(ui->textEditorPage);
}

