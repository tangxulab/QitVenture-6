/********************************************************************************
** Form generated from reading UI file 'AddSampleWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSAMPLEWINDOW_H
#define UI_ADDSAMPLEWINDOW_H

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

class Ui_AddSampleWindow
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *line_sample_name;
    QLineEdit *line_sample_thoery;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *line_sample_experiment;
    QPushButton *btn_add_sample;
    QPushButton *btn_add_sample_cancel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AddSampleWindow)
    {
        if (AddSampleWindow->objectName().isEmpty())
            AddSampleWindow->setObjectName(QString::fromUtf8("AddSampleWindow"));
        AddSampleWindow->resize(273, 257);
        centralwidget = new QWidget(AddSampleWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        line_sample_name = new QLineEdit(centralwidget);
        line_sample_name->setObjectName(QString::fromUtf8("line_sample_name"));

        formLayout->setWidget(0, QFormLayout::FieldRole, line_sample_name);

        line_sample_thoery = new QLineEdit(centralwidget);
        line_sample_thoery->setObjectName(QString::fromUtf8("line_sample_thoery"));

        formLayout->setWidget(1, QFormLayout::FieldRole, line_sample_thoery);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        line_sample_experiment = new QLineEdit(centralwidget);
        line_sample_experiment->setObjectName(QString::fromUtf8("line_sample_experiment"));

        formLayout->setWidget(2, QFormLayout::FieldRole, line_sample_experiment);

        btn_add_sample = new QPushButton(centralwidget);
        btn_add_sample->setObjectName(QString::fromUtf8("btn_add_sample"));

        formLayout->setWidget(3, QFormLayout::LabelRole, btn_add_sample);

        btn_add_sample_cancel = new QPushButton(centralwidget);
        btn_add_sample_cancel->setObjectName(QString::fromUtf8("btn_add_sample_cancel"));

        formLayout->setWidget(3, QFormLayout::FieldRole, btn_add_sample_cancel);

        AddSampleWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AddSampleWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 273, 23));
        AddSampleWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AddSampleWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AddSampleWindow->setStatusBar(statusbar);

        retranslateUi(AddSampleWindow);

        QMetaObject::connectSlotsByName(AddSampleWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AddSampleWindow)
    {
        AddSampleWindow->setWindowTitle(QApplication::translate("AddSampleWindow", "\346\267\273\345\212\240\346\240\267\345\223\201", nullptr));
        label->setText(QApplication::translate("AddSampleWindow", "\346\240\267\345\223\201\345\220\215", nullptr));
        label_2->setText(QApplication::translate("AddSampleWindow", "\347\220\206\350\256\272\345\200\274", nullptr));
        label_3->setText(QApplication::translate("AddSampleWindow", "\345\256\236\351\252\214\345\200\274", nullptr));
        btn_add_sample->setText(QApplication::translate("AddSampleWindow", "\347\241\256\345\256\232", nullptr));
        btn_add_sample_cancel->setText(QApplication::translate("AddSampleWindow", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddSampleWindow: public Ui_AddSampleWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSAMPLEWINDOW_H
