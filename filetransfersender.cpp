#include "filetransfersender.h"

#include <QDebug>
#include <QFile>
#include <QByteArray>
#include <QDataStream>

FileTransferSender::FileTransferSender(QObject *parent) : QTcpServer(parent)
{
    qDebug() << "Sender was started";
    connect(this,SIGNAL(acceptError(QAbstractSocket::SocketError)),this,SLOT(acceptError(QAbstractSocket::SocketError)));
    connect(this,SIGNAL(newConnection()),this,SLOT(newConnection()));
}

void FileTransferSender::incomingConnection(qintptr socketfd)
{
    senderSocket = new QTcpSocket(this);
    senderSocket->setSocketDescriptor(socketfd);

    qDebug() << "Client(" << senderSocket->peerAddress().toString() << ") has connected and is ready to receive the file";
    connect(senderSocket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(senderSocket,SIGNAL(readyRead()),this,SLOT(readyRead()));

    startSending();

}

void FileTransferSender::startSending()
{
    QFile inputFile(this->filePath);
        inputFile.open(QIODevice::ReadOnly);

        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_0);
        out << (quint32)0;
        QByteArray qwerty=inputFile.readAll();


        block.append(qwerty);

        inputFile.close();
        out.device()->seek(0);
        out << (quint32)(block.size() - sizeof(quint32));

        qint64 x=0;
        while(x<block.size())
        {
            qint64 y=senderSocket->write(block);
            x=x+y;
            qDebug()<<x;
        }

        senderSocket->waitForBytesWritten(5000);
        senderSocket->disconnectFromHost();
}

void FileTransferSender::disconnected()
{
    qDebug() << "The client has closed the connection";
    this->close();
}

void FileTransferSender::readyRead()
{
    qDebug() << "There a bytes to read yay";
}

void FileTransferSender::acceptError(QAbstractSocket::SocketError socketError)
{
    qDebug() << "Error (SENDER) " << socketError;
}

void FileTransferSender::newConnection()
{
    qDebug() << "New Conncetion??";
}

QString FileTransferSender::getFilePath()
{
    return this->filePath;
}

void FileTransferSender::setFilePath(QString path)
{
    this->filePath = path;
}
