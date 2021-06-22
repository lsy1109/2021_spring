#include "motor.h"
#include <iostream>
#include <string>
using namespace std;

class Vehicle;

Motor::Motor(int num, string engine): Vehicle(num, engine, 1) {
    this->type_v = "motor";
    built();
}

void Motor::sell(){
    cout << "A motor is sold!" << endl;
}