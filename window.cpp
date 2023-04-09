#include "window.h"
#include <QMouseEvent>
#include "label.h"

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    _label = new Label{this};
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

