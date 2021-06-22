#pragma once
#include "Student.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class StudentCollection {
    //int len;
    vector<Student> students;
public:
    StudentCollection();
    friend istream& operator>> (istream& in, StudentCollection& dst);
    friend ostream& operator<< (ostream& out, const StudentCollection& src);
    Student operator[] (string name);
    void sortByScore();
};

