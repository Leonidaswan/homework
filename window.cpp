// 可观察事件在四个层次的传递，如果不处理，则事件由焦点逐步向父对象传递
// author:wanlukuan
// date:2023-4-16

#include "window.h"
#include <QMouseEvent>
#include "label.h"

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    setGeometry(300,300,400,400);

    //连续创建三个层次子类
    _label = new Label{this};
    _label->setGeometry(0,0,200,200);
    _label = new Label{_label};
    _label->setGeometry(0,0,120,80);
    _label->setText("first label child");
    _label = new Label{_label};
    _label->setGeometry(0,0,120,35);
    _label->setText("second label child");
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

