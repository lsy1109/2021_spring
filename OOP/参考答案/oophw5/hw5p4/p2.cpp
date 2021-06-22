#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec = {1,2,3,4,5};
    auto a = vec.end();
    auto b = vec.begin();
    auto c = vec.begin() + 2;
    auto d = vec.erase(vec.begin() + 1);
    cout << *a << *b << *c << *d << endl;
    return 0;
}