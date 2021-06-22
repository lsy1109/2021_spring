#pragma once
#include <iostream>
using namespace std;

class PerformStrategy{
protected:
    double Perform; 
public:
    PerformStrategy(double);
    virtual int getbonus(int)=0;
    virtual ~PerformStrategy();
};

class sPerformStrategy:public PerformStrategy{
public:
    using PerformStrategy::PerformStrategy;
    int getbonus(int)override;
};

class mPerformStrategy:public PerformStrategy{
public:
    using PerformStrategy::PerformStrategy;
    int getbonus(int)override;
};

class lPerformStrategy:public PerformStrategy{
public:
    using PerformStrategy::PerformStrategy;
    int getbonus(int)override;
};