#include "DelistedTool.h"
#include "ui_DelistedTool.h"
#include "QtSql/QSqlDatabase"
#include "QsqlQuery"
#include "QMessageBox"
#include "QTimer"
#include "QDateTime"
#include <QThread>
#include "getzhidanthread.h"
#include "QCompleter"
#include "QHostAddress"
#include "QNetworkInterface"
#include "QHostInfo"
#include "QSqlQueryModel"
#include "QSqlTableModel"
#include "QFile"
#include "WriteExcel.h"
#include "QFileDialog"
#include "LoginDlg.h"
#include "ui_LoginDlg.h"

//全局
extern QString userName;
extern QString ConnStr;
//QSqlQuery dbQuery;
QString serverTime;
QStringList zhidanList;
QString computerIP;
bool dbOpenFlag;
QSqlQueryModel *nullModel = new QSqlQueryModel;
WriteExcel *writeExcel = new WriteExcel;

DelistedTool::DelistedTool(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DelistedTool)
{
    ui->setupUi(this);

    //数据库连接
    //主
    if(QSqlDatabase::contains("qt_sql_default_connection"))       //需要加判断，不然重复连接数据库会报错
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName(ConnStr);
        dbOpenFlag = db.open();
        sqlTableModel = new QSqlTableModel(this);
        sqlTableModel->setTable("Gps_DelistedRecord");
        sqlTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //获取服务器时间
    if(QSqlDatabase::contains("qt_sql_default_connection"))       //需要加判断，不然重复连接数据库会报错
      timeDb = QSqlDatabase::database("qt_sql_default_connection");
    else
      timeDb = QSqlDatabase::addDatabase("QODBC");
        timeDb.setDatabaseName(ConnStr);
        timeDb.open();

    //填充制单号到combo box
    QSqlQuery query(db);
    QString selectZhiDan = "select ZhiDan from [GPSTest].[dbo].Gps_ManuOrderParam order by ZhiDan";
    query.exec(selectZhiDan);
    while(query.next())
    {
        ui->ZhiDanBox->addItem(query.value("ZhiDan").toString());
    }
    ui->ZhiDanBox->setCurrentIndex(-1);

    //状态栏
    userNmaeShow = new QLabel;
    timeShow = new QLabel;
    userNmaeShow->setMinimumSize(450,20);
    timeShow->setMinimumSize(450,20);
    userNmaeShow->setText(QString(tr("当前用户ID：%1")).arg(userName));
    QTimer *timer=new QTimer(this);
    timer->start(1000); // 1s刷新一次
    ui->statusBar->addWidget(userNmaeShow,0);
    ui->statusBar->addWidget(timeShow,1);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeUpdate()));

    //combo box可编辑
    ui->ZhiDanBox->setEditable(true);

    //获取电脑ip
    computerIP = get_localmachine_ip();
    ui->PCAddress->setText(computerIP);

    //设置table view属性
    ui->DelistedCheck->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->DelistedCheck->setModel(nullModel);
    ui->DelistedCheck->setAlternatingRowColors(true);

    //菜单
    fileMenu = menuBar()->addMenu(tr("系统"));
    fileMenu->addAction(ui->channgeUser);
    fileMenu->addAction(ui->logOut);
    fileMenu->addSeparator();
}

DelistedTool::~DelistedTool()
{
    delete ui;
}

//更新状态栏的时间
void DelistedTool::timeUpdate()
{
    QSqlQuery query(timeDb);
    QString selectStr;
    selectStr = QString("SELECT CONVERT(varchar(100), GETDATE(), 20) as'%1'").arg("serverTime");
    query.exec(selectStr);
    if(query.next())
    {
       query.first();
       serverTime = query.value("serverTime").toString();
    }
    timeShow->setText(QString(tr("服务器时间：%1")).arg(serverTime));
}

