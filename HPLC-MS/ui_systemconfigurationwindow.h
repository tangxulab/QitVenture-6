/********************************************************************************
** Form generated from reading UI file 'systemconfigurationwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMCONFIGURATIONWINDOW_H
#define UI_SYSTEMCONFIGURATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemConfigurationWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *line_inject_pump_clean_perform_rate;
    QLabel *label_3;
    QLineEdit *line_inject_pump_clean_times;
    QLineEdit *line_inject_pump_waster_clean_times;
    QPushButton *btn_inject_pump_clean_perform;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *btn_clean_stop;
    QWidget *tab_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SystemConfigurationWindow)
    {
        if (SystemConfigurationWindow->objectName().isEmpty())
            SystemConfigurationWindow->setObjectName(QString::fromUtf8("SystemConfigurationWindow"));
        SystemConfigurationWindow->resize(504, 283);
        centralwidget = new QWidget(SystemConfigurationWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 351, 151));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        line_inject_pump_clean_perform_rate = new QLineEdit(groupBox);
        line_inject_pump_clean_perform_rate->setObjectName(QString::fromUtf8("line_inject_pump_clean_perform_rate"));

        gridLayout->addWidget(line_inject_pump_clean_perform_rate, 2, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        line_inject_pump_clean_times = new QLineEdit(groupBox);
        line_inject_pump_clean_times->setObjectName(QString::fromUtf8("line_inject_pump_clean_times"));

        gridLayout->addWidget(line_inject_pump_clean_times, 0, 1, 1, 1);

        line_inject_pump_waster_clean_times = new QLineEdit(groupBox);
        line_inject_pump_waster_clean_times->setObjectName(QString::fromUtf8("line_inject_pump_waster_clean_times"));

        gridLayout->addWidget(line_inject_pump_waster_clean_times, 1, 1, 1, 1);

        btn_inject_pump_clean_perform = new QPushButton(groupBox);
        btn_inject_pump_clean_perform->setObjectName(QString::fromUtf8("btn_inject_pump_clean_perform"));

        gridLayout->addWidget(btn_inject_pump_clean_perform, 1, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 1, 1, 1);

        btn_clean_stop = new QPushButton(groupBox);
        btn_clean_stop->setObjectName(QString::fromUtf8("btn_clean_stop"));

        gridLayout->addWidget(btn_clean_stop, 2, 2, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        SystemConfigurationWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SystemConfigurationWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 504, 23));
        SystemConfigurationWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SystemConfigurationWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SystemConfigurationWindow->setStatusBar(statusbar);

        retranslateUi(SystemConfigurationWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SystemConfigurationWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SystemConfigurationWindow)
    {
        SystemConfigurationWindow->setWindowTitle(QApplication::translate("SystemConfigurationWindow", "\347\263\273\347\273\237\351\205\215\347\275\256", nullptr));
        groupBox->setTitle(QApplication::translate("SystemConfigurationWindow", "\350\207\252\345\212\250\346\270\205\346\264\227", nullptr));
        label_3->setText(QApplication::translate("SystemConfigurationWindow", "\345\272\237\346\266\262\346\254\241\346\225\260", nullptr));
        btn_inject_pump_clean_perform->setText(QApplication::translate("SystemConfigurationWindow", "\346\211\247\350\241\214", nullptr));
        label_2->setText(QApplication::translate("SystemConfigurationWindow", "\346\211\247\350\241\214\351\200\237\345\272\246", nullptr));
        label->setText(QApplication::translate("SystemConfigurationWindow", "\346\270\205\346\264\227\346\254\241\346\225\260", nullptr));
        label_4->setText(QApplication::translate("SystemConfigurationWindow", "\345\275\223\345\211\215\350\277\233\345\272\246", nullptr));
        label_5->setText(QApplication::translate("SystemConfigurationWindow", "\346\232\202\346\227\240", nullptr));
        btn_clean_stop->setText(QApplication::translate("SystemConfigurationWindow", "\345\201\234\346\255\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SystemConfigurationWindow", " \346\263\250\345\260\204\346\263\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("SystemConfigurationWindow", "\345\210\206\345\255\220\346\263\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SystemConfigurationWindow: public Ui_SystemConfigurationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMCONFIGURATIONWINDOW_H
