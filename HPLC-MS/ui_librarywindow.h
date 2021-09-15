/********************************************************************************
** Form generated from reading UI file 'librarywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBRARYWINDOW_H
#define UI_LIBRARYWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LibraryWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *tool_add_lib;
    QSpacerItem *horizontalSpacer;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LibraryWindow)
    {
        if (LibraryWindow->objectName().isEmpty())
            LibraryWindow->setObjectName(QString::fromUtf8("LibraryWindow"));
        LibraryWindow->resize(800, 600);
        centralwidget = new QWidget(LibraryWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setColumnCount(6);

        gridLayout->addWidget(tableWidget, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tool_add_lib = new QToolButton(centralwidget);
        tool_add_lib->setObjectName(QString::fromUtf8("tool_add_lib"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        tool_add_lib->setIcon(icon);

        horizontalLayout->addWidget(tool_add_lib);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        LibraryWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(LibraryWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LibraryWindow->setStatusBar(statusbar);

        retranslateUi(LibraryWindow);

        QMetaObject::connectSlotsByName(LibraryWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LibraryWindow)
    {
        LibraryWindow->setWindowTitle(QApplication::translate("LibraryWindow", "MainWindow", nullptr));
        tool_add_lib->setText(QApplication::translate("LibraryWindow", "\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LibraryWindow: public Ui_LibraryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBRARYWINDOW_H
