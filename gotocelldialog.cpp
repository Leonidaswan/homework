// Class implementation.
// Author:wanlukuan
// Date:2023-3-15

#include "gotocelldialog.h"
#include <QRegularExpression>
#include <QValidator>
#include "./ui_gotocelldialog.h"

GoToCellDialog::GoToCellDialog(QWidget *parent)
    : QDialog(parent)
    , _ui(new Ui::GoToCellDialog)
{
    _ui->setupUi(this);
    QRegularExpression regExp("[A-Za-z][1-9][0-9]{0,2}");
    _ui->lineEdit->setValidator(new QRegularExpressionValidator(regExp, this));

    connect(_ui->okButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(_ui->cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void GoToCellDialog::on_lineEdit_textChanged()
{
    _ui->okButton->setEnabled(_ui->lineEdit->hasAcceptableInput());
}

GoToCellDialog::~GoToCellDialog()
{
    delete _ui;
}

