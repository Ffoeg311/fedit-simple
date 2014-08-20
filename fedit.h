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
    void on_openButtonEditor_clicked();
    void on_saveButtonEditor_clicked();
    void on_searchButtonEdit_clicked();
    void on_cancelButton_ow_clicked();
    void on_openButton_ow_clicked();

private:
    Ui::Fedit *ui;
    void switchToOpenWidget();
    void switchToEditorWidget();
};

#endif // FEDIT_H
