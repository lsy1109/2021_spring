#include "Stack.h"
int Stack::pop()
{
    idx_end--;
    return data[idx_end];
}
Stack::Iterator Stack::begin() 
{
    Iterator tmp(&data[idx_begin],idx_begin);
    return tmp;
}
Stack::Iterator Stack::end() 
{
    Iterator tmp(&data[idx_end],idx_end);
    return tmp;
}
