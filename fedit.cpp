#include "fedit.h"
#include "ui_fedit.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
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

void Fedit::on_openButton_clicked()
{
    //std::cout << "hello open button" << std::endl; //SC
    openFile();
}

void Fedit::on_saveButton_clicked()
{
    std::cout << "hello save button" << std::endl; //SC
}

void Fedit::on_searchButton_clicked()
{
    std::cout << "hello search button" << std::endl; //SC
}

/*Methods for openFilePage buttons*/

/*Helper methods*/

void Fedit::openFile()
{
    QFileDialog dialog;
    QString fileName = dialog.getOpenFileName(this,
                           tr("Open File"));
    std::string test = fileName.toStdString();
    std::cout << test << std::endl; //SC

    //Open the requested file
    QFile inputFile(fileName);
    inputFile.open(QIODevice::ReadWrite);

    //Load the requested file into memory
    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();

    //Spit the file onto the qlabel
    ui->textEdit->setText(line);
}

