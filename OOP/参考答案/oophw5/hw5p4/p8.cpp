#include <memory>
#include <iostream>
using namespace std;
void f(shared_ptr<int> p1){
    cout << p1.use_count() << endl;
    static auto t2 = p1;
}
int main()
{
    int *x = new int(1);
    {
        shared_ptr<int> p1(x);
        cout << p1.use_count() << endl;
        f(p1);
        cout << p1.use_count() << endl;
        f(p1);
        cout << p1.use_count() << endl;
    }
    //(1)
    shared_ptr<int> p2(x);
    cout << p2.use_count() << endl;
    return 0;
}