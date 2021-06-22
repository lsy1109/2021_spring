// // // // // class SmallInt{
// // // // //     int val;
// // // // // public:
// // // // //     SmallInt(int i=0): val(i){
// // // // //     }
// // // // //     operator int() const { //(1)
// // // // //         return val; 
// // // // //     }
// // // // //     SmallInt& operator=(SmallInt&& right) {
// // // // //         if (this != &right){
// // // // //             this->val = right.val;
// // // // //         }
// // // // //         return *this;
// // // // //     }
// // // // // };

// // // // // int main() {
// // // // //     SmallInt s1,s2;
// // // // //     s1=4.10;
// // // // //     s1=s1+3;
// // // // //     s2=s2+s1;
// // // // //     return 0;
// // // // // }

// // // // #include <iostream>
// // // // using namespace std;

// // // // class Wheel {
// // // // public:
// // // //     int n = 2;
// // // //     Wheel(){cout << "Wheel::Wheel()" <<endl;}
// // // //     Wheel(int i):n(i){cout << "Wheel::Wheel(" << n << ")" << endl;}
// // // // };

// // // // class Engine {
// // // // public:
// // // //     int n = 1;
// // // //     Engine(){cout << "Engine::Engine()" << endl;}
// // // //     Engine(const Engine &other){n = other.n + 1;}
// // // // };

// // // // class Car {
// // // //     Wheel w;
// // // // public:
// // // //     Engine e;
// // // //     Car(){
// // // //     e = Engine();
// // // //     w = Wheel(4); //(1)
// // // //     } 
// // // // };

// // // // int main(){
// // // //     Car c1;
// // // //     Car c2(c1); //(2)
// // // //     return 0;
// // // // }

// // // #include <iostream>
// // // using namespace std;

// // // class Base {
// // //     Base(int i) {}
// // // public:
// // //     const static int data = 10;
// // //     int n = 0;
// // //     Base() {}
// // //     Base & operator=(const Base & right){
// // //     if(this != &right){
// // //         n = right.n + 1;
// // //     }
// // //     return *this;
// // //     }
// // // protected:
// // //     void f() {}
// // // };

// // // class Derive : public Base {
// // // public:
// // //     using Base::Base;
// // //     using Base::f;
// // // };

// // // class Derive2 : protected Base {};

// // // class Derive3 : private Base {};

// // // int main(){
// // //     Derive d;
// // //     Derive d1;
// // //     d = d1; // (1)
// // //     d.data;//(2)
// // //     d.f();

// // //     Derive2 d2;
// // //     Derive3 d3;
// // //     d2.data;
// // //     d3.data;//(3)
// // //     return 0;
// // // }

// // #include <iostream>
// // using namespace std;

// // class Base {
// // public:
// //     void f(){cout << "Base::f()" << endl;} // (1)
// //     void f(int i){cout << "Base::f(" << i << ")" << endl;} // (2)
// // };

// // class Derive : public Base {
// //     void f(){cout << "Derive::f()" << endl;} // (3)
// // public:
// //     using Base::f; // (4)
// // };

// // int main(){
// //     Derive d;
// //     d.Base::f(); // (5)
// //     return 0;
// // }

// #include <iostream>
// class Test {
// public:
//     Test() {
//     std::cout << "Test()\n";
//     }
//     ~Test() {
//     std::cout << "~Test()\n";
//     }
//     Test(const Test &con) {
//     std::cout << "Test(const Test &con)\n";
//     }
//     // Test(Test &&con) {
//     // printf("Test(Test &&con)\n");
//     // }
// };

// // Test func(Test a) {
// //     return Test();
// // }

// int main() {
//     Test a;
//     Test b(std::move(a));
//     return 0;
// }

#include <iostream>
#include "a.h"
using namespace std;

v = 1;

int main(){
    v = 1;
    return 0;
}