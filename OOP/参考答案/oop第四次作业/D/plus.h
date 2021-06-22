#pragma once
#include "operation.h"
#include "node.h"
class plus:public OperationNodeTwo
{
    public:
        plus(string name, Node *x1, Node *x2);
        virtual void UpdateValue() override;
};