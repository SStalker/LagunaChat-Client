#ifndef NEWDATAAUTHDIALOG_H
#define NEWDATAAUTHDIALOG_H

#include <QDialog>

namespace Ui {
class newDataAuthDialog;
}

class newDataAuthDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit newDataAuthDialog(QWidget *parent = 0);
    ~newDataAuthDialog();
    void setEmailText(QString text);
    void setUsernametext(QString text);
    void setFileText(QString text);
    
private:
    Ui::newDataAuthDialog *ui;


};

#endif // NEWDATAAUTHDIALOG_H
