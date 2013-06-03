#include "dialogdeletefriendship.h"
#include "ui_dialogdeletefriendship.h"

DialogDeleteFriendship::DialogDeleteFriendship(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDeleteFriendship)
{
    ui->setupUi(this);

    connect(ui->lineEditEmail,SIGNAL(textChanged(QString)),this,SLOT(getEmail(QString)));
}

DialogDeleteFriendship::~DialogDeleteFriendship()
{
    delete ui;
}

QString DialogDeleteFriendship::getEmail()
{
    return this->email;
}

void DialogDeleteFriendship::getEmail(QString email)
{
    this->email = email;
}
