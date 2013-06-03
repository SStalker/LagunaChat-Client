#ifndef DIALOGDELETEFRIENDSHIP_H
#define DIALOGDELETEFRIENDSHIP_H

#include <QDialog>

namespace Ui {
class DialogDeleteFriendship;
}

class DialogDeleteFriendship : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogDeleteFriendship(QWidget *parent = 0);
    ~DialogDeleteFriendship();
    QString getEmail();
    
private:
    Ui::DialogDeleteFriendship *ui;
    QString email;

public slots:
    void getEmail(QString mail);
};

#endif // DIALOGDELETEFRIENDSHIP_H
