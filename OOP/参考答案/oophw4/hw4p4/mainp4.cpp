#include <iostream>
using namespace std;

class Base {
public:
    virtual void f(){cout << "Base::f()" << endl;} // (1)
    void f(int i){cout << "Base::f(" << i << ")" << endl;} // (2)
};

class Derive : public Base {
public:
    void f(){cout << "Derive::f()" << endl;} // (3)
};

int main(){
    Derive d;
    Base &b = d;
    d.Base::f(1);
    b.Base::f();
    return 0;
}