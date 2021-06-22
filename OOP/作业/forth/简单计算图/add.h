#include"operation.h"

class add: public OperationNodeTwo
{   public:
    add(string name, Node *x1, Node *x2) : OperationNodeTwo(name,x1,x2){}
    ~add(){}
    void UpdateValue() override;
};
//OperationNodeTwo(string name, Node *x1, Node *x2) : Node(name), input1(x1), input2(x2) {}