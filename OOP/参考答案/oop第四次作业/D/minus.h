#pragma once
#include "operation.h"
#include "node.h"
class minus:public OperationNodeTwo
{
    public:
        minus(string name, Node *x1, Node *x2);
        virtual void UpdateValue() override;
};