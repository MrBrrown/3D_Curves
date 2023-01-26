#include "Elips.h"
#include <iostream>
#include <cmath>

using namespace std;

Elips::Elips(double radius_x, double radius_y) {
    this->radius_x = radius_x;
    this->radius_y = radius_y;
}

Point3D Elips::GetPoint3D(double t) {
    Point3D point3D{radius_x*cos(t),radius_y*sin(t),0};
    return point3D;
}

Derivative Elips::GetDerivative(double t) {
    Derivative derivative{(-1*radius_x*sin(t)),(radius_y* cos(t)),0};
    return derivative;
}

void Elips::PrintParams() {
    cout<<"This is Elips, radius_x = "<<radius_x<<", radius_y = "<<radius_y<<endl;
}

string Elips::GetType() {
    return "elips";
}
