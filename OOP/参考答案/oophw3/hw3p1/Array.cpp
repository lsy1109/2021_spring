#include "Array.h"
#include <iostream>
using namespace std;

Array::Array(int l){
    len = l;
    nodes = new Node[l];
}

Array::~Array() {
    delete[] nodes;
}

Node& Array::operator[] (int i){
    return this->nodes[i];
}
void Array::update(int pos, int rep){
    this->nodes[pos] = this->nodes[rep];
}
void Array::swap(int a, int b){
    Node tmp(move(this->nodes[a]));
    this->nodes[a] = move(this->nodes[b]);
    this->nodes[b] = move(tmp);
}
void Array::insert(int pos, int val){
    for (int i = this->len - 1; i > pos; i--) {
        this->nodes[i] = move(this->nodes[i - 1]);
    }
    this->nodes[pos] = move(Node(val));
}