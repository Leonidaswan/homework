#include "window.h"
#include "./ui_window.h"

#include "finddialog.h"
#include "gotocelldialog.h"
#include "sortdialog.h"

Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window_bridge)
    , _findDialog(nullptr)
    , _gotocell(nullptr)
{
    ui->setupUi(this);
}

Window::~Window()
{
    delete ui;
}


void Window::on_action_Find_triggered()
{
    if(!_findDialog){
        _findDialog = new FindDialog{this};
        connect(_findDialog, &FindDialog::findNext, ui->spreadsheet, &Spreadsheet::findNext);
        connect(_findDialog, &FindDialog::findPrevious, ui->spreadsheet, &Spreadsheet::findPrevious);
    }
    _findDialog->show();
    _findDialog->raise();
    _findDialog->activateWindow();
}


void Window::on_action_Go_to_Cell_triggered()
{
    _gotocell = new GoToCellDialog{this};
    if(_gotocell->exec()){
        QString str = _gotocell->getCellLocation();
        ui->spreadsheet->setCurrentCell(str.mid(1).toInt() - 1,
                                        str[0].unicode() - 'A');
    }
}

void Window::on_action_Sort_triggered()
{
    SortDialog sortDialog{this};
    QTableWidgetSelectionRange range = ui->spreadsheet->selectedRange();
    sortDialog.setColumnRange(QChar('A' + range.leftColumn()),
                              QChar('A' + range.rightColumn()));

    if(sortDialog.exec()){
        SpreadsheetCompare compare;
        compare.keys[0] =
            sortDialog.primaryColumnComboCurrentIndex();
        compare.keys[1] =
            sortDialog.secondaryColumnComboCurrentIndex()-1;
        compare.keys[2] =
            sortDialog.tertiaryColumnComboCurrentIndex()-1;
        compare.ascending[0] =
            (sortDialog.primaryOrderComboCurrentIndex()==0);
        compare.ascending[1] =
            (sortDialog.secondaryOrderComboCurrentIndex()==0);
        compare.ascending[2] =
            (sortDialog.tertiaryOrderComboCurrentIndex()==0);
        ui->spreadsheet->sort(compare);
    }

}


void Window::on_action_New_triggered()
{
    qDebug()<<"todo new file.";
}

