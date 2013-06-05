#ifndef FILETRANSFERSENDER_H
#define FILETRANSFERSENDER_H

#include <QTcpServer>
#include <QTcpSocket>

class FileTransferSender : public QTcpServer
{
    Q_OBJECT

public:
    FileTransferSender(QObject *parent = 0);


private slots:
    void readyRead();
    void disconnected();

protected:
    void incomingConnection(qintptr socketfd);

private:
    QTcpSocket *receiver;

};

#endif // FILETRANSFERSENDER_H
