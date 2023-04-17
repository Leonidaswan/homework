// 使用定时器判断鼠标点击和松开的间隔，决定是否调用自定义事件处理器
// author:wanlukuan
// date:2023-4-16

#include "button.h"

#include <QApplication>
#include <QMouseEvent>

Button::Button(QWidget *parent)
    :QPushButton(parent)
{
    setText("Exit");
}

bool Button::event(QEvent *event)
{
    if(event->type()==QEvent::MouseButtonPress){
        m_timerId = startTimer(300);    //创建并启动定时器，返回定时器ID
    }
    if(event->type()==QEvent::MouseButtonRelease){
        if(m_timerId!=0){   //未超时
            killTimer(m_timerId);   //关闭定时器
            mouseClick();
//            qDebug()<<"release. kill timer"<<m_timerId;
        }else{
            event->ignore();
        }
    }
    return QWidget::event(event);
}

void Button::timerEvent(QTimerEvent *event)     //超时处理
{
//    qDebug()<<"time out...";
    killTimer(m_timerId);
    m_timerId = 0;
}

void Button::mouseClick()
{
    QApplication::quit();
}
