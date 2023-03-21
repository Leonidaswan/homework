#include <QApplication>
#include <QLabel>
#include <memory>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    auto label = std::make_unique<QLabel>("<h2><i>Hello</i> "
                                "<font color=red>Qt!</font></h2>");
    label->show();
    return app.exec();
}
