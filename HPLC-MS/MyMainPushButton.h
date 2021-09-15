#ifndef MYMAINPUSHBUTTON_H
#define MYMAINPUSHBUTTON_H
//按钮重写类
#include <QPushButton>

class MyMainPushButton : public QPushButton
{
    Q_OBJECT
public:
   explicit  MyMainPushButton(QWidget *parent = nullptr);
};

#endif // MYMAINPUSHBUTTON_H
