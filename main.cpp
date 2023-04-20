// use QtDesigner to design ui
// Author: wanlukuan
// Date: 2023-4-20

#include <QApplication>
#include "finddialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Finddialog finddialog;
    finddialog.show();
    return a.exec();
}
