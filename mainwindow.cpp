#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>
#include <QFontDialog>
#include <QMessageBox>

#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printer)
#if QT_CONFIG(printdialog)
#include <QPrintDialog>
#endif
#include <QPrinter>
#endif
#endif

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

#if !QT_CONFIG(printer)
    ui->print->setEnabled(false);
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}

//新建文件
void MainWindow::on_actionnew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText("");
}

//打开文件
void MainWindow::on_actionopen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"open file");
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,"warning","open file failed: "+file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

//保存文件
void MainWindow::on_actionsave_triggered()
{
    QString fileName;
    if(currentFile.isEmpty()){
        fileName =QFileDialog::getSaveFileName(this,"保存文件");
        currentFile =fileName;
    }else{
        fileName =currentFile;
    }
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly|QFile::Text)){
        QMessageBox::warning(this,"警告","无法保存文件:"+file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text =ui->textEdit->toPlainText();
    out<<text;
    file.close();
}

//另存为
void MainWindow::on_actionsaveas_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"另存文件");
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly|QFile::Text)){
        QMessageBox::warning(this,"警告","无法保存文件:"+file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<<text;
    file.close();
}

//打印
void MainWindow::on_actionprint_triggered()
{
#if defined(QT_PRINTSUPPORT_LIB) && QT_CONFIG(printer)
    QPrinter printDev;
#if QT_CONFIG(printdialog)
    QPrintDialog dialog(&printDev,this);
    if(dialog.exec()==QDialog::Rejected)
        return;
#endif
    ui->textEdit->print(&printDev);
#endif
}

//复制
void MainWindow::on_actioncopy_triggered()
{
    ui->textEdit->copy();
}

//粘贴
void MainWindow::on_actionpaste_triggered()
{
    ui->textEdit->paste();
}

//剪切
void MainWindow::on_actioncut_triggered()
{
    ui->textEdit->cut();
}

//加粗
void MainWindow::on_actionbold_triggered(bool checked)
{
    ui->textEdit->setFontWeight(checked?QFont::Bold:QFont::Normal);
}

//斜体
void MainWindow::on_actionitalic_triggered(bool checked)
{
    ui->textEdit->setFontItalic(checked);
}

//下划线
void MainWindow::on_actionunderline_triggered(bool checked)
{
    ui->textEdit->setFontUnderline(checked);
}

//关于
void MainWindow::on_actionabout_triggered()
{
    QMessageBox::about(this,"关于","这是我的Notepad！");
}

//退出
void MainWindow::on_actionexit_triggered()
{
    qApp->exit();
}

//字体设置
void MainWindow::on_actionfont_triggered()
{
    bool fontSelected;
    QFont font = QFontDialog::getFont(&fontSelected,this);
    if(fontSelected){
        ui->textEdit->setFont(font);
    }
}

//撤销
void MainWindow::on_actionundo_triggered()
{
    ui->textEdit->undo();
}

//取消撤销
void MainWindow::on_actionredu_triggered()
{
    ui->textEdit->redo();
}

