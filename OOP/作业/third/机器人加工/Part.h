#pragma once
#include<iostream>
using namespace std;
class Part {
private:
	int x;
public:
	Part();
	Part(int z);
	const int getx();
	void setx(int m);
	~Part();
};