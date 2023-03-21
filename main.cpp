//
// Author:wanlukuan
// Date:2023-3-18

#include "sortdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SortDialog *dialog = new SortDialog;
    dialog->setColumnRange('C','F');
    dialog->show();
    return a.exec();
}
