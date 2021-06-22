#pragma once
#include"Part.h"
#include"Robot.h"
#include"Bob.h"

int Bob::run()
{
	int tmp = 0;
	int end = this->getuse();
	for (int i = 0; i < end; i++)
	{
		int j = this->getzcyvalue(i);
		tmp += j*j;
	}
	return tmp;
}
ostream& operator<< (ostream& out, const Bob& src)
{
	out << "Build robot Bob";
	return out;
}

Bob::Bob(int n) : Robot(n) {};
Bob::~Bob(){}