#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
#include <QPushButton>

class Label : public QLabel
{
    Q_OBJECT
public:
    Label(QWidget *parent = nullptr);

    virtual bool event(QEvent *e)override;

};

#endif // LABEL_H
