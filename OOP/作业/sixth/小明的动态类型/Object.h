#pragma once
#include <list>
#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include "CustomClass.h"


class Content
{
	public:
	virtual void output(std::ostream& out){ //virtual function for output
		std::cout << "the operator is not supported for this type." << std::endl;
	}
};

class IntContent: public Content
{
private:
	int x;
public:
	IntContent(int _x): x(_x) {}
	IntContent& operator+=(int other){
		x+=other;
		return *this;
	}//首先，这里的返回值可以void，因为我们用+=符号的时候，根本不会有东西来接受它
	//对比下，int a=x++;这里先对x做++，再把原本的x返回给a，故而需要返回值为int，但是返回int&不安全，因为这个实现过程会用到一个临时变量tmp储存原本的x，直接返回tmp是拷贝构造，但是返回tmp的引用会造成返回了临时变量的引用，不安全
	//第二，回到这题里，我们希望对于IntContent的某个对象来+=，实际上x+=other是指this->x+other，你改变了this的x，这就足够了。返回值为IntContent且return一个*this是为了把当前的数据赋值给接受者
	//第三，返回此处一个引用和返回一个类型没有区别，甚至前者更不安全
	void output(std::ostream& out){
		out<<x;
	}
};
class StringContent: public	 Content
{
private:
	std::string x;
public:
	StringContent(const std::string& _x): x(_x) {}
	StringContent& operator+=(std::string other){
		x+=other;
		return *this;
	}
	void output(std::ostream& out){  //???
		out<<x;
	}
};


class CustomContent: public Content
{
private:
	CustomClass x;
public:
	CustomContent(const CustomClass& _x): x(_x) {}
};


class VectorContent:public Content//如果一个object其中储存的是object的vector的话
{
public:
	std::vector<Object> x;
	VectorContent(const std::vector<Object>& _x):x(_x){}
	Object& operator[](const int i){
		return x[i];
	}
};

class Object
{
private:
	std::shared_ptr<Content>pt;

public:
	Object() {}
	Object(int x) {
		pt = std::make_shared<IntContent>(x); // where to delete? maybe use std::shared_ptr?
	}
	Object(const std::string &x){
		pt = std::make_shared<StringContent>(x);
	}

	Object(const CustomClass &x){
		pt = std::make_shared<CustomContent>(x);
	}

	Object(const std::vector<Object>&x){//以一个Object的vector作为参数，构造**一个**Object!!!!
		pt = std::make_shared<VectorContent>(x);
	}


	friend std::ostream& operator<<(std::ostream& out, const Object& obj) {
		obj.pt->output(out);
		return out;
	}//重载了三种类型的cout。

	Object& operator=(const Object other){
		pt = other.pt;
		return *this;
	}

	Object& operator+=(int y){
		Content *p=pt.get();
		IntContent* tmp=dynamic_cast<IntContent*>(p);
		tmp->operator+=(y);
		return *this;
	}
	Object& operator+=(const std::string &y){
		Content *p=pt.get();
		StringContent* tmp=dynamic_cast<StringContent*>(p);
		tmp->operator+=(y);	
		return *this;
	}
	Object& operator[](const int i){
		Content *p=pt.get();
		VectorContent* tmp= dynamic_cast<VectorContent*>(p);
		return tmp->x[i];//tmp是一个vector类的指针了！
	}
};
