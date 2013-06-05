#ifndef FILETRANSFERRECEIVER_H
#define FILETRANSFERRECEIVER_H

#include <QTcpSocket>

class FileTransferReceiver : public QTcpSocket
{
    Q_OBJECT
public:
    explicit FileTransferReceiver(QObject *parent = 0);
    
signals:

public slots:
    void readyRead();
    void connected();
    void hostFound();
    void error(QAbstractSocket::SocketError);

protected:
    qint64 readData(char *data, qint64 maxlen);
    qint64 writeData(const char *data, qint64 len);
};

#endif // FILETRANSFERRECEIVER_H
