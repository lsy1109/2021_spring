#pragma once

#include <iostream>

using namespace std;

class Test {
	int *buf;
public:
	Test() {
		buf = new int(0);
		cout << "Test(): this->buf @ " << hex << buf << endl;
	}
	Test(int val) {
		buf = new int(val);
		cout << "Test(int): this->buf @ " << hex << buf << endl;
	}
	~Test() {
		cout << "~Test(): this->buf @ " << hex << buf << endl;
		if (buf) delete buf;
	}
	Test(const Test& t) : buf(new int(*t.buf)) {
		cout << "Test(const Test&) called. this->buf @ "
			<< hex << buf << endl;
	}//f1必然调用了拷贝构造函数，实际上是，假如我传参数，我传入一个形参，不是引用。他会先把a赋值给形参，这里使用拷贝构造(因为地址改变了)
	//接下来给形参一次print。不过是碰巧形参和a重名了。移动赋值的话，地址是不发生改变的，改变的只有指针的名字
	//形参移动是否会构造临时变量 比如说Test tmp=a?
	//其实是不会的，这在析构时体现的很明显。
	// 注意到此题禁用了返回值优化，那么如果我还构造了临时变量，连带着A，显然我会有四次构造和三次析构
	// 构造A和析构返回值和形参的先后顺序：先执行完函数体，暂不析构，然后执行完整个语句，具体到这个语句，外面还有一个移动构造。(等号不一定是赋值，等的时机决定了等号是赋值还是构造)
	//构造返回对象，析构形参，析构之前都已近把指向的地址清空了
	//你以为你需要考虑如何把指针置为空吗？你是智障吗？这里用了移动，当然会被置为空

	Test(Test&& t) : buf(t.buf) {
		cout << "Test(Test&&) called. this->buf @ "
			<< hex << buf << endl;
		t.buf = nullptr;
	}//f2传入的如果纯粹是参数，那么怎么着都会有移动构造or拷贝构造，但是这里没有这两种构造的print，从而我们怀疑是传的引用。
	//实际上，f2马上就把参数给print了，参数的地址已经出现过，那必然是传的引用
	//f2还干了啥事儿，不得而知，至少应该返回了一个Test并且给B赋值
	//B前面的那个引用是在干啥？

		//B是一个Test类型的引用，但是Test &B是个左值引用，左值引用不能引用右值；
	//引用的标准写法，比如int a=3; int &b=a;这就是说b是a的引用，但是你不能写int &b=3,只有常量左值引用可以引用右值。
	//f2(b)如果返回的是个Test，那他就是个Test类型的右值。但是如何你用f2(b)去赋值了另一个东西，比如tmp=f2(b)，那tmp是个左值，但是f2(b)如果返回值是Test而不是Test &，那f2(b)本身还是右值。
	//所以说这个题，f2(b)必然返回的是一个Test类型的引用；
	//传一个引用，返回一个引用
	//前文叙述的返回值优化，是针对你返回的是一个具体的对象的优化，如果你返回的是一个引用(比如传参&b,retrun b)，那就直接返回，而不会构造。
	Test& operator= (const Test& right) {
		if (this != &right){
			if(buf) delete buf;
			buf = new int(*right.buf);
		}
		return *this;
	}

	//f3移动构造了tmp，输出了1550；
	//f3也是传引用，不然他还会再构造一次a和b
	//关键是你后面的析构可以看出端倪
	//最早构造的a最晚析构，析构函数是给出地址，然后清除对应地址内存空间，故而可以看出a和b的地址交换了，故而可以看出这是一个移动类型的swap
	//我们在做swap的时候，主要考虑的是swap内存上的数据，不太care内存本身，但是可以从内存本身看出是哪种swap
	//比如我们用拷贝类型的swap，Test tmp=b；b=a；a=tmp；你会发现a和b的地址没变，但是他俩内存空间的数据变了，而移动的实现必须依赖于指针，a和b的指针指向的地址交换，但是这俩地址对应的内存空间的数据没有改变
	Test& operator= (Test&& right) {
		if (this != &right){
			if(buf) delete buf;
			this->buf = right.buf;
			right.buf = nullptr;
		}
		return *this;
	}
	void print(const char *name) {
		cout << name << ".buf @ " << hex << buf << endl;
	}
};
