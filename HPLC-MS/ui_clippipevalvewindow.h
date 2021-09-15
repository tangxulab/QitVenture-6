/********************************************************************************
** Form generated from reading UI file 'clippipevalvewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIPPIPEVALVEWINDOW_H
#define UI_CLIPPIPEVALVEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClipPipeValveWindow
{
public:

    void setupUi(QWidget *ClipPipeValveWindow)
    {
        if (ClipPipeValveWindow->objectName().isEmpty())
            ClipPipeValveWindow->setObjectName(QString::fromUtf8("ClipPipeValveWindow"));
        ClipPipeValveWindow->resize(400, 300);

        retranslateUi(ClipPipeValveWindow);

        QMetaObject::connectSlotsByName(ClipPipeValveWindow);
    } // setupUi

    void retranslateUi(QWidget *ClipPipeValveWindow)
    {
        ClipPipeValveWindow->setWindowTitle(QApplication::translate("ClipPipeValveWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClipPipeValveWindow: public Ui_ClipPipeValveWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIPPIPEVALVEWINDOW_H
