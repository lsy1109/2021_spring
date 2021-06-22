#include<iostream>
#include"Part.h"
using namespace std;

const int Part::getx()
{
	return x;
}
void Part::setx(int m){
	this->x = m;
	return;
}

Part::~Part(){}

Part::Part():x(0) {}

Part::Part(int z) :x(z) {}