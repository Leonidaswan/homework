#include "button.h"

#include <QMouseEvent>

Button::Button(QWidget *parent)
    :QPushButton(parent)
{
    setText("OK");
//    setBackgroundRole(QPalette::Shadow);
//    setAutoFillBackground(true);
}

bool Button::event(QEvent *event)
{
    if(event->type()==QEvent::MouseMove){
        QMouseEvent *e = static_cast<QMouseEvent *>(event);
//        move(e->scenePosition().toPoint());
        qDebug()<<"move in button::event";
//        qDebug()<<"You press the button";
        return true;
//        e->accept();
    }
    return QWidget::event(event);
}
