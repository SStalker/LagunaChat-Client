#ifndef NEWTAB_H
#define NEWTAB_H

#include <QWidget>
#include <QTcpSocket>
//#include <QMediaPlayer>

namespace Ui {
class newTab;
}

class newTab : public QWidget
{
    Q_OBJECT
    
public:
    explicit newTab(QWidget *parent = 0, QTcpSocket *socket = 0);
    ~newTab();
    void setUser(QString mail);
    void setFriend(QString mail);

    void writeInTextfield(QString text);
    QString setSmileys(QString text);

private slots:
    void writeMessage();
    
private:
    Ui::newTab *ui;
    QTcpSocket *sock;
    QString user;
    QString friend_;

    //QMediaPlayer *player;
};

#endif // NEWTAB_H
