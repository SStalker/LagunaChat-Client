#ifndef DEBUG_H
#define DEBUG_H
#include <QFile>


class Debug
{
public:
    Debug();
    QFile *debug;
    void debugging(QString text);
    void close();
};

#endif // DEBUG_H
