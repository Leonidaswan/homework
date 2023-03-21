//class FindDialog
//author: wanlukuan
//data: 2023-3-5

#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include <QtWidgets>

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    FindDialog(QWidget *parent = nullptr);
    ~FindDialog();

signals:
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private slots:
    void findClicked();
    void enableFindButton(const QString &text);

//private:
//    QLabel *_label;
//    QLineEdit *_lineEdit;
//    QCheckBox *_caseCheckBOX;
//    QCheckBox *_backwardCheckBox;
//    QPushButton *_findButton;
//    QPushButton *_closeButton;
};
#endif // FINDDIALOG_H
