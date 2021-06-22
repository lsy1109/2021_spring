#pragma once
#include<iostream>
using namespace std;

class Robot {
private:
	int use;
	int nowuse=0;
	Part* zcy;
public:
	Robot(int x);
	void add_part(Part tmp);
	const int getzcyvalue(int k);
	const int getuse();
	bool is_full();
	virtual ~Robot();
};