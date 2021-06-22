#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cow {
public:
    string name;
    int l, u, m;
    Cow(string a, int b, int c, int d) {
        name = a, l = b, u = c, m = d;
    }
};