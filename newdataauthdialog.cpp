#include "newdataauthdialog.h"
#include "ui_newdataauthdialog.h"

newDataAuthDialog::newDataAuthDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newDataAuthDialog)
{
    ui->setupUi(this);
}

newDataAuthDialog::~newDataAuthDialog()
{
    delete ui;
}

void newDataAuthDialog::setUsernametext(QString text)
{
    ui->labelUsername->setText(text);
}

void newDataAuthDialog::setEmailText(QString text)
{
    ui->labelEmail->setText(text);
}

void newDataAuthDialog::setFileText(QString text)
{
    ui->labelFile->setText(text);
}
