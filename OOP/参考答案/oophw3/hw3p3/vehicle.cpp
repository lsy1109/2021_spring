#include "vehicle.h"
#include <iostream>
#include <string>
using namespace std;

class Wheel;
class Engine;


void Vehicle::built(){
    cout << "Finish building a " 
         << this->type_v 
         << " with "
         << this->w->get_num()
         << " wheels and a " 
         << this->e->get_name()
         << " engine." << endl;
}

Vehicle::Vehicle(int num_wheels, string engine_type) {
    this->e = new Engine(engine_type);
    this->w = new Wheel(num_wheels);
    type_v = "vehicle";
    built();
}

Vehicle::Vehicle(int num_wheels, string engine_type, int dummy) {
    this->e = new Engine(engine_type);
    this->w = new Wheel(num_wheels);
    type_v = "vehicle";
}

void Vehicle::describe(){
    cout << "A " 
    << type_v 
    <<" with " 
    << this->w->get_num()
    << " wheels and a " 
    << this->e->get_name()
    << " engine." << endl;
}