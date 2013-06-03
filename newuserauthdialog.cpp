#include "newuserauthdialog.h"
#include "ui_newuserauthdialog.h"

newUserAuthDialog::newUserAuthDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newUserAuthDialog)
{
    ui->setupUi(this);
}

newUserAuthDialog::~newUserAuthDialog()
{
    delete ui;
}

void newUserAuthDialog::setUsernametext(QString text)
{
    ui->labelUsername->setText(text);
}

void newUserAuthDialog::setEmailText(QString text)
{
    ui->labelEmail->setText(text);
}
