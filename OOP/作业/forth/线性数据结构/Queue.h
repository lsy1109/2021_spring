#ifndef __QUEUE
#define __QUEUE

#include "LinearDataStruct.h"
#include "IteratorBase.h"

class Queue: public LinearDataStruct {
    // TODO
public:
    class Iterator: public IteratorBase {
    public:
    Iterator (int* _data, int _idx):IteratorBase(_data,_idx){}
    bool operator!=(const Iterator &zcy){return !(idx==zcy.idx);}
    };
    // TODO
    Iterator begin();
    Iterator end();
    int pop();
    Queue(int n=0):LinearDataStruct(n){};
};

#endif