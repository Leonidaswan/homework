#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

class Button : public QPushButton
{
    Q_OBJECT
public:
    Button(QWidget *parent = nullptr);

protected:
    virtual bool event(QEvent *event)override;
    virtual void timerEvent(QTimerEvent *event)override;

private:
    void mouseClick();

private:
    int m_timerId;
};

#endif // BUTTON_H
