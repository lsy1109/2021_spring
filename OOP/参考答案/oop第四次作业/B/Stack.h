#ifndef __STACK
#define __STACK

#include "LinearDataStruct.h"
#include "IteratorBase.h"

class Stack: public LinearDataStruct {
    
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

    // TODO
    Stack(int n=0):LinearDataStruct(n){};
    int pop();
    Iterator begin(); 
    Iterator end(); 

};


#endif