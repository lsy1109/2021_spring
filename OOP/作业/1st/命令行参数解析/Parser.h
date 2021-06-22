#pragma once
#include <iostream>
#include <map>
#include <string>
using namespace std;

class Parser{
public:
    Parser()
    {
        thismap["one"]=1;
        thismap["two"]=2;
        thismap["three"]=3;
    }
    void add_argument(string s,int n,string l);
    void init(int argc,char *argv[]);
    int get_argument(string s);
    map<string, int> thismap;
    //{thismap["one"] = 1;
    //thismap["one"] +1 == 2
    //其实也可以通过三个固定的变量值完成，比如one对应int x。two 对应 y，three 对应 z
} ;