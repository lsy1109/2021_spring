#pragma once
using namespace std;
class OccupationStrategy {		
public:
	virtual double getSalary(double base, double bonus, double level) = 0;
	virtual ~OccupationStrategy() {}
};
double OccupationStrategy::getSalary(double base, double bonus, double level) { return 0; }

class SalesmanStrategy : public OccupationStrategy {
public:
	double getSalary(double base, double bonus, double level)
	{
		double zcy = 0;
		if (level < 60) { zcy = 0; }
		else if (60 <= level&& level < 70) { zcy = bonus * 0.6; }
		else if (70 <= level&& level < 80) { zcy = bonus * 0.7; }
		else { zcy = bonus; }
		return base+zcy;
	}

};

class DeveloperStrategy : public OccupationStrategy {
public:
	double getSalary(double base, double bonus, double level)
	{
		double zcy = 0;
		if (level == 20) { zcy = bonus * 0.2; }
		else if (level == 40) { zcy = bonus * 0.4; }
		else if (level == 60) { zcy = bonus * 0.6; }
		else if (level == 80) { zcy = bonus * 0.8; }
		else { zcy = bonus; }
		return base + zcy;
	}
};