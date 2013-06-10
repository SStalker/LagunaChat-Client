#ifndef FILETRANSFERRECEIVER_H
#define FILETRANSFERRECEIVER_H

#include <QTcpSocket>

class FileTransferReceiver : public QTcpSocket
{
    Q_OBJECT
public:
    explicit FileTransferReceiver(QObject *parent = 0);
    void setFileName(QString filename);
signals:

public slots:
    void readyRead();
    void connected();
    void hostFound();
    void disconnect();
    void error(QAbstractSocket::SocketError);

private:
    QString fileName;
protected:
    qint64 readData(char *data, qint64 maxlen);
    qint64 writeData(const char *data, qint64 len);
};

#endif // FILETRANSFERRECEIVER_H
