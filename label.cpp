// 可观察事件在四个层次的传递，如果不处理，则事件由焦点逐步向父对象传递
// author:wanlukuan
// date:2023-4-16

#include "label.h"
#include <QMouseEvent>
#include <QDebug>

Label::Label(QWidget *parent)
    : QLabel{parent}
{
    setText("event test");
    setBackgroundRole(QPalette::Dark);  //设置背景颜色
    setAutoFillBackground(true);        //颜色自动填充
}

bool Label::event(QEvent *e)
{
    if(e->type()==QEvent::MouseMove){
        QMouseEvent *event = static_cast<QMouseEvent *>(e);
        move(event->scenePosition().toPoint());
        qDebug()<<"move in Label::event";
//        return true;     //处理完事件返回true
        event->accept();   
    }
    return QWidget::event(e);
}
