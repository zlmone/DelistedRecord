#include "WriteExcel.h"
#include "QAbstractItemModel"
#include "QTableView"
#include <QAxObject>
#include "QDebug"
#include <QtSql/QSqlDatabase>
#include "QException"
WriteExcel::WriteExcel(QObject *parent) : QObject(parent)
{

}

bool WriteExcel::saveFromTable(QString filePath, QTableView *tableView, QString comment)
{
    QAbstractItemModel *model=tableView->model();
    const int column=model->columnCount();
    const int row=model->rowCount();

    //header
    QStringList headers;
    for(int i=0;i<column;i++)
    {
        //隐藏列
        if(tableView->isColumnHidden(i))
            continue;
        headers<<model->headerData(i,Qt::Horizontal).toString();
    }

    //data
    QStringList list;
    QList<QStringList> data;
    for(int i=0;i<row;i++)
    {
        if(model->index(i,0).data().isNull())
            continue;
        list.clear();
        for(int j=0;j<column;j++){
            //隐藏列
            if(tableView->isColumnHidden(j))
                continue;
            list<<model->index(i,j).data().toString();
        }
        data<<list;
    }
    return WriteExcel::save(filePath,headers,data,comment);
}

bool WriteExcel::save(QString filePath, QStringList headers, QList<QStringList> data,QString comment)
{
    QString sheetName = "Sheet1";
    // 创建一个数据库实例， 设置连接字符串
    QSqlDatabase dbexcel = QSqlDatabase::addDatabase("QODBC","excel");//excel   excelexport
    if(!dbexcel.isValid())
    {
        qDebug()<<"数据库驱动异常";
        return false;   //! type error
    }
//MICROSOFT EXCEL DRIVER (*.XLS)     Microsoft Excel Driver (*.xls, *.xlsx, *.xlsm, *.xlsb)
    QString dsn = QString("DRIVER={Microsoft Excel Driver (*.xls)};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%1\";DBQ=%2").
                  arg(filePath).arg(filePath);
    //QString dsn = QString("DRIVER={MICROSOFT EXCEL DRIVER (*.xls)};READONLY=FALSE;DriverId=790;DBQ=" + QString("c:\\file.xls"));
    qDebug()<<dsn;
    dbexcel.setDatabaseName(dsn);
    // open connection
    if(!dbexcel.open())
    {
         qDebug()<<tr("无法打开数据库");
        return false;  //! db error
    }
    QSqlQuery query(dbexcel);
    QString sql;

    // drop the table if it's already exists
    sql = QString("DROP TABLE [%1]").arg(sheetName);
    query.exec( sql);
    //create the table (sheet in Excel file)
    sql = QString("CREATE TABLE [%1] (").arg(sheetName);
    foreach (QString name, headers)
    {
        sql +=QString("[%1] varchar(200)").arg(name);
        if(name!=headers.last())
            sql +=",";
    }
    sql += ")";
    query.prepare(sql);
    if( !query.exec())
    {
        //UIDemo01::printError( query.lastError());
        dbexcel.close();
        return false;
    }
    foreach (QStringList slist, data)
    {
        insert(query,sheetName,slist);
    }
    if(!comment.isEmpty())
    {
        QStringList slist;
        slist<<comment;
        for(int i=0,n=headers.size()-1;i<n;i++)
        {
            slist<<"";
        }
        insert(query,sheetName,slist);
    }

    dbexcel.close();
    return true;
}

bool WriteExcel::insert(QSqlQuery &query, QString sheetName, QStringList slist)
{
    QString sSql = QString("INSERT INTO [%1] VALUES(").arg(sheetName);
    for(int i=0,n=slist.size();i<n;i++)
    {
        sSql+=QString(":%1").arg(i);
        if(i!=n-1)
            sSql+=",";
        else
            sSql+=")";
    }
    query.prepare(sSql);
    for(int i=0,n=slist.size();i<n;i++)
    {
        query.bindValue(QString(":%1").arg(i),slist.at(i));
    }
    if( !query.exec())
    {
        return false;
    }
    return true;
}

