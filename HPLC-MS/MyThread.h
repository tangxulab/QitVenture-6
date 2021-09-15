//mythread.h
#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QDebug>
#include <QThread>
#include <QMutex>
class MyThread:public QThread
{
    Q_OBJECT
public:
    ~MyThread();
    static MyThread* getSingleton();
    void run();
private:
    MyThread();

public slots:
    void threadStart();
    void threadPause();
    void threadStop();
    void threadResume();
    void threadPR();
private:
    bool m_buttonState; //if pause m_buttonState=false;else m_buttonState=true;
    int m_i;
    QMutex m_mutex;//互斥量
    static MyThread *mythread;

};

#endif // MYTHREAD_H
