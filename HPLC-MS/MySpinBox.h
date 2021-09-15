#ifndef MYSPINBOX_H
#define MYSPINBOX_H

#include <QSpinBox>
class MySpinBox : public QSpinBox
{
    Q_OBJECT
public:
    explicit MySpinBox(QWidget *parent = nullptr);
private:
    void wheelEvent(QWheelEvent *event);
};

#endif // MYSPINBOX_H
