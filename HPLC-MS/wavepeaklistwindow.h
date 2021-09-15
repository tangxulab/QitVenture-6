#ifndef WAVEPEAKLISTWINDOW_H
#define WAVEPEAKLISTWINDOW_H

//寻峰界面类
#include <QMainWindow>
#include <QPushButton>
#include <QComboBox>
#include <QTableWidget>
#include <QFormLayout>
namespace Ui {
class WavePeakListWindow;
}

class WavePeakListWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WavePeakListWindow(QWidget *parent = nullptr);
    ~WavePeakListWindow();
    QPushButton *btn_search_peak;
    QComboBox *QComboBox_seacrch_peak;
    QTableWidget *table_seacrch_peak;

private:
    Ui::WavePeakListWindow *ui;
};

#endif // WAVEPEAKLISTWINDOW_H
