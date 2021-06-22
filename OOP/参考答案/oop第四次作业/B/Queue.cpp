#include "Queue.h"
int Queue::pop()
{
    idx_begin++;
    return data[idx_begin-1];
}
Queue::Iterator Queue::begin() 
{
    Iterator tmp(&data[idx_begin],idx_begin);
    return tmp;
}
Queue::Iterator Queue::end() 
{
    Iterator tmp(&data[idx_end],idx_end);
    return tmp;
}