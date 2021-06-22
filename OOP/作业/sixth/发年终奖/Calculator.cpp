#include "Calculator.h"

Calculator::Calculator(LevelStrategy* m_level,PerformStrategy* m_perform):p_levelstrategy(m_level),p_performstrategy(m_perform) {}

int Calculator::get_base(){
    {return p_levelstrategy->getbase();}
}

int Calculator::get_total(int base){
        int bonus=p_performstrategy->getbonus(base);
        return base+bonus;
    }

Calculator::~Calculator(){
    delete p_levelstrategy;
    delete p_performstrategy;
}