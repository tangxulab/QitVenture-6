/********************************************************************************
** Form generated from reading UI file 'ChromatographicFormWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHROMATOGRAPHICFORMWINDOW_H
#define UI_CHROMATOGRAPHICFORMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChromatographicFormWindow
{
public:

    void setupUi(QWidget *ChromatographicFormWindow)
    {
        if (ChromatographicFormWindow->objectName().isEmpty())
            ChromatographicFormWindow->setObjectName(QString::fromUtf8("ChromatographicFormWindow"));
        ChromatographicFormWindow->resize(400, 300);

        retranslateUi(ChromatographicFormWindow);

        QMetaObject::connectSlotsByName(ChromatographicFormWindow);
    } // setupUi

    void retranslateUi(QWidget *ChromatographicFormWindow)
    {
        ChromatographicFormWindow->setWindowTitle(QApplication::translate("ChromatographicFormWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChromatographicFormWindow: public Ui_ChromatographicFormWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHROMATOGRAPHICFORMWINDOW_H
