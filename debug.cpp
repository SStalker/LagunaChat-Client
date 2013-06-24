#include "debug.h"
#include <QDateTime>
#include <QByteArray>
#include <QDebug>


Debug::Debug()
{
    debug = new QFile("debug.txt");

}

void Debug::debugging(QString text)
{
    if(!debug->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Keine Datei";
        return;
    }


    QString time = QDateTime::currentDateTime().toString("dd.MM.yyyy-HH:mm:ss");
    QByteArray ar;
    ar.append(time + " ### " + text + "\n");

    debug->write(ar);

    debug->close();
}

void Debug::close()
{
    debug->close();
}
