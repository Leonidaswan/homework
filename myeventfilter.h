// use eventfilter to filter and handle event.
// author:wanlukuan
// date:2023-4-9

#ifndef MYEVENTFILTER_H
#define MYEVENTFILTER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class MyEventfilter : public QWidget
{
    Q_OBJECT

public:
    MyEventfilter(QWidget *parent = nullptr);
    ~MyEventfilter();

    virtual bool eventFilter(QObject *watched, QEvent *event) override;

private:
    QLabel *_label;
    QPushButton *_button;
};
#endif // MYEVENTFILTER_H
