/********************************************************************************
** Form generated from reading UI file 'controlpancelwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLPANCELWINDOW_H
#define UI_CONTROLPANCELWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlPancelWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QToolButton *toolButton_pump;
    QToolButton *toolButton_high_voltage;
    QToolButton *toolButton_molecular_pump;
    QToolButton *toolButton_camera_lighting;
    QToolButton *toolButton_pinch_valve;
    QToolButton *toolButton_24_voltage;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ControlPancelWindow)
    {
        if (ControlPancelWindow->objectName().isEmpty())
            ControlPancelWindow->setObjectName(QString::fromUtf8("ControlPancelWindow"));
        ControlPancelWindow->resize(251, 227);
        ControlPancelWindow->setStyleSheet(QString::fromUtf8(".QPushButton{\n"
"border-style:none;\n"
"border:1px solid #C0DCF2;\n"
"color:#386487;\n"
"padding:65px;\n"
"min-height:40px;\n"
"width:50px;\n"
"border-radius:1px;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #DEF0FE,stop:1 #C0DEF6);\n"
"}\n"
".QPushButton:hover{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #F2F9FF,stop:1 #DAEFFF);\n"
"}\n"
"\n"
".QPushButton:pressed{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #DEF0FE,stop:1 #C0DEF6);\n"
"}"));
        centralwidget = new QWidget(ControlPancelWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 6, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        toolButton_pump = new QToolButton(centralwidget);
        toolButton_pump->setObjectName(QString::fromUtf8("toolButton_pump"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/gemo.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_pump->setIcon(icon);
        toolButton_pump->setIconSize(QSize(60, 50));
        toolButton_pump->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(toolButton_pump, 0, 1, 1, 1);

        toolButton_high_voltage = new QToolButton(centralwidget);
        toolButton_high_voltage->setObjectName(QString::fromUtf8("toolButton_high_voltage"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/high_voltage_close.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_high_voltage->setIcon(icon1);
        toolButton_high_voltage->setIconSize(QSize(60, 50));
        toolButton_high_voltage->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(toolButton_high_voltage, 0, 3, 1, 1);

        toolButton_molecular_pump = new QToolButton(centralwidget);
        toolButton_molecular_pump->setObjectName(QString::fromUtf8("toolButton_molecular_pump"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/molecular_pump_close.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_molecular_pump->setIcon(icon2);
        toolButton_molecular_pump->setIconSize(QSize(60, 50));
        toolButton_molecular_pump->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(toolButton_molecular_pump, 0, 2, 1, 1);

        toolButton_camera_lighting = new QToolButton(centralwidget);
        toolButton_camera_lighting->setObjectName(QString::fromUtf8("toolButton_camera_lighting"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/camera_lighting_close.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_camera_lighting->setIcon(icon3);
        toolButton_camera_lighting->setIconSize(QSize(60, 50));
        toolButton_camera_lighting->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(toolButton_camera_lighting, 1, 2, 1, 1);

        toolButton_pinch_valve = new QToolButton(centralwidget);
        toolButton_pinch_valve->setObjectName(QString::fromUtf8("toolButton_pinch_valve"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/valve_close.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_pinch_valve->setIcon(icon4);
        toolButton_pinch_valve->setIconSize(QSize(60, 50));
        toolButton_pinch_valve->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(toolButton_pinch_valve, 1, 3, 1, 1);

        toolButton_24_voltage = new QToolButton(centralwidget);
        toolButton_24_voltage->setObjectName(QString::fromUtf8("toolButton_24_voltage"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/voltage_close.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_24_voltage->setIcon(icon5);
        toolButton_24_voltage->setIconSize(QSize(60, 50));
        toolButton_24_voltage->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(toolButton_24_voltage, 1, 1, 1, 1);

        ControlPancelWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ControlPancelWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 251, 23));
        ControlPancelWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ControlPancelWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ControlPancelWindow->setStatusBar(statusbar);

        retranslateUi(ControlPancelWindow);

        QMetaObject::connectSlotsByName(ControlPancelWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ControlPancelWindow)
    {
        ControlPancelWindow->setWindowTitle(QApplication::translate("ControlPancelWindow", "\346\216\247\345\210\266\351\235\242\346\235\277", nullptr));
        toolButton_pump->setText(QApplication::translate("ControlPancelWindow", "\351\232\224\350\206\234\346\263\265", nullptr));
        toolButton_high_voltage->setText(QApplication::translate("ControlPancelWindow", "\351\253\230\345\216\213", nullptr));
        toolButton_molecular_pump->setText(QApplication::translate("ControlPancelWindow", "\345\210\206\345\255\220\346\263\265", nullptr));
        toolButton_camera_lighting->setText(QApplication::translate("ControlPancelWindow", "\346\216\242\345\244\264\347\201\257", nullptr));
        toolButton_pinch_valve->setText(QApplication::translate("ControlPancelWindow", "\346\224\276\346\260\224", nullptr));
        toolButton_24_voltage->setText(QApplication::translate("ControlPancelWindow", "24V", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ControlPancelWindow: public Ui_ControlPancelWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLPANCELWINDOW_H
