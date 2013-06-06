#include "error.h"
#include <QMessageBox>

Error::Error()
{
}

void Error::loginFailed()
{
    QMessageBox msgBox;
    msgBox.setText("Login failed!\nThe username and/or password is wrong");
    msgBox.setWindowTitle("Infomation");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}

void Error::registrationFailed()
{
    QMessageBox msgBox;
    msgBox.setText("Registration failed!\nThe email is already used");
    msgBox.setWindowTitle("Infomation");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}

void Error::sendFileFailedOffline()
{
    QMessageBox msgBox;
    msgBox.setText("Send File to User failed!\nThe user is offline");
    msgBox.setWindowTitle("Infomation");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}
