#include "Calculator.h"
Calculator::~Calculator()
{
	delete level;
	delete perform;
}

int Calculator::get_base()
{
	return level->get_ba();
}

int Calculator::get_total(int base)
{
	return perform->get_tot(base);
}

Calculator::Calculator(LevelStrategy* lev, PerformStrategy* perf):level(lev), perform(perf) {}