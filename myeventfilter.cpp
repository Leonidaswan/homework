// use eventfilter to filter and handle event.
// author:wanlukuan
// date:2023-4-9

#include "myeventfilter.h"

#include <QEvent>
#include <QDebug>
#include <QMouseEvent>

MyEventfilter::MyEventfilter(QWidget *parent)
    : QWidget(parent)
{
    setGeometry(500,300,500,500);
    _label = new QLabel{"eventfilter.",this};
    _button = new QPushButton{"exit",this};

    _label->setGeometry(10,10,80,30);
    _button->setGeometry(10,40,80,30);

    //安装事件过滤器
    _label->installEventFilter(this);
    _button->installEventFilter(this);
}

MyEventfilter::~MyEventfilter()
{
}

bool MyEventfilter::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==_label){
        if(event->type()==QEvent::MouseMove){
            QMouseEvent *e = static_cast<QMouseEvent *>(event);
            _label->move(e->scenePosition().toPoint());
            qDebug()<<"move _label event.";
            e->accept();
            return true;
        }
//        if(event->type()==QEvent::MouseButtonPress){
//            qDebug()<<"eventfilter:_label pressed.";
//            event->accept();
//            return true;
//        }
    }
    if(watched==_button){
        if(event->type()==QEvent::MouseButtonPress){
            QMouseEvent *e = static_cast<QMouseEvent *>(event);
            if(e->button()==Qt::LeftButton){
                qDebug()<<"eventfilter::_button::event";
                exit(EXIT_SUCCESS);
            }else{
                return false;    //e->ignore();  //右键按下不处理
            }

        }
    }
    return QWidget::eventFilter(watched,event);
}

