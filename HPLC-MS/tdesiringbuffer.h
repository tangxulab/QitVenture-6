//TDESI协议设置
#ifndef TDESIRINGBUFFER_H
#define TDESIRINGBUFFER_H

#include <QObject>
#include <QByteArray>
#include <QString>
#include <QTime>
#include <QApplication>
#define rbSIZE 10000
class TDESIRingBuffer : public QObject
{
    Q_OBJECT
public:
    explicit TDESIRingBuffer(QObject *parent = nullptr);
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

    char lastchar=0x00;
signals:

public slots:
};

#endif // TDESIRINGBUFFER_H
