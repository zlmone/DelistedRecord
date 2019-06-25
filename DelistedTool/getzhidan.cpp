#include "getzhidan.h"
#include "QDebug"
getZhiDan::getZhiDan()
{

}

void getZhiDan::run(QSqlQuery sqlquery, QComboBox *box)
{
    qDebug()<<"SimpleThreadOne run!";
    while (sqlquery.next())
    {
        box->addItem(sqlquery.value("ZhiDan").toString());
    }
}


