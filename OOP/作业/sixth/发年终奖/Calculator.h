#pragma once
#include <iostream>

#include "LevelStrategy.h"
#include "PerformStrategy.h"
using namespace std;

class Calculator{
private:
    LevelStrategy* p_levelstrategy;
    PerformStrategy* p_performstrategy;
public:
    Calculator(LevelStrategy*,PerformStrategy*);
    int get_base();
    int get_total(int);
    ~Calculator();
};