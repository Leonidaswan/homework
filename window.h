#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

    virtual bool event(QEvent *event)override;

private:
    QLabel *_label;
//    QPushButton *_button;
};
#endif // WINDOW_H
