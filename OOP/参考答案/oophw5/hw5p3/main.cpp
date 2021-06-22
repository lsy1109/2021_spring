// #include<iostream>
// #include<list>
// #include"myqueriable.h"

// using namespace std;

// bool op1(int x){return x > 2 && x < 10;}
// class Op2{
// public:
//     int operator()(int x) {return x * 2;}
// }op2;

// int main(){
//     list<int> li = {1, 4, 6, 2, 10};
//     auto out = from(li)
//         .where(op1)  // 4, 6
//         .apply(op2)  // 8, 12
//         .sum();
//     cout << out << endl;
// }

#include<iostream>
#include<vector>
#include<cmath>
#include<functional>
#include"myqueriable.h"

using namespace std;

float fn(float x){return sqrt(x);}
function<float(float)> op = fn;

int main(){
    vector<float> vec = {2.0, 3.0, 4.0, 5.0};
    auto li = from(vec)
        .apply(op);
    for(int i = 0; i < li.size(); i++){
        cout << li[i] << endl;
    }
}