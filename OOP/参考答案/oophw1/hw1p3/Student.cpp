#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student(string s) { 
    this->name = s; 
}

string Student::getName(){
    return this->name;
}

int Student::getAbsentTimes(){
    return this->absent;
}

int Student::getPresentTimes(){
    return this->present;
}