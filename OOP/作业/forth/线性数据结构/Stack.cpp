#include"Stack.h"
#include<iostream>
using namespace std;

Stack::Iterator Stack:: begin()//指定函数
{
    Stack::Iterator zcy(&data[idx_begin],idx_begin);
    return zcy;
}
Stack::Iterator Stack:: end()
{
    Stack::Iterator zcy(&data[idx_end],idx_end);
    return zcy;
}

int Stack:: pop()
{
    idx_end--;
    int zcy=data[idx_end];
    return zcy;
}