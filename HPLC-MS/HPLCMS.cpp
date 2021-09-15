#include "HPLCMS.h"
#include <iostream>
#include <QMessageBox>
#include<Qdebug>
using namespace std;

//登录界面类
HPLCMS::HPLCMS(QWidget *parent)
	: QWidget(parent)
{
    ui->setupUi(this);
	//showMaximized();
	//this->move((this->width()) / 2, (this->width()) / 2);
	//ui.formLayout->
    connect(ui->login_btn, SIGNAL(clicked()), this, SLOT(validate()));
	//connect(ui.login_btn, SIGNAL(clicked()), this, SLOT(validate()));
    ui->user_account->setText("admin");
    ui->password->setText("123456");
    //ui->user
    ui->login_btn->setFocus();//设置默认焦点
    ui->login_btn->setShortcut(QKeySequence::InsertParagraphSeparator);//设置快捷键为键盘的“回车”键

}
void HPLCMS::validate()
{
    QString userAccount = ui->user_account->text();
        QString password = ui->password->text();
		qDebug() << userAccount << password;
		if (userAccount == "admin" && password == "123456")
		{
			//MainWindow(this).show();
			//mainWindow.show();
//			MenuWindow *menuWindow = new MenuWindow();
//			menuWindow->showMaximized();
//			menuWindow->setWindowTitle("参数设置");
//			menuWindow->show();
			this->hide();
		}
		else
		{
			QMessageBox msg;
			msg.setText("Logon failure");
			msg.exec();
		}
	//	}


	/*QMessageBox msg;
	msg.setText("HelloWord!");
	msg.exec();
	cout << "asdas" << endl;*/
	//mainWindow.show();
}
