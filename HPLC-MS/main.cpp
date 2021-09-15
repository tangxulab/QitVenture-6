#include "HPLCMS.h"
#include "loginwindow.h"
#include <QtWidgets/QApplication>
#include "MenuWindow.h"
#include <qtextcodec.h>
//#include <QByteArray>
//#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    // QApplication::setStyle(QStyleFactory::create("plastique"));
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    //QDir::setCurrent(a.applicationDirPath());//添加这句 立马可以
    LoginWindow loginWindow;
    loginWindow.show();
    // menuWindow = new MenuWindow();
    //menuWindow->show();
    // menuWindow->hide();
    // menuWindow->show();
    // menuWindow->hide();
    // menuWindow->mainWindow->show();
    return a.exec();

    /*QByteArray data;
    data[0] = 0xFF;
    uchar tmp;
    tmp = (uchar)data[0];
    qDebug() << tmp;*/
}
