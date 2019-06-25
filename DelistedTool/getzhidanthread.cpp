#include "getzhidanthread.h"
getZhiDanThread::getZhiDanThread()
{

}

void getZhiDanThread::run()
{
    while (zhidanQuery.next())
    {
       //box->addItem(zhidanQuery.value("ZhiDan").toString());
        list<<zhidanQuery.value("ZhiDan").toString();
    }
    box->addItems(list);
    box->setCurrentIndex(-1);
}
