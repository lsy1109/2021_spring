#include <iostream>
using namespace std;

class Base {
public:
    Base() {};
    virtual void f(); // (1)
    virtual ~Base() {cout << "~Base()\n";};
};

class Derive : public Base {
public:
    Derive() {};
    void f() {}
    ~Derive() {cout << "~Derived()\n";} // (3)
};

int main(){
    Base *b = new Derive;
    Derive *d = b;
    return 0;
}