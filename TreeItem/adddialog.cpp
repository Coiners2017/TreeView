#include "adddialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
AddDialog::AddDialog(QWidget *parent):QDialog(parent)
{
    label = new QLabel(tr("Find &what:"));
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);
    findButton = new QPushButton(tr("&OK"));
    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButton = new QPushButton(tr("Close"));

    connect(lineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(enableFindButton(const QString&)));
    connect(findButton, SIGNAL(clicked()), this, SLOT(findClicked()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    QHBoxLayout *rightLayout = new QHBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLeftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("工作组信息"));
    setFixedHeight(sizeHint().height());
}

AddDialog::~AddDialog()
{

}

void AddDialog::findClicked()
{
    QString text = lineEdit->text();
    emit sendData(lineEdit->text());
    //          Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseInsensitive : Qt::CaseSensitive;
    //          if(backwardCheckBox->isChecked()) {
    //                  emit findPrevious(text, cs);
    //          } else {
    //                  emit findNext(text, cs);
    //          }
    this->close();

}

void AddDialog::enableFindButton(const QString &text)
{
    findButton->setEnabled(!text.isEmpty());
}
