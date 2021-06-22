#include<iostream>
using namespace std;

template <typename T>
void fun(T x, T y)
{
    static int count = 0;
    cout << count <<endl;
    ++count;
}

int main()
{
    fun(1, 1); //(1)
    fun(1, 2); //(2)
    fun<double>(1.1, 2); //(3)
    fun<int>(1.1, 2); //(4)
    return 0;
}