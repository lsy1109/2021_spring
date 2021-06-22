#include <iostream>
#include "Shape.h"
using namespace std;

Rectangle::Rectangle(double width, double height) {
    this->w = width;
    this->h = height;
}

Circle::Circle(double radius) {
    this->r = radius;
}

double Rectangle::getArea() {
    return this->w * this->h;
}

double Circle::getArea() {
    return 3.14 * this->r * this->r;
}