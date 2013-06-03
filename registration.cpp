#include "registration.h"
#include "ui_registration.h"

#include <QCryptographicHash>

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);

    connect(ui->lineEdit_registration_email,SIGNAL(textChanged(QString)),this,SLOT(getEmail(QString)));
    connect(ui->lineEdit_registration_password,SIGNAL(textChanged(QString)),this,SLOT(getPasswordFirst(QString)));
    connect(ui->lineEdit_registration_password_2,SIGNAL(textChanged(QString)),this,SLOT(getPasswordSecond(QString)));
    connect(ui->lineEdit_registration_username,SIGNAL(textChanged(QString)),this,SLOT(getUsername(QString)));
}

Registration::~Registration()
{
    delete ui;
}

void Registration::getEmail(QString email)
{
    this->email = email;
}

void Registration::getUsername(QString username)
{
    this->username = username;
}

void Registration::getPasswordFirst(QString pass)
{
    this->passwordFirst = QString(QCryptographicHash::hash((pass.toUtf8()),QCryptographicHash::Md5).toHex());
}

void Registration::getPasswordSecond(QString pass)
{
    this->passwordSecond = QString(QCryptographicHash::hash((pass.toUtf8()),QCryptographicHash::Md5).toHex());
}



QString Registration::getEmail()
{
    return this->email;
}

QString Registration::getUsername()
{
    return this->username;
}

QString Registration::getPasswordFirst()
{
    return this->passwordFirst;
}

QString Registration::getPasswordSecond()
{
    return this->passwordSecond;
}
