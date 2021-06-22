#include <iostream>
using namespace std;

class Base {
public:
    Base() {};
    virtual void f() = 0; // (1)
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
    delete b;
    return 0;
}