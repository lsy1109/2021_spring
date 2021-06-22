#include <iostream>
using namespace std;

class Base {
public:
    int data;
    Base(){fn();}
    virtual void fn(){}
    virtual ~Base(){fn();}
private:
    virtual void g(){}
};

class Derive : public Base {
public:
    Derive(){fn();}
    void fn(){}
    ~Derive(){fn();}
    void g(){}
};

int main(){
    Base *b = new Derive;//(1)
    b->g();
    delete b;
    return 0;
}