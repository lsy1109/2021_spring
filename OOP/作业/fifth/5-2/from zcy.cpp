#include<iostream>
#include<list>
#include <vector>
#include <string>
#include <algorithm>

class Friend
{
public:
    int id;
    std::vector<std::string> x;//每一个人的vector从后往前读就可以了，不停地push_back
    Friend(int a) : id(a) {}
    ~Friend() {}
    bool operator==(const Friend& other)
    {
        return (id == other.id);
    }
};

int main(){
    std::list<Friend> l;//list先new一个tmp，然后拷贝，然后erase，然后push_front
    int N;
    std::cin>>N;
    for(int i=0;i<N;i++)
    {
        int initial;
        std::cin>>initial;
        Friend a(initial);
        std::string zcy = "";
        getchar();//吸收空格！！！
        char m;
        while ((m=getchar())>' ')
        {   
            if (m != '/')
            {
                zcy += m;
            }
            else
            {
                a.x.push_back(zcy);
                zcy ="";
            }
        }
        a.x.push_back(zcy);
        l.push_front(a);//注意到我的l的顺序满足了最新消息的人在前面，然后每个人的vector满足最新发的消息在后面
    }
    int M;
    std::cin >> M;
    for (int i = 0; i < M; i++)
    {
        int ind;
        std::cin >> ind;
        auto k = std::find(l.begin(), l.end(), Friend(ind));
        if (k == l.end())
        {
            Friend chw(ind);
            std::string alex;
            getchar();
            std::cin >> alex;
            chw.x.push_back(alex);
            l.push_front(chw);
        }
        else
        {   
            std::string alex;
            getchar();
            std::cin >> alex;
            k->x.push_back(alex);
            Friend tmp = *k;
            l.erase(k);
            l.push_front(tmp);
        }
    }
    for (auto it = l.begin(); it != l.end(); it++)
    {
        std::cout << it->id << std::endl;
        for (auto zex = it->x.rbegin(); zex != it->x.rend(); zex++)
        {
            std::cout << *zex << std::endl;
        }
    }
}


#include"what.h"
#include<string>
using namespace std;
class Alien : public WhatCanMotion,public WhatCanSpeak
{
public:
    string zcy;
    Alien(string name):zcy(name){}
    void speak() { cout << zcy << " is speaking" << endl; }
    void stop() { cout << zcy << " stops" << endl; }
    void motion() { cout << zcy << " is moving" << endl; }
};
