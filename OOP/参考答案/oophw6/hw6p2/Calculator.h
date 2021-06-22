#pragma once
#include "LoadStrategy.h"
#include "PayStrategy.h"

class Calculator {								
    LoadStrategy* lstrategy;
    PayStrategy* pstrategy;
public:
    Calculator(LoadStrategy* l, PayStrategy* p) : 
        lstrategy(l), pstrategy(p) {}
    float load(){
        return lstrategy->input();
    }
    float pay(float money){
        return pstrategy->calc(money);
    }
};