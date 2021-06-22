#include <thread>
#include <iostream>
using namespace std;

void test() {
  cout << "test" << endl;
}

int main() {
  thread t1;
  thread t2(test);
  thread t3 = move(t2);
  thread t4(test);
  t4.join();
  //t1.join();
  //t2.join();
  t3.join();
  return 0;
}