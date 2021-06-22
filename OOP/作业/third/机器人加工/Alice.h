#pragma once
#include"Part.h"
#include"Robot.h"

class Alice : public Robot
{
public:
	Alice(int n);
	int run();
	friend ostream& operator<< (ostream& out, const Alice& src);
	~Alice();
};
