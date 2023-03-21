// main function
// author:wanlukuan
// date: 2023-3-15

#include "gotocelldialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GoToCellDialog w;
    w.show();
    return a.exec();
}
