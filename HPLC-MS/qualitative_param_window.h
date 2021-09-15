#ifndef QUALITATIVE_PARAM_WINDOW_H
#define QUALITATIVE_PARAM_WINDOW_H

#include <QMainWindow>

namespace Ui {
class Qualitative_Param_Window;
}

class Qualitative_Param_Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Qualitative_Param_Window(QWidget *parent = nullptr);
    ~Qualitative_Param_Window();

private:
    Ui::Qualitative_Param_Window *ui;
};

#endif // QUALITATIVE_PARAM_WINDOW_H
