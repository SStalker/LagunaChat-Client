#include "filetransfersender.h"

#include <QDebug>

FileTransferSender::FileTransferSender(QObject *parent) : QTcpServer(parent)
{

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
