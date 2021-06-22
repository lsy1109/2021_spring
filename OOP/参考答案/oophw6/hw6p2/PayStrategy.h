#pragma once

class PayStrategy {		
public:
    virtual float calc(float money) = 0;						
};


class NormalStrategy : public PayStrategy {	
public:
    float calc(float money) {
        return money;
    }
};

class RebateStrategy : public PayStrategy {	
public:
    float calc(float money) {
        return money * 0.38;
    }
};

class ReturnStrategy : public PayStrategy {
public:
    float calc(float money) {
        if (money >= 25) return money - 10;
        else return money;
    }
};
