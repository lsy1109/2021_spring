#pragma once
#include <memory>
#include <iostream>
using namespace std;

template<class zcy>class Container
{
    zcy chw[1100];
    int numx[1100];
    int number;
    int numy[1100];
    public:
    Container():number(0){}
    ~Container(){}
    void insert(int x,int y, zcy name)//这路非常奇妙，因为使用了类模板，所以在cpp中定义遇到了问题
    {
        numx[number]=x;
        numy[number]=y;
        chw[number]=name;
        number++;
    }
    zcy* find(int x,int y)//主函数里需要返回指针！！！
    {
        for(int i=0;i<number;i++)
        {
            if((numx[i]==x)&&(numy[i]==y))
            return &chw[i];
        }
        return nullptr;
    }
};
