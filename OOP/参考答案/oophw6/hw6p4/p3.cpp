#include<thread>
using namespace std;

const int maxn = 10000;
int num[maxn];
int s = 0;
void test(int l, int r) {
    for (int i = l; i < r; i++)
        s += num[i];
}
int main() {
    thread t1(test, 0, 2500);
    thread t2(test, 2500, 5000);
    thread t3(test, 5000, 7500);
    thread t4(test, 7500, 10000);
    t1.join();t2.join();t3.join();t4.join();
    return 0;
}