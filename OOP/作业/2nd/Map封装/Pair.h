#pragma once
#include <string>
using namespace std;

class Pair{
    string key;
    int val;
public:
    static int n_create;
    static int n_free;
    Pair();
    void reset(string k, int v);//reset:重新赋值
    bool hasKey(string k);//是否有key
    int & getVal();//get value
    ~Pair();
};