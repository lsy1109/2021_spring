#include <iostream>
#include "Test.h" 
#include "func.h" 

using namespace std;

int main()
{
	cout << "------entering main------" << endl;
	Test a;
	Test b;
	cout << "------before call f1------" << endl;
	
	cout << "f1():" << endl;
	Test A = f1(a);//f1(a)是个右值，因为你没法对f1(a)++; 因为f1(a)是个右值，故而默认调用了移动构造函数
	
	cout << "------after f1 return------" << endl;
	
	cout << "------before call f2------" << endl;
	
	cout << "f2():" << endl;
	Test& B = f2(b);


	cout << "------after f2 return------" << endl;
	
	cout << "------before call f3------" << endl;
	
	cout << "f3():" << endl;
	f3(a, b);
	
	cout << "------after f3 return------" << endl;
	
	cout << "------exiting main------" << endl;
	
	return 0;
}

