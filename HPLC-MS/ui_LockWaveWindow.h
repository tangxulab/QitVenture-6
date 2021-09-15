/********************************************************************************
** Form generated from reading UI file 'LockWaveWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCKWAVEWINDOW_H
#define UI_LOCKWAVEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LockWaveWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_lock;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *spinBox_spectrometry_x_from;
    QLabel *label_3;
    QSpinBox *spinBox_spectrometry_x_to;
    QLabel *label_2;
    QSpinBox *spinBox_spectrometry_y_from;
    QSpinBox *spinBox_spectrometry_y_to;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LockWaveWindow)
    {
        if (LockWaveWindow->objectName().isEmpty())
            LockWaveWindow->setObjectName(QString::fromUtf8("LockWaveWindow"));
        LockWaveWindow->resize(228, 135);
        centralwidget = new QWidget(LockWaveWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        checkBox_lock = new QCheckBox(centralwidget);
        checkBox_lock->setObjectName(QString::fromUtf8("checkBox_lock"));

        verticalLayout->addWidget(checkBox_lock);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spinBox_spectrometry_x_from = new QSpinBox(centralwidget);
        spinBox_spectrometry_x_from->setObjectName(QString::fromUtf8("spinBox_spectrometry_x_from"));
        spinBox_spectrometry_x_from->setMaximum(1000);

        gridLayout->addWidget(spinBox_spectrometry_x_from, 0, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        spinBox_spectrometry_x_to = new QSpinBox(centralwidget);
        spinBox_spectrometry_x_to->setObjectName(QString::fromUtf8("spinBox_spectrometry_x_to"));
        spinBox_spectrometry_x_to->setMaximum(1500);

        gridLayout->addWidget(spinBox_spectrometry_x_to, 0, 4, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinBox_spectrometry_y_from = new QSpinBox(centralwidget);
        spinBox_spectrometry_y_from->setObjectName(QString::fromUtf8("spinBox_spectrometry_y_from"));
        spinBox_spectrometry_y_from->setMaximum(100000);

        gridLayout->addWidget(spinBox_spectrometry_y_from, 1, 1, 1, 1);

        spinBox_spectrometry_y_to = new QSpinBox(centralwidget);
        spinBox_spectrometry_y_to->setObjectName(QString::fromUtf8("spinBox_spectrometry_y_to"));
        spinBox_spectrometry_y_to->setMaximum(100000);

        gridLayout->addWidget(spinBox_spectrometry_y_to, 1, 4, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_2->addLayout(verticalLayout);

        LockWaveWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LockWaveWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 228, 23));
        LockWaveWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LockWaveWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LockWaveWindow->setStatusBar(statusbar);

        retranslateUi(LockWaveWindow);

        QMetaObject::connectSlotsByName(LockWaveWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LockWaveWindow)
    {
        LockWaveWindow->setWindowTitle(QApplication::translate("LockWaveWindow", "\345\217\202\346\225\260\351\224\201\345\256\232", nullptr));
        checkBox_lock->setText(QApplication::translate("LockWaveWindow", "\351\224\201\345\256\232", nullptr));
        label->setText(QApplication::translate("LockWaveWindow", "\350\264\250\351\207\217\346\225\260\357\274\232", nullptr));
        label_3->setText(QApplication::translate("LockWaveWindow", "to", nullptr));
        label_2->setText(QApplication::translate("LockWaveWindow", "\344\270\260\345\272\246\345\200\274", nullptr));
        label_4->setText(QApplication::translate("LockWaveWindow", "to", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LockWaveWindow: public Ui_LockWaveWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCKWAVEWINDOW_H
