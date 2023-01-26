#include "Helixe.h"
#include <iostream>
#include <cmath>

using namespace std;

Helixe::Helixe(double radius, double step) {
    this->radius = radius;
    this->step = step;
}

Point3D Helixe::GetPoint3D(double t) {
    Point3D point3D{radius*t*cos(t),radius*t*sin(t),step*t};
    return point3D;
}

Derivative Helixe::GetDerivative(double t) {
    Derivative derivative{(radius*(cos(t)-t*sin(t))),(radius*(sin(t)+t*cos(t))),step};
    return  derivative;
}

void Helixe::PrintParams() {
    cout<<"This is Helixe, radius = "<<radius<<", step = "<<step<<endl;
}

string Helixe::GetType() {
    return "helixe";
}
