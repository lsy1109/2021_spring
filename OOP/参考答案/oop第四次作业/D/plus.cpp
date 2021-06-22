#include "plus.h"
plus::plus(string name, Node *x1, Node *x2):OperationNodeTwo(name,x1,x2){};
void plus::UpdateValue()
{
    value_=input1->value()+input2->value();
}