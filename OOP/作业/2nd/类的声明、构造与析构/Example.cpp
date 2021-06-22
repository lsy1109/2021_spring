#include <iostream>
#include "Example.h"

using namespace std;
int Example::index=0;//Example.index和Example::index区别？

Example::Example(int data) {
 Example::x=data;
 index++;
 Example::y=index;
 cout<<"Example #"<<y<<" is created\n";
}

void Example::getData() {
cout<<"The data of Example #"<<y<<" is " <<x<<endl;
}

Example::~Example() {
	cout<<"Example #"<<y<<" is destroyed\n";
	// (5)
}