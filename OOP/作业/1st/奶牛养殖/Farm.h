#pragma once
#include <iostream>
#include "Cow.h"
#include <string>
using namespace std;

class Farm{
    public:
        int n;
        Farm(int a){n=a;}
        string Name[10000];
        int L[10000];//吃艹的下界
        int U[10000];//吃的艹的上界
        double M[10000];//每天产的奶
        int Record[10000];//记录当前艹余量的记录器
        double milkproduct[10000];//记录产奶的量
        void addCow(Cow n);
        void supply(string s, int a);
        void startMeal();
        void produceMilk();
        double getMilkProduction();
        int k = 0;
};