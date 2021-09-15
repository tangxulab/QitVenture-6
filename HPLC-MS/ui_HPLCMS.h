/********************************************************************************
** Form generated from reading UI file 'HPLCMS.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HPLCMS_H
#define UI_HPLCMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HPLCMSClass
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *password;
    QLabel *label;
    QPushButton *cancal_btn;
    QPushButton *login_btn;
    QLineEdit *user_account;
    QLabel *label_2;

    void setupUi(QWidget *HPLCMSClass)
    {
        if (HPLCMSClass->objectName().isEmpty())
            HPLCMSClass->setObjectName(QString::fromUtf8("HPLCMSClass"));
        HPLCMSClass->resize(600, 400);
        widget = new QWidget(HPLCMSClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(160, 160, 216, 95));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        password = new QLineEdit(widget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setEchoMode(QLineEdit::Password);
        password->setCursorMoveStyle(Qt::LogicalMoveStyle);

        gridLayout->addWidget(password, 1, 1, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        cancal_btn = new QPushButton(widget);
        cancal_btn->setObjectName(QString::fromUtf8("cancal_btn"));

        gridLayout->addWidget(cancal_btn, 2, 1, 1, 1);

        login_btn = new QPushButton(widget);
        login_btn->setObjectName(QString::fromUtf8("login_btn"));

        gridLayout->addWidget(login_btn, 2, 0, 1, 1);

        user_account = new QLineEdit(widget);
        user_account->setObjectName(QString::fromUtf8("user_account"));

        gridLayout->addWidget(user_account, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        retranslateUi(HPLCMSClass);

        QMetaObject::connectSlotsByName(HPLCMSClass);
    } // setupUi

    void retranslateUi(QWidget *HPLCMSClass)
    {
        HPLCMSClass->setWindowTitle(QApplication::translate("HPLCMSClass", "HPLCMS", nullptr));
        label->setText(QApplication::translate("HPLCMSClass", "\350\264\246\345\217\267", nullptr));
        cancal_btn->setText(QApplication::translate("HPLCMSClass", "\345\217\226\346\266\210", nullptr));
        login_btn->setText(QApplication::translate("HPLCMSClass", "\347\231\273\345\275\225", nullptr));
        label_2->setText(QApplication::translate("HPLCMSClass", "\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HPLCMSClass: public Ui_HPLCMSClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HPLCMS_H
