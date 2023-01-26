#ifndef INC_3D_CURVES_ELIPS_H
#define INC_3D_CURVES_ELIPS_H
#include "Curve.h"

class Elips : public Curve
{
private:
    double radius_x;
    double radius_y;
public:
    Elips(double radius_x, double radius_y);

    Point3D GetPoint3D(double t) override;

    Derivative GetDerivative(double t) override;

    void PrintParams() override;

    string GetType() override;
};


#endif
