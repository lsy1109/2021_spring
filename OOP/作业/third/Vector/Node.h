#pragma once
#include <iostream>

class Node
{
private:
	static long long int num_createfunc_default, num_createfunc, num_copyfunc, num_movefunc, num_copyassign, num_moveassign, num_delfunc;
	int val;//只有value是我们要用到的，别的都不需要
public:	
	Node(int v);
	Node();
	~Node();
	Node(const Node &y);//node的拷贝构造函数。结合题意，Vector的拷贝构造需要保留原来的Node，故而要用Node的拷贝构造
	Node(Node &&y);//node的移动构造。查看下Node.cpp会发现，对node而言，因为node内部没有数组，copyfunc和movefucn没有显著效率区别；
//但是出题人为了强调一般拷贝比移动效率低，所以强行把拷贝的cost设为10，move设为1；
//故而尽量多用移动而少用拷贝
	Node& operator=(const Node &y);
	Node& operator=(Node &&y);
	bool operator!=(const Node &y);
	friend std::istream& operator>>(std::istream& in, Node& x);
	friend std::ostream& operator<<(std::ostream& out, const Node& x);
	static void outputResult(int ref_ans);
};
