#include"IteratorBase.h"
#include<iostream>
using namespace std;

IteratorBase IteratorBase:: operator++(int)
{
    data++;
    idx++;
    return *this;
}

int IteratorBase::operator*()
{
    return *this->data;
}