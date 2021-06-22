#pragma once
#include <string>
using namespace std;

class PayStrategy {	
public:
	virtual double pay(std::string name, double money) = 0;
	virtual ~PayStrategy() {}
};


class NormalStrategy : public PayStrategy {	
public:
	double pay(std::string, double zcy)
	{
		return zcy;
	}
};

class SwiftStrategy : public PayStrategy {	
public:
	double pay(string, double zcy)
	{
		if (zcy <= 10000) { return zcy - 10; }
		else
		{
			double chw = zcy / 1000;
			if (chw <= 20) {
				return (zcy - chw);
			}
			else
			{
				return (zcy - 20);
			}
		}

	}
};

class BitcoinStrategy : public PayStrategy {	
public:
	double pay(string fuck, double zcy)
	{
		double chw = (fuck.length() + 8) * 0.01;
		return (zcy-chw);
	}
};