//制单输入框模糊查询
void DelistedTool::on_ZhiDanBox_editTextChanged(const QString &arg1)
{
    QStringList list;
    QSqlQuery query;
    query = QSqlQuery(db);
    QString selectStr = QString("select ZhiDan from Gps_ManuOrderParam where ZhiDan like '%%1%'").arg(arg1);
    if(arg1.length()<6)
    {
        query.exec(selectStr);
        for(int i = 0;i<=8;i++)
        {
            if(query.next())
            {
               list<<query.value("ZhiDan").toString();
               query.next();
            }
        }
        QCompleter *pleter = new QCompleter(list);
        ui->ZhiDanBox->setCompleter(pleter);
    }

}

//扫入ID
void DelistedTool::on_IDCtrl_returnPressed()
{
    if(!dbOpenFlag)
    {
        QMessageBox::warning(this,tr("提示"),tr("数据库连接出错"),tr("确定"));
        return;
    }
    if(userName.isEmpty())
    {
        QMessageBox::warning(this,tr("提示"),tr("请先登录"),tr("确定"));
        return;
    }
    QString ctrlVal = ui->IDCtrl->text();
    if(ctrlVal.isEmpty())
    {
        QMessageBox::warning(this,tr("提示"),tr("ID不能为空"),tr("确定"));
        return;
    }
    if(ui->ZhiDanBox->currentText().isEmpty())
    {
        QMessageBox::warning(this,tr("提示"),tr("订单不能为空"),tr("确定"));
        return;
    }
    if(computerIP.isEmpty())
    {
        QMessageBox::warning(this,tr("提示"),tr("获取IP地址出错"),tr("确定"));
        return;
    }
    QString historyIpAndTime,nowIpAndTime,testerId;
    int scanTimes;
    QString saveDataStr,selectStr;
    selectStr = QString("select [FirstTime],[DelistedTimeAndIP],[Scans],[TesterID] from Gps_DelistedRecord where TerminalID = '%1'").arg(ctrlVal);
    QSqlQuery query;
    qDebug()<<selectStr;
    query = QSqlQuery(db);
    query.exec(selectStr);
    if(query.next())
    {
        historyIpAndTime = query.value("DelistedTimeAndIP").toString()+",("+computerIP+"^^"+serverTime+")";
        qDebug()<<historyIpAndTime;
        scanTimes = query.value("Scans").toInt();
        testerId = query.value("TesterID").toString();
        testerId =testerId+tr(",")+ userName;
        nowIpAndTime = "("+computerIP+"^^"+serverTime+")";
        saveDataStr = QString("update Gps_DelistedRecord set [DelistedTimeAndIP] = '%1',[Scans] = '%2',[LastTime] = '%3', TesterID = '%4' where [TerminalID] = '%5'").arg(historyIpAndTime).arg(QString::number(scanTimes+1)).arg(serverTime).arg(testerId).arg(ctrlVal);
        if(query.exec(saveDataStr))
        {
            ui->delistedLog->append(serverTime);
            ui->delistedLog->append(tr("ID：")+ctrlVal+tr("退板成功"));
            writeLog(tr("ID：")+ctrlVal+tr("退板成功"));
            ui->IDCtrl->clear();
        }
        else
        {
            ui->delistedLog->append(serverTime);
            ui->delistedLog->append(tr("ID：")+ctrlVal+tr("退板失败"));
            writeLog(tr("ID：")+ctrlVal+tr("退板失败"));
            ui->IDCtrl->clear();
        }
    }
    else
    {
        nowIpAndTime = "("+computerIP+"^^"+serverTime+")";
        saveDataStr = QString("insert into Gps_DelistedRecord values('%1','%2','%3','%4','%5','%6','%7')").arg(ui->ZhiDanBox->currentText()).arg(ctrlVal).arg(nowIpAndTime).arg("1").arg(serverTime).arg(serverTime).arg(userName);
        if(query.exec(saveDataStr))
        {
            ui->delistedLog->append(serverTime);
            ui->delistedLog->append(tr("ID：")+ctrlVal+tr("退板成功"));
            writeLog(tr("ID：")+ctrlVal+tr("退板成功"));
            ui->IDCtrl->clear();
        }
        else
        {
            ui->delistedLog->append(serverTime);
            ui->delistedLog->append(tr("ID：")+ctrlVal+tr("退板失败"));
            writeLog(tr("ID：")+ctrlVal+tr("退板失败"));
            ui->IDCtrl->clear();
        }
    }
}

