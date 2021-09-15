//mythread.cpp
#include "mythread.h"
MyThread::MyThread()
{
    m_i=0;
    m_buttonState=false;
}

MyThread::~MyThread()
{

}

void MyThread::run()
{
    m_buttonState=true;
    while(1)
    {
        m_mutex.lock();
        m_i++;
        qDebug()<<QString("the value of m_i is %1 ").arg(m_i);
        m_mutex.unlock();
        this->sleep(1);
    }



}


void MyThread::threadPause()
{
    qDebug()<<QString("pause :%1").arg(m_buttonState);
    this->m_mutex.lock();
    this->m_buttonState=false;
    qDebug()<<QString("pause");
}
void MyThread::threadResume()
{
    qDebug()<<QString("resume :%1").arg(m_buttonState);
    this->m_mutex.unlock();
    this->m_buttonState=true;
    qDebug()<<QString("resume");

}
void MyThread::threadStop()
{
    this->exit();

}
void MyThread::threadStart()
{
    this->start();
}
void MyThread::threadPR()
{
    if(m_buttonState)
    {
        threadPause();

    }
    else
    {
        threadResume();
    }

}
