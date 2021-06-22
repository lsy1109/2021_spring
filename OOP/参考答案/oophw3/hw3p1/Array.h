#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

class Node;

class Array {
    int len;
    Node *nodes;
public:
    Array(int l);
    ~Array();
    Node& operator[] (int i);
    void update(int pos, int rep);
    void swap(int a, int b);
    void insert(int pos, int val);
};