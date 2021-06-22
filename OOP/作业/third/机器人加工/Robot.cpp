#pragma once
#include"Part.h"
#include "Robot.h"

void Robot::add_part(Part tmp)
{
	zcy[nowuse].setx(tmp.getx());
	nowuse++;
	return;
}

bool Robot::is_full()
{
	if (nowuse == use)
		return true;
	else
		return false;
}

const int Robot::getuse()
{
	return this->use;
}

const int Robot::getzcyvalue(const int k)
{
	return zcy[k].getx();
}

Robot::Robot(int x) { use = x; zcy = new Part[x]; };

Robot::~Robot()
{
	delete[]zcy;
}