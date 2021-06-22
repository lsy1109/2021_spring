#ifndef __STACK
#define __STACK

#include "LinearDataStruct.h"
#include "IteratorBase.h"

class Stack: public LinearDataStruct {
    // TODO
public:
    class Iterator: public IteratorBase {
    public:
    Iterator (int* _data, int _idx):IteratorBase(_data,_idx){}
    bool operator!=(const Iterator &zcy){return !(idx==zcy.idx);}
    };
    Iterator begin();
    Iterator end();
    int pop();
    Stack(int n=0):LinearDataStruct(n){};
};


#endif