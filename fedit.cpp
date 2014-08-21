#include "fedit.h"
#include "ui_fedit.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
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

/*Methods for the pushButtons*/

void Fedit::on_newButton_clicked(){
    newFile();
}

void Fedit::on_openButton_clicked(){
    open();
}

void Fedit::on_saveAsButton_clicked(){
    saveFileAs();
}

void Fedit::on_saveButton_clicked(){
    save();
}

/*Helper methods****************************************************/

void Fedit::newFile()
{
    //only continue if the user says its ok.
    bool contin = warnUserNew();
    if(contin){
        emptyTextEditor();
        saveFileName = "untitled";
    }
}

//warn the user that unsaved progress will be lost when starting anew
bool Fedit::warnUserNew(){
    QMessageBox msgBox;
    msgBox.setText("Any unsaved changes will be lost.");
    msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    int ret = msgBox.exec();
    switch (ret) {
       case QMessageBox::Cancel:
            return false;
            break;
        case QMessageBox::Ok:
            return true;
            break;
       default: // should never be reached
           return false;
           break;
    }
}

void Fedit::emptyTextEditor(){
    ui->textEdit->clear();
}

//Prompts user for a file and displays it to textEdit
void Fedit::open()
{
    QFileDialog dialog;
    QString fileName = dialog.getOpenFileName(this,
                           tr("Open File"));
    openFile(fileName);
}

//Opens a file with the passed in filepath and displays it in textEdit
void Fedit::openFile(const QString &fileName)
{
    //Open the requested file
    QFile inputFile(fileName);
    inputFile.open(QIODevice::ReadWrite);

    //Load the requested file into memory
    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();

    //Spit the file onto the qlabel
    ui->textEdit->setText(line);

    //Let future file saves to know to save it here.
    saveFileName = fileName;
}

//Prompts the user with a file-dialog saves it.
void Fedit::saveFileAs()
{
    QFileDialog dialog;
    saveFileName =
            dialog.getSaveFileName(this, tr("Save"));
    save();
}

void Fedit::save(){
    saveFile(saveFileName);
}

//Saves the text in the textEdit widget to a file of the passed-in name.
void Fedit::saveFile(const QString &fileName)
{
    //Initialize the output file and open it
    QFile file(fileName);
    file.open(QFile::WriteOnly | QFile::Text);

    //Write the textEdit contents to the output file
    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
}
