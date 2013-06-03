#ifndef DIALOGADDUSER_H
#define DIALOGADDUSER_H

#include <QDialog>

namespace Ui {
class DialogAddUser;
}

class DialogAddUser : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogAddUser(QWidget *parent = 0);
    ~DialogAddUser();
    QString getEmail();
    
private:
    Ui::DialogAddUser *ui;
    QString email;

public slots:
    void getEmail(QString mail);
};

#endif // DIALOGADDUSER_H
