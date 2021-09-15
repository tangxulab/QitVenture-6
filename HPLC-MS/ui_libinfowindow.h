/********************************************************************************
** Form generated from reading UI file 'libinfowindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBINFOWINDOW_H
#define UI_LIBINFOWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LibInfoWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *photo_path;
    QLabel *label_2;
    QLabel *label_6;
    QToolButton *tool_add_sub_ion;
    QLineEdit *line_object_name;
    QLabel *label_5;
    QPushButton *btn_ok;
    QPushButton *pushButton_2;
    QLineEdit *line_precursor_ion;
    QToolButton *tool_ion_photo;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *line_object_formula;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LibInfoWindow)
    {
        if (LibInfoWindow->objectName().isEmpty())
            LibInfoWindow->setObjectName(QString::fromUtf8("LibInfoWindow"));
        LibInfoWindow->resize(546, 355);
        centralwidget = new QWidget(LibInfoWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        photo_path = new QLabel(centralwidget);
        photo_path->setObjectName(QString::fromUtf8("photo_path"));

        gridLayout->addWidget(photo_path, 5, 2, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        tool_add_sub_ion = new QToolButton(centralwidget);
        tool_add_sub_ion->setObjectName(QString::fromUtf8("tool_add_sub_ion"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        tool_add_sub_ion->setIcon(icon);

        gridLayout->addWidget(tool_add_sub_ion, 3, 1, 1, 1);

        line_object_name = new QLineEdit(centralwidget);
        line_object_name->setObjectName(QString::fromUtf8("line_object_name"));
        line_object_name->setMaximumSize(QSize(300, 30));

        gridLayout->addWidget(line_object_name, 0, 1, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        btn_ok = new QPushButton(centralwidget);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));

        gridLayout->addWidget(btn_ok, 6, 0, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 6, 1, 1, 1);

        line_precursor_ion = new QLineEdit(centralwidget);
        line_precursor_ion->setObjectName(QString::fromUtf8("line_precursor_ion"));
        line_precursor_ion->setMaximumSize(QSize(300, 30));

        gridLayout->addWidget(line_precursor_ion, 2, 1, 1, 1);

        tool_ion_photo = new QToolButton(centralwidget);
        tool_ion_photo->setObjectName(QString::fromUtf8("tool_ion_photo"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/photo.png"), QSize(), QIcon::Normal, QIcon::Off);
        tool_ion_photo->setIcon(icon1);
        tool_ion_photo->setIconSize(QSize(50, 50));

        gridLayout->addWidget(tool_ion_photo, 5, 1, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        line_object_formula = new QLineEdit(centralwidget);
        line_object_formula->setObjectName(QString::fromUtf8("line_object_formula"));
        line_object_formula->setMaximumSize(QSize(300, 30));

        gridLayout->addWidget(line_object_formula, 1, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        LibInfoWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LibInfoWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 546, 23));
        LibInfoWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LibInfoWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LibInfoWindow->setStatusBar(statusbar);

        retranslateUi(LibInfoWindow);

        QMetaObject::connectSlotsByName(LibInfoWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LibInfoWindow)
    {
        LibInfoWindow->setWindowTitle(QApplication::translate("LibInfoWindow", "\346\267\273\345\212\240", nullptr));
        photo_path->setText(QApplication::translate("LibInfoWindow", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("LibInfoWindow", "\347\233\256\346\240\207\347\211\251", nullptr));
        label_6->setText(QApplication::translate("LibInfoWindow", "\345\210\206\345\255\220\347\273\223\346\236\204", nullptr));
        tool_add_sub_ion->setText(QApplication::translate("LibInfoWindow", "\346\267\273\345\212\240", nullptr));
        label_5->setText(QApplication::translate("LibInfoWindow", "\345\214\226\345\255\246\345\274\217", nullptr));
        btn_ok->setText(QApplication::translate("LibInfoWindow", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QApplication::translate("LibInfoWindow", "\345\217\226\346\266\210", nullptr));
        tool_ion_photo->setText(QApplication::translate("LibInfoWindow", "...", nullptr));
        label_4->setText(QApplication::translate("LibInfoWindow", "\347\242\260\346\222\236\350\203\275\351\207\217", nullptr));
        label_3->setText(QApplication::translate("LibInfoWindow", "\345\255\220\347\246\273\345\255\220", nullptr));
        label->setText(QApplication::translate("LibInfoWindow", "\346\257\215\347\246\273\345\255\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LibInfoWindow: public Ui_LibInfoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBINFOWINDOW_H
