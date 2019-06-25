#ifndef GETZHIDANTHREAD_H
#define GETZHIDANTHREAD_H
#include <QThread>
#include "QSqlQuery"
#include "QComboBox"
class getZhiDanThread : public QThread
{
public:
    getZhiDanThread();
    void run();
    QComboBox *box;
    QSqlQuery zhidanQuery;
    QStringList list;
};

#endif // GETZHIDANTHREAD_H
