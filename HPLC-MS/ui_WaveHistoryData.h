/********************************************************************************
** Form generated from reading UI file 'WaveHistoryData.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAVEHISTORYDATA_H
#define UI_WAVEHISTORYDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WaveHistoryData
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;

    void setupUi(QMainWindow *WaveHistoryData)
    {
        if (WaveHistoryData->objectName().isEmpty())
            WaveHistoryData->setObjectName(QString::fromUtf8("WaveHistoryData"));
        WaveHistoryData->resize(800, 600);
        centralwidget = new QWidget(WaveHistoryData);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        WaveHistoryData->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WaveHistoryData);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        WaveHistoryData->setMenuBar(menubar);

        retranslateUi(WaveHistoryData);

        QMetaObject::connectSlotsByName(WaveHistoryData);
    } // setupUi

    void retranslateUi(QMainWindow *WaveHistoryData)
    {
        WaveHistoryData->setWindowTitle(QApplication::translate("WaveHistoryData", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WaveHistoryData: public Ui_WaveHistoryData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAVEHISTORYDATA_H
