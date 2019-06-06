/********************************************************************************
** Form generated from reading UI file 'LoginDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDLG_H
#define UI_LOGINDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDlg
{
public:
    QLineEdit *userNameCtl;
    QLineEdit *passwordCtl;
    QPushButton *Login;
    QPushButton *Cancel;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *LoginDlg)
    {
        if (LoginDlg->objectName().isEmpty())
            LoginDlg->setObjectName(QStringLiteral("LoginDlg"));
        LoginDlg->resize(303, 215);
        QIcon icon;
        icon.addFile(QStringLiteral("../build-DelistedTool-Desktop_Qt_5_10_1_MSVC2017_64bit-Debug/loninIco.ico"), QSize(), QIcon::Normal, QIcon::Off);
        LoginDlg->setWindowIcon(icon);
        userNameCtl = new QLineEdit(LoginDlg);
        userNameCtl->setObjectName(QStringLiteral("userNameCtl"));
        userNameCtl->setGeometry(QRect(111, 51, 129, 20));
        passwordCtl = new QLineEdit(LoginDlg);
        passwordCtl->setObjectName(QStringLiteral("passwordCtl"));
        passwordCtl->setGeometry(QRect(111, 78, 129, 20));
        passwordCtl->setInputMethodHints(Qt::ImhHiddenText);
        Login = new QPushButton(LoginDlg);
        Login->setObjectName(QStringLiteral("Login"));
        Login->setGeometry(QRect(50, 140, 71, 28));
        Cancel = new QPushButton(LoginDlg);
        Cancel->setObjectName(QStringLiteral("Cancel"));
        Cancel->setGeometry(QRect(180, 140, 71, 28));
        label = new QLabel(LoginDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 50, 41, 16));
        label_2 = new QLabel(LoginDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 80, 41, 16));

        retranslateUi(LoginDlg);

        QMetaObject::connectSlotsByName(LoginDlg);
    } // setupUi

    void retranslateUi(QDialog *LoginDlg)
    {
        LoginDlg->setWindowTitle(QApplication::translate("LoginDlg", "\347\231\273\345\275\225", nullptr));
        Login->setText(QApplication::translate("LoginDlg", "\347\231\273\345\275\225", nullptr));
        Cancel->setText(QApplication::translate("LoginDlg", "\351\200\200\345\207\272", nullptr));
        label->setText(QApplication::translate("LoginDlg", "\350\264\246\345\217\267\357\274\232", nullptr));
        label_2->setText(QApplication::translate("LoginDlg", "\345\257\206\347\240\201\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDlg: public Ui_LoginDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDLG_H
