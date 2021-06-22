#include <iostream>
#include "Example.h"

using namespace std;

int Example::total = 0;

Example::Example(int data) {
	this->data = data;
	this->num = ++total;
	cout << "Example #" << num << " is created" << endl;
}

void Example::getData() {
    cout << "The data of Example #" << this->num << " is " << this->data << endl;
}

Example::~Example() {
	//total--;
    cout << "Example #" << num << " is destroyed" << endl;
}