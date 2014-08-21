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

private slots:
    void on_openButton_clicked();
    void on_saveAsButton_clicked();
    void on_newButton_clicked();
    void on_saveButton_clicked();

private:
    Ui::Fedit *ui;
    QString saveFileName;

private:
    void newFile();
    bool warnUserNew();
    void emptyTextEditor();
    void open();
    void openFile(const QString &fileName);
    void saveFileAs();
    void save();
    void saveFile(const QString &fileName);
};

#endif // FEDIT_H
