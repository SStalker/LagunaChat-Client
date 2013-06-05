#include "filetransferreceiver.h"

FileTransferReceiver::FileTransferReceiver(QObject *parent) :
    QTcpSocket(parent)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(readyRead()));
    connect(this,SIGNAL(connected()),this,SLOT(connected()));
    connect(this,SIGNAL(hostFound()),this,SLOT(hostFound()));
    connect(this,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(error(QAbstractSocket::SocketError)));

}

void FileTransferReceiver::readyRead()
{

}

void FileTransferReceiver::connected()
{

}

qint64 FileTransferReceiver::readData(char *data, qint64 maxlen)
{

}

qint64 FileTransferReceiver::writeData(const char *data, qint64 len)
{

}

void FileTransferReceiver::hostFound()
{

}

void FileTransferReceiver::error(QAbstractSocket::SocketError error)
{

}
