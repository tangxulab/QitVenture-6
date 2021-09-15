//分子泵协议设置
#pragma once
#include <QByteArray>
#include <QString>
#include <QTime>
#include <QApplication>

#define rbSIZE 10000

class RingBuffer : public QObject
{
	Q_OBJECT

public:
	explicit RingBuffer(void);
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
};
