#include "DelistedTool.h"
#include <QApplication>
#include "LoginDlg.h"
#include "ui_LoginDlg.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDlg myLogInDialg;
    Ui_LoginDlg *pui;
    pui = myLogInDialg.ui;
    pui->cancelChange->hide();
    pui->changeUser->hide();
    if(myLogInDialg.exec()==QDialog::Accepted)
    {
       DelistedTool w;
       w.show();
       return a.exec();
    }
    else
    {
        return 0;
    }
}
