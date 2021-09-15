/********************************************************************************
** Form generated from reading UI file 'permissionwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERMISSIONWINDOW_H
#define UI_PERMISSIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PermissionWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PermissionWindow)
    {
        if (PermissionWindow->objectName().isEmpty())
            PermissionWindow->setObjectName(QString::fromUtf8("PermissionWindow"));
        PermissionWindow->resize(800, 600);
        centralwidget = new QWidget(PermissionWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        PermissionWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PermissionWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        PermissionWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PermissionWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PermissionWindow->setStatusBar(statusbar);

        retranslateUi(PermissionWindow);

        QMetaObject::connectSlotsByName(PermissionWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PermissionWindow)
    {
        PermissionWindow->setWindowTitle(QApplication::translate("PermissionWindow", "\346\235\203\351\231\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PermissionWindow: public Ui_PermissionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERMISSIONWINDOW_H