//写日志
void DelistedTool::writeLog(QString log)
{
    QString path = QCoreApplication::applicationDirPath();
    QString logName = serverTime.left(10);
    logName =logName+tr("_")+ui->ZhiDanBox->currentText()+".txt";
    qDebug()<<path+"/log/"+logName;
    QFile myFile(path+"/log/"+logName);
    if(!myFile.open(QIODevice::ReadWrite | QIODevice::Text|QIODevice::Append))
    {
        QMessageBox::warning(this,tr("提示"),tr("无法打开日志文件，请检查路径是否正确"),tr("确定"));
        return;
    }
    QTextStream write(&myFile);
    write<<serverTime+"\r\n";
    write<<log+"\r\n";
    myFile.close();
}

//获取本机ip
QString DelistedTool::get_localmachine_ip()
{
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address())
        {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    return ipAddress;
}

//查询记录
void DelistedTool::on_pushButton_2_clicked()
{
    if(userName.isEmpty())
    {
        QMessageBox::warning(this,tr("提示"),tr("请先登录"),tr("确定"));
        return;
    }
    QString startTime,endTime;
    startTime = ui->dateTimeEdit->text();
    endTime = ui->dateTimeEdit_2->text();
    if(!ui->IDlineEdit->text().isEmpty())
    {
        if(startTime=="2019-06-01 00:00:00"&&endTime=="2019-06-01 00:00:00")
        {
            sqlTableModel->setFilter(QObject::tr("TerminalID = '%1'").arg(ui->IDlineEdit->text()));
        }
        else
        {
            if(startTime>endTime)
            {
                QMessageBox::warning(this,tr("提示"),tr("开始时间大于结束时间"),tr("确定"));
                return;
            }
            else
            {
                sqlTableModel->setFilter(QObject::tr("TerminalID = '%1' and ((FirstTime >= '%2' and FirstTime<= '%3') or (LastTime >= '%4' and LastTime<= '%5'))").arg(ui->IDlineEdit->text()).arg(startTime).arg(endTime).arg(startTime).arg(endTime));
            }
        }
        //selectStr = QString("select * from Gps_DelistedRecord where TerminalID = '%1'").arg(ui->IDlineEdit->text());
    }
    else
    {
        if(!ui->zhidanlineEdit->text().isEmpty())
        {
            if(startTime=="2019-06-01 00:00:00"&&endTime=="2019-06-01 00:00:00")
            {
                sqlTableModel->setFilter(QObject::tr("ZhiDan = '%1'").arg(ui->zhidanlineEdit->text()));
                //selectStr = QString("select * from Gps_DelistedRecord where ZhiDan = '%1'").arg(ui->zhidanlineEdit->text());
            }
            else
            {
                if(startTime>endTime)
                {
                    QMessageBox::warning(this,tr("提示"),tr("开始时间大于结束时间"),tr("确定"));
                    return;
                }
                else
                {
                     sqlTableModel->setFilter(QObject::tr("ZhiDan = '%1' and ((FirstTime >= '%2' and FirstTime<= '%3') or (LastTime >= '%4' and LastTime<= '%5'))").arg(ui->zhidanlineEdit->text()).arg(startTime).arg(endTime).arg(startTime).arg(endTime));
                     //selectStr = QString("select * from Gps_DelistedRecord where ZhiDan = '%1' and FirstTime >= '%2' and LastTime<= '%3'").arg(ui->zhidanlineEdit->text()).arg(startTime).arg(endTime);
                }
            }
        }
        else
        {
            if(startTime>endTime)
            {
                QMessageBox::warning(this,tr("提示"),tr("开始时间大于结束时间"),tr("确定"));
                return;
            }
            else
            {
                sqlTableModel->setFilter(QObject::tr("(FirstTime >= '%1' and FirstTime<= '%2') or (LastTime >= '%3' and LastTime<= '%4')").arg(startTime).arg(endTime).arg(startTime).arg(endTime));
                //selectStr = QString("select * from Gps_DelistedRecord where FirstTime >= '%1' and LastTime<= '%2'").arg(startTime).arg(endTime);
            }
        }
    }
    sqlTableModel->select();
    while(sqlTableModel->canFetchMore())
    {
          sqlTableModel->fetchMore();
    }
    sqlTableModel -> setHeaderData(1, Qt::Horizontal, tr("订单号"));
    sqlTableModel -> setHeaderData(2, Qt::Horizontal, tr("ID"));
    sqlTableModel -> setHeaderData(3, Qt::Horizontal, tr("退板时间/IP"));
    sqlTableModel -> setHeaderData(4, Qt::Horizontal, tr("退板次数"));
    //sqlTableModel -> setHeaderData(5, Qt::Horizontal, tr("首次退板时间"));
    sqlTableModel -> setHeaderData(6, Qt::Horizontal, tr("最新退板时间"));
    sqlTableModel -> setHeaderData(7, Qt::Horizontal, tr("操作员"));
    ui->DelistedCheck->setModel(sqlTableModel);
    ui->DelistedCheck->show();
    ui->DelistedCheck->hideColumn(0);
    ui->DelistedCheck->hideColumn(5);
    ui->DelistedCheck->setColumnWidth(2,320);
    ui->DelistedCheck->setColumnWidth(3,350);
    ui->DelistedCheck->setColumnWidth(4,80);
    ui->DelistedCheck->setColumnWidth(6,200);
    ui->DelistedCheck->setColumnWidth(7,75);
    if(ui->DelistedCheck->model()->rowCount()==0)
    {
        QMessageBox::warning(this,tr("提示"),tr("数据为空"),tr("确定"));
    }
    else
    {
        QMessageBox::warning(this,tr("提示"),tr("查询成功"),tr("确定"));
    }
}

