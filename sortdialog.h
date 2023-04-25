// sort dialog
// author:stardust
// date: 2023-04-21
// 采用指针的方式来实现SortDialog类和Ui::sort_bridge类的组合关系
// Ui::sort_bridge类存放在ui_sort.h中，该头文件是通过编译sort.ui文件自动生成的。
#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>

namespace Ui {
class sort_bridge;
}

class SortDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SortDialog(QWidget *parent = 0);
    ~SortDialog();
    void setColumnRange(QChar first, QChar last);

    int primaryColumnComboCurrentIndex();
    int secondaryColumnComboCurrentIndex();
    int tertiaryColumnComboCurrentIndex();

    int primaryOrderComboCurrentIndex();
    int secondaryOrderComboCurrentIndex();
    int tertiaryOrderComboCurrentIndex();

private:
    Ui::sort_bridge *_ui;
};

#endif // SORTDIALOG_H
