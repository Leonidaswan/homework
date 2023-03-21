#include <QApplication>

#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDialog *finddialog = new QDialog;
    finddialog->setWindowTitle("Find");

    QLabel *label = new QLabel("Find &what:");
    QLineEdit *lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);

    QCheckBox *caseCheckBOX = new QCheckBox("Match &case");
    QCheckBox *backwardCheckBox = new QCheckBox("Search &backward");

    QPushButton *findButton = new QPushButton("&Find");
    findButton->setDefault(true);
    findButton->setEnabled(false);

    QPushButton *closeButton = new QPushButton("&Close");

    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBOX);
    leftLayout->addWidget(backwardCheckBox);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    finddialog->setLayout(mainLayout);

    QObject::connect(closeButton, SIGNAL(clicked(bool)),
            &a, SLOT(quit()));

    finddialog->show();
    return a.exec();
}
