#include <iostream>
#include "Example.h"

using namespace std;

void create_example(int n) {
	
	cout << "--------create_example is ready--------\n";
	
	Example* e[10];//这里是创立了十个example类型的指针，e本身是example**，指针数组的表头
	
	for (int i = 0; i < n; i++)
		e[i] = new Example(i);
			
	static Example c(2333);//还要给这个对象命名啊！注意传入参数不是n而是2333；
	for(int i=0;i<n;i++)
	{
		e[i]->getData();//为什么上文写e[i]不会报错，但是这里只写e[i]就报错了？注意到指针数组的用法。下面的析构函数同理
	}
	for(int i=0;i<n;i++)
	{
		e[i]->~Example();
	}
	c.getData();//注意getData的奇怪的大小写	
	cout << "--------create_example is over--------\n";
}

Example a(23);
// (7)
//如果在main之前就构造了对象，会先调用构造函数；如果你把对象建构在main的第三行，则会先输出再构造。但是先声明（这是先声明还是先定义？）在main以外，则会先调用构造函数；
//所以说构造函数里有cou<<
int main() {	
	cout << "--------main_function is ready--------\n";

	Example b(233);// (8)
		
	create_example(3);
	Example d(23333);
	//查一下如何搞另一种for循环，待会更新
    a.getData();
	b.getData();
	d.getData();
	// (9)

	cout << "--------main_function is over---------\n";//"/n"才是换行，不要写反了

	return 0;
}
