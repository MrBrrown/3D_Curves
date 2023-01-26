#include "Circle.h"
#include <iostream>
#include <cmath>

using namespace std;

double Circle::GetRadius() {
    return radius;
}

Circle::Circle(double radius) {
    this->radius = radius;
}

Point3D Circle::GetPoint3D(double  t) {
    Point3D point3D{radius*cos(t), radius*sin(t),0};
    return point3D;
}

Derivative Circle::GetDerivative(double t) {
    Derivative derivative{(-1*radius*sin(t)),(radius*cos(t)),0};
    return derivative;
}

void Circle::PrintParams() {
    cout<<"This is Circle, radius = "<<radius<<endl;
}

string Circle::GetType() {
    return "circle";
}
