#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student{
public:
    string name = "test";
    int present = 0;
    int absent = 0;
    int id;
    Student () { };
    Student(string s);
    string getName();
    int getPresentTimes();
    int getAbsentTimes();
};