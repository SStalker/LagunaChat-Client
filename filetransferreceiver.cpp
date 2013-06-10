#include "filetransferreceiver.h"

#include <QDebug>
#include <QHostAddress>
#include <QFile>
#include <QDataStream>
#include <QTextStream>
#include <QMessageBox>

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

    /*QByteArray data = readAll();
    //char *daten[bytes];
    //qint64 readBytes = read(*daten,1000);


    //daten[bytes] = "\0";
    //qDebug() << "Bytes gelesen: ";
    //int fileSize;

    qDebug() << data.toHex() << endl;
    qDebug() << data.toLower() << endl;
    qDebug() << data.toInt() << endl;
    QFile out("downloads/" + this->fileName);
    out.open(QIODevice::WriteOnly | QIODevice::Append);

    //out.write(data.toLower());
    QTextStream hi(&out);

    hi.setCodec("ISO 8859-1");
    hi << data;

    qDebug() << out.fileName() << "was written";

    out.close();*/
int blockSize = 0;
    QDataStream in(this);
    in.setVersion(QDataStream::Qt_4_0);
    if (blockSize == 0)
    {
        if (bytesAvailable() < sizeof(quint32))
        return ;


        in >> blockSize;
    }

    if (bytesAvailable() < blockSize)
    return ;

    QByteArray line;
    line= readAll();
    QFile file("downloads/" + this->fileName);
    if(!(file.open(QIODevice::Append)))
    //QMessageBox::information(this, tr("File"),tr("File cannot be opened."));
    file.write(line);


    blockSize=0;


    file.close();

}

void FileTransferReceiver::connected()
{
    QHostAddress ip = this->peerAddress();
    qDebug() << "Sender(" << ip.toString() << ") can now send the file";
}

void FileTransferReceiver::disconnect()
{
    qDebug() << "The sender has closed the connection";
    this->close();
}
qint64 FileTransferReceiver::readData(char *data, qint64 maxlen)
{
    return 0;
}

qint64 FileTransferReceiver::writeData(const char *data, qint64 len)
{
    return 0;
}

void FileTransferReceiver::hostFound()
{
    qDebug() << "Just found an host (sender)";
}

void FileTransferReceiver::error(QAbstractSocket::SocketError error)
{

}

void FileTransferReceiver::setFileName(QString filename)
{
    this->fileName = filename;
}
