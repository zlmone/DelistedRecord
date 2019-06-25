#ifndef GETZHIDAN_H
#define GETZHIDAN_H
#include "QSqlQuery"
#include "QComboBox"
#include <QThread>
class getZhiDan : public QThread
{
public:
    getZhiDan();
    void run(QSqlQuery sqlquery,QComboBox *box);
protected:

};

#endif // GETZHIDAN_H
