/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mymainpushbutton.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_system_status;
    QGridLayout *gridLayout;
    QLabel *label_temperature;
    QLabel *label_pressure;
    QPushButton *btn_temperature;
    QPushButton *btn_pressure;
    QGroupBox *groupBox_pump;
    QGridLayout *gridLayout_2;
    QLineEdit *molecular_pump_temp;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *molecular_pump_current;
    QLineEdit *molecular_pump_speed;
    QLabel *label_3;
    MyMainPushButton *btn_molecular_pump_open;
    QGroupBox *groupBox_scaner_setting;
    QGridLayout *gridLayout_3;
    QLineEdit *line_low_mass;
    QLineEdit *line_icon_cool_time;
    QLineEdit *line_high_mass;
    QLabel *label_18;
    QLabel *label_6;
    QLabel *label_4;
    QLineEdit *line_scanner_cycle_time;
    MyMainPushButton *btn_scanner_setting;
    QLabel *label_5;
    QLabel *label_14;
    QLineEdit *line_icon_cool_voltage;
    QLabel *label_15;
    QLineEdit *line_icon_cool_open_time;
    QLabel *label_7;
    QLineEdit *line_total_cycle_time;
    MyMainPushButton *btn_main_experience_start;
    QGroupBox *aa;
    QGridLayout *gridLayout_4;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *line_velocity;
    MyMainPushButton *btn_end_point;
    QLabel *label_16;
    QProgressBar *progressBar_rest_volumn;
    MyMainPushButton *btn_extract_volume;
    QLineEdit *line_extract_speed;
    QLabel *label_17;
    MyMainPushButton *btn_stop_perform;
    MyMainPushButton *btn_start_perform;
    QLineEdit *line_extract_volume;
    QGroupBox *groupBox_esi_setting;
    QGridLayout *gridLayout_5;
    QLineEdit *line_main_high_volatge_return;
    QLabel *label_9;
    QLineEdit *lineEdit_2;
    QLabel *label_10;
    QLineEdit *line_main_pwm;
    QLineEdit *line_main_high_volatge;
    QLineEdit *line_main_high_temp;
    QLabel *label_11;
    MyMainPushButton *main_btn_indicator_light;
    QLabel *label_8;
    QLineEdit *line_main_high_current;
    MyMainPushButton *btn_main_esi_setting;
    QLineEdit *line_main_high_temp_return;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout_6;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QDockWidget *dockWidget_4;
    QWidget *dockWidgetContents_4;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QDockWidget *dockWidget_3;
    QWidget *dockWidgetContents_3;
    QVBoxLayout *verticalLayout_5;
    QTextBrowser *textBrowser;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1118, 1081);
        MainWindow->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid rgb(41, 57, 85);\n"
"    border-radius: 3px;\n"
"    background: white;\n"
"    selection-background-color: green;\n"
"    font-size: 14px ;\n"
"	width:5px;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 1px solid blue;\n"
"}\n"
"\n"
"MyMainPushButton\n"
"{\n"
"       color:black; /*\346\226\207\345\255\227\351\242\234\350\211\262*/\n"
"    background-color:#FFFFFF;/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:outset; /*\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"    border-width:1px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"    border-color:rgb(10, 46,112); /*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    border-radius:10px; /*\350\276\271\346\241\206\345\200\222\350\247\222*/\n"
"    font:bold 14px; /*\345\255\227\344\275\223*/\n"
"    font-family: Segoe UI;\n"
"    max-width:80px;/*\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"	min-width:80px;/*\346\216\247\344\273\266\346\234\200\345"
                        "\260\217\345\256\275\345\272\246*/\n"
