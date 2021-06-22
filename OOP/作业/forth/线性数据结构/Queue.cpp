#include"Queue.h"
#include<iostream>
using namespace std;

Queue::Iterator Queue:: begin()//指定函数
{
    Queue::Iterator zcy(&data[idx_begin],idx_begin);
    return zcy;
}
Queue::Iterator Queue:: end()
{
    Queue::Iterator zcy(&data[idx_end],idx_end);
    return zcy;
}

int Queue:: pop()
{
    int zcy=data[idx_begin];
    idx_begin++;
    return zcy;
}
