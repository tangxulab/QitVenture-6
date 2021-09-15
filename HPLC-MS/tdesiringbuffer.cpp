#include "TDESIRingBuffer.h"
//char lastchar;

TDESIRingBuffer::TDESIRingBuffer(QObject *parent) : QObject(parent)
{

}
void TDESIRingBuffer::clear(void)
{
    head = 0;
    tail = 0;
    count = 0;
    lines = 0;
}

void TDESIRingBuffer::waitforline(int timeout = 0)
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

int TDESIRingBuffer::size(void)
{
    return count;
}

int TDESIRingBuffer::numLines(void)
{
    return lines;
}

char TDESIRingBuffer::getch(void){
    char c;
    if(count == 0) return(0);
    c = buffer[tail++];
    if(tail >= rbSIZE)
        tail = 0;
    count--;
    if(c == 'A'&&lastchar=='A')
    {
        lines--;
        lastchar=0x00;
        return c;
    }
    lastchar=c;
    return c;}
int TDESIRingBuffer::putch(char c){
    //if(c == 0x06) return(count);
    //if(c == 0x15) return(count);
    //if(c == '\r') return(count);
    // ignore \r
    if(count >= rbSIZE) return(-1);
    buffer[head++] = c;
    if(head >= rbSIZE)
        head = 0;
        count++;
    if(c == 'A'&lastchar=='A')
    {
        lines++;
        lastchar=0x00;
        return count;
    }
    lastchar=c;
    return(count);
}

QString TDESIRingBuffer::getline(void)
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
