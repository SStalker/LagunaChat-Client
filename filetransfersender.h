#ifndef FILETRANSFERSENDER_H
#define FILETRANSFERSENDER_H

#include <QTcpServer>
#include <QTcpSocket>

class FileTransferSender : public QTcpServer
{
    Q_OBJECT

public:
    FileTransferSender(QObject *parent = 0);
    void startSending();

    QString getFilePath();
    void setFilePath(QString path);

private slots:
    void readyRead();
    void disconnected();
    void acceptError(QAbstractSocket::SocketError socketError);
    void newConnection();

protected:
    void incomingConnection(qintptr socketfd);

private:
    QTcpSocket *senderSocket;
    QString filePath;
};

#endif // FILETRANSFERSENDER_H
