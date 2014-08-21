#include "fedit.h"
#include "ui_fedit.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QString>
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
    openFile();
}

void Fedit::on_saveButton_clicked()
{
    saveFileAs();
}

void Fedit::on_searchButton_clicked()
{
    std::cout << "hello search button" << std::endl; //SC
}

/*Helper methods*/

void Fedit::openFile(){
    //Display an open file dialog
    QFileDialog dialog;
    QString fileName = dialog.getOpenFileName(this,
                           tr("Open File"));

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

//Prompts the user with a file-dialog and returns the selected file name.
void Fedit::saveFileAs(){
    //Prompt the user for an output file
    QFileDialog dialog;
    QString fileName =
            dialog.getSaveFileName(this, tr("Save"));

    //Write the textEdit contents to the output file.
    saveFile(fileName);
}

//Saves the text in the textEdit widget to a file of the passed-in name.
void Fedit::saveFile(const QString &fileName){

    //Initialize the output file
    QFile file(fileName);
    file.open(QFile::WriteOnly | QFile::Text);

    //Write the textEdit contents to the output file
    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
}


