// 利用组合的方法与ui桥梁类相关联
// Author: wanlukuan
// Date: 2023-4-20

#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class bridge;}
QT_END_NAMESPACE


class Finddialog : public QDialog
{
    Q_OBJECT
public:
    explicit Finddialog(QWidget *parent = nullptr);
    ~Finddialog();

signals:
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private slots:
    void enableButton(const QString &text);
    void findClicked();

private:
    Ui::bridge *_ui;
};

#endif // FINDDIALOG_H
