// Class implementation.
// Author:wanlukuan
// Date:2023-3-18

#include "sortdialog.h"
#include <QtGui>
#include <QSize>
#include "./ui_sortdialog.h"

SortDialog::SortDialog(QWidget *parent)
    : QDialog(parent)
    ,_ui{new Ui::SortDialog}
{
    _ui->setupUi(this);

    _ui->secondaryGroupBox->hide();
    _ui->tertiaryGroupBox->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    setColumnRange('A','Z');
}

void SortDialog::setColumnRange(QChar first, QChar last)
{
    _ui->primaryColumnCombo->clear();
    _ui->secondaryColumnCombo->clear();
    _ui->tertiaryColumnCombo->clear();

    _ui->secondaryColumnCombo->addItem(tr("None"));
    _ui->tertiaryColumnCombo->addItem(tr("None"));
    _ui->primaryColumnCombo->setMinimumSize(_ui->secondaryColumnCombo->sizeHint());

    QChar ch = first;
    while (ch <= last){
        _ui->primaryColumnCombo->addItem(QString(ch));
        _ui->secondaryColumnCombo->addItem(QString(ch));
        _ui->tertiaryColumnCombo->addItem(QString(ch));
        ch = (QChar)(ch.unicode() + 1);
    }
}

SortDialog::~SortDialog()
{
    delete _ui;
}

