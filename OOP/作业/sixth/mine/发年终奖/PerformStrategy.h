#pragma once
#include<iostream>
#include<string>
using namespace std;

class PerformStrategy {
protected:
	double bonus;
public:
	PerformStrategy(double x);
	virtual ~PerformStrategy();
	virtual int get_tot(int) = 0;
};

class sPerformStrategy:public PerformStrategy {
public:
	using PerformStrategy::PerformStrategy;
	int get_tot(int)override;
};

class mPerformStrategy :public PerformStrategy {
public:
	using PerformStrategy::PerformStrategy;
	int get_tot(int)override;
};

class lPerformStrategy :public PerformStrategy {
public:
	using PerformStrategy::PerformStrategy;
	int get_tot(int)override;
};