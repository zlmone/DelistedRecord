#ifndef DELISTEDTOOL_H
#define DELISTEDTOOL_H

#include <QMainWindow>
#include "QLabel"
#include "QModelIndexList"
#include "QSqlTableModel"
namespace Ui {
class DelistedTool;
}

class DelistedTool : public QMainWindow
{
    Q_OBJECT

public:
    explicit DelistedTool(QWidget *parent = 0);
    ~DelistedTool();

private:
    Ui::DelistedTool *ui;
public:
    QLabel *userNmaeShow;
    QLabel *timeShow;
    QString getIP2();
    QString get_localmachine_ip();
    void deleteItem();
    QModelIndexList deleteRepeatList(QModelIndexList indexList);
    void writeLog(QString log);
    QString getIPAddress(QString localHost);
public slots:
    void timeUpdate();
private slots:
    void on_ZhiDanBox_editTextChanged(const QString &arg1);
    void on_IDCtrl_returnPressed();
    void on_pushButton_2_clicked();
    void on_deleteAll_clicked();
    void on_deletePart_clicked();
    void on_writrToExcel_clicked();

    void on_pushButton_clicked();


    void on_channgeUser_triggered();

    void on_logOut_triggered();

private:
    QSqlTableModel *sqlTableModel;
    QSqlDatabase db;
    QSqlDatabase timeDb;
    QRect rect ;
    QMenu * fileMenu;
};
#endif // DELISTEDTOOL_H
