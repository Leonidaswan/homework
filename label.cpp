#include "label.h"
#include <QMouseEvent>
#include <QDebug>
#include "button.h"

Label::Label(QWidget *parent)
    : QLabel{parent}
{
    setText("event test");
    setBackgroundRole(QPalette::Dark);
    setAutoFillBackground(true);

    _button = new Button{this};
//    _button->setGeometry(0,0,80,30);
}

bool Label::event(QEvent *e)
{
    if(e->type()==QEvent::MouseMove){
        QMouseEvent *event = static_cast<QMouseEvent *>(e);
        move(event->scenePosition().toPoint());
        qDebug()<<"move in Label::event";
        return true;
//        event->accept();
    }
    return QWidget::event(e);
}
