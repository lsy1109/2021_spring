#pragma once
#include <iostream>
#include"Test.h"

Test f1(Test a)
{
	a.print("a");//单引号是字符，双引号是字符串，const char *name是个字符串，但是const char name是个字符
	return a;
}

Test& f2(Test& b)//我调用的是f2(b)，但是他调用的是f2(b),这里会给b取引用
{
	b.print("b");
	return b;
}

void f3(Test& a, Test& b)
{
	Test tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
	return;
}

