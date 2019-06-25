#ifndef WRITEEXCEL_H
#define WRITEEXCEL_H

#include <QObject>
#include "QString"
#include "QSqlQuery"
#include "QTableView"
class WriteExcel : public QObject
{
    Q_OBJECT
public:
    explicit WriteExcel(QObject *parent = nullptr);

signals:

public slots:
public:
    //将数据保存为excel
   bool static save(QString filePath,QStringList headers,QList<QStringList> data,QString comment="");
   //将QTableView保存为excel
   bool static saveFromTable(QString filePath,QTableView *tableView,QString comment="");
   bool static insert(QSqlQuery& query, QString sheetName, QStringList slist);
   QString ExcelDriver;
};

#endif // WRITEEXCEL_H
