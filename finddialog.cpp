//use object tree to realize.
//author: wanlukuan
//data: 2023-3-5
#include "finddialog.h"

#include <QtGui>

FindDialog::FindDialog(QWidget *parent)
    : QDialog(parent)
{
    new QLabel{"Find &what:",this};
    new QLineEdit{this};
    new QCheckBox{"Match &case",this};
    new QCheckBox{"Search &backward",this};
    new QPushButton{"&Find",this};
    new QPushButton{"&Close",this};

    auto label = this->findChild<QLabel *>();
    auto lineEdit = this->findChild<QLineEdit *>();
    auto checkBox = this->findChildren<QCheckBox *>();
    auto pushButton = this->findChildren<QPushButton *>();

    label->setBuddy(lineEdit);

    pushButton[0]->setDefault(true);
    pushButton[0]->setEnabled(false);

    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(checkBox[0]);
    leftLayout->addWidget(checkBox[1]);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(pushButton[0]);
    rightLayout->addWidget(pushButton[1]);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);
    setWindowTitle("Find");
    setFixedHeight(sizeHint().height());

    connect(lineEdit, &QLineEdit::textChanged,
            this, &FindDialog::enableFindButton);
    connect(pushButton[0], &QPushButton::clicked,
            this, &FindDialog::findClicked);
    connect(pushButton[1], &QPushButton::clicked,
            this, &FindDialog::close);
}

void FindDialog::findClicked()
{
    QString text = this->findChild<QLineEdit *>()->text();
    auto cb = this->findChildren<QCheckBox *>();
    Qt::CaseSensitivity cs =
        cb[0]->isChecked() ? Qt::CaseSensitive
                           : Qt::CaseInsensitive;
    if(cb[1]->isChecked()){
        emit findPrevious(text, cs);
    }else{
        emit findNext(text, cs);
    }
}

void FindDialog::enableFindButton(const QString &text)
{
    auto pb = this->findChildren<QPushButton *>();
    pb[0]->setEnabled(!text.isEmpty());
}

FindDialog::~FindDialog()
{
}

