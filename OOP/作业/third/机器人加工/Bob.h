#pragma once
#include"Part.h"
#include"Robot.h"

class Bob : public Robot
{
public:
	Bob(int n);
	int run();
	friend ostream& operator<< (ostream& out, const Bob& src);
	~Bob();
};

