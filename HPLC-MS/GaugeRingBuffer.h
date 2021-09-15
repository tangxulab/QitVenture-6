//真空规协议设置
#pragma once
#include <QByteArray>
#include <QString>
#include <QTime>
#include <QApplication>

#define rbSIZE 10000

class GaugeRingBuffer : public QObject
{
	Q_OBJECT

public:
	explicit GaugeRingBuffer(void);
	char getch(void);
	int  putch(char c);
	int  size(void);
	int  numLines(void);
	void clear(void);
	void waitforline(int);
	QString getline(void);

protected:

private:
	int     buffer[rbSIZE];
	int     head;
	int     tail;
	int     count;
	int     lines;

	char    lastchar = 0x00;
};


