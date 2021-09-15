/********************************************************************************
** Form generated from reading UI file 'systemcheckwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMCHECKWINDOW_H
#define UI_SYSTEMCHECKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemCheckWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SystemCheckWindow)
    {
        if (SystemCheckWindow->objectName().isEmpty())
            SystemCheckWindow->setObjectName(QString::fromUtf8("SystemCheckWindow"));
        SystemCheckWindow->resize(283, 179);
        centralwidget = new QWidget(SystemCheckWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 80, 54, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 80, 54, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 20, 54, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 50, 54, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 50, 54, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(80, 20, 54, 16));
        SystemCheckWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SystemCheckWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 283, 23));
        SystemCheckWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SystemCheckWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SystemCheckWindow->setStatusBar(statusbar);

        retranslateUi(SystemCheckWindow);

        QMetaObject::connectSlotsByName(SystemCheckWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SystemCheckWindow)
    {
        SystemCheckWindow->setWindowTitle(QApplication::translate("SystemCheckWindow", "\347\263\273\347\273\237\346\243\200\346\237\245", nullptr));
        label->setText(QApplication::translate("SystemCheckWindow", "\344\273\252\345\231\250\347\212\266\346\200\201", nullptr));
        label_2->setText(QApplication::translate("SystemCheckWindow", "\346\232\202\346\227\240", nullptr));
        label_3->setText(QApplication::translate("SystemCheckWindow", "\346\212\245\350\255\246\347\240\201", nullptr));
        label_4->setText(QApplication::translate("SystemCheckWindow", "\347\234\237\347\251\272\347\212\266\346\200\201", nullptr));
        label_5->setText(QApplication::translate("SystemCheckWindow", "\346\232\202\346\227\240", nullptr));
        label_6->setText(QApplication::translate("SystemCheckWindow", "\346\232\202\346\227\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SystemCheckWindow: public Ui_SystemCheckWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMCHECKWINDOW_H
