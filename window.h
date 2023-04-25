/*
 * connect main window with multiple dialog boxes.
 *
 * author: wanlukuan
 * date:2023-4-23
 *
 */


#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Window_bridge; }
QT_END_NAMESPACE

class FindDialog;
class GoToCellDialog;

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

private slots:
    void on_action_Find_triggered();

    void on_action_Go_to_Cell_triggered();

    void on_action_Sort_triggered();

    void on_action_New_triggered();

private:
    FindDialog *_findDialog;
    GoToCellDialog *_gotocell;

    Ui::Window_bridge *ui;
};
#endif // WINDOW_H
