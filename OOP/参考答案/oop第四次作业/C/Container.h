#ifndef CONTAINER_H
#define CONTAINER_H
#include <memory>
#include <iostream>
using namespace std;
template<typename A> class Container
{
    A item[1000];
    int num1[1000];
    int num2[1000];
    int cnt;
    public:
    Container(){
        cnt=0;
    };
    ~Container(){};
    void insert(int x,int y,A in )
    {
        item[cnt]=in;
        num1[cnt]=x;
        num2[cnt]=y;
        cnt++;

    }
    A* find(int x,int y)
    {
        for(int i=0;i<cnt;i++)
        {
            if(num1[i]==x&&num2[i]==y)
                return &item[i];
        }
        return nullptr;
    }



};

#endif 