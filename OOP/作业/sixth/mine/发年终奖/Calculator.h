#pragma once
#include <iostream>
#include <string>
#include "LevelStrategy.h"
#include "PerformStrategy.h"

class Calculator {
private:
	LevelStrategy* level;
	PerformStrategy* perform;
public:
	~Calculator();
	Calculator(LevelStrategy* lev, PerformStrategy* perf);
	int get_base();
	int get_total(int base);
};