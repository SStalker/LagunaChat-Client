#include "filetransfersender.h"

FileTransferSender::FileTransferSender(QObject *parent) : QTcpServer(parent)
{

}

void FileTransferSender::incomingConnection(qintptr socketfd)
{
    receiver = new QTcpSocket(this);
    receiver->setSocketDescriptor(socketfd);

    connect(receiver,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(receiver,SIGNAL(readyRead()),this,SLOT(readyRead()));

}

void FileTransferSender::disconnected()
{

}

void FileTransferSender::readyRead()
{

}
