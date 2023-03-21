//
//author: wanlukuan
//data: 2023-3-5
#include <QApplication>
#include <memory>

#include "finddialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto finddialog = std::make_unique<FindDialog>();

    finddialog->show();
    return a.exec();
}
