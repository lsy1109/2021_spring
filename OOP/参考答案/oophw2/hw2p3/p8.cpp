#include <iostream>
using namespace std;

class A{
//public: //1
    static int data; //2
    static void f(int x){
        static int t = x; //3
        cout << t << endl;
    }    
};
int A::data = 0; //4
static A a; //5

int main(){
    static A b;
    cout << a.data << endl;
    a.f(2);
    b.f(3);
    return 0;
}