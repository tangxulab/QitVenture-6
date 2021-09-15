/********************************************************************************
** Form generated from reading UI file 'CheckAMSWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKAMSWINDOW_H
#define UI_CHECKAMSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckAMSWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QToolButton *tool_sample_insert;
    QTableWidget *tableWidget;
    QToolButton *tool_do;
    QToolButton *tool_undo;
    QToolButton *tool_save;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *CheckAMSWindow)
    {
        if (CheckAMSWindow->objectName().isEmpty())
            CheckAMSWindow->setObjectName(QString::fromUtf8("CheckAMSWindow"));
        CheckAMSWindow->resize(408, 401);
        centralwidget = new QWidget(CheckAMSWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tool_sample_insert = new QToolButton(centralwidget);
        tool_sample_insert->setObjectName(QString::fromUtf8("tool_sample_insert"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("resource/images/insert.png"), QSize(), QIcon::Normal, QIcon::Off);
        tool_sample_insert->setIcon(icon);
        tool_sample_insert->setIconSize(QSize(32, 32));

        gridLayout->addWidget(tool_sample_insert, 0, 3, 1, 1);

        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        if (tableWidget->rowCount() < 4)
            tableWidget->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(3, 1, __qtablewidgetitem7);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setRowCount(4);
        tableWidget->setColumnCount(3);

        gridLayout->addWidget(tableWidget, 1, 0, 1, 6);

        tool_do = new QToolButton(centralwidget);
        tool_do->setObjectName(QString::fromUtf8("tool_do"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/do-no.png"), QSize(), QIcon::Normal, QIcon::Off);
        tool_do->setIcon(icon1);
        tool_do->setIconSize(QSize(32, 32));

        gridLayout->addWidget(tool_do, 0, 2, 1, 1);

        tool_undo = new QToolButton(centralwidget);
        tool_undo->setObjectName(QString::fromUtf8("tool_undo"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/undo-no.png"), QSize(), QIcon::Normal, QIcon::Off);
        tool_undo->setIcon(icon2);
        tool_undo->setIconSize(QSize(32, 32));

        gridLayout->addWidget(tool_undo, 0, 1, 1, 1);

        tool_save = new QToolButton(centralwidget);
        tool_save->setObjectName(QString::fromUtf8("tool_save"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("resource/images/save-open.png"), QSize(), QIcon::Normal, QIcon::Off);
        tool_save->setIcon(icon3);
        tool_save->setIconSize(QSize(32, 32));

        gridLayout->addWidget(tool_save, 0, 4, 1, 1);

        CheckAMSWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CheckAMSWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 408, 23));
        CheckAMSWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CheckAMSWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CheckAMSWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(CheckAMSWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        CheckAMSWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(CheckAMSWindow);

        QMetaObject::connectSlotsByName(CheckAMSWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CheckAMSWindow)
    {
        CheckAMSWindow->setWindowTitle(QApplication::translate("CheckAMSWindow", "\346\240\241\345\207\206\347\225\214\351\235\242", nullptr));
        tool_sample_insert->setText(QApplication::translate("CheckAMSWindow", "...", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem = tableWidget->item(0, 0);
        ___qtablewidgetitem->setText(QApplication::translate("CheckAMSWindow", "C5H12NO2", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->item(1, 0);
        ___qtablewidgetitem1->setText(QApplication::translate("CheckAMSWindow", "C6H19N3O6P3", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->item(2, 0);
        ___qtablewidgetitem2->setText(QApplication::translate("CheckAMSWindow", "C12H19F12N3O6P3", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->item(3, 0);
        ___qtablewidgetitem3->setText(QApplication::translate("CheckAMSWindow", "C18H19F24N3O6P3", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        tool_do->setText(QApplication::translate("CheckAMSWindow", "...", nullptr));
        tool_undo->setText(QApplication::translate("CheckAMSWindow", "...", nullptr));
        toolBar->setWindowTitle(QApplication::translate("CheckAMSWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CheckAMSWindow: public Ui_CheckAMSWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKAMSWINDOW_H
