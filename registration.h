#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>

namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = 0);
    ~Registration();
    QString getEmail();
    QString getPasswordFirst();
    QString getPasswordSecond();
    QString getUsername();
    
private:
    Ui::Registration *ui;
    QString email;
    QString username;
    QString passwordFirst;
    QString passwordSecond;

public slots:
    void getEmail(QString email);
    void getUsername(QString username);
    void getPasswordSecond(QString second);
    void getPasswordFirst(QString first);
};

#endif // REGISTRATION_H
