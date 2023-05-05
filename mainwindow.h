/*
 * 文本编辑器，实现了新建、打开、保存等基本功能
 * Author:wanlukuan
 * Date:2023-5-1
 * Version:0.1.0
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionnew_triggered();

    void on_actionopen_triggered();

    void on_actionsave_triggered();

    void on_actionsaveas_triggered();

    void on_actionprint_triggered();

    void on_actioncopy_triggered();

    void on_actionpaste_triggered();

    void on_actioncut_triggered();

    void on_actionbold_triggered(bool checked);

    void on_actionitalic_triggered(bool checked);

    void on_actionunderline_triggered(bool checked);

    void on_actionabout_triggered();

    void on_actionexit_triggered();

    void on_actionfont_triggered();

    void on_actionundo_triggered();

    void on_actionredu_triggered();

private:
    QString currentFile;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
