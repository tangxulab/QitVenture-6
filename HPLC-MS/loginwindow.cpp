#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    /**
      登陆界面设计
      */
    ui->setupUi(this);
    connect(ui->btn_login, SIGNAL(clicked()), this, SLOT(validate()));
    ui->line_user_account->setPlaceholderText("请输入账号");
    ui->line_password->setEchoMode(QLineEdit::Password);
    ui->line_password->setPlaceholderText("请输入密码");
    ui->btn_login->setFocus();//设置默认焦点
    this->setFixedSize(500,370);
    ui->label_3->setFixedSize(500,200);
    ui->label_3->move(0,0);
    ui->frame->move(132,210);
    ui->btn_login->setShortcut(QKeySequence::InsertParagraphSeparator);//设置快捷键为键盘的“回车”键
    QImage *img=new QImage; //新建一个image对象
    img->load(":/images/login.png"); //将图像资源载入对象img，注意路径，可点进图片右键复制路径
    show_frame(*img);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

//输入帐号和密码进行验证
void LoginWindow::validate()
{
    QString userAccount = ui->line_user_account->text();
    QString password = ui->line_password->text();
    if ((userAccount == "admin"||userAccount == "banff") && password == "123456")
    {
        this->hide();

        QSplashScreen *splash = new QSplashScreen;
        splash->setPixmap(QPixmap(":/images/loading.png"));
        splash->show();
        Qt::Alignment topRight = Qt::AlignLeft | Qt::AlignBottom;
        splash->showMessage(QObject::tr("[1/7] 正在初始化..."),
                            topRight,
                            Qt::black);
        MenuWindow *menuWindow = new MenuWindow();
        //     menuWindow->paramTree_init();
        //  menuWindow->paramSet_init();
        //        menuWindow->hide();
        QThread::sleep(1);
        menuWindow->fileData_init(userAccount);

        splash->showMessage(QObject::tr("[2/7] 正在构造文件..."),
                            topRight,
                            Qt::black);
        menuWindow->dockWidget_init();
        QThread::sleep(1);
        splash->showMessage(QObject::tr("[3/7] 创建套件"),
                            topRight,
                            Qt::black);
        menuWindow->paramTree_init();
        QThread::sleep(1);
        splash->showMessage(QObject::tr("[4/7] 界面构建中"),
                            topRight,
                            Qt::black);
        menuWindow->tableWidget_td_esi_set_init();
        QThread::sleep(1);
        splash->showMessage(QObject::tr("[5/7] 创建宏变量"),
                            topRight,
                            Qt::black);
        menuWindow->menuBar_init();
        QThread::sleep(1);
        splash->showMessage(QObject::tr("[6/7] 参数加载中"),
                            topRight,
                            Qt::black);
        menuWindow->paramSet_init();
        QThread::sleep(1);
        menuWindow->connectList();
        splash->showMessage(QObject::tr("[7/7] 请稍后..."),
                            topRight,
                            Qt::black);

        //        //menuWindow->setWindowFlags(Qt::FramelessWindowHint);//无边框
        //        menuWindow->loadStyleSheet(":/qss/myStyleSheet.qss");
        menuWindow->showMaximized();
        splash->finish(menuWindow);
        delete splash;

    }
    else {
        QMessageBox msg;
        msg.setText("Logon failure");
        msg.exec();
    }
}

//登陆界面的图片显示
void LoginWindow::show_frame(QImage &image)
{
    QSize laSize=ui->label_3->size();//label_carema是要显示图片的label的名称
    QImage image1=image.scaled(laSize,Qt::IgnoreAspectRatio);//重新调整图像大小以适应窗口
    ui->label_3->setPixmap(QPixmap::fromImage(image1));//显示
}
