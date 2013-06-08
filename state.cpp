#include "state.h"
#include "MainWindow.h"

State::State()
{
}

void State::stateLogin(QObject *parent)
{
    //MainWindow *main = (MainWindow*)parent;


}

void State::setDataStream(QDataStream *in)
{
    this->mainIn = in;
}

void State::setSocket(QTcpSocket *s)
{
    this->sock = s;
}
