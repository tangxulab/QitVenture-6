/********************************************************************************
** Form generated from reading UI file 'slidingwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLIDINGWINDOW_H
#define UI_SLIDINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SlidingWindow
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SlidingWindow)
    {
        if (SlidingWindow->objectName().isEmpty())
            SlidingWindow->setObjectName(QString::fromUtf8("SlidingWindow"));
        SlidingWindow->resize(800, 600);
        menubar = new QMenuBar(SlidingWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        SlidingWindow->setMenuBar(menubar);
        centralwidget = new QWidget(SlidingWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SlidingWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SlidingWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SlidingWindow->setStatusBar(statusbar);

        retranslateUi(SlidingWindow);

        QMetaObject::connectSlotsByName(SlidingWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SlidingWindow)
    {
        SlidingWindow->setWindowTitle(QApplication::translate("SlidingWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SlidingWindow: public Ui_SlidingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLIDINGWINDOW_H
