#include "filetransfersender.h"

#include <QDebug>

FileTransferSender::FileTransferSender(QObject *parent) : QTcpServer(parent)
{
    qDebug() << "Sender was started";
    connect(this,SIGNAL(acceptError(QAbstractSocket::SocketError)),this,SLOT(acceptError(QAbstractSocket::SocketError)));
}

void FileTransferSender::incomingConnection(qintptr socketfd)
{
    receiver = new QTcpSocket(this);
    receiver->setSocketDescriptor(socketfd);

    qDebug() << "Client(" << receiver->peerAddress().toString() << ") has connected and is ready to receive the file";
    connect(receiver,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(receiver,SIGNAL(readyRead()),this,SLOT(readyRead()));

}

void FileTransferSender::disconnected()
{
    qDebug() << "The client has closed the connection";
}

void FileTransferSender::readyRead()
{
    qDebug() << "There a bytes to read yay";
}

void FileTransferSender::acceptError(QAbstractSocket::SocketError socketError)
{
    qDebug() << "Error (SENDER) " << socketError;
}
