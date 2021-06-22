#pragma once
#include "Node.h"
#include <iostream>

class Vector {
private:
	int capacity;
	int len;
	Node* array;
public:
	Vector(int n);
	~Vector();
	Vector(const Vector & other);//拷贝构造函数，也就是复制构造函数。这里当然没法不写拷贝构造函数，第一，因为Node.cpp里面测试了拷贝构造的次数。
	//此题没有啥自由度可言
	//第二，移动构造是直接利用原有对象开辟的内存空间，而拷贝构造是复制一份保留原来的，二者的应用场景不一样，移动构造不能替代拷贝构造的功能
	//当你想用一个对象去初始化另一个对象时，如果你想保留原来的对象继续使用，就要用拷贝；如果原来的对象只是个临时对象，或者用来初始化新的对象后就没用了，就可以用移动构造，来减免新的对象开辟内存带来的开销
	// 退回到这道题里面，main.cpp的74行、80行等几个地方都用到了拷贝
	//拷贝构造函数的形参类型为常量左值引用，可以绑定常量左值、左值和右值
    //移动赋值运算符函数的形参类型为右值引用，可以且仅仅可以绑定右值(常量、表达式、函数返回)
	//PPT的48页！
	Vector(Vector && other);//基于右值引用的移动构造函数
	//注意到此题涉及了两个class的移动构造与拷贝构造，vector的移动用node的移动，vector的拷贝用node的拷贝。而node的移动与拷贝系统都给你写好了，所以只用写vector的移动与拷贝

	Vector & operator=(const Vector & other);//拷贝赋值运算符，其实也是重载等号
	Vector & operator=(Vector && other);//移动赋值运算符
	//根据赋值运算符右侧变量的类型决定调用拷贝或移动赋值运算符函数,且两种可以调用时优先调用右值
	//移动赋值和移动构造的区别：虽然他们都是移动机制，但是使用的目的不一样
	//一个是拿临时变量构造对象，一个是拿临时变量赋值。就是我的移动构造是直接创建新的对象，用了移动。但是我的移动赋值是原来有的对象，赋新的值
	Node& operator [] (int pos);//你是傻逼吗？这里是在重载vector的[],返回值类型是对应位置的node
	void append(int value);
	void insert(int pos, int value);
	void swap(int pos1, int pos2);
	void dilatation();
	int getlen();
};