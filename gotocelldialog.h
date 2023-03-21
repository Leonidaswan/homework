// Use pointer member integration.
// Author:wanlukuan
// Date:2023-3-15

#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class GoToCellDialog; }
QT_END_NAMESPACE

class GoToCellDialog : public QDialog
{
    Q_OBJECT

public:
    GoToCellDialog(QWidget *parent = nullptr);
    ~GoToCellDialog();

private slots:
    void on_lineEdit_textChanged();

private:
    Ui::GoToCellDialog *_ui;
};
#endif // GOTOCELLDIALOG_H
