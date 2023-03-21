#include "finddialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FindDialog *finddialog = new FindDialog;
    finddialog->show();
    return a.exec();
}
