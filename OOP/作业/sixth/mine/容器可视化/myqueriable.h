#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;

template <typename T> class MyQueriable {
    vector<T> zcy;
public:
    MyQueriable() {};
    MyQueriable(list<T>& x)//对于一个list或者vector取引用就是这么简单
    {
        for (auto it = x.begin(); it != x.end(); it++)
        {
            zcy.push_back(*it);
        }
    }
    MyQueriable(vector<T>& x)
    {
        for (auto it = x.begin(); it != x.end(); it++)
        {
            zcy.push_back(*it);
        }
    }
    int size();
    T& operator[](int x)//也可以把返回理解为一个赋值过程
    {
        return zcy[x];
    }//如果传入参数是赋值，那么return呢？这里真的表示返回了zcy[x]的引用吗？
    MyQueriable where(function<bool(T)>f);//这里只需要传入函数f就可以了，决定f的是参数类型，而不是参数的名字，故而不写成<bool(T x)>f);
    MyQueriable apply(function<T(T)>f);
    T sum();
};

template <typename T>//<typename T>的写法
int MyQueriable<T>::size() { return this->zcy.size(); }
template <typename T>
MyQueriable<T> MyQueriable<T>::where(function<bool(T)>f)//这个完全是一个道理：function<string()> read
{//因为你的yQueriable是个模板，本身需要T才能确定，故而返回值类型是个myQueriable<T>，而不是myQueriable
    MyQueriable<T> chw;
    for (auto i : this->zcy)
    {
        if (f(i))
        {
            chw.zcy.push_back(i);
        }
    }
    return chw;
}
template <typename T>
MyQueriable<T> MyQueriable<T>::apply(function<T(T)>f)//这个完全是一个道理：function<string()> read
{
    MyQueriable<T> chw;
    for (auto i : this->zcy)
    {
        chw.zcy.push_back(f(i));
    }
    return chw;
}
template <typename T>
T MyQueriable<T>::sum() { T tmp = 0; for (auto i : this->zcy) { tmp += i; }return tmp; }

template <typename T>
MyQueriable<T> from(list<T>& x)
{
    return MyQueriable<T>(x);//这里直接就是传参地过程了，在函数内部不可能写成return MyQueriable<T>(ist<T>& x);
}
template <typename T>
MyQueriable<T> from(vector<T>& x)
{
    return MyQueriable<T>(x);
}