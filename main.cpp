#include "fedit.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Fedit w;
    w.show();

    return a.exec();
}
