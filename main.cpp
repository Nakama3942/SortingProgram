#include "sortingprogram.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SortingProgram w;
    w.show();
    return a.exec();
}
