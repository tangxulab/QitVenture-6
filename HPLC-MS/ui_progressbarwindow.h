/********************************************************************************
** Form generated from reading UI file 'progressbarwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSBARWINDOW_H
#define UI_PROGRESSBARWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProgressBarWindow
{
public:
    QWidget *centralwidget;
    QProgressBar *progressBar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ProgressBarWindow)
    {
        if (ProgressBarWindow->objectName().isEmpty())
            ProgressBarWindow->setObjectName(QString::fromUtf8("ProgressBarWindow"));
        ProgressBarWindow->resize(282, 135);
        centralwidget = new QWidget(ProgressBarWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(60, 30, 191, 21));
        progressBar->setValue(24);
        ProgressBarWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ProgressBarWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 282, 23));
        ProgressBarWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ProgressBarWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ProgressBarWindow->setStatusBar(statusbar);

        retranslateUi(ProgressBarWindow);

        QMetaObject::connectSlotsByName(ProgressBarWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ProgressBarWindow)
    {
        ProgressBarWindow->setWindowTitle(QApplication::translate("ProgressBarWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProgressBarWindow: public Ui_ProgressBarWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSBARWINDOW_H
