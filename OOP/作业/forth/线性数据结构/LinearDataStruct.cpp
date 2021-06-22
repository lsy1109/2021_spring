#include"LinearDataStruct.h"
#include<iostream>
using namespace std;

void LinearDataStruct::push(int x)
{
    data[idx_end]=x;
    idx_end++;
    return;
}
int LinearDataStruct::max_size()
{
    return max_n;
}
int LinearDataStruct::size()
{   int zcy=idx_end-idx_begin;
    return zcy;
}

int LinearDataStruct:: pop()
{
    return 0;
}