//删除所有数据
void DelistedTool::on_deleteAll_clicked()
{
    if(userName.isEmpty())
    {
        QMessageBox::warning(this,tr("提示"),tr("请先登录"),tr("确定"));
        return;
    }
     if(sqlTableModel->rowCount()==0)
     {
         QMessageBox::warning(this,tr("提示"),tr("当前界面没有数据"),tr("确定"));
         return;
     }
     if(QMessageBox::warning(this,tr("提示"),tr("确定删除？"),tr("确定"),tr("取消"))==0)
     {
         QString backUpStr;
         QSqlQuery query;
         query = QSqlQuery(db);
         for(int i = 0;i<sqlTableModel->rowCount();i++)
         {
             backUpStr = QString("  insert into Gps_DelistedRecord_BackUp select [ZhiDan]\
                                 ,[TerminalID]\
                                 ,[DelistedTimeAndIP]\
                                 ,[Scans]\
                                 ,[FirstTime]\
                                 ,[LastTime]\
                                 ,[TesterID] from Gps_DelistedRecord where TerminalID = '%1'").arg(sqlTableModel->index(i,2).data().toString());
                     query.exec(backUpStr);
         }
         sqlTableModel->removeRows(0,sqlTableModel->rowCount());
         sqlTableModel->submitAll();
         QMessageBox::warning(this,tr("提示"),tr("删除成功"),tr("确定"));
     }
}

//删除按钮
void DelistedTool::on_deletePart_clicked()
{
    if(userName.isEmpty())
    {
        QMessageBox::warning(this,tr("提示"),tr("请先登录"),tr("确定"));
        return;
    }
    deleteItem();
}

