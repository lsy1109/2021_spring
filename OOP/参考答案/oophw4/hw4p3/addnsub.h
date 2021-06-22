#pragma once
#include "operation.h"

class OperationAdd: public OperationNodeTwo {
public:
    OperationAdd(string name, Node *x1, Node *x2): OperationNodeTwo(name, x1, x2) {}
    void UpdateValue() override {
        float val1 = this->input1->value();
        float val2 = this->input2->value();
        float v = val1 + val2;
        this->value_ = v;
    };
    ~OperationAdd() {}
};

class OperationSub: public OperationNodeTwo {
public:
    OperationSub(string name, Node *x1, Node *x2): OperationNodeTwo(name, x1, x2) {}
    void UpdateValue() override {
        float val1 = this->input1->value();
        float val2 = this->input2->value();
        float v = val1 - val2;
        this->value_ = v;
    };
    ~OperationSub() {}
};