#include <iostream>
using namespace std;
template <typename T>

class Base {
public:
	void fun() {
		cout << "Base::fun" << endl;
	}

	void d() {
		T* pT = static_cast<T*>(this);
		pT->fun();
	}

};

class Drive : public Base<Drive> {
public:
	void fun() {
		cout << "Drive::fun" << endl;
	}
};

int main() {
	Drive obj;
	obj.d();
	return 0;
}