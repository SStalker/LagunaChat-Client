#ifndef STATE_H
#define STATE_H
#include <QObject>
#include <QDataStream>
#include <QTcpSocket>

class State
{

public:
    State();
    void stateLogin(QObject *parent);

    void setDataStream(QDataStream *in);
    void setSocket(QTcpSocket *s);
    
private:
    QDataStream *mainIn;
    QTcpSocket *sock;
};

#endif // STATE_H
