/********************************************************************************
** Form generated from reading UI file 'progresswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSWINDOW_H
#define UI_PROGRESSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProgressWindow
{
public:
    QWidget *centralwidget;
    QProgressBar *progressBar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ProgressWindow)
    {
        if (ProgressWindow->objectName().isEmpty())
            ProgressWindow->setObjectName(QString::fromUtf8("ProgressWindow"));
        ProgressWindow->resize(481, 163);
        centralwidget = new QWidget(ProgressWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(60, 50, 371, 31));
        progressBar->setValue(24);
        ProgressWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ProgressWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 481, 23));
        ProgressWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ProgressWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ProgressWindow->setStatusBar(statusbar);

        retranslateUi(ProgressWindow);

        QMetaObject::connectSlotsByName(ProgressWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ProgressWindow)
    {
        ProgressWindow->setWindowTitle(QApplication::translate("ProgressWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProgressWindow: public Ui_ProgressWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSWINDOW_H
