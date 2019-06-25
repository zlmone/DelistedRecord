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
#include <QtWidgets/QGridLayout>
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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DelistedTool
{
public:
    QAction *channgeUser;
    QAction *logOut;
    QWidget *centralWidget;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
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
    QPushButton *writrToExcel;
    QTableView *DelistedCheck;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *ZhiDanBox;
    QLabel *label_3;
    QLineEdit *PCAddress;
    QLineEdit *IDCtrl;
    QPushButton *pushButton;
    QLabel *label_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *delistedLog;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DelistedTool)
    {
        if (DelistedTool->objectName().isEmpty())
            DelistedTool->setObjectName(QStringLiteral("DelistedTool"));
        DelistedTool->resize(1174, 681);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DelistedTool->sizePolicy().hasHeightForWidth());
        DelistedTool->setSizePolicy(sizePolicy);
        DelistedTool->setMinimumSize(QSize(1174, 681));
        DelistedTool->setMaximumSize(QSize(1174, 681));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ico1/\351\200\200\346\235\277\350\256\260\345\275\225.png"), QSize(), QIcon::Normal, QIcon::Off);
        DelistedTool->setWindowIcon(icon);
        channgeUser = new QAction(DelistedTool);
        channgeUser->setObjectName(QStringLiteral("channgeUser"));
        channgeUser->setShortcutContext(Qt::WindowShortcut);
        logOut = new QAction(DelistedTool);
        logOut->setObjectName(QStringLiteral("logOut"));
        centralWidget = new QWidget(DelistedTool);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(11, 248, 1151, 391));
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(12, 24, 1131, 361));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        dateTimeEdit = new QDateTimeEdit(layoutWidget);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setDateTime(QDateTime(QDate(2019, 6, 1), QTime(0, 0, 0)));

        horizontalLayout->addWidget(dateTimeEdit);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("font: 75 9pt \"ADMUI3Lg\";"));

        horizontalLayout->addWidget(label_5);

        dateTimeEdit_2 = new QDateTimeEdit(layoutWidget);
        dateTimeEdit_2->setObjectName(QStringLiteral("dateTimeEdit_2"));
        dateTimeEdit_2->setDateTime(QDateTime(QDate(2019, 6, 1), QTime(0, 0, 0)));

        horizontalLayout->addWidget(dateTimeEdit_2);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout->addWidget(label_6);

        IDlineEdit = new QLineEdit(layoutWidget);
        IDlineEdit->setObjectName(QStringLiteral("IDlineEdit"));

        horizontalLayout->addWidget(IDlineEdit);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout->addWidget(label_7);

        zhidanlineEdit = new QLineEdit(layoutWidget);
        zhidanlineEdit->setObjectName(QStringLiteral("zhidanlineEdit"));

        horizontalLayout->addWidget(zhidanlineEdit);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        deletePart = new QPushButton(layoutWidget);
        deletePart->setObjectName(QStringLiteral("deletePart"));

        horizontalLayout->addWidget(deletePart);

        deleteAll = new QPushButton(layoutWidget);
        deleteAll->setObjectName(QStringLiteral("deleteAll"));

        horizontalLayout->addWidget(deleteAll);

        writrToExcel = new QPushButton(layoutWidget);
        writrToExcel->setObjectName(QStringLiteral("writrToExcel"));

        horizontalLayout->addWidget(writrToExcel);


        verticalLayout->addLayout(horizontalLayout);

        DelistedCheck = new QTableView(layoutWidget);
        DelistedCheck->setObjectName(QStringLiteral("DelistedCheck"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(10);
        DelistedCheck->setFont(font);
        DelistedCheck->setStyleSheet(QString::fromUtf8("/*tablewidget \346\240\267\345\274\217*/\n"
"QTableView {\n"
"    selection-background-color:rgb(210,246,251);\n"
"	selection-color:black;\n"
"    background-color:white;     /*\346\225\264\344\270\252\350\241\250\346\240\274\347\232\204\350\203\214\346\231\257\350\211\262\357\274\214\350\277\231\351\207\214\344\270\272\347\231\275\350\211\262*/\n"
"    border:1px solid #E0DDDC;   /*\350\276\271\346\241\206\344\270\2721\345\203\217\347\264\240\357\274\214\347\201\260\350\211\262*/\n"
"    gridline-color:lightgray;   /*\350\277\231\344\270\252\346\230\257\350\241\250\346\240\274\347\232\204\346\240\274\345\255\220\347\272\277\347\232\204\351\242\234\350\211\262\357\274\214\344\270\272\344\272\256\347\201\260*/\n"
"}\n"
" \n"
"/*\350\277\231\351\207\214\346\230\257\350\241\250\346\240\274\350\241\250\345\244\264\346\240\267\345\274\217*/\n"
"QHeaderView::section {\n"
"    background-color:rgb(238,232,231);     /*\350\203\214\346\231\257\350\211\262 \347\231\275\350\211\262*/\n"
"    border:0.5px solid #E0DDDC;  "
                        " /*\345\205\210\346\212\212\350\276\271\346\241\206\345\256\275\345\272\246\350\256\276\344\270\2720\357\274\214\345\215\263\351\232\220\350\227\217\346\211\200\346\234\211\350\241\250\345\244\264\350\276\271\346\241\206*/\n"
"    border-bottom:1px solid #E0DDDC;/*\347\204\266\345\220\216\345\217\252\346\230\276\347\244\272\344\270\213\350\276\271\346\241\206\357\274\214\345\233\240\344\270\272\344\270\212\350\276\271\346\241\206\345\222\214\345\267\246\345\217\263\350\276\271\346\241\206\346\230\257\346\225\264\344\270\252Table\347\232\204\350\276\271\346\241\206\357\274\214\351\203\275\346\230\276\347\244\272\344\274\232\346\234\2112px\347\232\204\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"    height:20px;                /*\350\241\250\345\244\264\351\253\230\345\272\246*/\n"
"}\n"
""));
        DelistedCheck->setEditTriggers(QAbstractItemView::NoEditTriggers);
        DelistedCheck->setSelectionMode(QAbstractItemView::MultiSelection);
        DelistedCheck->setSelectionBehavior(QAbstractItemView::SelectRows);
        DelistedCheck->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

        verticalLayout->addWidget(DelistedCheck);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(12, 12, 381, 221));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        ZhiDanBox = new QComboBox(groupBox);
        ZhiDanBox->setObjectName(QStringLiteral("ZhiDanBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ZhiDanBox->sizePolicy().hasHeightForWidth());
        ZhiDanBox->setSizePolicy(sizePolicy2);
        ZhiDanBox->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(ZhiDanBox, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        PCAddress = new QLineEdit(groupBox);
        PCAddress->setObjectName(QStringLiteral("PCAddress"));
        PCAddress->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        PCAddress->setReadOnly(true);

        gridLayout->addWidget(PCAddress, 1, 1, 1, 1);

        IDCtrl = new QLineEdit(groupBox);
        IDCtrl->setObjectName(QStringLiteral("IDCtrl"));
        IDCtrl->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(IDCtrl, 3, 1, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setStyleSheet(QString::fromUtf8("\n"
"QToolButton#delAlarmBtn{\n"
"\n"
"       font-size: 12px;\n"
"\n"
"       border-style:inset;\n"
"\n"
"       border:0px solid #E5E5E5;\n"
"\n"
"  \n"
"    qproperty-iconSize: 16px 16px;//\345\233\276\347\211\207\345\244\247\345\260\217\n"
"\n"
"    qproperty-toolButtonStyle: ToolButtonTextBesideIcon;//\346\226\207\345\255\227\345\222\214\345\233\276\347\211\207\346\240\267\345\274\217\n"
"\n"
"}"));

        gridLayout->addWidget(pushButton, 4, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(410, 10, 751, 221));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy3);
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        delistedLog = new QTextEdit(groupBox_2);
        delistedLog->setObjectName(QStringLiteral("delistedLog"));
        sizePolicy3.setHeightForWidth(delistedLog->sizePolicy().hasHeightForWidth());
        delistedLog->setSizePolicy(sizePolicy3);
        delistedLog->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        delistedLog->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        delistedLog->setReadOnly(true);

        horizontalLayout_2->addWidget(delistedLog);

        DelistedTool->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DelistedTool);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1174, 23));
        DelistedTool->setMenuBar(menuBar);
        statusBar = new QStatusBar(DelistedTool);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DelistedTool->setStatusBar(statusBar);

        retranslateUi(DelistedTool);

        QMetaObject::connectSlotsByName(DelistedTool);
    } // setupUi

    void retranslateUi(QMainWindow *DelistedTool)
    {
        DelistedTool->setWindowTitle(QApplication::translate("DelistedTool", "DelistedTool_V1.0.1_1906241925", nullptr));
        channgeUser->setText(QApplication::translate("DelistedTool", "\345\210\207\346\215\242\350\264\246\345\217\267", nullptr));
        logOut->setText(QApplication::translate("DelistedTool", "\351\200\200\345\207\272\350\264\246\345\217\267", nullptr));
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
        writrToExcel->setText(QApplication::translate("DelistedTool", "\345\257\274\345\207\272", nullptr));
        groupBox->setTitle(QApplication::translate("DelistedTool", "\351\200\200\346\235\277\346\223\215\344\275\234", nullptr));
        label->setText(QApplication::translate("DelistedTool", "\350\256\242\345\215\225\345\217\267\357\274\232", nullptr));
        label_3->setText(QApplication::translate("DelistedTool", "\346\234\254\346\234\272IP\357\274\232", nullptr));
        IDCtrl->setText(QString());
        pushButton->setText(QApplication::translate("DelistedTool", "\345\210\267\346\226\260\350\256\242\345\215\225", nullptr));
        label_2->setText(QApplication::translate("DelistedTool", "\350\276\223\345\205\245ID\345\217\267\357\274\232", nullptr));
        groupBox_2->setTitle(QApplication::translate("DelistedTool", "\351\200\200\346\235\277\346\227\245\345\277\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DelistedTool: public Ui_DelistedTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELISTEDTOOL_H
