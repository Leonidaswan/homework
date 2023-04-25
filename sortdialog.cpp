#include "sortdialog.h"
#include "ui_sort.h"
#include <iostream>

SortDialog::SortDialog(QWidget *parent) :
    QDialog(parent),
    _ui(new Ui::sort_bridge)
{
    _ui->setupUi(this);

    _ui->secondaryGroupBox->hide();
    _ui->tertiaryGroupBox->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    setColumnRange('A', 'Z');
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
    while(ch <= last){
        _ui->primaryColumnCombo->addItem(QString(ch));
        _ui->secondaryColumnCombo->addItem(QString(ch));
        _ui->tertiaryColumnCombo->addItem(QString(ch));
        //        std::cerr << std::showbase << std::hex << ch.unicode() << '\n'; //only valid in c++17
        ch = ++(ch.unicode());
    }
}

int SortDialog::primaryColumnComboCurrentIndex()
{
    return _ui->primaryColumnCombo->currentIndex();
}

int SortDialog::secondaryColumnComboCurrentIndex()
{
    return _ui->secondaryColumnCombo->currentIndex();
}

int SortDialog::tertiaryColumnComboCurrentIndex()
{
    return _ui->tertiaryColumnCombo->currentIndex();
}

int SortDialog::primaryOrderComboCurrentIndex()
{
    return _ui->primaryOrderCombo->currentIndex();
}

int SortDialog::secondaryOrderComboCurrentIndex()
{
    return _ui->secondaryOrderCombo->currentIndex();
}

int SortDialog::tertiaryOrderComboCurrentIndex()
{
    return _ui->tertiaryOrderCombo->currentIndex();
}

SortDialog::~SortDialog()
{
    delete _ui;
}
