#include <iostream>
using namespace std;

class Car {
public:
    int wheel;
    Car(){} 
    Car(const Car & t){} //(3)
    void fn(){}
};

class Van: public Car {
public:
    Van(){}
    void fn(){}
};

int main(){
    Van v;
    Car c = v; //(1)
    Car & a = v;
    a.fn(); //(2)
    return 0;
}