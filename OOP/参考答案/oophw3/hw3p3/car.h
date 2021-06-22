#pragma once
#include "vehicle.h"
#include <iostream>
#include <string>
using namespace std;

class Vehicle;

class Car : public Vehicle {
public:
    Car(int num, string engine);
    using Vehicle::describe;
    using Vehicle::built;
};