"    min-height:20px;/*\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"    padding:4px;/*\345\206\205\350\276\271\350\267\235*/ \n"
"}\n"
"MyMainPushButton:hover{\n"
"color:#0000ff;\n"
"    background-color:#FFFFFF; /*\346\224\271\345\217\230\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:inset;/*\346\224\271\345\217\230\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"    padding-left:8px;\n"
"    padding-top:8px;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton#btn_pressure,#btn_temperature{\n"
"        background-color: #4CAF50;\n"
"    border: none;\n"
"    color: white;\n"
"        padding: 16px 16px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    \n"
"}\n"
"QScrollArea{\n"
"background-color: #FFFFFF;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(130, 850, 260, 127));
        frame->setMinimumSize(QSize(100, 100));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);

        verticalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1118, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(dockWidgetContents);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 307, 941));
        verticalLayout_7 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        groupBox_system_status = new QGroupBox(scrollAreaWidgetContents);
        groupBox_system_status->setObjectName(QString::fromUtf8("groupBox_system_status"));
        groupBox_system_status->setLayoutDirection(Qt::LeftToRight);
        groupBox_system_status->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        groupBox_system_status->setCheckable(false);
        gridLayout = new QGridLayout(groupBox_system_status);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_temperature = new QLabel(groupBox_system_status);
        label_temperature->setObjectName(QString::fromUtf8("label_temperature"));

        gridLayout->addWidget(label_temperature, 1, 0, 1, 1);

        label_pressure = new QLabel(groupBox_system_status);
        label_pressure->setObjectName(QString::fromUtf8("label_pressure"));

        gridLayout->addWidget(label_pressure, 0, 0, 1, 1);

        btn_temperature = new QPushButton(groupBox_system_status);
        btn_temperature->setObjectName(QString::fromUtf8("btn_temperature"));

        gridLayout->addWidget(btn_temperature, 1, 1, 1, 1);

        btn_pressure = new QPushButton(groupBox_system_status);
        btn_pressure->setObjectName(QString::fromUtf8("btn_pressure"));

        gridLayout->addWidget(btn_pressure, 0, 1, 1, 1);


        verticalLayout_7->addWidget(groupBox_system_status);

        groupBox_pump = new QGroupBox(scrollAreaWidgetContents);
        groupBox_pump->setObjectName(QString::fromUtf8("groupBox_pump"));
        gridLayout_2 = new QGridLayout(groupBox_pump);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        molecular_pump_temp = new QLineEdit(groupBox_pump);
        molecular_pump_temp->setObjectName(QString::fromUtf8("molecular_pump_temp"));
        molecular_pump_temp->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(molecular_pump_temp, 2, 2, 1, 1);

        label = new QLabel(groupBox_pump);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox_pump);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        molecular_pump_current = new QLineEdit(groupBox_pump);
        molecular_pump_current->setObjectName(QString::fromUtf8("molecular_pump_current"));
        molecular_pump_current->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(molecular_pump_current, 1, 2, 1, 1);

        molecular_pump_speed = new QLineEdit(groupBox_pump);
        molecular_pump_speed->setObjectName(QString::fromUtf8("molecular_pump_speed"));
        molecular_pump_speed->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(molecular_pump_speed, 0, 2, 1, 1);

        label_3 = new QLabel(groupBox_pump);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        btn_molecular_pump_open = new MyMainPushButton(groupBox_pump);
        btn_molecular_pump_open->setObjectName(QString::fromUtf8("btn_molecular_pump_open"));

        gridLayout_2->addWidget(btn_molecular_pump_open, 3, 0, 1, 2);


        verticalLayout_7->addWidget(groupBox_pump);

        groupBox_scaner_setting = new QGroupBox(scrollAreaWidgetContents);
        groupBox_scaner_setting->setObjectName(QString::fromUtf8("groupBox_scaner_setting"));
        gridLayout_3 = new QGridLayout(groupBox_scaner_setting);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        line_low_mass = new QLineEdit(groupBox_scaner_setting);
        line_low_mass->setObjectName(QString::fromUtf8("line_low_mass"));
        line_low_mass->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(line_low_mass, 1, 1, 1, 1);

        line_icon_cool_time = new QLineEdit(groupBox_scaner_setting);
        line_icon_cool_time->setObjectName(QString::fromUtf8("line_icon_cool_time"));
        line_icon_cool_time->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(line_icon_cool_time, 5, 1, 1, 1);

        line_high_mass = new QLineEdit(groupBox_scaner_setting);
        line_high_mass->setObjectName(QString::fromUtf8("line_high_mass"));
        line_high_mass->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(line_high_mass, 2, 1, 1, 1);

        label_18 = new QLabel(groupBox_scaner_setting);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_3->addWidget(label_18, 3, 0, 1, 1);

        label_6 = new QLabel(groupBox_scaner_setting);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 5, 0, 1, 1);

        label_4 = new QLabel(groupBox_scaner_setting);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        line_scanner_cycle_time = new QLineEdit(groupBox_scaner_setting);
        line_scanner_cycle_time->setObjectName(QString::fromUtf8("line_scanner_cycle_time"));
        line_scanner_cycle_time->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(line_scanner_cycle_time, 3, 1, 1, 1);

        btn_scanner_setting = new MyMainPushButton(groupBox_scaner_setting);
        btn_scanner_setting->setObjectName(QString::fromUtf8("btn_scanner_setting"));

        gridLayout_3->addWidget(btn_scanner_setting, 7, 0, 1, 1);

        label_5 = new QLabel(groupBox_scaner_setting);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 4, 0, 1, 1);

        label_14 = new QLabel(groupBox_scaner_setting);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 1, 0, 1, 1);

        line_icon_cool_voltage = new QLineEdit(groupBox_scaner_setting);
        line_icon_cool_voltage->setObjectName(QString::fromUtf8("line_icon_cool_voltage"));
        line_icon_cool_voltage->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(line_icon_cool_voltage, 4, 1, 1, 1);

        label_15 = new QLabel(groupBox_scaner_setting);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_3->addWidget(label_15, 2, 0, 1, 1);

        line_icon_cool_open_time = new QLineEdit(groupBox_scaner_setting);
        line_icon_cool_open_time->setObjectName(QString::fromUtf8("line_icon_cool_open_time"));
        line_icon_cool_open_time->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(line_icon_cool_open_time, 6, 1, 1, 1);

        label_7 = new QLabel(groupBox_scaner_setting);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 6, 0, 1, 1);

        line_total_cycle_time = new QLineEdit(groupBox_scaner_setting);
        line_total_cycle_time->setObjectName(QString::fromUtf8("line_total_cycle_time"));
        line_total_cycle_time->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(line_total_cycle_time, 0, 1, 1, 1);

        btn_main_experience_start = new MyMainPushButton(groupBox_scaner_setting);
        btn_main_experience_start->setObjectName(QString::fromUtf8("btn_main_experience_start"));

        gridLayout_3->addWidget(btn_main_experience_start, 7, 1, 1, 1);


        verticalLayout_7->addWidget(groupBox_scaner_setting);

        aa = new QGroupBox(scrollAreaWidgetContents);
        aa->setObjectName(QString::fromUtf8("aa"));
        gridLayout_4 = new QGridLayout(aa);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_12 = new QLabel(aa);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_4->addWidget(label_12, 0, 0, 1, 1);

        label_13 = new QLabel(aa);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_4->addWidget(label_13, 1, 0, 1, 1);

        line_velocity = new QLineEdit(aa);
        line_velocity->setObjectName(QString::fromUtf8("line_velocity"));

        gridLayout_4->addWidget(line_velocity, 3, 2, 1, 1);

        btn_end_point = new MyMainPushButton(aa);
        btn_end_point->setObjectName(QString::fromUtf8("btn_end_point"));

        gridLayout_4->addWidget(btn_end_point, 4, 2, 1, 1);

        label_16 = new QLabel(aa);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_4->addWidget(label_16, 2, 0, 1, 1);

        progressBar_rest_volumn = new QProgressBar(aa);
        progressBar_rest_volumn->setObjectName(QString::fromUtf8("progressBar_rest_volumn"));
        progressBar_rest_volumn->setValue(24);

        gridLayout_4->addWidget(progressBar_rest_volumn, 0, 2, 1, 1);

        btn_extract_volume = new MyMainPushButton(aa);
        btn_extract_volume->setObjectName(QString::fromUtf8("btn_extract_volume"));

        gridLayout_4->addWidget(btn_extract_volume, 4, 0, 1, 2);

        line_extract_speed = new QLineEdit(aa);
        line_extract_speed->setObjectName(QString::fromUtf8("line_extract_speed"));

        gridLayout_4->addWidget(line_extract_speed, 2, 2, 1, 1);

        label_17 = new QLabel(aa);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_4->addWidget(label_17, 3, 0, 1, 1);

        btn_stop_perform = new MyMainPushButton(aa);
        btn_stop_perform->setObjectName(QString::fromUtf8("btn_stop_perform"));

        gridLayout_4->addWidget(btn_stop_perform, 5, 2, 1, 1);

        btn_start_perform = new MyMainPushButton(aa);
        btn_start_perform->setObjectName(QString::fromUtf8("btn_start_perform"));

        gridLayout_4->addWidget(btn_start_perform, 5, 0, 1, 2);

        line_extract_volume = new QLineEdit(aa);
        line_extract_volume->setObjectName(QString::fromUtf8("line_extract_volume"));

        gridLayout_4->addWidget(line_extract_volume, 1, 2, 1, 1);


        verticalLayout_7->addWidget(aa);

        groupBox_esi_setting = new QGroupBox(scrollAreaWidgetContents);
        groupBox_esi_setting->setObjectName(QString::fromUtf8("groupBox_esi_setting"));
        gridLayout_5 = new QGridLayout(groupBox_esi_setting);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        line_main_high_volatge_return = new QLineEdit(groupBox_esi_setting);
        line_main_high_volatge_return->setObjectName(QString::fromUtf8("line_main_high_volatge_return"));
        line_main_high_volatge_return->setMaximumSize(QSize(100, 16777215));

        gridLayout_5->addWidget(line_main_high_volatge_return, 0, 3, 1, 1);

        label_9 = new QLabel(groupBox_esi_setting);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_5->addWidget(label_9, 2, 0, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox_esi_setting);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMaximumSize(QSize(100, 16777215));

        gridLayout_5->addWidget(lineEdit_2, 2, 3, 1, 1);

        label_10 = new QLabel(groupBox_esi_setting);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_5->addWidget(label_10, 3, 0, 1, 1);

        line_main_pwm = new QLineEdit(groupBox_esi_setting);
        line_main_pwm->setObjectName(QString::fromUtf8("line_main_pwm"));
        line_main_pwm->setMaximumSize(QSize(100, 16777215));

        gridLayout_5->addWidget(line_main_pwm, 4, 2, 1, 1);

        line_main_high_volatge = new QLineEdit(groupBox_esi_setting);
        line_main_high_volatge->setObjectName(QString::fromUtf8("line_main_high_volatge"));
        line_main_high_volatge->setMaximumSize(QSize(100, 16777215));

        gridLayout_5->addWidget(line_main_high_volatge, 0, 2, 1, 1);

        line_main_high_temp = new QLineEdit(groupBox_esi_setting);
        line_main_high_temp->setObjectName(QString::fromUtf8("line_main_high_temp"));
        line_main_high_temp->setMaximumSize(QSize(100, 16777215));

        gridLayout_5->addWidget(line_main_high_temp, 3, 2, 1, 1);

        label_11 = new QLabel(groupBox_esi_setting);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_5->addWidget(label_11, 4, 0, 1, 1);

        main_btn_indicator_light = new MyMainPushButton(groupBox_esi_setting);
        main_btn_indicator_light->setObjectName(QString::fromUtf8("main_btn_indicator_light"));

        gridLayout_5->addWidget(main_btn_indicator_light, 5, 2, 1, 1);

        label_8 = new QLabel(groupBox_esi_setting);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_5->addWidget(label_8, 0, 0, 1, 1);

        line_main_high_current = new QLineEdit(groupBox_esi_setting);
        line_main_high_current->setObjectName(QString::fromUtf8("line_main_high_current"));
        line_main_high_current->setMaximumSize(QSize(100, 16777215));

        gridLayout_5->addWidget(line_main_high_current, 2, 2, 1, 1);

        btn_main_esi_setting = new MyMainPushButton(groupBox_esi_setting);
        btn_main_esi_setting->setObjectName(QString::fromUtf8("btn_main_esi_setting"));

        gridLayout_5->addWidget(btn_main_esi_setting, 5, 0, 1, 2);

        line_main_high_temp_return = new QLineEdit(groupBox_esi_setting);
        line_main_high_temp_return->setObjectName(QString::fromUtf8("line_main_high_temp_return"));
        line_main_high_temp_return->setMaximumSize(QSize(100, 16777215));

        gridLayout_5->addWidget(line_main_high_temp_return, 3, 3, 1, 1);


        verticalLayout_7->addWidget(groupBox_esi_setting);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);
        dockWidget_2 = new QDockWidget(MainWindow);
        dockWidget_2->setObjectName(QString::fromUtf8("dockWidget_2"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        gridLayout_6 = new QGridLayout(dockWidgetContents_2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        frame_2 = new QFrame(dockWidgetContents_2);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(100, 0));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        tabWidget = new QTabWidget(frame_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::South);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout_4->addWidget(tabWidget);


        verticalLayout_3->addLayout(verticalLayout_4);


        gridLayout_6->addWidget(frame_2, 0, 0, 1, 1);

        dockWidget_2->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_2);
        dockWidget_4 = new QDockWidget(MainWindow);
        dockWidget_4->setObjectName(QString::fromUtf8("dockWidget_4"));
        dockWidget_4->setToolTipDuration(-4);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QString::fromUtf8("dockWidgetContents_4"));
        verticalLayout_6 = new QVBoxLayout(dockWidgetContents_4);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));

        verticalLayout_6->addLayout(horizontalLayout_2);

        dockWidget_4->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_4);
        dockWidget_3 = new QDockWidget(MainWindow);
        dockWidget_3->setObjectName(QString::fromUtf8("dockWidget_3"));
        dockWidget_3->setFloating(false);
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        verticalLayout_5 = new QVBoxLayout(dockWidgetContents_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        textBrowser = new QTextBrowser(dockWidgetContents_3);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout_5->addWidget(textBrowser);

        dockWidget_3->setWidget(dockWidgetContents_3);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_3);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QitVenture 6", nullptr));
        dockWidget->setWindowTitle(QApplication::translate("MainWindow", "\345\217\202\346\225\260", nullptr));
        groupBox_system_status->setTitle(QApplication::translate("MainWindow", "\347\263\273\347\273\237\347\212\266\346\200\201", nullptr));
        label_temperature->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246\357\274\210\302\260C\357\274\211", nullptr));
        label_pressure->setText(QApplication::translate("MainWindow", "\346\260\224\345\216\213\357\274\210torr\357\274\211", nullptr));
        btn_temperature->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        btn_pressure->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        groupBox_pump->setTitle(QApplication::translate("MainWindow", "\345\210\206\345\255\220\346\263\265", nullptr));
        label->setText(QApplication::translate("MainWindow", "\350\275\254\351\200\237(r/s)", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\347\224\265\346\265\201(nA)", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246\357\274\210\302\260C\357\274\211", nullptr));
        btn_molecular_pump_open->setText(QApplication::translate("MainWindow", "\345\210\206\345\255\220\346\263\265\345\274\200\345\220\257", nullptr));
        groupBox_scaner_setting->setTitle(QApplication::translate("MainWindow", "\346\211\253\346\217\217\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        line_low_mass->setText(QApplication::translate("MainWindow", "100", nullptr));
        line_icon_cool_time->setText(QApplication::translate("MainWindow", "5000", nullptr));
        line_high_mass->setText(QApplication::translate("MainWindow", "650", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "\346\211\253\346\217\217\345\221\250\346\234\237", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\347\246\273\345\255\220\345\206\267\345\215\264\346\227\266\351\227\264(0.1ms)", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\346\200\273\345\221\250\346\234\237\357\274\2100.1ms\357\274\211", nullptr));
        line_scanner_cycle_time->setText(QApplication::translate("MainWindow", "600", nullptr));
        btn_scanner_setting->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\347\246\273\345\255\220\345\206\267\345\215\264RF\347\224\265\345\216\213\357\274\210v\357\274\211", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\344\275\216\350\264\250\351\207\217\346\225\260", nullptr));
        line_icon_cool_voltage->setText(QApplication::translate("MainWindow", "200", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "\351\253\230\350\264\250\351\207\217\346\225\260", nullptr));
        line_icon_cool_open_time->setText(QApplication::translate("MainWindow", "38", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\345\244\271\347\256\241\351\230\200\345\274\200\345\220\257\346\227\266\351\227\264(0.1ms)", nullptr));
        line_total_cycle_time->setText(QApplication::translate("MainWindow", "15000", nullptr));
        btn_main_experience_start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        aa->setTitle(QApplication::translate("MainWindow", "\346\263\250\345\260\204\346\263\265\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\345\211\251\344\275\231\344\275\223\347\247\257\357\274\210UL\357\274\211", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\346\212\275\345\217\226\344\275\223\347\247\257\357\274\210UL\357\274\211", nullptr));
        line_velocity->setText(QApplication::translate("MainWindow", "0.5", nullptr));
        btn_end_point->setText(QApplication::translate("MainWindow", "\346\216\222\345\272\237\346\266\262", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "\346\212\275\345\217\226\351\200\237\345\272\246", nullptr));
        btn_extract_volume->setText(QApplication::translate("MainWindow", "\346\212\275\345\217\226", nullptr));
        line_extract_speed->setText(QApplication::translate("MainWindow", "200", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "\346\211\247\350\241\214\346\265\201\351\200\237", nullptr));
        btn_stop_perform->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\346\211\247\350\241\214", nullptr));
        btn_start_perform->setText(QApplication::translate("MainWindow", "  \345\274\200\345\247\213\346\211\247\350\241\214", nullptr));
        line_extract_volume->setText(QApplication::translate("MainWindow", "100", nullptr));
        groupBox_esi_setting->setTitle(QApplication::translate("MainWindow", "ESI\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\347\224\265\346\265\201\357\274\210NA\357\274\211", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246", nullptr));
        line_main_pwm->setText(QApplication::translate("MainWindow", "0", nullptr));
        line_main_high_volatge->setText(QApplication::translate("MainWindow", "0", nullptr));
        line_main_high_temp->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\346\263\265\350\275\254\351\200\237", nullptr));
        main_btn_indicator_light->setText(QApplication::translate("MainWindow", "\346\214\207\347\244\272\347\201\257\345\274\200\345\220\257", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\347\224\265\345\216\213\357\274\210v\357\274\211", nullptr));
        line_main_high_current->setText(QApplication::translate("MainWindow", "0", nullptr));
        btn_main_esi_setting->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        dockWidget_2->setWindowTitle(QApplication::translate("MainWindow", "\346\230\276\347\244\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\350\264\250\350\260\261\345\233\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\346\260\224\345\216\213\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
