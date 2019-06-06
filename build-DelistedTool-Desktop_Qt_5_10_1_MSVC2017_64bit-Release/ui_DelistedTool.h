/********************************************************************************
** Form generated from reading UI file 'DelistedTool.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELISTEDTOOL_H
#define UI_DELISTEDTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DelistedTool
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QComboBox *ZhiDanBox;
    QPushButton *pushButton;
    QLineEdit *PCAddress;
    QLabel *label_2;
    QLineEdit *IDCtrl;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QTextEdit *delistedLog;
    QGroupBox *groupBox_3;
    QTableView *DelistedCheck;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_5;
    QDateTimeEdit *dateTimeEdit_2;
    QLabel *label_6;
    QLineEdit *IDlineEdit;
    QLabel *label_7;
    QLineEdit *zhidanlineEdit;
    QPushButton *pushButton_2;
    QPushButton *deletePart;
    QPushButton *deleteAll;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DelistedTool)
    {
        if (DelistedTool->objectName().isEmpty())
            DelistedTool->setObjectName(QStringLiteral("DelistedTool"));
        DelistedTool->resize(1128, 701);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../build-DelistedTool-Desktop_Qt_5_10_1_MSVC2017_64bit-Release/\351\200\200\345\207\272.svg"), QSize(), QIcon::Normal, QIcon::Off);
        DelistedTool->setWindowIcon(icon);
        centralWidget = new QWidget(DelistedTool);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 451, 201));
        ZhiDanBox = new QComboBox(groupBox);
        ZhiDanBox->setObjectName(QStringLiteral("ZhiDanBox"));
        ZhiDanBox->setGeometry(QRect(90, 40, 271, 31));
        ZhiDanBox->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(370, 40, 71, 28));
        PCAddress = new QLineEdit(groupBox);
        PCAddress->setObjectName(QStringLiteral("PCAddress"));
        PCAddress->setGeometry(QRect(90, 90, 271, 31));
        PCAddress->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 160, 76, 16));
        IDCtrl = new QLineEdit(groupBox);
        IDCtrl->setObjectName(QStringLiteral("IDCtrl"));
        IDCtrl->setGeometry(QRect(89, 151, 273, 31));
        IDCtrl->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 31, 63, 91));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(480, 10, 641, 201));
        delistedLog = new QTextEdit(groupBox_2);
        delistedLog->setObjectName(QStringLiteral("delistedLog"));
        delistedLog->setGeometry(QRect(10, 20, 621, 171));
        delistedLog->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        delistedLog->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        delistedLog->setReadOnly(true);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 230, 1111, 421));
        DelistedCheck = new QTableView(groupBox_3);
        DelistedCheck->setObjectName(QStringLiteral("DelistedCheck"));
        DelistedCheck->setGeometry(QRect(10, 60, 1091, 351));
        DelistedCheck->setSelectionMode(QAbstractItemView::MultiSelection);
        DelistedCheck->setSelectionBehavior(QAbstractItemView::SelectRows);
        widget1 = new QWidget(groupBox_3);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 20, 1091, 30));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        dateTimeEdit = new QDateTimeEdit(widget1);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setDateTime(QDateTime(QDate(2019, 6, 1), QTime(0, 0, 0)));

        horizontalLayout->addWidget(dateTimeEdit);

        label_5 = new QLabel(widget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("font: 75 9pt \"ADMUI3Lg\";"));

        horizontalLayout->addWidget(label_5);

        dateTimeEdit_2 = new QDateTimeEdit(widget1);
        dateTimeEdit_2->setObjectName(QStringLiteral("dateTimeEdit_2"));
        dateTimeEdit_2->setDateTime(QDateTime(QDate(2019, 6, 1), QTime(0, 0, 0)));

        horizontalLayout->addWidget(dateTimeEdit_2);

        label_6 = new QLabel(widget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout->addWidget(label_6);

        IDlineEdit = new QLineEdit(widget1);
        IDlineEdit->setObjectName(QStringLiteral("IDlineEdit"));

        horizontalLayout->addWidget(IDlineEdit);

        label_7 = new QLabel(widget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout->addWidget(label_7);

        zhidanlineEdit = new QLineEdit(widget1);
        zhidanlineEdit->setObjectName(QStringLiteral("zhidanlineEdit"));

        horizontalLayout->addWidget(zhidanlineEdit);

        pushButton_2 = new QPushButton(widget1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        deletePart = new QPushButton(widget1);
        deletePart->setObjectName(QStringLiteral("deletePart"));

        horizontalLayout->addWidget(deletePart);

        deleteAll = new QPushButton(widget1);
        deleteAll->setObjectName(QStringLiteral("deleteAll"));

        horizontalLayout->addWidget(deleteAll);

        pushButton_4 = new QPushButton(widget1);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        DelistedTool->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DelistedTool);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1128, 23));
        DelistedTool->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DelistedTool);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DelistedTool->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DelistedTool);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DelistedTool->setStatusBar(statusBar);

        retranslateUi(DelistedTool);

        QMetaObject::connectSlotsByName(DelistedTool);
    } // setupUi

    void retranslateUi(QMainWindow *DelistedTool)
    {
        DelistedTool->setWindowTitle(QApplication::translate("DelistedTool", "DelistedTool", nullptr));
        groupBox->setTitle(QApplication::translate("DelistedTool", "\351\200\200\346\235\277\346\223\215\344\275\234", nullptr));
        pushButton->setText(QApplication::translate("DelistedTool", "\345\210\267\346\226\260\350\256\242\345\215\225", nullptr));
        label_2->setText(QApplication::translate("DelistedTool", "\350\276\223\345\205\245ID\345\217\267\357\274\232", nullptr));
        IDCtrl->setText(QString());
        label->setText(QApplication::translate("DelistedTool", "\350\256\242\345\215\225\345\217\267\357\274\232", nullptr));
        label_3->setText(QApplication::translate("DelistedTool", "\346\234\254\346\234\272IP\357\274\232", nullptr));
        groupBox_2->setTitle(QApplication::translate("DelistedTool", "\351\200\200\346\235\277\346\227\245\345\277\227", nullptr));
        groupBox_3->setTitle(QApplication::translate("DelistedTool", "\351\200\200\346\235\277\346\237\245\350\257\242", nullptr));
        label_4->setText(QApplication::translate("DelistedTool", "\346\227\266\351\227\264\346\256\265\357\274\232", nullptr));
        dateTimeEdit->setDisplayFormat(QApplication::translate("DelistedTool", "yyyy-MM-dd HH:mm:ss", nullptr));
        label_5->setText(QApplication::translate("DelistedTool", "---->", nullptr));
        dateTimeEdit_2->setDisplayFormat(QApplication::translate("DelistedTool", "yyyy-MM-dd HH:mm:ss", nullptr));
        label_6->setText(QApplication::translate("DelistedTool", "ID\357\274\232", nullptr));
        label_7->setText(QApplication::translate("DelistedTool", "\350\256\242\345\215\225\345\217\267\357\274\232", nullptr));
        pushButton_2->setText(QApplication::translate("DelistedTool", "\346\237\245\350\257\242", nullptr));
        deletePart->setText(QApplication::translate("DelistedTool", "\345\210\240\351\231\244\351\200\211\344\270\255\346\225\260\346\215\256", nullptr));
        deleteAll->setText(QApplication::translate("DelistedTool", "\345\210\240\351\231\244\346\211\200\346\234\211\346\225\260\346\215\256", nullptr));
        pushButton_4->setText(QApplication::translate("DelistedTool", "\345\257\274\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DelistedTool: public Ui_DelistedTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELISTEDTOOL_H
