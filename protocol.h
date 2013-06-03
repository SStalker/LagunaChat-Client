#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QDataStream>

class Protocol
{
public:
    Protocol(QDataStream *stream);
    void checkMessage();

private:
    int messageID;
    QDataStream *stream;
};

#endif // PROTOCOL_H
