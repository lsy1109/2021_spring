//每一种行为各自有方法虚基类A、B
//每一个方法基类A有若干具体的方法A1,A2,A3，每一种都会继承A
//所有对象具有一个对象基类O，对象基类O含有所有的方法基类指针A*、B*，从而实现多态
//注意到对象基类如果仅含有方法基类指针，实际上没法调用方法基类的方法，故而还需要调用接口
//每种对象是一个具体的对象类O1,O2,O3，每种都会继承对象类O，同时让方法基类指针A*、B*具体指向方法派生类上Ax、By
#pragma once
#include<iostream>

class LevelStrategy{//LevelStrategy是不用存储数据的，但是perform需要存储数据
public:
	LevelStrategy();
	virtual ~LevelStrategy();
	virtual int get_ba() = 0;
};

class P1LStrategy:public LevelStrategy {//方法类并不需要显式定义构造函数
public:
	int get_ba()override;
};

class P2LStrategy:public LevelStrategy {
public:
	int get_ba()override;
};

class P3LStrategy:public LevelStrategy{
public:
	int get_ba()override;
};