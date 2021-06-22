#pragma once
#include "vehicle.h"
#include <iostream>
#include <string>
using namespace std;

class Vehicle;

class Motor : public Vehicle {
public:
    Motor(int num, string engine);
    using Vehicle::describe;
    using Vehicle::built;
    void sell();
};