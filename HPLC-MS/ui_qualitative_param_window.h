/********************************************************************************
** Form generated from reading UI file 'qualitative_param_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUALITATIVE_PARAM_WINDOW_H
#define UI_QUALITATIVE_PARAM_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qualitative_Param_Window
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *line_signal_value;
    QPushButton *btn_signal_set;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Qualitative_Param_Window)
    {
        if (Qualitative_Param_Window->objectName().isEmpty())
            Qualitative_Param_Window->setObjectName(QString::fromUtf8("Qualitative_Param_Window"));
        Qualitative_Param_Window->resize(410, 300);
        centralwidget = new QWidget(Qualitative_Param_Window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 54, 12));
        line_signal_value = new QLineEdit(centralwidget);
        line_signal_value->setObjectName(QString::fromUtf8("line_signal_value"));
        line_signal_value->setGeometry(QRect(90, 30, 113, 20));
        btn_signal_set = new QPushButton(centralwidget);
        btn_signal_set->setObjectName(QString::fromUtf8("btn_signal_set"));
        btn_signal_set->setGeometry(QRect(220, 30, 75, 23));
        Qualitative_Param_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Qualitative_Param_Window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 410, 23));
        Qualitative_Param_Window->setMenuBar(menubar);
        statusbar = new QStatusBar(Qualitative_Param_Window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Qualitative_Param_Window->setStatusBar(statusbar);

        retranslateUi(Qualitative_Param_Window);

        QMetaObject::connectSlotsByName(Qualitative_Param_Window);
    } // setupUi

    void retranslateUi(QMainWindow *Qualitative_Param_Window)
    {
        Qualitative_Param_Window->setWindowTitle(QApplication::translate("Qualitative_Param_Window", "\345\256\232\346\200\247\345\217\202\346\225\260", nullptr));
        label->setText(QApplication::translate("Qualitative_Param_Window", "\344\277\241\345\217\267\351\230\210\345\200\274", nullptr));
        btn_signal_set->setText(QApplication::translate("Qualitative_Param_Window", "\350\256\276\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qualitative_Param_Window: public Ui_Qualitative_Param_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUALITATIVE_PARAM_WINDOW_H
