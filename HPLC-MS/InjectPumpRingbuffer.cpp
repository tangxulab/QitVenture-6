#include "InjectPumpRingbuffer.h"
#include <QDebug>

InjectPumpRingbuffer::InjectPumpRingbuffer()
{
	clear();
}


void InjectPumpRingbuffer::clear(void)
{
	head = 0;
	tail = 0;
	count = 0;
	lines = 0;
}

void InjectPumpRingbuffer::waitforline(int timeout = 0)
{
	QTime timer;

	if (timeout == 0)
	{
		while (1)
		{
			QApplication::processEvents();
			if (lines > 0) break;
		}
		return;
	}
	timer.start();
	while (timer.elapsed() < timeout)
	{
		QApplication::processEvents();
		if (lines > 0)
		{
			break;
		}
	}
}

int InjectPumpRingbuffer::size(void)
{
	return count;
}

int InjectPumpRingbuffer::numLines(void)
{
	return lines;
}

char InjectPumpRingbuffer::getch(void)
{
	char c;

	if (count == 0) return(0);
	c = buffer[tail++];
	if (tail >= rbSIZE) tail = 0;
	count--;
	if (c == '\n')
	{
		lines--;
	}
	return c;
}

int InjectPumpRingbuffer::putch(char c)
{
	if (c == 0x00) return(count);
	if (c == 0x15) return(count);
	//if(c == '\r') return(count);        // ignore \r
	if (count >= rbSIZE) return(-1);
	if (c == 0x0a)
	{
		lines++;
	}
	buffer[head++] = c;
	if (head >= rbSIZE) head = 0;
	count++;
	return(count);
}

QString InjectPumpRingbuffer::getline(void)
{
	QString str = "";
	char c;

	if (lines <= 0) return str;
	while (1)
	{
		c = getch();
		if (c == '\n') break;
		if (count <= 0) break;
		str += c;
	}
	return str;
}

