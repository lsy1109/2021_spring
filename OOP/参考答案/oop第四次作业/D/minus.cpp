#include "minus.h"
#include "minus.h"
minus::minus(string name, Node *x1, Node *x2):OperationNodeTwo(name,x1,x2){};
void minus::UpdateValue()
{
    value_=input1->value()-input2->value();
}