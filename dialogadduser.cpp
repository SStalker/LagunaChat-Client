#include "dialogadduser.h"
#include "ui_dialogadduser.h"

DialogAddUser::DialogAddUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddUser)
{
    ui->setupUi(this);

    connect(ui->lineEditEmail,SIGNAL(textChanged(QString)),this,SLOT(getEmail(QString)));
}

DialogAddUser::~DialogAddUser()
{
    delete ui;
}

QString DialogAddUser::getEmail()
{
    return this->email;
}

void DialogAddUser::getEmail(QString email)
{
    this->email = email;
}
