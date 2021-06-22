#pragma once
#include <iostream>
using namespace std;

class LevelStrategy{
public:
    LevelStrategy();
    virtual int getbase()=0;
    virtual ~LevelStrategy();
};

class P1LStrategy:public LevelStrategy{
public:
   int getbase()override;
};

class P2LStrategy:public LevelStrategy{
public:
   int getbase()override;
};

class P3LStrategy:public LevelStrategy{
public:
    int getbase()override;
};