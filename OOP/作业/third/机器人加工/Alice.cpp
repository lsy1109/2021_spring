
#include"Part.h"
#include"Robot.h"
#include"Alice.h"

int Alice::run()
{
	int tmp = 0;
	int end = this->getuse();
	for (int i = 0; i < end; i++)
	{
		int j = this->getzcyvalue(i);
		tmp += j;
	}
	return tmp;
}

ostream& operator<< (ostream& out, const Alice& src)
{
	out << "Build robot Alice";
	return out;
}

Alice::Alice(int n) : Robot(n) {}

Alice::~Alice() {}