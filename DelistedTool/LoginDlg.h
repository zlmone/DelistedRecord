#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>

namespace Ui {
class LoginDlg;
}

class LoginDlg : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDlg(QWidget *parent = 0);
    ~LoginDlg();

private slots:
    void on_Login_clicked();

    void on_Cancel_clicked();

    void on_cancelChange_clicked();

    void on_changeUser_clicked();

private:
public:
     Ui::LoginDlg *ui;

};

#endif // LOGINDLG_H
