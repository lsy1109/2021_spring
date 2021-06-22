#pragma once
#include "wheel.h"
#include "engine.h"
#include <iostream>
#include <string>
using namespace std;

class Wheel;
class Engine;

class Vehicle{
public:
    Wheel *w;
    Engine *e;
    string type_v;
    Vehicle(int num_wheels, string engine_type);
    Vehicle(int num_wheels, string engine_type, int dummy);
    void built();
    void describe();
};