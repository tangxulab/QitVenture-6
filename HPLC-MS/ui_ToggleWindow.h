/********************************************************************************
** Form generated from reading UI file 'ToggleWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOGGLEWINDOW_H
#define UI_TOGGLEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToggleWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ToggleWindow)
    {
        if (ToggleWindow->objectName().isEmpty())
            ToggleWindow->setObjectName(QString::fromUtf8("ToggleWindow"));
        ToggleWindow->resize(332, 280);
        centralwidget = new QWidget(ToggleWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ToggleWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ToggleWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 332, 23));
        ToggleWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ToggleWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ToggleWindow->setStatusBar(statusbar);

        retranslateUi(ToggleWindow);

        QMetaObject::connectSlotsByName(ToggleWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ToggleWindow)
    {
        ToggleWindow->setWindowTitle(QApplication::translate("ToggleWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ToggleWindow: public Ui_ToggleWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOGGLEWINDOW_H
