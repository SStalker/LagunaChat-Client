#ifndef NEWUSERAUTHDIALOG_H
#define NEWUSERAUTHDIALOG_H

#include <QDialog>

namespace Ui {
class newUserAuthDialog;
}

class newUserAuthDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit newUserAuthDialog(QWidget *parent = 0);
    ~newUserAuthDialog();
    void setEmailText(QString text);
    void setUsernametext(QString text);
    
private:
    Ui::newUserAuthDialog *ui;


};

#endif // NEWUSERAUTHDIALOG_H
