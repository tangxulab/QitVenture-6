/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_3;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *line_user_account;
    QLabel *label_2;
    QPushButton *btn_cancel;
    QLineEdit *line_password;
    QLabel *label;
    QPushButton *btn_login;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(400, 300);
        LoginWindow->setMinimumSize(QSize(400, 300));
        LoginWindow->setMaximumSize(QSize(400, 300));
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 20, 54, 12));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(140, 150, 236, 97));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        line_user_account = new QLineEdit(frame);
        line_user_account->setObjectName(QString::fromUtf8("line_user_account"));

        gridLayout->addWidget(line_user_account, 0, 1, 1, 2);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        btn_cancel = new QPushButton(frame);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        gridLayout->addWidget(btn_cancel, 2, 2, 1, 1);

        line_password = new QLineEdit(frame);
        line_password->setObjectName(QString::fromUtf8("line_password"));

        gridLayout->addWidget(line_password, 1, 1, 1, 2);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        btn_login = new QPushButton(frame);
        btn_login->setObjectName(QString::fromUtf8("btn_login"));

        gridLayout->addWidget(btn_login, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 23));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "QitVenture 6", nullptr));
        label_3->setText(QApplication::translate("LoginWindow", "TextLabel", nullptr));
        line_user_account->setText(QApplication::translate("LoginWindow", "admin", nullptr));
        label_2->setText(QApplication::translate("LoginWindow", "\345\257\206\347\240\201", nullptr));
        btn_cancel->setText(QApplication::translate("LoginWindow", "\345\217\226\346\266\210", nullptr));
        line_password->setText(QApplication::translate("LoginWindow", "123456", nullptr));
        label->setText(QApplication::translate("LoginWindow", "\350\264\246\345\217\267", nullptr));
        btn_login->setText(QApplication::translate("LoginWindow", "\347\231\273\351\231\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
