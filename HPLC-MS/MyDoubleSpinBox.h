#ifndef MYDOUBLESPINBOX_H
#define MYDOUBLESPINBOX_H

#include <QDoubleSpinBox>
class MyDoubleSpinBox:public QDoubleSpinBox
{
    Q_OBJECT
public:
    explicit MyDoubleSpinBox(QWidget *parent = nullptr);
private:
    void wheelEvent(QWheelEvent *event);
};

#endif // MYDOUBLESPINBOX_H
