#include"operation.h"

class mi: public OperationNodeTwo
{   public:
    mi(string name, Node *x1, Node *x2) : OperationNodeTwo(name,x1,x2){}
    ~mi(){}
    void UpdateValue()override;//没必要再把虚的写出来
};
//OperationNodeTwo(string name, Node *x1, Node *x2) : Node(name), input1(x1), input2(x2) {}