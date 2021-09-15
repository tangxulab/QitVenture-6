/********************************************************************************
** Form generated from reading UI file 'SampleInfoInsertWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAMPLEINFOINSERTWINDOW_H
#define UI_SAMPLEINFOINSERTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SampleInfoInsertWindow
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *line_sample_name;
    QLabel *label_2;
    QLineEdit *line_sample_ms;
    QPushButton *pushButton_2;
    QPushButton *btn_sample_insert_ok;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SampleInfoInsertWindow)
    {
        if (SampleInfoInsertWindow->objectName().isEmpty())
            SampleInfoInsertWindow->setObjectName(QString::fromUtf8("SampleInfoInsertWindow"));
        SampleInfoInsertWindow->resize(243, 176);
        centralwidget = new QWidget(SampleInfoInsertWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        line_sample_name = new QLineEdit(centralwidget);
        line_sample_name->setObjectName(QString::fromUtf8("line_sample_name"));

        formLayout->setWidget(0, QFormLayout::FieldRole, line_sample_name);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        line_sample_ms = new QLineEdit(centralwidget);
        line_sample_ms->setObjectName(QString::fromUtf8("line_sample_ms"));

        formLayout->setWidget(2, QFormLayout::FieldRole, line_sample_ms);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        formLayout->setWidget(5, QFormLayout::FieldRole, pushButton_2);

        btn_sample_insert_ok = new QPushButton(centralwidget);
        btn_sample_insert_ok->setObjectName(QString::fromUtf8("btn_sample_insert_ok"));

        formLayout->setWidget(5, QFormLayout::LabelRole, btn_sample_insert_ok);

        SampleInfoInsertWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SampleInfoInsertWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 243, 23));
        SampleInfoInsertWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SampleInfoInsertWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SampleInfoInsertWindow->setStatusBar(statusbar);

        retranslateUi(SampleInfoInsertWindow);

        QMetaObject::connectSlotsByName(SampleInfoInsertWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SampleInfoInsertWindow)
    {
        SampleInfoInsertWindow->setWindowTitle(QApplication::translate("SampleInfoInsertWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("SampleInfoInsertWindow", "\346\240\267\345\223\201\345\220\215\347\247\260", nullptr));
        label_2->setText(QApplication::translate("SampleInfoInsertWindow", "\350\264\250\351\207\217\346\225\260", nullptr));
        pushButton_2->setText(QApplication::translate("SampleInfoInsertWindow", "\345\217\226\346\266\210", nullptr));
        btn_sample_insert_ok->setText(QApplication::translate("SampleInfoInsertWindow", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SampleInfoInsertWindow: public Ui_SampleInfoInsertWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAMPLEINFOINSERTWINDOW_H
