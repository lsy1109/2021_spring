#include <iostream>
using namespace std;
//auto *x = "123";
//auto f(int x) { return x+1; }

template <typename _Tx, typename _Ty>
auto multiply(_Tx x, _Ty y) -> decltype(x*y) { return x*y; }

int main() {
    auto a = multiply(2, 3.3f);
    //for(auto x: "123") { cout << x << endl; }
    return 0;
}

