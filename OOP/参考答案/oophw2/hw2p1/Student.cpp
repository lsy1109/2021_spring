#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string s) {
    this->name = s;
    this->scores[0] = 0;
    this->scores[1] = 0;
    this->scores[2] = 0;
    this->scores[3] = 0;
}

string Student::get_name() {
    return this->name;
}

int Student::get_total() {
    return this->scores[0];
}

int Student::get_chi() {
    return this->scores[1];
}

int Student::get_mat() {
    return this->scores[2];
}

int Student::get_eng() {
    return this->scores[3];
}

ostream& operator<< (ostream& out, const Student& src) {
    // tracer-Total-201-Chinese-1-Math-100-English-100
    out << src.name << "-Total-" << src.scores[0] << "-Chinese-" << src.scores[1] << "-Math-" << src.scores[2] << "-English-" << src.scores[3];
    return out;
}

bool operator< (Student&a, Student&b) {
    if (a.get_total() < b.get_total()) return true;
    else if (b.get_total() < a.get_total()) return false;
    else if (a.get_chi() < b.get_chi()) return true;
    else if (b.get_chi() < a.get_chi()) return false;
    else if (a.get_mat() < b.get_mat()) return true;
    else if (b.get_mat() < a.get_mat()) return false;
    else if (a.get_eng() < b.get_eng()) return true;
    else if (b.get_eng() < a.get_eng()) return false;
    else return false;
};