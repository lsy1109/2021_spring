#include "car.h"
#include <iostream>
#include <string>
using namespace std;

class Vehicle;

Car::Car(int num, string engine): Vehicle(num, engine, 1) {
    type_v = "car";
    built();
};