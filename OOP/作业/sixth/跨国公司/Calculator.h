#pragma once
#include <string>
#include "OccupationStrategy.h"
#include "PayStrategy.h"
using namespace std;

class Calculator {								
public:
	PayStrategy* zcy;
	OccupationStrategy* chw;
	Calculator(OccupationStrategy* m2,PayStrategy* m1) :zcy(m1), chw(m2) {}
	double getSalary(double base, double bonus, double level)
	{
		return this->chw->getSalary(base, bonus, level);
	}
	double pay(std::string name, double money)
	{
		return this->zcy->pay(name, money);
	}
};