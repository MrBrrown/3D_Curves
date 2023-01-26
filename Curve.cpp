#include "Curve.h"

Point3D Curve::GetPoint3D(double t) {
    return Point3D{};
}

Derivative Curve::GetDerivative(double t) {
    return Derivative{};
}

void Curve::PrintParams() {

}

string Curve::GetType() {
    return std::string();
}
