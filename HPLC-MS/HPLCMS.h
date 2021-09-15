#pragma once

#include <QtWidgets/QWidget>
#include "ui_HPLCMS.h"
#include "MainWindow.h"
#include "MenuWindow.h"

class HPLCMS : public QWidget
{
	Q_OBJECT

public:
	HPLCMS(QWidget *parent = Q_NULLPTR);
private slots:
	void validate();

private:
    Ui::HPLCMSClass *ui;

};