//删除tableview选中行
void DelistedTool::deleteItem()
{
    QString backUpStr;
    QSqlQuery query;
    query = QSqlQuery(db);
    QModelIndexList indexList1 = ui->DelistedCheck->selectionModel()->selectedIndexes();
    if(indexList1.isEmpty())
    {
        QMessageBox::warning(this,tr("提示"),tr("未选中数据"),tr("确定"));
        return;
    }
    else
    {
        if(QMessageBox::warning(this,tr("提示"),tr("确定删除？"),tr("确定"),tr("取消"))!=0)
         {
             return;
         }
    }
    while (!indexList1.isEmpty())
    {
        QModelIndexList indexList = deleteRepeatList(indexList1);
        QModelIndex index = indexList.first();
        for(int i = index.row();i<=indexList.count();i++)
        {
            backUpStr = QString("  insert into Gps_DelistedRecord_BackUp select [ZhiDan]\
                                ,[TerminalID]\
                                ,[DelistedTimeAndIP]\
                                ,[Scans]\
                                ,[FirstTime]\
                                ,[LastTime]\
                                ,[TesterID] from Gps_DelistedRecord where TerminalID = '%1'").arg(sqlTableModel->index(i,2).data().toString());
            query.exec(backUpStr);
        }
        sqlTableModel->removeRows(index.row(),indexList.count());
        sqlTableModel->submitAll();
        indexList1 = ui->DelistedCheck->selectionModel()->selectedIndexes();
        indexList = deleteRepeatList(indexList1);
    }
    QMessageBox::warning(this,tr("提示"),tr("删除成功"),tr("确定"));
}
QModelIndexList DelistedTool::deleteRepeatList(QModelIndexList indexList)
{
    QModelIndex index,newIndex;
    QModelIndexList newIndexList;
    foreach(index,indexList)
    {
        if (newIndex.row() != index.row())
        {
            newIndex = index;
            newIndexList.append(newIndex);
        }
    }
    return newIndexList;
}

//导出按钮
void DelistedTool::on_writrToExcel_clicked()
{
    if(userName.isEmpty())
    {
        QMessageBox::warning(this,tr("提示"),tr("请先登录"),tr("确定"));
        return;
    }
    QString filename;
    if(ui->DelistedCheck->model()->rowCount()==0)
    {
         QMessageBox::warning(this,tr("提示"),tr("数据为空，无法保存！"),tr("确定"));
         return;
    }
    filename = serverTime.left(10);
    filename =filename+tr("_")+ui->ZhiDanBox->currentText();
    QString filePath = QFileDialog::getSaveFileName(this,"Excle file",filename,"Excel Files(*.xls)");    //设置保存的文件名
    if(filePath != "")
    {
        if(writeExcel->saveFromTable(filePath,ui->DelistedCheck,tr("注释：退板数据")))
        {
            QMessageBox::information(this,tr("提示"),tr("保存成功"),tr("确定"));
        }
        else
        {
            QMessageBox::information(this,tr("提示"),tr("保存失败"),tr("确定"));
        }
    }
}

//刷新制单
void DelistedTool::on_pushButton_clicked()
{
    if(dbOpenFlag)
    {
        QSqlQuery query;
        QString selectZhiDan = "select ZhiDan from [GPSTest].[dbo].Gps_ManuOrderParam";
        query.exec(selectZhiDan);
        while(query.next())
        {
            ui->ZhiDanBox->addItem(query.value("ZhiDan").toString());
        }
        QMessageBox::warning(this,tr("提示"),tr("刷新成功"),tr("确定"));
    }
    ui->ZhiDanBox->setCurrentIndex(-1);
}

//切换账号
void DelistedTool::on_channgeUser_triggered()
{
    LoginDlg myLogInDialg;
    Ui_LoginDlg *pui;
    pui = myLogInDialg.ui;
    pui->Login->hide();
    pui->Cancel->hide();
    if(myLogInDialg.exec()==QDialog::Accepted)
    {
        ui->DelistedCheck->setModel(nullModel);
        ui->ZhiDanBox->setCurrentIndex(-1);
        userNmaeShow->setText(QString(tr("当前用户ID：%1")).arg(userName));
        QMessageBox::warning(this,tr("提示"),tr("切换成功"),tr("确定"));
    }
}

//退出账号
void DelistedTool::on_logOut_triggered()
{
    userName.clear();
    ui->DelistedCheck->setModel(nullModel);
    ui->ZhiDanBox->setCurrentIndex(-1);
    ui->delistedLog->clear();
    userNmaeShow->setText(QString(tr("当前用户ID：%1")).arg(tr("未登录")));
}
