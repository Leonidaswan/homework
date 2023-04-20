#include "finddialog.h"

#include "ui_finddialog.h"

Finddialog::Finddialog(QWidget *parent)
    :QDialog(parent),_ui(new Ui::bridge)
{
    _ui->setupUi(this);

    connect(_ui->closeButton, &QPushButton::clicked, this, &Finddialog::close);
    connect(_ui->lineEdit, &QLineEdit::textChanged, this, &Finddialog::enableButton);
    connect(_ui->findButton, &QPushButton::clicked, this, &Finddialog::findClicked);
}

Finddialog::~Finddialog()
{

}

void Finddialog::enableButton(const QString &text)
{
    _ui->findButton->setEnabled(!text.isEmpty());
}

void Finddialog::findClicked()
{
    Qt::CaseSensitivity cs =
        _ui->caseCheckBox->isChecked() ? Qt::CaseSensitive
                                       :Qt::CaseInsensitive;
    if(_ui->caseCheckBox->isChecked()){
        cs = Qt::CaseSensitive;
    }else{
        cs = Qt::CaseInsensitive;
    }

    QString text = _ui->lineEdit->text();
    if(_ui->backwardCheckBox->isChecked()){
        emit findPrevious(text, cs);
        qDebug()<<"Singal findPrevious is emitted.";
    }else{
        emit findNext(text, cs);
        qDebug()<<"Singal findNext is emitted.";
    }
}
