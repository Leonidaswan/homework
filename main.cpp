// use QtDesigner to design ui
// Author: wanlukuan
// Date: 2023-3-5

#include <QApplication>
#include "ui_finddialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ui::Bridge uib;

    QDialog finddialog;

    uib.setupUi(&finddialog);

    finddialog.show();
    return a.exec();
}
