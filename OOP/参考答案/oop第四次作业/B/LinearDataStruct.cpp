#include "LinearDataStruct.h"
int LinearDataStruct::max_size()
{
    return max_n;
}
int LinearDataStruct::size()
{
    return (idx_end-idx_begin);
}
void LinearDataStruct::push(int n)
{
    data[idx_end]=n;
    idx_end++;
    
}
