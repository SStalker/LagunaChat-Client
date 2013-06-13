#include "filetransferreceiver.h"

#include <QDebug>
#include <QHostAddress>
#include <QDataStream>

FileTransferReceiver::FileTransferReceiver(QObject *parent) :
    QTcpSocket(parent)
{
    qDebug() << "Receiver was started";
    connect(this,SIGNAL(readyRead()),this,SLOT(readyRead()));
    connect(this,SIGNAL(connected()),this,SLOT(connected()));
    connect(this,SIGNAL(hostFound()),this,SLOT(hostFound()));
    connect(this,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(error(QAbstractSocket::SocketError)));
    connect(this,SIGNAL(disconnected()),this,SLOT(disconnect()));
}

void FileTransferReceiver::readyRead()
{
    qDebug() << "There a bytes to read yay";
    qint64 bytes = this->bytesAvailable();
    qDebug() << "Anzahl: " << bytes;

    data += readAll();
}

void FileTransferReceiver::connected()
{
    QHostAddress ip = this->peerAddress();
    qDebug() << "Sender(" << ip.toString() << ") can now send the file";
}

void FileTransferReceiver::disconnect()
{
    qDebug() << "The sender has closed the connection";
    data.remove(0,4);

    QFile output("downloads/" + this->fileName);
    output.open(QIODevice::WriteOnly | QIODevice::Append);
    output.write(data);

    qDebug() << output.fileName() << "was written";
    output.close();
    this->close();
}
/*qint64 FileTransferReceiver::readData(char *data, qint64 maxlen)
{
return 0;
}

qint64 FileTransferReceiver::writeData(const char *data, qint64 len)
{
return 0;
}*/

void FileTransferReceiver::hostFound()
{
    qDebug() << "Just found an host (sender)";
}

void FileTransferReceiver::error(QAbstractSocket::SocketError error)
{
    qDebug() << error;
}

void FileTransferReceiver::setFileName(QString filename)
{
    this->fileName = filename;
}
