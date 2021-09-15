#include "GaugeRingBuffer.h"
#include <QDebug>


GaugeRingBuffer::GaugeRingBuffer(void)
{
	clear();
}

void GaugeRingBuffer::clear(void)
{
	head = 0;
	tail = 0;
	count = 0;
	lines = 0;
}

void GaugeRingBuffer::waitforline(int timeout = 0)
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

int GaugeRingBuffer::size(void)
{
	return count;
}

int GaugeRingBuffer::numLines(void)
{
	return lines;
}

char GaugeRingBuffer::getch(void)
{

	char c;
	if (count == 0) return(0);
	c = buffer[tail++];
	if (tail >= rbSIZE) tail = 0;
	count--;
	if (c == 'F' && lastchar == 'F')
	{
		lines--;
		lastchar = 0x00;
		return c;
	}
	lastchar = c;
	return c;
}

int GaugeRingBuffer::putch(char c)
{
	//if(c == 0x06) return(count);
	//if(c == 0x15) return(count);
	//if(c == '\r') return(count);        // ignore \r
	if (count >= rbSIZE) return(-1);
	buffer[head++] = c;
	if (head >= rbSIZE) head = 0;
	count++;
	if (c == 'F' & lastchar == 'F')
	{
		lines++;
		lastchar = 0x00;
		return count;
	}
	lastchar = c;
	return(count);
}

QString GaugeRingBuffer::getline(void)
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

