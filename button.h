#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

class Button : public QPushButton
{
    Q_OBJECT
public:
    Button(QWidget *parent = nullptr);

    virtual bool event(QEvent *event)override;
};

#endif // BUTTON_H
