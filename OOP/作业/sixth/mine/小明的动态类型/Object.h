#pragma once
#include <list>
#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include "CustomClass.h"
//貌似不准用namespace std

class Object;//提前申明，declare in this scope

class Content
{	public:
	virtual void output(std::ostream& out) { //virtual function for output
		std::cout << "the operator is not supported for this type." << std::endl;
	}//回忆一下虚函数的意义，通过虚函数动态绑定来实现调用子类的函数，如果子类没这个函数，那么就会输出不支持
};

class IntContent : public Content
{
private:
	int x;
public:
	IntContent(int _x) : x(_x) {}
	void operator +=(int zcy) {
		this->x+=zcy;
		return;
	}

	void output(std::ostream& out) { //不能使用const，因为要更改流
		out << x;
	}
};

class StringContent : public Content
{
private:
	std::string x;
public:
	StringContent(std::string _x) : x(_x) {}
	void output(std::ostream& out) {
		out << x;
	}
	void operator +=(std::string zcy) {
		this->x += zcy;
		return;
	}
};

class VectorContent: public Content//虽然object是引用，但是返回引用的引用没有问题
{
public:
	std::vector<Object> x;
	Object& operator[](const int zcy) {
		return x[zcy];
	}
VectorContent(const std::vector<Object>& _x): x(_x) {}
};//不需要重载vector的output，看看main函数的调用方式就明白了

class CustomContent : public Content
{
private:
	CustomClass x;
public:
	CustomContent(const CustomClass& _x) : x(_x) {}
};

class Object
{
private:
	std::shared_ptr<Content>pt;//检测析构，那么必定是用shared_pointer，基类的shared_pointer管理派生类
	//注意到你的pt是个基类指针，调用重载应该用派生类的函数
public:
	Object() {}
	Object(int x) {
		pt = std::make_shared<IntContent>(x); 
	}

	Object(const std::string& x) {
		pt = std::make_shared<StringContent>(x);
	}

	Object(const std::vector<Object> &x){
		pt = std::make_shared<VectorContent>(x);
	}//看看主函数的构造方式你就明白了传入参数的合法性

	Object(const CustomClass& x) {
		pt = std::make_shared<CustomContent>(x);
	}

	friend std::ostream& operator<<(std::ostream& out, const Object& obj) {
		obj.pt->output(out);//你这里都用了虚函数，当然不用在意基类管理派生类的问题，但是接下来两个函数应该考虑这个问题
		return out;
	}//具体在每个派生类里重写覆盖output函数
	
	void operator=(const Object zcy) {
		pt = zcy.pt;
		return;
	}

	Object& operator+=(int y) {
		std::shared_ptr<IntContent> q = std::dynamic_pointer_cast<IntContent>(pt);
		q->operator+=(y);//pt是个基类的智能指针，调用派生类的函数
		return *this;
	}


	Object& operator+=(const std::string& y) {
		std::shared_ptr<StringContent> q = std::dynamic_pointer_cast<StringContent>(pt);
		q->operator+=(y);//通过指针调用函数的写法
		return *this;
	}
	//对于object本身就是vector，还要重载[]
	Object& operator[](const int zcy) {
		std::shared_ptr<VectorContent> chw = std::dynamic_pointer_cast<VectorContent>(pt);
		return chw->x[zcy];
	}//为什么还需要重载object的[]呢？如果你的object指向一个vector，但是自己是不支持[]的，需要重载到vector上的[]，但是对于vector里面是啥，那就无所谓了
};
