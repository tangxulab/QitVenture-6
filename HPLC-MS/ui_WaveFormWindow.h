/********************************************************************************
** Form generated from reading UI file 'WaveFormWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAVEFORMWINDOW_H
#define UI_WAVEFORMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WaveFormWindowClass
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;

    void setupUi(QWidget *WaveFormWindowClass)
    {
        if (WaveFormWindowClass->objectName().isEmpty())
            WaveFormWindowClass->setObjectName(QString::fromUtf8("WaveFormWindowClass"));
        WaveFormWindowClass->resize(1071, 720);
        gridLayoutWidget = new QWidget(WaveFormWindowClass);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(40, 60, 261, 141));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(WaveFormWindowClass);

        QMetaObject::connectSlotsByName(WaveFormWindowClass);
    } // setupUi

    void retranslateUi(QWidget *WaveFormWindowClass)
    {
        WaveFormWindowClass->setWindowTitle(QApplication::translate("WaveFormWindowClass", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WaveFormWindowClass: public Ui_WaveFormWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAVEFORMWINDOW_H
