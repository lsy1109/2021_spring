#ifndef __QUEUE
#define __QUEUE

#include "LinearDataStruct.h"
#include "IteratorBase.h"

class Queue: public LinearDataStruct {
    // TODO
public:

    class Iterator: public IteratorBase {
        // TODO
    public:
        Iterator(int* _data, int _idx):IteratorBase(_data,_idx){};
    bool operator!=(Iterator src)
    {
        return !(idx==src.idx);
    }
    
    };

    
    Queue(int n=0):LinearDataStruct(n){};
    int pop();
    Iterator begin(); 
    Iterator end(); 
};

#endif