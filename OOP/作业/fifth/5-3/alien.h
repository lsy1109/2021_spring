#include "what.h"
#include <iostream>
#include <cstring>

class Alien:public WhatCanMotion ,public WhatCanSpeak{
    string name;
public:
    Alien(string n):name(n){};
    void speak() override {
        cout<<name<<" is speaking"<<std::endl;
    }
    void motion() override {
        cout<<name<<" is moving"<<std::endl;
    }
    void stop() override {
        cout<<name<<" stops"<<std::endl;
    }
    ~Alien(){}
};