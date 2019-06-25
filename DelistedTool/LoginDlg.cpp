#include "LoginDlg.h"
#include "ui_LoginDlg.h"
#include "QString"
#include <QSettings>
#include "QMessageBox"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSql"
#include "QsqlQuery"
#include <QSqlError>
#include "QMessageBox"
#include "QSqlQueryModel"
#include "QDebug"

//全局
QString userName,password;
QString ServerIp,DataBase,UserID,PassWord,ServerPort,ConnStr;

LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);
}

LoginDlg::~LoginDlg()
{
    delete ui;
}

void LoginDlg::on_Login_clicked()
{
    QSettings *setting = new QSettings(tr("DataBaseSetting.ini"),QSettings::IniFormat);
    ServerIp = setting->value(tr("DBSETTING/SERVER")).toString();
    DataBase = setting->value(tr("DBSETTING/DATABASE")).toString();
    UserID = setting->value(tr("DBSETTING/USER")).toString();
    PassWord = setting->value(tr("DBSETTING/PWD")).toString();
    ServerPort = setting->value(tr("DBSETTING/PORT")).toString();
    userName = ui->userNameCtl->text();
    password = ui->passwordCtl->text();
    if(userName.isEmpty()||password.isEmpty())
    {
        QMessageBox::warning(this,tr("提示"),tr("用户名或密码不能为空"),tr("确定"));
        ui->userNameCtl->setFocus();
        return;
    }
    QString selectStr = QString("select * from LUserAccount where [Name] = '%1' and [Password] = '%2'")\
            .arg(userName).arg(password);
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))       //需要加判断，不然重复连接数据库会报错
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QODBC");
    ConnStr = QString("DRIVER={SQL SERVER};"
                      "SERVER=%1,%2;"
                      "DATABASE=%3;"
                      "UID=%4;"
                      "PWD=%5;").arg(ServerIp)
                      .arg(ServerPort)
                      .arg(DataBase)
                      .arg(UserID)
                      .arg(PassWord);
    db.setDatabaseName(ConnStr);
        if(db.open())
        {
            QSqlQuery loginQuery;
            if( loginQuery.exec(selectStr))
            {
                if(loginQuery.next())
                {
                     db.close();
                     userName = ui->userNameCtl->text();
                     password = ui->passwordCtl->text();
                     accept();                    
                }
                else
                {
                    QMessageBox::warning(this,tr("提示"),tr("用户名或密码错误，请重新输入"),tr("确定"));
                    ui->userNameCtl->clear();
                    ui->userNameCtl->setFocus();
                    userName.clear();
                    db.close();
                    return;
                }
            }
        }
        else
        {
            QMessageBox::warning(this,tr("提示"),tr("网络错误！"),tr("确定"));
        }
}

void LoginDlg::on_Cancel_clicked()
{
    reject();
}

void LoginDlg::on_cancelChange_clicked()
{
    reject();
}

void LoginDlg::on_changeUser_clicked()
{
    if(ui->userNameCtl->text().isEmpty()||ui->passwordCtl->text().isEmpty())
    {
        QMessageBox::warning(this,tr("提示"),tr("用户名或密码不能为空"),tr("确定"));
        ui->userNameCtl->setFocus();
        return;
    }
    QString selectStr = QString("select * from LUserAccount where [Name] = '%1' and [Password] = '%2'")\
            .arg(ui->userNameCtl->text()).arg(ui->passwordCtl->text());
    QSqlDatabase changeDb;
    if(QSqlDatabase::contains("qt_sql_default_connection"))       //需要加判断，不然重复连接数据库会报错
      changeDb = QSqlDatabase::database("qt_sql_default_connection");
    else
      changeDb = QSqlDatabase::addDatabase("QODBC");
    changeDb.setDatabaseName(ConnStr);
        if(changeDb.open())
        {
            QSqlQuery loginQuery;
            if( loginQuery.exec(selectStr))
            {
                if(loginQuery.next())
                {
                     //changeDb.close();
                     userName = ui->userNameCtl->text();
                     password = ui->passwordCtl->text();
                     accept();
                }
                else
                {
                    QMessageBox::warning(this,tr("提示"),tr("用户名或密码错误，请重新输入"),tr("确定"));
                    ui->userNameCtl->clear();
                    ui->userNameCtl->setFocus();
                    //userName.clear();
                    //changeDb.close();
                    return;
                }
            }
        }
        else
        {
            QMessageBox::warning(this,tr("提示"),tr("网络错误！"),tr("确定"));
        }
}
