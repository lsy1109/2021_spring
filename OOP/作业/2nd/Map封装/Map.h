#pragma once
#include "Pair.h"

class Map{
    Pair * data;
    int sz;
public:
    Map(int n);
    int& operator[](string x);//实际上非const对象会先调用非const的函数
    int operator[](string x) const;
    //注意到这里需要确定你重载后的的函数的返回值，我选择返回了student，之后再重载Stundent的输出运算符
    int size();
    ~Map();
};