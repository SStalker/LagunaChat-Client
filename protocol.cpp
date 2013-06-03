#include "protocol.h"
#include <QDebug>

Protocol::Protocol(QDataStream *stream)
{
    this->stream = stream;
}

void Protocol::checkMessage()
{
    //stream >> messageID;
    //qDebug() << "ID: " << messageID ;
}
