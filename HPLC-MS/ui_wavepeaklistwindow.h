/********************************************************************************
** Form generated from reading UI file 'wavepeaklistwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAVEPEAKLISTWINDOW_H
#define UI_WAVEPEAKLISTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WavePeakListWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WavePeakListWindow)
    {
        if (WavePeakListWindow->objectName().isEmpty())
            WavePeakListWindow->setObjectName(QString::fromUtf8("WavePeakListWindow"));
        WavePeakListWindow->resize(800, 600);
        centralwidget = new QWidget(WavePeakListWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        WavePeakListWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WavePeakListWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        WavePeakListWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WavePeakListWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        WavePeakListWindow->setStatusBar(statusbar);

        retranslateUi(WavePeakListWindow);

        QMetaObject::connectSlotsByName(WavePeakListWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WavePeakListWindow)
    {
        WavePeakListWindow->setWindowTitle(QApplication::translate("WavePeakListWindow", "\345\257\273\345\263\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WavePeakListWindow: public Ui_WavePeakListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAVEPEAKLISTWINDOW_H
