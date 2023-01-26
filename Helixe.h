#ifndef INC_3D_CURVES_HELIXE_H
#define INC_3D_CURVES_HELIXE_H
#include "Curve.h"

class Helixe : public Curve
{
private:
    double radius;
    double step;
public:
    Helixe(double radius, double step);

    Point3D GetPoint3D(double t) override;

    Derivative GetDerivative(double t) override;

    void PrintParams() override;

    string GetType() override;
};


#endif
