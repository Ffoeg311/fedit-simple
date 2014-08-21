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
    void on_saveButton_clicked();
    void on_searchButton_clicked();

private:
    Ui::Fedit *ui;
    void openFile();
    void saveFileAs();
    void saveFile(const QString &fileName);
};

#endif // FEDIT_H
