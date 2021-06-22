#include <iostream>
#include <vector>
#include <list>
#include <functional>
using namespace std;

template<typename T>//T是int或者float
class MyQueriable{
    public:
    int Size;
    vector<T> data;

    MyQueriable():Size(0){};
    T size(){return Size;}
    T operator[](int i){return data[i];}
    T sum(){
        T res=0;
        for (auto i:data){
            res+=i;
        }
        return res;
    }
    MyQueriable where(function<bool(T)>func){
        MyQueriable tmp;
        for (auto i: data){
            if(func(i))tmp.data.push_back(i);
            tmp.Size++;
        }
        return tmp;
    }
    MyQueriable apply(function<T(T)>func){
        MyQueriable tmp;
        for (auto i:data){
            tmp.data.push_back(func(i));
            tmp.Size++;
        }
        return tmp;
    }
};

template<typename T>
MyQueriable<T> from(vector<T> arg){
    MyQueriable<T> tmp;
    for (auto i: arg){
        tmp.data.push_back(i);
        tmp.Size++;
    }
    return tmp;
} 

template<typename T>
MyQueriable<T> from(list<T> arg){
    MyQueriable<T> tmp;
    for (auto i: arg){
        tmp.data.push_back(i);
        tmp.Size++;
    }
    return tmp;
} 