#include "readablewadlwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ReadableWadlWindow w;
    w.show();

    return a.exec();
}
