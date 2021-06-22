#pragma once
//#include "StudentCollection.h"
#include <iostream>
#include <string>
using namespace std;

//class StudentCollection{};

class Student {
    string name;
public:
    int scores[4];
    Student(string s);
    friend class StudentCollection;
    //friend istream& operator>> (istream& in, StudentCollection& dst);
    friend ostream& operator<< (ostream& out, const Student& src);
    friend bool operator< (Student&a, Student&b);
    string get_name();
    int get_total();
    int get_chi();
    int get_mat();
    int get_eng();
};

