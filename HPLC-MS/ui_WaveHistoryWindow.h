/********************************************************************************
** Form generated from reading UI file 'WaveHistoryWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAVEHISTORYWINDOW_H
#define UI_WAVEHISTORYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WaveHistoryWindow
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WaveHistoryWindow)
    {
        if (WaveHistoryWindow->objectName().isEmpty())
            WaveHistoryWindow->setObjectName(QString::fromUtf8("WaveHistoryWindow"));
        WaveHistoryWindow->resize(800, 600);
        menubar = new QMenuBar(WaveHistoryWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        WaveHistoryWindow->setMenuBar(menubar);
        centralwidget = new QWidget(WaveHistoryWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        WaveHistoryWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(WaveHistoryWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        WaveHistoryWindow->setStatusBar(statusbar);

        retranslateUi(WaveHistoryWindow);

        QMetaObject::connectSlotsByName(WaveHistoryWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WaveHistoryWindow)
    {
        WaveHistoryWindow->setWindowTitle(QCoreApplication::translate("WaveHistoryWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WaveHistoryWindow: public Ui_WaveHistoryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAVEHISTORYWINDOW_H
