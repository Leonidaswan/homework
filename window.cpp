#include "window.h"
#include <QMouseEvent>
#include "label.h"
#include "button.h"

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    setGeometry(300,300,200,200);
    _label = new Label{this};
//    _button = new Button{this};
    _label->setGeometry(20,20,80,100);
//    _button->setGeometry(20,50,80,30);
}

Window::~Window()
{
}

bool Window::event(QEvent *event)
{
    if(event->type()==QEvent::MouseMove){
        qDebug()<<"move in window::event";
        return true;
//        event->accept();
    }
    return QWidget::event(event);
}

