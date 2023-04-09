#include "myeventfilter.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyEventfilter w;
    w.show();
    return a.exec();
}
