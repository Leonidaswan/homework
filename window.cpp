//
// author:wanlukuan
// date:2023-4-16

#include "window.h"
#include <QMouseEvent>
#include "button.h"

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    setGeometry(400,300,100,90);

    _label = new QLabel{"hello Qt",this};
    _label->setAlignment(Qt::AlignCenter);
    _label->setGeometry(10,10,80,30);

    _button = new Button{this};
    _button->setGeometry(10,50,80,30);
}

Window::~Window()
{
}


