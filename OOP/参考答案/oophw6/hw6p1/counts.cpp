#include<thread>
#include<mutex>
using namespace std;
static mutex exclusive;

void count(int array[], int start, int end, int local[], int global[], int max_value) {
    for (int i = start; i <= end; ++i) {
        local[array[i]]++;
    }
    exclusive.lock();
    for (int i = 0; i <= max_value; ++i) {
        global[i] += local[i];
    }
    exclusive.unlock();
}

void parallel_count(int array[], int array_size, int counts[], int max_value) {
    thread* threads[4];    
    int s = 0, e;
    int* local_counts[4];
    for (int i = 0; i < 4; i++) {
        local_counts[i] = new int[max_value + 1];
        e = s + array_size / 4 + 1;
        if (e > array_size) e = array_size - 1;
        threads[i] = new thread(count, array, s, e, local_counts[i], counts, max_value);
        s = e + 1;
    }
    for (int i = 0; i < 4; i++)
        threads[i]->join();
    for (int i = 0; i < 4; i++)
        delete threads[i];
}